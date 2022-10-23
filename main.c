#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

typedef int bool;

int N;
int K;
int P[50000];

void sort(int *a,int size)
{
    int i,j;
    int temp;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

bool check(int diameter)
{
    int coverage = 0;
    int num = 0;
    int index = 0;
    int i;
    for(i=0;i<N;i++)
    {
        coverage = P[index] + diameter;
        num++;
        if(num > K)
        {
            return false;
        }
        if((num <= K) && (P[N-1] <= coverage))
        {
            return true;
        }
        do
        {
            index++;
        }
        while(P[index] <= coverage);
    }
}

int main()
{
    FILE *fp;
    int left,right,med,i;
    fp=fopen("C:\\Users\\USER\\Desktop\\apcs\\week6\\input3.txt","r");
    fscanf(fp,"%d %d",&N,&K);
    for(i=0;i<N;i++)
    {
        fscanf(fp,"%d",&P[i]);
    }
    sort(P,N);
    left = 1;
    right = floor((P[N-1]-P[0]) / K) + 1;
    while(left <= right)
    {
        med = floor((left+right) / 2);
        if(check(med)==true)
        {
            right = med;
        }
        else
        {
            left = med + 1;
        }
        if(left == right)
        {
            break;
        }
    }
    printf("%d\n",med);
    return 0;
}