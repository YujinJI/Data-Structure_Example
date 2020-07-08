#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SIZE 100
#define qt work

typedef struct {
    int pid;
    int weight;
} work;

typedef struct {
    qt data[MAX_SIZE];
    int front, rear;
} deque;

int is_empty(deque* dq);
int is_full(deque* dq);
int size(deque* dq);
qt push_back(deque* dq, qt item);
qt pop_back(deque* dq);
qt push_front(deque* dq, qt item);
qt pop_front(deque* dq);
qt peek_front(deque* dq);
qt peek_back(deque* dq);

typedef struct {
    deque dq;
    char name;
    pthread_t worker;
    int job_done;
} cpu;

const int core_n = 4;
cpu computer[core_n];

void* job(void* v) {
    cpu* c = (cpu*) v;

    while (!is_empty(&c->dq)) {
        work w = pop_front(&c->dq);

        printf("START : %c가 %d 비용 일을 시작합니다, pid-%d\n", c->name, w.weight, w.pid);
        sleep(w.weight);
        printf("FINISH : %c가 %d 비용 일을 종료했습니다, pid-%d\n", c->name, w.weight, w.pid);
        ++c->job_done;

        if (!is_empty(&c->dq)) continue;

        for (int i = 0; i < core_n; ++i) {
            cpu* next_cpu = &computer[i];
            if (is_empty(&next_cpu->dq)) continue;

            work steal_w = pop_back(&next_cpu->dq);
            push_back(&c->dq, steal_w);
            printf("STEAL : %c가 %c의 작업을 가져왔습니다, pid-%d\n", c->name, next_cpu->name, steal_w.pid);
            break;
        }
    }

    return 0;
}

void alloc_work(cpu* c, int pid, int weight) {
    printf("CPU %c에 가중치 %d의 작업 추가 : %d\n", c->name, weight, pid);
    work w = {pid, weight};
    push_back(&c->dq, w);
}

void start(cpu* c) {
    printf("CPU %c가 가동을 시작합니다.\n", c->name);
    pthread_create(&c->worker, 0, job, (void*) c);
}

void wait_for_end() {
    for (int i = 0; i < core_n; ++i) {
        if (computer[i].worker != 0) {
            pthread_join(computer[i].worker, 0);
        }
    }
}

int main() {
    computer[0].name = 'A';
    computer[1].name = 'B';
    computer[2].name = 'C';
    computer[3].name = 'D';

    alloc_work(&computer[0], 101, 4);
    alloc_work(&computer[0], 102, 7);
    alloc_work(&computer[0], 103, 1);
    alloc_work(&computer[0], 104, 9);
    alloc_work(&computer[0], 105, 2);

    alloc_work(&computer[1], 201, 11);
    alloc_work(&computer[1], 202, 9);
    alloc_work(&computer[1], 203, 3);
    alloc_work(&computer[1], 204, 19);
    alloc_work(&computer[1], 205, 15);

    alloc_work(&computer[2], 301, 15);
    alloc_work(&computer[2], 302, 13);
    alloc_work(&computer[2], 303, 16);
    alloc_work(&computer[2], 304, 8);
    alloc_work(&computer[2], 305, 11);

    alloc_work(&computer[3], 401, 9);
    alloc_work(&computer[3], 402, 8);
    alloc_work(&computer[3], 403, 6);
    alloc_work(&computer[3], 404, 8);
    alloc_work(&computer[3], 405, 4);

    start(&computer[0]);
    start(&computer[1]);
    start(&computer[2]);
    start(&computer[3]);

    wait_for_end();

    int global_job_done = 0;
    printf("시작한 작업 수: %d\n", 20);
    for (int i = 0; i < core_n; ++i) {
        printf("%c 가 완수한 작업 수 : %d\n", computer[i].name, computer[i].job_done);
        global_job_done += computer[i].job_done;
    }

    if (global_job_done == 20)
        printf("성공적으로 모든 작업을 완수했습니다.\n");

    return 0;
}

qt peek_back(deque *dq) {
    if (is_empty(dq)) exit(1);
    return dq->data[dq->rear];
}

qt peek_front(deque *dq) {
    if (is_empty(dq)) exit(1);
    return dq->data[(dq->front + 1) % MAX_SIZE];
}

qt pop_front(deque *dq) {
    if (is_empty(dq)) exit(1);
    return dq->data[dq->front = ((dq->front + 1) % MAX_SIZE)];
}

qt push_front(deque *dq, qt item) {
    if (is_full(dq)) exit(1);
    int f = dq->front;
    dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    return dq->data[f] = item;
}

qt pop_back(deque *dq) {
    if (is_empty(dq)) exit(1);
    int r = dq->rear;
    dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return dq->data[r];
}

qt push_back(deque *dq, qt item) {
    if (is_full(dq)) exit(1);
    return dq->data[dq->rear = ((dq->rear + 1) % MAX_SIZE)] = item;
}

int size(deque *dq) {
    return dq->front > dq->rear ? (MAX_SIZE - dq->front + dq->rear) : (dq->rear - dq->front);
}

int is_full(deque *dq) {
    return dq->front == ((dq->rear + 1) % MAX_SIZE);
}

int is_empty(deque *dq) {
    return dq->front == dq->rear;
}