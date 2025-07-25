#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void simple_rc4(unsigned char *data, int len, unsigned char *key, unsigned char *out) {
    unsigned char s[256], temp;
    int i, j = 0, k;
    for (i = 0; i < 256; i++) s[i] = i;
    for (i = 0; i < 256; i++) {
        j = (j + s[i] + key[i % strlen((char *)key)]) % 256;
        temp = s[i]; s[i] = s[j]; s[j] = temp;
    }
    i = j = 0;
    for (k = 0; k < len; k++) {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        temp = s[i]; s[i] = s[j]; s[j] = temp;
        out[k] = data[k] ^ s[(s[i] + s[j]) % 256];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Penggunaan: %s <file_yang_mau_dienkripsi>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    if (!in) return 1;

    fseek(in, 0, SEEK_END);
    long size = ftell(in);
    fseek(in, 0, SEEK_SET);

    unsigned char *data = malloc(size);
    fread(data, 1, size, in);
    fclose(in);

    unsigned char *out = malloc(size);
    simple_rc4(data, size, (unsigned char *)"rc4isthekey", out);

    FILE *out_file = fopen("flag.enc", "wb");
    fwrite(out, 1, size, out_file);
    fclose(out_file);

    printf("File '%s' telah berhasil dienkripsi menjadi 'flag.enc'.\n", argv[1]);

    free(data);
    free(out);
    return 0;
}