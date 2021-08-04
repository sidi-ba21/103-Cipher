/*
** EPITECH PROJECT, 2021
** gauss.c
** File description:
** gauss.c
*/

#include "cipher.h"
#include "my.h"

void reverse(struct cipher_t *cipher, int n)
{
    float **tab = malloc(sizeof(float *) * (n + 1));
    int k = 0;

    for (int i = 0; i < n; i++) {
        tab[i] = malloc(sizeof(float) * (2 * n));
        for (int j = 0; j < n; j++) {
            tab[i][j] = (float)cipher->ascii_key[k];
            k++;
        }
    }
    InverseOfMatrix(tab, n);
    cipher->reversed_key  = malloc(sizeof(float *) * (n + 1));
    for (int i = 0; i < n; i++) {
        k = 0;
        cipher->reversed_key[i] = malloc(sizeof(float) * n);
        for (int j = n; j < (2 * n); j++) {
            cipher->reversed_key[i][k] = tab[i][j];
            k++;
        }
    }
}

void InverseOfMatrix(float** matrix, int order)
{
    float temp;

    for (int i = 0; i < order; i++) {
        for (int j = 0; j < 2 * order; j++) {
            if (j == (i + order))
                matrix[i][j] = 1;
        }
    }
    for (int i = order - 1; i > 0; i--) {
        if (matrix[i - 1][0] < matrix[i][0]) {
            float* temp = matrix[i];
            matrix[i] = matrix[i - 1];
            matrix[i - 1] = temp;
        }
    }
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            if (j != i) {
                temp = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < 2 * order; k++)
                    matrix[j][k] -= matrix[i][k] * temp;
            }
        }
    }
    for (int i = 0; i < order; i++) {
        temp = matrix[i][i];
        if (temp == 0)
            exit(84);
        for (int j = 0; j < 2 * order; j++)
            matrix[i][j] = matrix[i][j] / temp;
    }
}
