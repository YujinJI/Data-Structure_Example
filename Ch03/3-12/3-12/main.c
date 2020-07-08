//
//  main.c
//  3-12
//
//  Created by mac on 2020. 4. 10..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진
#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main(){
    struct test{
        int i;
        char str[20];
    };
    struct test *p;
    
    p = (struct test*)malloc(sizeof(struct test));
    //동적 메모리 할당
    if(p==NULL)
        printf("memory error");
    p->i = 100;
    strcpy(p->str, "just test");
    free(p);
}
