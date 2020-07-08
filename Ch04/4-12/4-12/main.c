//
//  main.c
//  4-12
//
//  Created by mac on 2020. 4. 22..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진 4-12
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
    memset(ch, '\0',sizeof(ch));
    
    
    printf("문자열을 입력하시오 : ");
    scanf("%s",ch);
    
    for(int i=99;i>=0;i--){
        if(ch[i] == '\0') continue;
        
        if('A' <= ch[i] && ch[i] <= 'Z')
            ch[i] += 'a' - 'A';
    
        push(&s,ch[i]);
    }
    printf("압축된 문자열 : ");
    char before = (char) peek(&s);
    int count=0;
    
    while(!is_empty(&s)){
        char current = (char) pop(&s);
        
        if(current == before)
            ++count;
        else{
            printf("%d%c", count, before);
            count = 1;
            before = current;
        }
    }
    printf("%d%c", count, before);
    printf("\n");
    return 0;
}
