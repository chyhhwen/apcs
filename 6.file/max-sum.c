#include <stdio.h>
typedef int bool;
#define true 1
#define false 0

int main(void)
{
    FILE *fp;
    int N;
    int M;
    int X[20][20];
    int biggest[20];
    int i,j;
    bool divisible;
    int total=0;
    fp= fopen("C:\\Users\\USER\\Desktop\\apcs\\week6\\input.txt","r");
    fscanf(fp,"%d %d",&N,&M);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            fscanf(fp,"%d",&X[i][j]);
        }
    }
    for(i=0;i<N;i++)
    {
        biggest[i]=X[i][0];
        for(j=0;j<M;j++)
        {
            if(X[i][j] > biggest[i])
            {
                biggest[i] =  X[i][j];
            }
        }
    }
    for(i=0;i<N;i++)
    {
        total = total+biggest[i];
    }
    printf("%d \n",total);
    divisible = false;
    for(i=0;i<N;i++)
    {
        if(total % biggest[i] == 0)
        {
            divisible = true;
            printf("%d ",biggest[i]);
        }
    }
    if(divisible == false)
    {
        printf("-1 \n");
    }
    fclose(fp);
    return  0;
}