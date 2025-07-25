#include <stdio.h>
#include <string.h>

int main() {
    unsigned char enc_part1[] = {
        0x5d, 0x76, 0x65, 0x50, 0x7c, 0x7e, 0x63, 0x68, 0x76, 0x69,
        0x69, 0x69, 0x4c, 0x7f, 0x72, 0x7b, 0x4c, 0x6a, 0x72, 0x4c,
        0x71, 0x72, 0x61, 0x66
    };

    unsigned char enc_part2[] = {
        0x68, 0x47, 0x52, 0x5a, 0x56, 0x59, 0x56, 0x44, 0x56, 0x59,
        0x68, 0x54, 0x42, 0x5a, 0x56, 0x59, 0x68, 0x55, 0x56, 0x44,
        0x5e, 0x54, 0x68, 0x4f, 0x07, 0x45, 0x68, 0x53, 0x58, 0x56,
        0x59, 0x50, 0x4a
    };

    char input[128];
    size_t part1_len = sizeof(enc_part1);
    size_t part2_len = sizeof(enc_part2);
    size_t total_len = part1_len + part2_len;

    printf("Give me the flag:\n> ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (strlen(input) != total_len) {
        puts("Wrong flag length!");
        return 1;
    }

    for (int i = 0; i < part1_len; i++) {
        if ((input[i] ^ 0x13) != enc_part1[i]) {
            puts("Wrong flag!");
            return 1;
        }
    }

    for (int i = 0; i < part2_len; i++) {
        if ((input[part1_len + i] ^ 0x37) != enc_part2[i]) {
            puts("Wrong flag!");
            return 1;
        }
    }

    puts("Congratulations! Your flag is correct!");
    return 0;
}
