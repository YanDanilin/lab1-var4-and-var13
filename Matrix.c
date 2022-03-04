#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct RingInfo {
    size_t size;
    void (*zero)(void *);
    void (*sum)(void *, void *, void *);
    void (*negative)(void *);
    void (*mult) (void *, void *, void *);
    void (*one)(void *);
    void (*inverse)(void *);
} RingInfo;

struct Matrix {
    int width;
    int height;
    void *matr;
    RingInfo *ring;
};

struct Matrix *Create() {
    struct Matrix *set = (struct Matrix *)calloc(1, sizeof(struct Matrix));
    set->matr = NULL;
    set->height = 0;
    set->width = 0;
    set->ring = NULL;
    return set;
}

void Summa(struct Matrix *set1, struct Matrix *set2, struct Matrix *res) {
    if (res->matr) {
        free(res->matr);
    }
    res->ring = set1->ring;
    if (set1->width == set2->width && set1->height == set2->height) {
        res->width = set1->width;
        res->height = set1->height;
        res->matr = calloc(res->width*res->height, res->ring->size);
        int  i;
        for (i = 0; i < res->width * res->height; i++) {
            res->ring->sum(set1->matr + i * set1->ring->size, set2->matr + i * set2->ring->size, res->matr + i * res->ring->size);
        }
        return;
    }
    printf("Matrices cannot be summarised\n");
}

void forMult(struct Matrix *set1, struct Matrix *set2, struct Matrix *res, int i, int j) {
    int k;
    res->ring->zero(res->matr + (i * res->width + j) * res->ring->size);
    for (k = 0; k < set1->width; k++) {
        void *tmp = calloc(1, res->ring->size);
        res->ring->zero(tmp);
        res->ring->mult(set1->matr + (i * set1->width + k) * set1->ring->size, set2->matr + (k * set2->width + j) * res->ring->size, tmp);
        res->ring->sum(res->matr + (i * res->width + j) * res->ring->size, tmp, res->matr + (i * res->width + j) * res->ring->size);
        free(tmp);
    }
}

void Multiply(struct Matrix *set1, struct Matrix *set2, struct Matrix *res) {
    if (res->matr) {
        free(res->matr);
    }
    res->ring = set1->ring;
    if (set1->width == set2->height) {
        res->height = set1->height;
        res->width = set2->width;
        int  i, j;
        res->matr = calloc(res->width*res->height, res->ring->size);
        for (i = 0; i < res->height; i++) {
            for (j = 0; j < res->width; j++) {
                forMult(set1, set2, res, i, j);
            }
        }
        return;
    }
    printf("Matrices cannot be multiplied\n");
}

void OnePlusAnother(struct Matrix *set, int to, int what, void *scalar) {
    int i;
    if (to > set->height - 1 || what > set->height - 1) {
        printf("Wrong row\n");
        return;
    }
    for (i = 0; i < set->width; i++) {
        void *tmp = calloc(1, set->ring->size);
        set->ring->zero(tmp);
        set->ring->mult(scalar, set->matr + (what * set->width + i) * set->ring->size, tmp);
        set->ring->sum(set->matr + (to * set->width + i) * set->ring->size, tmp, set->matr + (to * set->width + i) * set->ring->size);
        free(tmp);
    }
}

struct Matrix *Transposition(struct Matrix *set) {
    if (set->height == set->width) {
        struct Matrix *res = Create();
        res->height = set->height;
        res->width = set->width;
        res->ring = set->ring;
        res->matr = calloc(res->height*res->width, res->ring->size);
        int i, j;
        void *tmp = calloc(1, res->ring->size);
        res->ring->zero(tmp);
        for (i = 0; i < res->height; i++) {
            for (j = 0; j < res->width; j++) {
                res->ring->sum(tmp, set->matr + (i * set->width + j) * set->ring->size, res->matr + (j * res->width + i) * res->ring->size);
            }
        }
        free(tmp);
        free(set->matr);
        return res;
    }
    printf("Only square matrices can be transposed\n");
    return set;
}

void Destroy(struct Matrix *set) {
    if (set->matr) {
        free(set->matr);
    }
    free(set);
}