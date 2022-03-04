#ifndef LAB1_UI_H
#define LAB1_UI_H

struct Matrix {
    int width;
    int height;
    void *matr;
    RingInfo *ring;
};

enum Type {
    INT = 1,
    DOUBLE,
    COMPLEX
};

struct Matrix *EnterInt(struct Matrix *set);
void OutputInt(struct Matrix* set);

struct Matrix *EnterDouble(struct Matrix *set);
void OutputDouble(struct Matrix* set);

struct Matrix *EnterComplex(struct Matrix *set);
void OutputComplex(struct Matrix* set);

#endif //LAB1_UI_H
