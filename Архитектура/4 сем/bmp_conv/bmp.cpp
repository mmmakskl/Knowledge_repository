#include <iostream>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <unistd.h>
#include <climits>

using namespace std;

#pragma pack(push, 1)
struct BITMAPFILEHEADER {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

struct BITMAPINFOHEADER {
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
};

struct RGBQUAD {
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;
    uint8_t rgbReserved;
};

struct RGBTRIPLE {
    uint8_t rgbtBlue;
    uint8_t rgbtGreen;
    uint8_t rgbtRed;
};
#pragma pack(pop)

RGBQUAD Palette[256];

uint8_t FindClosestColor(RGBTRIPLE pixel) {
    int minDistance = INT_MAX;
    uint8_t bestMatch = 0;

    for (int i = 0; i < 256; i++) {
        int dr = pixel.rgbtRed - Palette[i].rgbRed;
        int dg = pixel.rgbtGreen - Palette[i].rgbGreen;
        int db = pixel.rgbtBlue - Palette[i].rgbBlue;
        int distance = dr*dr + dg*dg + db*db;

        if (distance < minDistance) {
            minDistance = distance;
            bestMatch = i;
        }
    }
    return bestMatch;
}

void InitColorPalette() {
    for (int i = 0; i < 256; i++) {
        Palette[i].rgbRed = (i * 7) % 256;
        Palette[i].rgbGreen = (i * 13) % 256;
        Palette[i].rgbBlue = (i * 17) % 256;
        Palette[i].rgbReserved = 0;
    }
}

int main() {
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    
    // Открытие файлов
    ifstream inFile("Aiplane16.bmp", ios::binary);
    ofstream outFile("Result.bmp", ios::binary);

    if (!inFile || !outFile) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    // Чтение заголовков
    inFile.read(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));
    inFile.read(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));

    if (bmpInfoHeader.biBitCount != 16) {
        cerr << "Error: Input must be 16-bit bitmap!" << endl;
        return 1;
    }

    const int Width = bmpInfoHeader.biWidth;
    const int Height = abs(bmpInfoHeader.biHeight);
    const int rowSizeIn = ((Width * 2 + 3) & ~3);
    const int rowSizeOut = ((Width + 3) / 4) * 4; // Corrected row size calculation

    // Инициализация палитры
    InitColorPalette();

    // Обновление заголовков
    bmpFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + 
                             sizeof(BITMAPINFOHEADER) + 
                             sizeof(Palette);
    bmpInfoHeader.biBitCount = 8;
    bmpInfoHeader.biSizeImage = rowSizeOut * Height;
    bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + bmpInfoHeader.biSizeImage;
    bmpInfoHeader.biClrUsed = 256;

    // Запись заголовков
    outFile.write(reinterpret_cast<char*>(&bmpFileHeader), sizeof(bmpFileHeader));
    outFile.write(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));
    outFile.write(reinterpret_cast<char*>(Palette), sizeof(Palette));

    // Обработка пикселей
    uint8_t* inBuf = new uint8_t[rowSizeIn];
    uint8_t* outBuf = new uint8_t[rowSizeOut];

    for (int i = 0; i < Height; i++) {
        inFile.read(reinterpret_cast<char*>(inBuf), rowSizeIn);
        
        for (int j = 0; j < Width; j++) {
            uint16_t pixel = *reinterpret_cast<uint16_t*>(&inBuf[j*2]);
            
            RGBTRIPLE rgbTriple;
            rgbTriple.rgbtRed = ((pixel >> 11) & 0x1F) * 255 / 31;
            rgbTriple.rgbtGreen = ((pixel >> 5) & 0x3F) * 255 / 63;
            rgbTriple.rgbtBlue = (pixel & 0x1F) * 255 / 31;

            outBuf[j] = FindClosestColor(rgbTriple);
        }
        // Write the row and padding bytes
        outFile.write(reinterpret_cast<char*>(outBuf), Width);
        outFile.write("\0\0\0", rowSizeOut - Width); // Write padding bytes
    }

    delete[] inBuf;
    delete[] outBuf;
    cout << "Conversion successful!" << endl;
    return 0;
}