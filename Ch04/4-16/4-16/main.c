//
//  main.c
//  4-16
//
//  Created by mac on 2020. 4. 26..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진 4-16
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;
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
    printf("문자열을 입력하시오 : ");
    scanf("%[^\n]s",ch); //엔터 들어올때까지 모두 scanf 하겠다는 뜻
    
    for(int i=0;ch[i]!='\0';i++){
        if('A' <= ch[i] && ch[i] <= 'Z')
            ch[i] += 'a' - 'A';
        if('a' <= ch[i] && ch[i] <= 'z')
            push(&s, ch[i]);
    }
    for(int i=0;!is_empty(&s);i++){
        if('a' <= ch[i] && ch[i] <= 'z'){
            if(ch[i] != pop(&s)) {
                printf("회문이 아닙니다\n");
                return 0;
            }
        }
    }
    printf("회문입니다\n");
    return 0;
}
