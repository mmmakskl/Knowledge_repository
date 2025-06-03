#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
} RGBTRIPLE;

typedef struct {
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;
    uint8_t rgbReserved;
} RGBQUAD;

void write_bmp_header(FILE *output, BITMAPFILEHEADER header, BITMAPINFOHEADER infoHeader) {
    fwrite(&header, sizeof(header), 1, output);
    fwrite(&infoHeader, sizeof(infoHeader), 1, output);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_bmp>\n", argv[0]);
        return 1;
    }

    // Открываем входной файл
    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    // Читаем заголовки
    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(fileHeader), 1, input);

    if (fileHeader.bfType != 0x4D42) { // 'BM' in ASCII
        printf("Error: Not a valid BMP file.\n");
        fclose(input);
        return 1;
    }

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(infoHeader), 1, input);

    if (infoHeader.biBitCount != 24) {
        printf("Error: Only 24-bit BMP files are supported.\n");
        fclose(input);
        return 1;
    }

    int width = infoHeader.biWidth;
    int height = abs(infoHeader.biHeight);
    int padding = (4 - (width * 3) % 4) % 4;

    // Выделяем память для строки пикселей
    RGBTRIPLE *row = malloc(width * sizeof(RGBTRIPLE));
    if (!row) {
        printf("Error: Memory allocation failed.\n");
        fclose(input);
        return 1;
    }

    // Создаем выходной файл
    FILE *output = fopen("output_8bit.bmp", "wb");
    if (!output) {
        printf("Error: Cannot create output file.\n");
        free(row);
        fclose(input);
        return 1;
    }

    // Создаем палитру (256 цветов)
    RGBQUAD palette[128];
    for (int i = 0; i < 128; i++) {
        palette[i].rgbBlue = i;
        palette[i].rgbGreen = i;
        palette[i].rgbRed = i;
        palette[i].rgbReserved = 0;
    }

    // Обновляем заголовки для 8-битного формата
    BITMAPFILEHEADER newFileHeader = fileHeader;
    BITMAPINFOHEADER newInfoHeader = infoHeader;

    newFileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 128 * sizeof(RGBQUAD) + width * height;
    newFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 128 * sizeof(RGBQUAD);

    newInfoHeader.biBitCount = 8;
    newInfoHeader.biClrUsed = 128;
    newInfoHeader.biClrImportant = 128;

    // Записываем новые заголовки и палитру
    write_bmp_header(output, newFileHeader, newInfoHeader);
    fwrite(palette, sizeof(RGBQUAD), 128, output);

    // Выделяем память для 8-битных пикселей
    uint8_t *outRow = malloc(width * sizeof(uint8_t));
    if (!outRow) {
        printf("Error: Memory allocation failed.\n");
        free(row);
        fclose(input);
        fclose(output);
        return 1;
    }

    // Обрабатываем каждую строку
    for (int i = 0; i < height; i++) {
        // Читаем строку пикселей из входного файла
        fread(row, sizeof(RGBTRIPLE), width, input);
        fseek(input, padding, SEEK_CUR);

        // Преобразуем пиксели в 8-битные значения
        for (int j = 0; j < width; j++) {
            // Вычисляем яркость (grayscale)
            int gray = 0.3 * row[j].rgbRed + 0.59 * row[j].rgbGreen + 0.11 * row[j].rgbBlue;
            outRow[j] = gray / 2; // Нормализуем значение в диапазон [0, 255]
        }

        // Записываем преобразованную строку в выходной файл
        fwrite(outRow, sizeof(uint8_t), width, output);
    }

    // Освобождаем память
    free(row);
    free(outRow);

    // Закрываем файлы
    fclose(input);
    fclose(output);

    printf("Conversion completed successfully!\n");
    return 0;
}