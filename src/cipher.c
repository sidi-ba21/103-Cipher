/*
** EPITECH PROJECT, 2021
** cypher.c
** File description:
** cypher.c
*/

#include "cipher.h"
#include "my.h"

float res_col(struct cipher_t *cipher, int i, int j, int col)
{
    float res = 0;
    int k = 0;

    while ( k < col) {
        if (cipher->flag == 0)
            res += cipher->ascii_msg[i] * cipher->ascii_key[j];
        j = j + col;
        i++;
        k++;
    }
    return (res);
}

void mult_matrix(struct cipher_t *cipher)
{
    int j = 0;
    int size = cipher->key_len;
    int len = cipher->msg_len;
    int k = 0;

    cipher->result = malloc(sizeof(int) * len);
    if (cipher->result == NULL)
        error("Fatal error: malloc failed.\n");
    for (int i = 0; i < len; i++) {
        j = 0;
        while (j < (int)sqrt(size)) {
            cipher->result[i] += (int)res_col(cipher, k, j, (int)sqrt(size));
            j++;
            i++;
        }
        i--;
        k += (int)sqrt(size);
    }
}

void rev_mult(struct cipher_t *cipher)
{
    int j = 0;
    int size = cipher->key_len;
    int len = cipher->msg_len;
    int col = (int)sqrt(size);
    int l = len / col;

    reverse(cipher, col);
    cipher->res = malloc(sizeof(float *) * l);
    if (cipher->res == NULL)
        error("Fatal error: malloc failed.\n");
    for (int i = 0; i < l; i++) {
        cipher->res[i] = malloc(sizeof(float) * col);
        for (j = 0; j < col; j++) {
            for (int k = 0; k < col; k++) {
                cipher->res[i][j] += cipher->int_msg[i][k] *
                    cipher->reversed_key[k][j];
            }
        }
    }
}
