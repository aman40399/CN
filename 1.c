#include <stdio.h>
#include <math.h>

void generateHammingCode(char data[]) {
    char hammingCode[12];
    int k = 0;

    // Placing data bits and leaving spaces for parity bits
    for (int i = 1; i <= 11; i++) {
        if ((i & (i - 1)) == 0) {
            hammingCode[i - 1] = '0'; // Parity bit placeholder
        } else {
            hammingCode[i - 1] = data[k++];
        }
    }

    // Calculate parity bits
    for (int i = 0; i < 4; i++) {
        int parityIndex = (int)pow(2, i) - 1;
        int count = 0;

        for (int j = parityIndex; j < 11; j += (parityIndex + 1) * 2) {
            for (int k = j; k < j + parityIndex + 1 && k < 11; k++) {
                if (hammingCode[k] == '1') {
                    count++;
                }
            }
        }

        hammingCode[parityIndex] = (count % 2 == 0) ? '0' : '1';
    }

    printf("Encoded Hamming code: ");
    for (int i = 0; i < 11; i++) {
        printf("%c", hammingCode[i]);
    }
    printf("\n");
}

int main() {
    char data[8];

    printf("Enter 7-bit data: ");
    scanf("%7s", data);

    generateHammingCode(data);
    return 0;
}