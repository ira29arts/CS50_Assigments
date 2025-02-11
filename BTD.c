#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert binary to hexadecimal
char *binaryToHexadecimal(const char *binary) {
    if (binary == NULL) {
        return NULL; // Handle null input
    }

    int binaryLength = strlen(binary);

    // Check if the binary string contains only 0s and 1s
    for (int i = 0; i < binaryLength; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return NULL; // Invalid binary input
        }
    }

    // Pad with leading zeros if necessary to make length a multiple of 4
    int paddingNeeded = 4 - (binaryLength % 4);
    if (paddingNeeded != 4) {  // Avoid padding if already a multiple of 4
        char *paddedBinary = (char *)malloc((binaryLength + paddingNeeded + 1) * sizeof(char));
        if (paddedBinary == NULL) {
            perror("Memory allocation failed"); // Handle malloc failure
            exit(EXIT_FAILURE);
        }

        memset(paddedBinary, '0', paddingNeeded); // Fill with padding zeros
        strcpy(paddedBinary + paddingNeeded, binary); // Append original binary
        paddedBinary[binaryLength + paddingNeeded] = '\0'; // Null-terminate
        binary = paddedBinary; // Use the padded version
        binaryLength = strlen(binary); // Update length
    }


    int hexLength = binaryLength / 4;
    char *hexadecimal = (char *)malloc((hexLength + 1) * sizeof(char));
    if (hexadecimal == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    hexadecimal[hexLength] = '\0'; // Null-terminate the hexadecimal string

    for (int i = 0; i < hexLength; i++) {
        int decimalValue = 0;
        for (int j = 0; j < 4; j++) {
            decimalValue = decimalValue * 2 + (binary[i * 4 + j] - '0');
        }

        if (decimalValue < 10) {
            hexadecimal[i] = decimalValue + '0';
        } else {
            hexadecimal[i] = decimalValue - 10 + 'A';
        }
    }

    if (paddingNeeded != 4) {
        free((char*)binary); // Free the padded binary if it was allocated
    }

    return hexadecimal;
}

int main() {
    char binary[100];

    printf("Enter binary number: ");
    scanf("%99s", binary); // Limit input to prevent buffer overflows

    char *hexadecimal = binaryToHexadecimal(binary);

    if (hexadecimal == NULL) {
        printf("Invalid binary input or memory allocation failed.\n");
    } else {
        printf("Hexadecimal equivalent: %s\n", hexadecimal);
        free(hexadecimal); // Free the allocated memory
    }


    return 0;
}
