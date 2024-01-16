#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/opensslv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateUniqueKey(const char* input, unsigned char* key) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned int md_len;

    OpenSSL_add_all_digests();

    md = EVP_get_digestbyname("SHA256");

    if (!md) {
        printf("Error : SHA-256 not available.\n");
        exit(1);
    }

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, input, strlen(input));
    EVP_DigestFinal_ex(mdctx, key, &md_len);
    EVP_MD_CTX_free(mdctx);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <username>\n", argv[0]);
        return 1;
    }

    const char* pseudo = argv[1];
    unsigned char key[SHA256_DIGEST_LENGTH];

    generateUniqueKey(pseudo, key);

    printf("Generated Disk for User \"%s\":\n", pseudo);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");

    return 0;
}