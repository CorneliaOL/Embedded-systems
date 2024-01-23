#include <stdio.h>



int main() {
    unsigned int binaryValue = 0b10101010101010101010101010101010; // Example binary number
    binaryToHex(binaryValue);

    return 0;
}

void binaryToHex(unsigned int value) {
    char hexString[9]; // 8 hex digits + null terminator for 32-bit binary
    int hexDigitIndex = 8; // Start from the end of the string

    hexString[hexDigitIndex--] = '\0'; // Null-terminate the string

    for (int i = 0; i < 8; i++) { // Process each group of 4 bits
        // Extract the rightmost 4 bits and map to hex character
        unsigned int fourBits = value & 0xF; // 0xF is the bitmask for 4 bits
        if (fourBits < 10) {
            hexString[hexDigitIndex--] = '0' + fourBits;
        } else {
            hexString[hexDigitIndex--] = 'A' + (fourBits - 10);
        }

        value >>= 4; // Shift right by 4 bits
    }

    printf("0x%s\n", hexString + hexDigitIndex + 1); // Print hex string
}
