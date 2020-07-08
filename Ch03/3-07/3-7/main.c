//
//  main.c
//  3-7
//
//  Created by mac on 2020. 4. 6..
//  Copyright © 2020년 size. All rights reserved.
//


//20193036 지유진

#include <stdio.h>

typedef struct{
    float real;
    float imaginary;

} Complex;

Complex complex_add(Complex a, Complex b);

int main(void){
    Complex c1, c2;
    
    printf("두 복소수 a+bi + c+di에서 a,b,c,d를 입력 : ");
    scanf("%f %f %f %f",&c1.real,&c1.imaginary,&c2.real,&c2.imaginary);
    printf("add 출력 %.2f + %.2fi\n",complex_add(c1, c2).real, complex_add(c1, c2).imaginary);
}

Complex complex_add(Complex a, Complex b){
    Complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    
    return c;
}
