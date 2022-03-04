#include <stdio.h>
#include <stdlib.h>

typedef struct RingInfo {
    size_t size;
    void (*zero)(void *);
    void (*sum)(void *, void *, void *);
    void (*negative)(void *);
    void (*mult)(void *, void *, void *);
    void (*one)(void *);
    void (*inverse)(void *);
} RingInfo;

void IntOne(void *x) {
    *(int*)x = 1;
}

void IntZero(void *x) {
    *(int*)x = 0;
}

void IntNeg(void *x) {
    *(int *)x = -1 * *((int *)x);
}

void IntSum(void *x, void *y, void* res) {
    *(int*)res = *(int*)x + *(int*)y;
}

void IntMult(void *x, void *y, void *res) {
    *(int*)res = (*(int*)x) * (*(int*)y);
}

void InvInt(void *scalar) {
    *(int*)scalar = 1/(*(int*)scalar);
}

void DoubleOne(void *x) {
    *(double *)x = 1.0;
}

void DoubleZero(void *x) {
    *(double *)x = 0.0;
}

void DoubleNeg(void *x) {
    *(double*)x = -1 * *((double *)x);
}

void DoubleSum(void *x, void *y, void *res) {
    *(double*)res = *(double*)x + *(double*)y;
}

void DoubleMult(void *x, void *y, void *res) {
    *(double*)res = *(double*)x * *(double*)y;
}

void InvDouble(void *scalar) {
    *(double*)scalar = 1/(*(double*)scalar);
}

typedef struct Complex{
    double Re;
    double Im;
} Complex;

void ComplexOne(void *x) {
    ((Complex *)x)->Re = 1.0;
    ((Complex *)x)->Im = 0.0;
}

void ComplexZero(void *x) {
    ((Complex *)x)->Re = 0.0;
    ((Complex *)x)->Im = 0.0;
}

void ComplexNeg(void *x) {
    ((Complex *)x)->Re = -1 * *((double*)x);
    ((Complex *)x)->Im = -1 * *((double*)x);
}

void ComplexSum(void *x, void *y, void *res) {
    ((Complex *)res)->Re = ((Complex *)x)->Re + ((Complex *)y)->Re;
    ((Complex *)res)->Im = ((Complex *)x)->Im + ((Complex *)y)->Im;
}

void ComplexMult(void *x, void *y, void *res) {
    ((Complex *)res)->Re = ((Complex *)x)->Re * ((Complex *)y)->Re - ((Complex *)x)->Im * ((Complex *)y)->Im;
    ((Complex *)res)->Im = ((Complex *)x)->Re * ((Complex *)y)->Im + ((Complex *)x)->Im * ((Complex *)y)->Re;
}

void InvComplex(void *x) {
    ((Complex *)x)->Re = ((Complex *)x)->Re/(((Complex *)x)->Re * ((Complex *)x)->Re + ((Complex *)x)->Im * ((Complex *)x)->Im);
    ((Complex *)x)->Im = -((Complex *)x)->Im/(((Complex *)x)->Re * ((Complex *)x)->Re + ((Complex *)x)->Im * ((Complex *)x)->Im);
}

RingInfo *CreateRingInfo(
        size_t size,
        void (*one)(void *),
        void (*zero)(void *),
        void (*negative)(void *),
        void (*sum)(void *, void *, void *),
        void (*mult)(void *, void *, void *),
        void (*inverse)(void *)) {
    RingInfo *ring = calloc(1, sizeof(RingInfo));
    ring->size = size;
    ring->one = one;
    ring->zero = zero;
    ring->negative = negative;
    ring->sum = sum;
    ring->mult = mult;
    ring->inverse = inverse;
    return ring;
}
