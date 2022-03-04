#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RingInfo.h"

struct Matrix {
    int width;
    int height;
    void *matr;
    RingInfo *ring;
};

struct Matrix *EnterInt(struct Matrix *set) {
    if (set->matr) {
        free(set->matr);
    }
    printf("Enter height: ");
    scanf("%d", &(set->height));
    printf("Enter width: ");
    scanf("%d", &(set->width));
    int i;
    srand(time(NULL));
    set->matr = calloc(set->height * set->width, set->ring->size);
    for (i = 0; i < set->height*set->width; i++) {
        *((int*)(set->matr + i * set->ring->size)) = rand()%50;
    }
    return set;
}

void OutputInt(struct Matrix* set) {
    if (set->matr) {
        int i, j;
        for (i = 0; i < set->height; i++) {
            for (j = 0; j < set->width; j++) {
                printf("%5d", *(int *)(set->matr + (i * set->width + j) * set->ring->size));
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    printf("Nothing to output... Enter matrix before\n");
}

struct Matrix *EnterDouble(struct Matrix *set) {
    if (set->matr) {
        free(set->matr);
    }
    printf("Enter height: ");
    scanf("%d", &(set->height));
    printf("Enter width: ");
    scanf("%d", &(set->width));
    int i;
    srand(time(NULL));
    set->matr = calloc(set->height * set->width, set->ring->size);
    for (i = 0; i < set->height*set->width; i++) {
        *((double*)(set->matr + i * set->ring->size)) = (rand()%500)/10.0;
    }
    return set;
}

void OutputDouble(struct Matrix* set) {
    if (set->matr) {
        int i, j;
        for (i = 0; i < set->height; i++) {
            for (j = 0; j < set->width; j++) {
                printf("  %.1lf", *(double *)(set->matr + (i * set->width + j) * set->ring->size));
            }
            printf("\n");
        }
        printf("\n");

        return;
    }
    printf("Nothing to output... Enter matrix before\n");
}

struct Matrix *EnterComplex(struct Matrix *set) {
    if (set->matr) {
        free(set->matr);
    }
    printf("Enter height: ");
    scanf("%d", &(set->height));
    printf("Enter width: ");
    scanf("%d", &(set->width));
    int i;
    srand(time(NULL));
    set->matr = calloc(set->height * set->width, set->ring->size);
    for (i = 0; i < set->height*set->width; i++) {
        ((Complex *)(set->matr + i * set->ring->size))->Re = (rand()%500)/10.0;
        ((Complex *)(set->matr + i * set->ring->size))->Im = (rand()%500)/10.0;
    }
    return set;
}

void OutputComplex(struct Matrix* set) {
    if (set->matr) {
        int i, j;
        for (i = 0; i < set->height; i++) {
            for (j = 0; j < set->width; j++) {
                printf("  %.1lf+i%.1lf", ((Complex*)(set->matr + (i * set->width + j) * set->ring->size))->Re, ((Complex*)(set->matr + (i * set->width + j) * set->ring->size))->Im);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    printf("Nothing to output... Enter matrix before\n");
}