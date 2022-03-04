#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H

struct Matrix;
struct Matrix *Create();

void Summa(struct Matrix *set1, struct Matrix *set2, struct Matrix *res);
void Multiply(struct Matrix *set1, struct Matrix *set2, struct Matrix *res);
void OnePlusAnother(struct Matrix *set, int to, int what, void *scalar);
struct Matrix *Transposition(struct Matrix *set);
void Destroy(struct Matrix *set);

#endif //LAB1_MATRIX_H