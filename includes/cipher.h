/*
** EPITECH PROJECT, 2021
** cipher.h
** File description:
** cipher.h
*/

#ifndef CIPHER_H_
#define CIPHER_H_

#include <stddef.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cipher_t {
	char *msg;
	char *key;
	int *result;
    	float **res;
	int *ascii_msg;
        int **int_msg;
	float *ascii_key;
	float **reversed_key;
	int msg_len;
	int key_len;
        int flag;
};

int man(void);
int get_matrix_size(char *str);
int get_msg_matrix_size(struct cipher_t *cipher, int len);
void matrix_key(struct cipher_t *cipher);
void matrix_char_msg(struct cipher_t *cipher);
struct cipher_t *get_request(char *msg, char *key, char *flag);
void disp_key_matrix(struct cipher_t *cipher, int size);
void mult_matrix(struct cipher_t *cipher);
int get_correct_size(struct cipher_t *cipher, int len);
void check(int ac, char **av);
void error(const char *str);
void msg_len(struct cipher_t *cipher, char *msg);
void matrix_msg(struct cipher_t *cipher, char *msg);
void disp_encryptage(struct cipher_t *cipher, int size);
void reverse(struct cipher_t *cipher, int n);
void InverseOfMatrix(float** matrix, int order);
void my_decrypt_msg(struct cipher_t *cipher);
void PrintInverse(float** ar, int n);
void my_2d_msg(struct cipher_t *cipher);
void rev_mult(struct cipher_t *cipher);

#endif
