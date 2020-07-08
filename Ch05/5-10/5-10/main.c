//
//  main.c
//  5-10
//
//  Created by mac on 2020. 4. 29..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진 5-10
#include <stdio.h>
#include <stdlib.h>

// === 원형큐 코드 시작 ===
#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
    int size;
} QueueType;

//오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//원형큐 생성 함수
void init_queue(QueueType *q)
{
    q->front = q->rear = q->size = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType *q)
{
    return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//원형큐 출력 함수
void queue_print(QueueType *q)
{
    printf("QUEUE(front=%d reaf=%d) = ",q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1) % (MAX_QUEUE_SIZE);
            printf("%d |", q->data[i]);
            if(i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->size++;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->size--;
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
int get_size(QueueType *q)
{
    return q->size;
}
element get_front(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    return q->data[q->front+1];
}
// === 원형큐 코드 끝 ===

int main(void)
{
    QueueType q;
    init_queue(&q);
    
    enqueue(&q, 0);
    enqueue(&q, 1);
    for(int i=1;i<20;i++){
        int a = dequeue(&q);
        int b = get_front(&q);
        enqueue(&q, a+b);
        printf("%d ",a+b);
    }
    printf("\n");
}


