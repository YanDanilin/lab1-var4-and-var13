#ifndef LAB1_RINGINFO_H
#define LAB1_RINGINFO_H
#include <stdio.h>

typedef struct RingInfo{
size_t size;
void (*zero)(void *);
void (*sum)(void *, void *, void *);
void (*negative)(void *);
void (*mult)(void *, void *, void*);
void (*one)(void *);
void (*inverse)(void *);
} RingInfo;

typedef struct Complex {
    double Re;
    double Im;
} Complex;

void IntOne(void *);
void IntZero(void *);
void IntNeg(void *x);
void IntSum(void *x, void *y, void *res);
void IntMult(void *x, void *y, void *res);
void InvInt(void *scalar);

void DoubleOne(void *);
void DoubleZero(void *);
void DoubleNeg(void *x);
void DoubleSum(void *x, void *y, void *res);
void DoubleMult(void *x, void *y, void *res);
void InvDouble(void *scalar);

void ComplexOne(void *);
void ComplexZero(void *);
void ComplexNeg(void *x);
void ComplexSum(void *x, void *y, void *res);
void ComplexMult(void *x, void *y, void *res);
void InvComplex(void *scalar);

RingInfo *CreateRingInfo(
        size_t size,
        void (*one)(void *),
        void (*zero)(void *),
        void (*negative)(void *),
        void (*sum)(void *, void *, void*),
        void (*mult)(void *, void *, void*),
        void (*inverse)(void *));

#endif //LAB1_RINGINFO_H
