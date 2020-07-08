//
//  main.c
//  radix sort
//
//  Created by mac on 2020. 7. 3..
//  Copyright © 2020년 size. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void queue_print(QueueType *q)
{
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while(i != q->front);
    }
    printf("\n");
}

void print_bucket(QueueType* queues, int d, int b) {
    printf("%d자리수가 %d\n", d + 1, b);
    queue_print(queues);
}

#define BUCKETS 10
#define DIGITS 2
void radix_sort(int list[], int n)
{
    int i, b, d, factor = 1;
    QueueType queues[BUCKETS];
    
    for (b = 0; b<BUCKETS; b++) init_queue(&queues[b]);
    
    for (d = 0; d<DIGITS; d++) {
        for (i = 0; i<n; i++)
            enqueue(&queues[(list[i] / factor) % 10], list[i]);
        
        for (b = i = 0; b<BUCKETS; b++) {
//            if (!is_empty(&queues[b]))
                print_bucket(&queues[b], d, b);
            
            while (!is_empty(&queues[b]))
                list[i++] = dequeue(&queues[b]);
        }
        
        factor *= 10;
        
    }
}

int main(void) {
    int list[SIZE];
    srand(time(NULL));
    for (int i = 0; i<SIZE; i++)
        list[i] = rand() % 100;

    radix_sort(list, SIZE);
        for (int i = 0; i<SIZE; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}
