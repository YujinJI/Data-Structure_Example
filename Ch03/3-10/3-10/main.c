//
//  main.c
//  3-10
//
//  Created by mac on 2020. 4. 6..
//  Copyright © 2020년 size. All rights reserved.
//
//20193036 지유진
#include <stdio.h>
#define NUM 10

int delete(int array[], int loc);
void print_array(int array[]);

int main(void){
    int array[NUM] = {1,2,3,4,5,6,7,8,9,10};
    
    print_array(array);
    
    delete(array,4);
    print_array(array);
    
    delete(array,1);
    print_array(array);
    
}

int delete(int array[], int loc){

    for(int i=loc;i<NUM-1;i++){
        array[i] = array[i+1];
    }
    array[NUM - 1] = 0;
    
    return 0;       //함수를 int형으로 만들어 주었기 때문에 return값이 있어야함

}

void print_array(int array[]){
    for(int i=0;i<NUM;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

