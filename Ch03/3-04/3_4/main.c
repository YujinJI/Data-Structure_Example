//
//  main.c
//  3_4
//
//  Created by mac on 2020. 4. 6..
//  Copyright © 2020년 size. All rights reserved.
//

//20193036 지유진
#include <stdio.h>

int main(void){
    int two[10];
    two[0] = 1;
    
    for(int i=1;i<10;i++)
    {
        two[i] = two[i-1] * 2;
    }
    for(int i=0;i<9;i++)
    {
        printf("%d ",two[i]);
    }
    printf("\n");
    
}
