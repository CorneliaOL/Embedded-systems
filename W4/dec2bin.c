
#include <stdio.h>
#include <stdlib.h>

void displayBits(unsigned int value); // prototype

int main(int argc, char *argv[]) {

    if (argc == 2) {

        unsigned int x = atoi(argv[1]);
        displayBits(x);
    } else {
        unsigned int x;
        scanf("%u", &x);
        displayBits(x);
    }

    return 0;
}

// display bits of an unsigned int value
void displayBits(unsigned int value) {

    // define displayMask and left shift (8-bits)
    unsigned int displayMask = 1 << 7;

    // loop through bits
    for (unsigned int c = 1; c <= 8; ++c) {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; // shift value left by 1
    }

}