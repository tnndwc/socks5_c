//
// Created by Len on 12/11/15.
//

#include "aes_cfb.h"
#include <stdio.h>
#include <openssl/ssl.h>
#include <string.h>

#define BUFSIZE 256

int doit(char* text, char* key, char* iv)
{
    int outlen, inlen;

    unsigned char inbuf[BUFSIZE] , outbuf[BUFSIZE];

    strcpy(inbuf,text);

    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);

    EVP_EncryptInit_ex(&ctx, EVP_aes_256_cfb8(), NULL, key, iv);

    int i =0;
    int n = strlen(text);
    unsigned char* p = outbuf;
    for(i; i < n; i++) {

        if(!EVP_EncryptUpdate(&ctx, p, &outlen, &inbuf[i], 1))
            return 0;
        p += outlen;
    }

    if(!EVP_EncryptFinal(&ctx, p, &outlen))
        return 0;
    p += outlen;

    EVP_CIPHER_CTX_cleanup(&ctx);

    outlen = p - outbuf;
    for (n = 0; n < outlen; n++)
        printf("%c", outbuf[n] & 0xff);
}

int main()
{
    char* key = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char* iv = "BBBBBBBBBBBBBBBB";
    doit("hello world", key, iv);
}
