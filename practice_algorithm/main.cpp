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
/* 
 1   2    3     4
 3   9    27    81
 
 n = 110 binary = 6
 
 3^6 = 3^(1*0) * 3^(2*1) * 3^(4*1) = 3^(4+2)
 */
double Mypow(double input, int n)
{
    double result = 1;
    bool neg = false;
    if(n < 0){neg = true;}
    int ABSN = abs(n);
    while(ABSN)
    {
        if(ABSN & 1){result *= input;}
        ABSN = ABSN >> 1;
        input *= input;
    }
    if(neg)
    return 1/result;
    else{return result;}
}

/*
 
 13
 42
----
 26      for  2   carrycount+1 -> 2*10 ->20    for  6  carrycount == 0   20+6 = 26
52       for 52   k+1 -> 52*10 = 520
----
546
 
 */
char* multiply(char* num1, char* num2) {
    
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    int sum = 0;
    int carrycount = 0;
    int *eachOperate = new int[num1_len+num2_len];
    char *result = new char [num1_len + num2_len];
    int i = num1_len - 1, j = num2_len-1;
    int k = 0;
    for(i = num1_len - 1 ; i >= 0 ; i--)
    {
        carrycount = 0;
        for(j = num2_len - 1 ; j >= 0 ; j--)
        {
            if(carrycount > 0)
            eachOperate[k] += (num1[i]-'0')*(num2[j]-'0') * carrycount * 10;
            else{eachOperate[k] += (num1[i]-'0')*(num2[j]-'0');}
            carrycount++;
        }
        if(k > 0)
        {eachOperate[k] = eachOperate[k] * k * 10;}
        sum += eachOperate[k];
        k++;
    }
    sprintf(result,"%d",sum);
    return result;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int rowindex = 0;
    for(int i = 1 ; i < matrixRowSize ; i++)
    {
        if(matrix[i-1][0] < target && matrix[i][0] > target)
        {
            rowindex = i-1;
            break;
        }
    }
    for(int j = 0 ; j < matrixColSize ; j++)
    {
        if(matrix[rowindex][j] == target){return true;}
    }
    return false;
}


void Myquicksort(int *data, int left, int right)
{
    int i = 0 , j = 0 , pivot = 0;
    if(left >= right){return;}
    pivot = data[left];// initial pivot is the first num
    i = left+1;//從pivot的右邊一格開始掃
    j = right; //從最右邊開始掃
    
    while(true)
    {
        while( i <= right )
        {
            if(pivot < data[i]){break;}
            i++;
        }
        while( j > left)
        {
            if(data[j] < pivot){break;}
            j--;
        }
        if(i>j){break;}
        swap(&data[i] , &data[j]);
    }
    swap(&data[left] , &data[j]);//pivot swap to smallest num
    Myquicksort(data, left, j-1);
    Myquicksort(data, j + 1, right);
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
    
    //double a = Mysqrt(5);
    
    //double a = Mypow(2,-3);
    
    //char *r = multiply("42","13");
    /*
    int **A = new int*[3];
    for(int i = 0 ; i< 3 ;i++)
    {A[i] = new int[3];}
    A[0][0] = 1;
    A[0][1] = 4;
    A[0][2] = 7;
    A[1][0] = 10;
    A[1][1] = 14;
    A[1][2] = 17;
    A[2][0] = 20;
    A[2][1] = 24;
    A[2][2] = 27;
    bool r = searchMatrix(A,3,3,14);
     
     */
    
    int A[] = {30, 10, 88, 50, 2};
    Myquicksort(A,0,5-1);
    //std::cout << Result[0] << Result[1];
    //printf("  %s %s",Result[0], Result[1]);
    return 0;
}



