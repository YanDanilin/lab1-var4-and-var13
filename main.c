#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "RingInfo.h"
#include "UI.h"

void MenuInt();
void MenuDouble();
void MenuComplex();

int main() {
    enum Type type;
    printf("Choose the type of numbers to work with:\n1.Int\n2.Double\n3.Complex\n");
    scanf("%d", &type);
    if (type == INT) {
        MenuInt();
    } else if (type == DOUBLE) {
        MenuDouble();
    } else if (type == COMPLEX) {
        MenuComplex();
    }
    return 0;
}

void MenuInt() {
    struct Matrix *m1 = Create();
    struct Matrix *m2 = Create();
    m1->ring = CreateRingInfo(sizeof(int),
                              IntOne,
                              IntZero,
                              IntNeg,
                              IntSum,
                              IntMult,
                              InvInt);
    m2->ring = m1->ring;
    struct Matrix *res = Create();
    int key = 1;
    int key2;
    int to, what;
    while(key) {
        int key1 = 0;
        printf("Choose the option:\n1.Enter\n2.Output\n3.Operations\n4.Quit\n");
        scanf("%d", &key1);
        switch(key1){
            case 1:
                m1 = EnterInt(m1);
                m2 = EnterInt(m2);
                break;
            case 2:
                printf("Matrix number 1:\n");
                OutputInt(m1);
                printf("Matrix number 2:\n");
                OutputInt(m2);
                printf("Result matrix:\n");
                OutputInt(res);
                break;
            case 3:
                printf("Choose the option:\n 1.Summa\n 2.One plus Another\n 3.Multiply\n 4.Transposition\n");
                scanf("%d", &key2);
                switch(key2) {
                    case 1:
                        Summa(m1, m2, res);
                        break;
                    case 2:
                        printf("Enter string that you want to increase: ");
                        scanf("%d", &to);
                        printf("Enter string that you want to plus: ");
                        scanf("%d", &what);
                        void *scal = calloc(1, m1->ring->size);
                        printf("Enter scalar: ");
                        scanf("%d", (int*)scal);
                        OnePlusAnother(m1, to, what, scal);
                        free(scal);
                        break;
                    case 3:
                        Multiply(m1, m2, res);
                        break;
                    case 4:
                        m1 = Transposition(m1);
                        break;
                    default:
                        printf("Wrong option... Try again");
                }
                break;
                case 4:
                    Destroy(m1);
                    Destroy(m2);
                    Destroy(res);
                    key = 0;
                    break;
            default:
                printf("Wrong option... Choose again");
        }
    }
}

void MenuDouble() {
    struct Matrix *m1 = Create();
    struct Matrix *m2 = Create();
    m1->ring = CreateRingInfo(sizeof(double),
                              DoubleOne,
                              DoubleZero,
                              DoubleNeg,
                              DoubleSum,
                              DoubleMult,
                              InvDouble);
    m2->ring = m1->ring;
    struct Matrix *res = Create();
    int key = 1;
    int key2;
    int to, what;
    while(key) {
        int key1 = 0;
        printf("Choose the option:\n1.Enter\n2.Output\n3.Operations\n4.Quit\n");
        scanf("%d", &key1);
        switch(key1){
            case 1:
                m1 = EnterDouble(m1);
                m2 = EnterDouble(m2);
                break;
            case 2:
                printf("Matrix number 1:\n");
                OutputDouble(m1);
                printf("Matrix number 2:\n");
                OutputDouble(m2);
                printf("Result matrix:\n");
                OutputDouble(res);
                break;
            case 3:
                printf("Choose the option:\n 1.Summa\n 2.One plus Another\n 3.Multiply\n 4.Transposition\n");
                scanf("%d", &key2);
                switch(key2) {
                    case 1:
                        Summa(m1, m2, res);
                        break;
                    case 2:
                        printf("Enter string that you want to increase: ");
                        scanf("%d", &to);
                        printf("Enter string that you want to plus: ");
                        scanf("%d", &what);
                        void *scal = calloc(1, m1->ring->size);
                        printf("Enter scalar: ");
                        scanf("%lf", (double*)scal);
                        OnePlusAnother(m1, to, what, scal);
                        free(scal);
                        break;
                    case 3:
                        Multiply(m1, m2, res);
                        break;
                    case 4:
                        m1 = Transposition(m1);
                        break;
                    default:
                        printf("Wrong option... Try again");
                }
                break;
            case 4:
                Destroy(m1);
                Destroy(m2);
                Destroy(res);
                key = 0;
                break;
            default:
                printf("Wrong option... Choose again");
        }
    }
}

void MenuComplex() {
    struct Matrix *m1 = Create();
    struct Matrix *m2 = Create();
    m1->ring = CreateRingInfo(sizeof(Complex),
                              ComplexOne,
                              ComplexZero,
                              ComplexNeg,
                              ComplexSum,
                              ComplexMult,
                              InvComplex);
    m2->ring = m1->ring;
    struct Matrix *res = Create();
    int key = 1;
    int key2;
    int to, what;
    while (key) {
        int key1 = 0;
        printf("Choose the option:\n1.Enter\n2.Output\n3.Operations\n4.Quit\n");
        scanf("%d", &key1);
        switch (key1) {
            case 1:
                m1 = EnterComplex(m1);
                m2 = EnterComplex(m2);
                break;
            case 2:
                printf("Matrix number 1:\n");
                OutputComplex(m1);
                printf("Matrix number 2:\n");
                OutputComplex(m2);
                printf("Result matrix:\n");
                OutputComplex(res);
                break;
            case 3:
                printf("Choose the option:\n 1.Summa\n 2.One plus Another\n 3.Multiply\n 4.Transposition\n");
                scanf("%d", &key2);
                switch (key2) {
                    case 1:
                        Summa(m1, m2, res);
                        break;
                    case 2:
                        printf("Enter string that you want to increase: ");
                        scanf("%d", &to);
                        printf("Enter string that you want to plus: ");
                        scanf("%d", &what);
                        void *scal = calloc(1, m1->ring->size);
                        printf("Enter scalar(real part): ");
                        scanf("%lf", &(((Complex *)scal)->Re));
                        printf("Enter scalar(imaginary part): ");
                        scanf("%lf", &(((Complex *)scal)->Im));
                        OnePlusAnother(m1, to, what, scal);
                        free(scal);
                        break;
                    case 3:
                        Multiply(m1, m2, res);
                        break;
                    case 4:
                        m1 = Transposition(m1);
                        break;
                    default:
                        printf("Wrong option... Try again");
                }
                break;
            case 4:
                Destroy(m1);
                Destroy(m2);
                Destroy(res);
                key = 0;
                break;
            default:
                printf("Wrong option... Choose again");
        }
    }
}