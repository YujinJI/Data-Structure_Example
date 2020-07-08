//
//  main.c
//  5-11
//
//  Created by mac on 2020. 4. 29..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진 5-11
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

//오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//초기화
void init_queue(DequeType *q)
{
    q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(DequeType *q)
{
    return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(DequeType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//원형큐 출력 함수
void deque_print(DequeType *q)
{
    printf("DEQUE(front=%d rear=%d) = ",q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1) % MAX_QUEUE_SIZE;
            printf("%d |",q->data[i]);
            if(i == q->rear)
                break;
        } while(i != q->front);
    }
    printf("\n");
}

//삽입함수
void add_rear(DequeType *q, element item)
{
    if(is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

//삭제함수
element delete_front(DequeType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다");
    return q->data[(q->front+1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, element val)
{
    if(is_full(q))
        error("큐가 포화상태입니다");
    q->data[q->front] = val;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q)
{
    int prev = q->rear;
    if(is_empty(q))
        error("큐가 공백상태입니다");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[prev];
}

element get_rear(DequeType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다");
    return q->data[q->rear];
}

int main(void)
{
    DequeType q;
    init_queue(&q);
    
    char ch[100];
    printf("문자를 입력하시오 : ");
    scanf("%s",ch);
    
    for(int i=0;ch[i]!='\0';i++){
        add_rear(&q, ch[i]);
    }
    while(!is_empty(&q)){
        element c1 = delete_front(&q);
        if(!is_empty(&q)){
            element c2 = delete_rear(&q);
            if(c1 != c2){
                printf("회문이 아닙니다\n");
                exit(1);
            }
        }
    }
    printf("회문입니다\n");
}
