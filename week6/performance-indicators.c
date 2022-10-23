#include <stdio.h>
#include <stdio.h>
#define PASS 60

void arrange(int *score,int size)
{
    int i,j;
    int temp;
    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(score[i] > score[j])
            {
                temp = score[i];
                score[i] = score[j];
                score[j] = temp;
            }
        }
    }
}

int main(void)
{
    int score[21];
    int i;
    int n;
    FILE *fp;
    fp=fopen("C:\\Users\\USER\\Desktop\\apcs\\week6\\input2.txt","r");
    fscanf(fp,"%d",&n);
    for(i=0;i<=n-1;i++)
    {
        fscanf(fp,"%d",&score[i]);
    }
    arrange(score,n);
    for(i=0;i<=n-1;i++)
    {
        printf("%d ",score[i]);
    }
    printf("\n");
    if(score[0] >= PASS)
    {
        printf("best case \n");
        printf("%d \n",score[0]);
    }
    else if(score[n-1] < PASS)
    {
        printf("%d \n",score[n-1]);
        printf("worst case \n");
    }
    else
    {
        for(i=n-1;i>=0;i--)
        {
            if(score[i] < PASS)
            {
                printf("%d\n",score[i]);
                break;
            }
        }
        for(i=0;i<=n-1;i++)
        {
            if(score[i] >= PASS)
            {
                printf("%d\n",score[i]);
                break;
            }
        }
        return 0;
    }
}