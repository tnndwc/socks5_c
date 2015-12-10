//
// Created by Len on 12/9/15.
//

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct encry_key_s {
    size_t len;
    uint8_t key[0];
};

void f1() {
    int i = atoi("10");
    printf("atoi is %d\n", i);
}

void f2() {
    struct encry_key_s *key = NULL;
    size_t key_len;
    char st[] = "Hello";
    key_len = strlen(st);
    key = malloc(sizeof(*key) + key_len);
    key->len = key_len;
    memcpy(key->key, st, key_len);

    printf("%.*s\n", key_len, key->key);

    char *c = (char *) malloc(0.5);
    memcpy(c, key->key, key_len);

    printf("%s\n", c);
}

int main() {
    printf("Hello CLion\n");

    f2();

}
