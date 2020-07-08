//
//  main.c
//  5-09
//
//  Created by mac on 2020. 4. 29..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진 5-9
#include <stdio.h>
#include <stdlib.h>
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
typedef struct{
    StackType a, b;
    int size;
} QueueType;
void init_queue(QueueType *q)
{
    init_stack(&q->a);
    init_stack(&q->b);
    q->size = 0;
}
int get_size(QueueType *q)
{
    return q->size;
}
void enqueue(QueueType *q, element item)
{
    q->size++;
    push(&q->a,item);
}
element dequeue(QueueType *q)
{
    q->size--;
    if(is_empty(&q->b)){
        while(!is_empty(&q->a)){
            push(&q->b,pop(&q->a));
        }
    }
    return pop(&q->b);
}
int main(void)
{
    
    QueueType q;
    init_queue(&q);
    
    printf("정수를 입력하시오 : ");
    for(int i=0;i<10;i++){
        int tmp;
        scanf("%d",&tmp);
        enqueue(&q, tmp);
    }
    while(get_size(&q)){
        printf("%d ",dequeue(&q));
    }
    printf("\n");
}
