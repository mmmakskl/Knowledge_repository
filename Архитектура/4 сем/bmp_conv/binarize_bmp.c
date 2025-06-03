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

void write_bmp_header(FILE *output, BITMAPFILEHEADER header, BITMAPINFOHEADER infoHeader) {
    fwrite(&header, sizeof(header), 1, output);
    fwrite(&infoHeader, sizeof(infoHeader), 1, output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_bmp> <threshold>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    int threshold = atoi(argv[2]);

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(fileHeader), 1, input);

    if (fileHeader.bfType != 0x4D42) {
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

    RGBTRIPLE *row = malloc(width * sizeof(RGBTRIPLE));
    if (!row) {
        printf("Error: Memory allocation failed.\n");
        fclose(input);
        return 1;
    }

    // Create output file
    FILE *output = fopen("output_bmp.bmp", "wb");
    if (!output) {
        printf("Error: Cannot create output file.\n");
        free(row);
        fclose(input);
        return 1;
    }

    // Write headers to output file
    write_bmp_header(output, fileHeader, infoHeader);

    // Process each row
    for (int i = 0; i < height; i++) {
        fread(row, sizeof(RGBTRIPLE), width, input);
        fseek(input, padding, SEEK_CUR);

        for (int j = 0; j < width; j++) {
            int gray = 0.3 * row[j].rgbRed + 0.59 * row[j].rgbGreen + 0.11 * row[j].rgbBlue;
            if (gray > threshold) {
                row[j].rgbRed = row[j].rgbGreen = row[j].rgbBlue = 255;
            } else {
                row[j].rgbRed = row[j].rgbGreen = row[j].rgbBlue = 0;
            }
        }

        fwrite(row, sizeof(RGBTRIPLE), width, output);
        for (int k = 0; k < padding; k++) {
            fputc(0, output);
        }
    }

    free(row);
    fclose(input);
    fclose(output);

    printf("Binarization completed successfully!\n");
    return 0;
}