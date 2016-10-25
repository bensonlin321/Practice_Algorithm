//
//  main.cpp
//  practice_algorithm
//
//  Created by Benson on 2016/10/25.
//  Copyright © 2016年 Benson. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>



int comparefunc(const void *a , const void *b)
{
    return (*(int*) a - *(int*) b);
}

int comparefunc_char(const void *a, const void *b) {
    return  (*(char *)a - *(char *)b);
}

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
};

void bubblesort(int *data, int len)
{
    int temp = 0;
    for(int i = 0 ; i < len; i++)
    {
        for(int j = 0 ; j < len-i-1; j++)
        {
            if(data[j]>data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}


int* twoSum(int* nums, int numsSize, int target)
{
    int *temp = (int*)malloc(2*numsSize*sizeof(int));
    int *output = (int*)malloc(2*sizeof(int));
    bool Find = false;
    for(int i = 0 ; i < numsSize; i++)
    {
        temp[i*2] = nums[i];
        temp[i*2+1] = i;
    }
    qsort(temp,numsSize,2*sizeof(temp[0]),comparefunc);
    int i = 0;
    int j = numsSize - 1;
    while(i<numsSize && j>=0)
    {
        if(temp[2*i] + temp[2*j] < target)
        {i++;}
        else if(temp[2*i] + temp[2*j] > target)
        {j--;}
        else{
            Find = true;
            break;
        }
    }
    if(Find)
    {
        output[0] = temp[2*i];
        output[1] = temp[2*j];
        return output;
    }
    else {return 0;}
}



int spilt(char **output, char *input, const char *delim)
{
    int spiltcount = 0;
    char *temp = strtok(input, delim);
    while (temp != NULL)
    {
        output[spiltcount] = temp;
        temp = strtok(NULL, delim);
        spiltcount++;
    }
    return spiltcount;
}
char *ReverString(char *Input)
{
    int len = strlen(Input);
    char *temp = new char[len];
    for(int i = 0 ; i < len ; i++)
    {
        int j = (int)len - i - 1;
        temp[i] = Input[j];
    }
    return temp;
}

char **ReverseString2(char *Input, char* delim)
{
    int len = strlen(Input);
    char **temp2 = new char*[len];
    char **output = new char*[len];
    int count =  spilt(temp2,Input,delim);
    for(int i = 0 ; i < count; i++)
    {
        int j= count - 1 - i;
        output[i] = temp2[j];
    }
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //int A[] = {9,5,2,3,7,4};
    char B[] = "Hello My dear";
    //bubblesort(A,6);
    //int *Result = twoSum(A,6,12);
    char **Result = ReverseString2(B," ");
    
    
    //std::cout << Result[0] << Result[1];
    printf("  %s %s",Result[0], Result[1]);
    return 0;
}



