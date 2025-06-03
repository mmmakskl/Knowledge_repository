#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

#pragma pack(1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;
    uint8_t rgbReserved;
} RGBQUAD;

int main() {
    string inputFileName = "test.bmp";
    string outputFileName = "output.bmp";

    ifstream inputFile(inputFileName, ios::binary);
    if (!inputFile) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    ofstream outputFile(outputFileName, ios::binary);
    if (!outputFile) {
        cerr << "Error: Cannot create output file." << endl;
        inputFile.close();
        return 1;
    }

    // Считываем заголовки
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    RGBQUAD paletteInput[256];

    inputFile.read(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));
    inputFile.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));

    if (bmpFileHeader.bfType != 0x4D42) { // 'BM' in ASCII
        cerr << "Error: Not a valid BMP file." << endl;
        inputFile.close();
        outputFile.close();
        return 1;
    }

    if (bmpInfoHeader.biBitCount != 8) {
        cerr << "Error: Only 8-bit BMP files are supported." << endl;
        inputFile.close();
        outputFile.close();
        return 1;
    }

    // Считываем палитру
    inputFile.read(reinterpret_cast<char*>(paletteInput), 256 * sizeof(RGBQUAD));

    // Установка указателя на начало растра
    int padding = (4 - (bmpInfoHeader.biWidth) % 4) % 4;
    int width = bmpInfoHeader.biWidth;
    int height = abs(bmpInfoHeader.biHeight);

    // Вывод информации об изображении
    cout << "Разрешение изображения: " << width << "x" << height << endl;
    cout << "Количество бит на пиксел: " << bmpInfoHeader.biBitCount << endl;
    cout << "Размер изображения: " << bmpFileHeader.bfSize << " байт" << endl;

    // Создаем новую палитру (монохромную)
    RGBQUAD palette[2];
    palette[0].rgbBlue = 0;
    palette[0].rgbGreen = 0;
    palette[0].rgbRed = 0;
    palette[0].rgbReserved = 0;

    palette[1].rgbBlue = 255;
    palette[1].rgbGreen = 255;
    palette[1].rgbRed = 255;
    palette[1].rgbReserved = 0;

    // Обновляем заголовки для монохромного формата
    BITMAPFILEHEADER newBmpFileHeader = bmpFileHeader;
    BITMAPINFOHEADER newBmpInfoHeader = bmpInfoHeader;

    newBmpFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 2 * sizeof(RGBQUAD);
    newBmpFileHeader.bfSize = newBmpFileHeader.bfOffBits + ((width + 7) / 8) * height + padding * height;

    newBmpInfoHeader.biBitCount = 1; // Монохромный формат
    newBmpInfoHeader.biClrUsed = 2;  // Используется 2 цвета (черный и белый)

    // Записываем новые заголовки
    outputFile.write(reinterpret_cast<char*>(&newBmpFileHeader), sizeof(newBmpFileHeader));
    outputFile.write(reinterpret_cast<char*>(&newBmpInfoHeader), sizeof(newBmpInfoHeader));
    outputFile.write(reinterpret_cast<char*>(palette), 2 * sizeof(RGBQUAD));

    // Выделяем память для входных и выходных данных
    uint8_t* inBuf = new uint8_t[width];
    uint8_t* outBuf = new uint8_t[(width + 7) / 8]; // Для монохромного формата

    int binarizationThreshold;
    cout << "Введите порог бинаризации (число от 0 до 255): ";
    cin >> binarizationThreshold;

    // Бинаризация изображения
    for (int i = 0; i < height; i++) {
        // Считываем строку пикселей
        inputFile.read(reinterpret_cast<char*>(inBuf), width);
        inputFile.seekg(padding, ios::cur); // Пропускаем паддинг

        // Преобразуем пиксели в монохромный формат
        memset(outBuf, 0, (width + 7) / 8);
        for (int j = 0; j < width; j++) {
            uint8_t index = inBuf[j];
            uint8_t gray = (paletteInput[index].rgbRed + paletteInput[index].rgbGreen + paletteInput[index].rgbBlue) / 3;

            if (gray > binarizationThreshold) {
                outBuf[j / 8] |= (0x80 >> (j % 8)); // Устанавливаем бит
            }
        }

        // Записываем результат
        outputFile.write(reinterpret_cast<char*>(outBuf), (width + 7) / 8);

        // Добавляем паддинг для выравнивания строки
        for (int k = 0; k < padding; k++) {
            outputFile.put(0);
        }
    }

    // Освобождаем память
    delete[] inBuf;
    delete[] outBuf;

    // Закрываем файлы
    inputFile.close();
    outputFile.close();

    cout << "Бинаризация завершена успешно!" << endl;

    return 0;
}