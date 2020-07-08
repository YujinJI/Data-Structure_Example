//
//  main.c
//  3-8
//
//  Created by mac on 2020. 4. 10..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진

#include <stdio.h>

#define NUM 10

void insert(int array[], int loc, int value);
void print_array(int array[]);

int main(void){
    int array[NUM] = {1,2,3,4,5,6,7,8,9,10};
    
    print_array(array);
    
    insert(array,3,11);
    print_array(array);
    
    insert(array,0,100);
    print_array(array);
}

void insert(int array[], int loc, int value){
    for(int i=NUM-2;i>=loc;i--){
        array[i+1] = array[i];
    }
    array[loc] = value;
}

void print_array(int array[]){
    for(int i=0;i<NUM;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}



