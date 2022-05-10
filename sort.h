#include<iostream>
#include<cmath>
using namespace std;
void quickSort(int *a,int left,int right)//快速排序
{
    int base;
    int i = left;
    int j = right;
    base = *(a + i); //找数组最左边的为基值
    if (left >= right)
        return;
    do
    {
        for (; *(a + j) >= base&&i<j; j--)
            ;
        {
           swap(*(a+i),*(a+j));
        }
        for (; *(a + i) <= base &&i<j; i++)
            ;
        {
            swap(*(a + i), *(a + j));
        }
}while(i!=j);
quickSort(a,left,i-1);
quickSort(a, i+1,right);
}

void selectSort(int*a,int arraysize)//选择排序
{
    int i, j, m;
    int temp;
    for (i = 0; i <arraysize-1; i++)
    {
       for (j = i + 1; j < arraysize; j++) 
        {
            if (*(a + i) > *(a + j))
            {
                temp = *(a + j);
                *(a + j) = *(a + i);
                *(a + i) = temp;
            }
        }
    }
}

void bubbleSort(int*a,int arraysize)//冒泡排序

{
    int temp;
   for(int i=0;i<arraysize-1;i++)
   {
       for(int j=0;j<arraysize-1-i;j++)
       {
           if (*(a + j) > *(a + j+1))
           {
            temp = *(a + j);
            *(a + j) = *(a + j + 1);
            *(a + j + 1) = temp;
           }
       }
   }
}

void insertionSort(int *a,int arraysize)//插入排序
{
  for(int j=1;j<arraysize;j++)
  {
    int key=*(a+j);
    int i=j;
    while (key < *(a + i - 1) && i >= 1)
    {
        *(a + i) = *(a + i-1);
        i--;
    } 
    *(a+i)=key;
  }
}

void bucketSort(int *a,int arraysize)//桶排序
{
   int n;//n为余数
   int counter = 0; 
   int flag=0;
   int c=0;
   int max;
   for(int z=0;z<arraysize;z++)
   {
       static int key=*a;
       if(key<*(a+z))
       {
           key=*(a+z);
       }
       max=key;
   }
   while (max / (int)pow(10.0,flag)!=0)
   {
       int a1[100][10] = {0};
       int *b = &a1[0][0];
       for (int j = 0; j < arraysize; j++)
       {
           n = *(a + j) / (int)pow(10.0,flag) % 10;
           while (*(b+n)!= 0)
           {
               n+= 10;
           }
           *(b + n) = *(a + j); //将原数组中的元素都放到痛中
       }
       flag++;//本轮10的指数为flag，下一轮10的指数+1
       for (int j = 0; j < 10; j++)//将已排列的桶中的元素重新放入原数组中
       {
           for (int i = 0; i < 100; i++)//j为列 i为行
           {
               if (a1[i][j] != 0)
               {
                   *(a + counter) = a1[i][j]; //counter记录在存本次循环的元素之前往原数组存入的元素个数；
                   counter++;
               }
           }
       }
       counter=0;
   }
}