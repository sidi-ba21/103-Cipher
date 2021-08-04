/*
** EPITECH PROJECT, 2021
** cypher
** File description:
** main.c
*/

#include "my.h"
#include "cipher.h"

int main(int ac, char **av)
{
    struct cipher_t *cipher;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        man();
    check(ac, av);
    cipher = get_request(av[1], av[2], av[3]);
    matrix_key(cipher);
    if (cipher->flag == 0) {
        matrix_char_msg(cipher);
        mult_matrix(cipher);
    }
    else if (cipher->flag == 1) {
        matrix_msg(cipher, av[1]);
        rev_mult(cipher);
    }
    disp_key_matrix(cipher, cipher->key_len);
    disp_encryptage(cipher, cipher->msg_len);
    return (0);
}

void check(int ac, char **av)
{
    unsigned int i;

    if (ac != 4)
        error("Bad usage.\n");
    if (strlen(av[1]) == 0 || strlen(av[2]) == 0)
        error("Bad syntax.\n");
    if (my_getnbr(av[3]) != 0 && my_getnbr(av[3]) != 1)
        error("Bad syntax.\n");
    if (my_getnbr(av[3]) == 1) {
        for (i = 0; i < strlen(av[1]); i++)
            if (!(av[1][i] >= '0' && av[1][i] <= '9')
                && av[1][i] != ' ')
                error("Bad syntax.\n");
    }
}

void error(const char *str)
{
    int len = strlen(str);

    write(2, str, len);
    exit(84);
}
