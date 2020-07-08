//
//  main.c
//  Stack_1
//
//  Created by mac on 2020. 4. 21..
//  Copyright © 2020년 size. All rights reserved.
//

#include <stdio.h>

#define st int
#define MAX_SIZE 100

st stack[MAX_SIZE];
int top;

int size() {
    return top;
}

int is_empty() {
    return size() == 0;
}

st push(st item) {
    if (top == MAX_SIZE - 1) exit(1);
    return stack[top++] = item;
}

st pop() {
    if (top == 0) exit(1);
    return stack[--top];
}

st peek() {
    return stack[top - 1];
}

int main(int argc, const char * argv[]) {
    push(1);
    push(2);
    push(3);
    
    for (int i = 0; i < size(); ++i) {
        printf("%d ", stack[i]);
    }
    
    printf("\n");
    
    while (!is_empty()) {
        printf("%d ", pop());
    }
    
    return 0;
}
