/*
** EPITECH PROJECT, 2021
** get.c
** File description:
** get.c
*/

#include "cipher.h"
#include "my.h"

struct cipher_t *get_request(char *msg, char *key, char *flag)
{
    struct cipher_t *cipher = malloc(sizeof(struct cipher_t));

    if (cipher == NULL)
        error("Fatal error: malloc failed.\n");
    cipher->msg = msg;
    cipher->key = key;
    cipher->key_len = get_matrix_size(cipher->key);
    cipher->msg_len = get_correct_size(cipher, strlen(cipher->msg));
    if (flag[0] == '0')
        cipher->flag = 0;
    else if (flag[0] == '1')
        cipher->flag = 1;
    return (cipher);
}
