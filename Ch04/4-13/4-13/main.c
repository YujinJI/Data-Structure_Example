//
//  main.c
//  4-13
//
//  Created by mac on 2020. 4. 22..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진 4-13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int main(void)
{
    StackType s;
    init_stack(&s);
    
    char ch[100];
    memset(ch,'\0',sizeof(ch));

    printf("정수를 입력하시오 : ");
    scanf("%s",ch);
    
    for(int i=99;i>0;i--){
        if(ch[i] == '\0') continue;
        if(is_empty(&s)) {
            push(&s, ch[i]); continue;
        }
        if(peek(&s) != ch[i]) push(&s,ch[i]);
    }
    printf("출력 : ");

    while(!is_empty(&s)){
        printf("%c",pop(&s));
    }
    printf("\n");
    return 0;

}
