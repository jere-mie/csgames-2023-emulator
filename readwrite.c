#include <stdio.h>
#include <stdint.h>

uint8_t ram[65536]; // Simulate ram usage.
int total = 0; // Details total number of times 6502 writes to memory address 0xFFF1 (should be 48 times).
char output[49]; // Contains the history of what is written to address 0xFFF1. It's of length 49 for the null terminator.


uint8_t read6502(uint16_t address) {
    return ram[address]; // Simply return the memory address (or the index of the array).
}

void write6502(uint16_t address, uint8_t value) {
    ram[address] = value;
    if(address == 0xFFF1) {
        output[total] = value; // Add to the output variable.
        total++; // Increment total.
    }
}

// Reads atlantis.bin into RAM.
int readFile() {
    FILE *fp = fopen ("atlantis.bin", "rb"); // Open file.
    size_t bytes; // Contains return value of fread.
    uint8_t temp_value;
    uint16_t index = 0;

    if (!fp) {
        printf("Error: file open failed 'atlantis.bin'\n");
        return 1;
    }

    // Read data from file into a temporary value, then call write6502 to write to memory.
    while ((bytes = fread(&temp_value, 1, 1, fp)) == 1) {
        write6502(index++, temp_value);
    }

    fclose(fp); // Close file.
    return 0;
}

// Nullify the output string for each iteration.
void clear_output() {
    for(int i = 0;i < 49;i++) output[i] = 0;
}

int main(void) {

    // Brute force method to check all 1000 possible encryption keys.
    for(uint8_t i = '0';i <= '9';i++) {
        for(uint8_t j = '0';j <= '9';j++) {
            for(uint8_t k = '0';k <= '9';k++) {
                if(readFile()) return 1; // Read the file into memory.
                reset6502();

                // Write encryption key.
                write6502(0x200, i);
                write6502(0x201, j);
                write6502(0x202, k);
                total = 0; // Reset count.
                clear_output();

                // Keep executing until memory address 0xFFF1 has been written to 48 times.
                while(total < 48) {
                    step6502();
                }

                // Prophecy is fulfilled when there are no #'s.
                if(output[0] != '#') {
                    printf("The secret encryption key is %c%c%c, the prophecy:\n%s\n", i, j, k, output);
                    return 0; // Exit program.
                }
            }
        }
    }

    printf("No prophecy found!\n"); // No encryption key found.
    return 1;
}