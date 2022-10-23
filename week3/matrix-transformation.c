#include<stdio.h>
#include<stdlib.h>
#define X 10
#define Y 10
#define Z 10

void filp(int A[X][Y],int row,int col)
{
    int B[X][Y]={0};
    int i,j;
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            B[i][j]=A[row-i+1][j];
        }
    }
    for(i=1;i<X;i++)
    {
        for(j=1;j<Y;j++)
        {
            A[i][j]=B[i][j];
        }
    }
}

void counterclockwise(int A[X][Y],int *row,int *col)
{
    int B[X][Y]={0};
    int new_row=*col;
    int new_col=*row;
    int i,j;
    for(i=1;i<=new_row;i++)
    {
        for(j=1;j<=new_col;j++)
        {
            B[i][j]=A[j][*col-i+1];
        }
    }
    for(i=1;i<X;i++)
    {
        for(j=1;j<Y;j++)
        {
            A[i][j]=B[i][j];
        }
    }
    *row=new_row;
    *col=new_col;
}

int main(void)
{
    int i,j;
    int row,col,m;
    int A[X][Y]={0};
    int operation[Z];

    scanf("%d%d%d",&row,&col,&m);
    for(i=1;i<=row;i++)
    {
        for(j=1;j<=col;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&operation[i]);
    }
    for(i=m;i>=1;i--)
    {
        if(operation[i]==0)
        {
            counterclockwise(A,&row,&col);
        }
        else
        {
            filp(A,row,col);
        }
    }
    printf("%d %d\n",row,col);
    for(i=1;i<=row;i++)
    {
        for (j=1;j<=col;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}