
/*
** EPITECH PROJECT, 2021
** size.c
** File description:
** size.c
*/

#include "cipher.h"
#include "my.h"

int get_matrix_size(char *str)
{
    int len = strlen(str);
    int x = 1;

    while (x * x < len)
        x++;
    len = x * x;
    return (len);
}

int get_correct_size(struct cipher_t *cipher, int len)
{
    int size = (int)sqrt(cipher->key_len);

    while (len % size != 0)
        len++;
    return (len);
}

void matrix_key(struct cipher_t *cipher)
{
    int len = cipher->key_len;
    int str_len = strlen(cipher->key);
    int i = 0;

    cipher->ascii_key = malloc(sizeof(int) * len);
    if (cipher->ascii_key == NULL)
        error("Fatal error: malloc failed.\n");
    for (i = 0; i < len; i++)
        if (i >= str_len)
            cipher->ascii_key[i] = 0;
        else if (i < str_len)
            cipher->ascii_key[i] = (int)cipher->key[i];
}

void matrix_char_msg(struct cipher_t *cipher)
{
    int str_len = strlen(cipher->msg);
    int i = 0;
    int len = cipher->msg_len;

    cipher->ascii_msg = malloc(sizeof(int) * len);
    if (cipher->ascii_msg == NULL)
        error("Fatal error: malloc failed.\n");
    for (i = 0; i < len; i++) {
        if (i >= str_len)
            cipher->ascii_msg[i] = 0;
        else if (i < str_len)
            cipher->ascii_msg[i] = (int)cipher->msg[i];
    }
}
