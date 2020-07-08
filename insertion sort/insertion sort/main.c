//
//  main.c
//  insertion sort
//
//  Created by mac on 2020. 7. 3..
//  Copyright © 2020년 size. All rights reserved.
//

#include <stdio.h>

//삽입 정렬
void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for ( j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[i];
        list[j + 1] = key;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
