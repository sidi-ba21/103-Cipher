/*
** EPITECH PROJECT, 2021
** display.c
** File description:
** display.c
*/

#include "cipher.h"

void disp_key_matrix(struct cipher_t *cipher, int size)
{
    int modulo = (int)sqrt(cipher->key_len);
    if (cipher->flag == 0) {
    printf("Key matrix:\n");
    for (int i = 0; i < size; i++) {
        if (i % modulo != 0)
            printf("\t%d", (int)cipher->ascii_key[i]);
        else
            printf("%d", (int)cipher->ascii_key[i]);
        if ((i + 1) % modulo == 0)
            printf("\n");
    }
    printf("\n");
    }
    else
        PrintInverse(cipher->reversed_key, modulo);
}

void PrintInverse(float** ar, int n)
{
    int tmp = 0;
    int temp = 0;

    printf("Key matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp = ar[i][j];
            temp = (ar[i][j] * 1000) - (tmp * 1000);
            if (ar[i][j] == 0)
                printf("%.1f", ar[i][j]);
            else if (temp % 10 == 0)
                printf("%.2f", ar[i][j]);
            else
                printf("%.3f", ar[i][j]);
            if (j >= 0 && j < n - 1)
                printf("\t");
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void disp_encryptage(struct cipher_t *cipher, int size)
{
    if (cipher->flag == 0) {
        printf("Encrypted message:\n");
        for (int i = 0; i < (size - 1); i++)
            printf("%d ", cipher->result[i]);
        printf("%d\n", cipher->result[size - 1]);
    }
     else {
       printf("Decrypted message:\n");
       my_decrypt_msg(cipher);
     }
}
