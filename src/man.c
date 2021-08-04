/*
** EPITECH PROJECT, 2021
** man
** File description:
** manuel
*/

#include "my.h"

int man(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./103cipher message key flag\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    message    a message, made of ASCII characters\n");
    my_putstr("    key        the encryption key, made of ASCII characters\n");
    my_putstr("    flag       0 for the message to be encrypted, ");
    my_putstr("1 to be decrypted\n");
    exit(0);
}
