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

int bitcount(unsigned int n)
{
    int count = 0;
    while(n)
    {
        if(n & 1){
            count++;
        }
        n=n>>1;
    }
    return count;
}

int Adder(int a, int b)
{
    int carry = 0;
    while(b)
    {
        carry = (a&b) << 1;
        a = a^b;
        b = carry;
    }
    return a;
}

int Myatoi(char *input)
{
    int len = strlen(input);
    int sum = 0;
    for(int i = 0 ; i < len ; i++)
    {
        if(input[i] >='0' && input[i]  <='9')
        {
            sum = sum*10 + input[i]-'0';
        }
        else{return sum;}
    }
    return sum;
    
}
int Fibonacci(int n)
{
    int *temp = new int[n+1];
    temp[0] = 1;
    temp[1] = 1;
    for(int i = 2 ; i < n ; i++)
    {
        temp[i] = temp[i-1]+temp[i-2];
    }
    return temp[n];
}

int IntegerReverse(int x)
{
    int sigma = 0;
    int num = 0;
    int result = 0;
    if(x < 0){sigma = -1;}
    num = x * sigma;
    while(num)
    {
        result *= 10;
        result += num%10;
        num /= 10;
    }
    result = result*sigma;
    return result;
}


int ReverseBit(int x, int maxbit)
{
    int count = 0;
    for(int i = 0 ; i < maxbit; i++)
    {
        count = count << 1;
        if(x & 1)
        {count++;}
        x = x>>1;
    }
    return count;
}

char* MyStrstr(char *input, char* indexString)
{
    int inputlen = strlen(input);
    int indexlen = strlen(indexString);
    int match_index = 0;
    bool checkflag = false;
    int i = 0 , j = 0;
    while(i < inputlen && j < indexlen)
    {
        if(input[i] == indexString[j])
        {
            if(!checkflag)
            {
                checkflag = true;
                match_index = i;
            }
            i++;
            j++;
        }
        else{
            i++;
            j = 0;
            checkflag = false;
            match_index = 0;
        }
    }
    if(j == indexlen)
    {return &input[match_index];}
    else{return input;}
}

double Mysqrt(int num)
{
    float start = 0;
    float end = num/2+1;
    float sum = 0;
    char temp[10]={0};
    int count = 0;
    while(true){
        sum = (start + end) /2;
        sprintf(temp,"%0.2f",sum);
        sum = atof(temp);
        if(sum * sum == num)
        {break;}
        else if(sum * sum < num)
        {start = sum;}
        else{
            end = sum;
        }
        count++;
        if(count >= 500){break;}
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //int A[] = {9,5,2,3,7,4};
    //char B[] = "Hello My dear";
    //bubblesort(A,6);
    //int *Result = twoSum(A,6,12);
    //char **Result = ReverseString2(B," ");
    
    //int c = bitcount(9);
    //char* result = MyStrstr("rabbg tty","bbg");
    
    double a = Mysqrt(5);
    
    //std::cout << Result[0] << Result[1];
    //printf("  %s %s",Result[0], Result[1]);
    return 0;
}



