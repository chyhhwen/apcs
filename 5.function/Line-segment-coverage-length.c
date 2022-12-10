#include <stdio.h>
#define false 0
#define true 1

const unsigned long SIZE = 9999;
typedef unsigned int bool;
void line(bool data[10000],unsigned long left,unsigned long right)
{
    unsigned long j;
    for(j=left;j<right;j++)
    {
        data[j]=true;
    }
}
int main(void)
{
    int N;
    bool original[10000]={false};
    bool next_segment[10000]={false};
    unsigned long left,right;
    unsigned long i,j,total;
    scanf("%d",&N);
    scanf("%d %d",&left,&right);
    line(original,left,right);
    for(i=1;i<=N-1;i++)
    {
        scanf("%d %d",&left,&right);
        line(next_segment,left,right);
        for(j=0;j<SIZE;j++)
        {
            if(original[j] == true || next_segment[j] == true)
            {
                original[j]=true;
            }
        }
    }
    total = 0;
    int index = 0;
    while(index < SIZE)
    {
        if(original[index] == true)
        {
            total++;
        }
        index++;
    }
    printf("%d",total);
    return 0;
}