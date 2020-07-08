//
//  main.c
//  11-7
//
//  Created by mac on 2020. 7. 4..
//  Copyright © 2020년 size. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10
#define INF 1000000

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
    struct GraphNode* adj_list[MAX_VERTICES];
} GraphType;



void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v, int weight)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n)
    {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->weight[u][v] = weight;
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v=0; v<MAX_VERTICES; v++)
    {
        g->adj_list[v] = NULL;
        for (int a=0; a<MAX_VERTICES; a++)
            g->weight[v][a] = INF;
    }
}

void print_adj_list(GraphType* g)
{
    for (int i=0; i<g->n; i++)
    {
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ",i);
        while(p != NULL) {
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i=0; i<n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = -i;
        }
    return minpos;
}

void print_status(GraphType *g)
{
    static int step=1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (int i=0; i<g->n; i++) {
        if (distance[i] == INF)
            printf(" * ");
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf(" found: ");
    for (int i=0; i<g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

void shortest_path(GraphType *g, int start)
{
    int i, u, w;
    for (i=0; i<g->n; i++)
    {
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE;
    distance[start] = 0;
    for (i=0; i<g->n; i++) {
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for (w=0; w<g->n; w++)
            if (!found[w])
                if(distance[u] + g->weight[u][w] < distance[w])
                    distance[w] = distance[u] + g->weight[u][w];
    }
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);
    for (int i=0; i<4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1, 3);
    insert_edge(g, 1, 0, 3);
    insert_edge(g, 1, 2, 2);
    insert_edge(g, 2, 1, 2);
    insert_edge(g, 2, 3, 7);
    insert_edge(g, 3, 2, 7);
    insert_edge(g, 1, 3, 4);
    insert_edge(g, 3, 1, 4);
    print_adj_list(g);
    printf("\n");
    shortest_path(g, 0);
    return(0);
}
