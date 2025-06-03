#include <stdio.h>
#include <stdint.h>

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
} BITMAPINFOHEADER;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <bmp_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(fileHeader), 1, file);

    if (fileHeader.bfType != 0x4D42) { // 'BM' in ASCII
        printf("Error: Not a valid BMP file.\n");
        fclose(file);
        return 1;
    }

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(infoHeader), 1, file);

    printf("File Size: %d bytes\n", fileHeader.bfSize);
    printf("Image Width: %d pixels\n", infoHeader.biWidth);
    printf("Image Height: %d pixels\n", infoHeader.biHeight);
    printf("Bits per Pixel: %d\n", infoHeader.biBitCount);

    fclose(file);
    return 0;
}