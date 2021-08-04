/*
** EPITECH PROJECT, 2021
** cipher reverse.c
** File description:
** cipher reverse.c
*/

#include "cipher.h"

void matrix_msg(struct cipher_t *cipher, char *msg)
{
    int i = 0;
    int nb = 0;

    msg_len(cipher, msg);
    for (int j = 0; msg[j] != '\0'; j++) {
        if (msg[j] >= '0' && msg[j] <= '9') {
            nb *= 10;
            nb += msg[j] - '0';
        }
        else if (nb > 0) {
            cipher->ascii_msg[i] = nb;
            nb = 0;
            i++;
        }
    }
    if (nb != 0)
        cipher->ascii_msg[i] = nb;
    my_2d_msg(cipher);
}

void my_2d_msg(struct cipher_t *cipher)
{
    int size = cipher->key_len;
    int len = cipher->msg_len;
    int col = (int)sqrt(size);
    int l = len / col;
    int j = 0;
    int k = 0;

    cipher->int_msg = malloc(sizeof(int *) * l);
    for (int i = 0; i < l; i++) {
        cipher->int_msg[i] = malloc(sizeof(int) * col);
        for (j = 0; j < col; j++) {
            cipher->int_msg[i][j] = (float)cipher->ascii_msg[k];
            k++;
        }
    }
}

void msg_len(struct cipher_t *cipher, char *msg)
{
    int len = 1;

    for (int i = 0; msg[i]; i++)
        if (msg[i] == ' ' && msg[i + 1] != ' ')
            len++;
    len = get_correct_size(cipher, len);
    cipher->ascii_msg = malloc(sizeof(int) * len);
    cipher->msg_len = len;
    if (cipher->ascii_msg == NULL)
        error("Fatal error: malloc failed.");
}

void my_decrypt_msg(struct cipher_t *cipher)
{
    int j = 0;
    int size = cipher->key_len;
    int len = cipher->msg_len;
    int col = (int)sqrt(size);
    int l = len / col;

    for (int i = 0; i < l; i++)
        for (j = 0; j < col; j++)
            if (round(cipher->res[i][j]) != 0)
                printf("%c", (char)(int)round(cipher->res[i][j]));
    printf("\n");
}
