//
//  main.c
//  4-14
//
//  Created by mac on 2020. 4. 26..
//  Copyright © 2020년 size. All rights reserved.
//

#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element *data;
    int capacity;
    int top;
} StackType;

//스택 생성 함수
void init_stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

//공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

//삭제함수
element pop(StackType *s)
{
    if (is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

//피크함수
element peek(StackType *s)
{
    if (is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}
int size(StackType *s)
{
    return s->top + 1;
}
