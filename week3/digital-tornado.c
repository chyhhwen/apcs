#include <stdio.h>;
const int unit[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

int main()
{
    int n;
    int i,j;
    int dir;
    int row,col;
    int step=1;
    int dirindex=0;
    int number=1;
    scanf("%d",&n);
    scanf("%d",&dir);
    int data[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&data[i][j]);
        }
    }
    row =(int)(n/2);
    col =(int)(n/2);
    printf("%d",data[row][col]);
    while(number < n*n)
    {
        for(i=0;i<step;i++)
        {
            row += unit[dir][0];
            col += unit[dir][1];
            printf("%d",data[row][col]);
            number++;
            if(number == n*n)
            {
                break;
            }
        }
        dirindex++;
        if(dirindex %2 == 0)
        {
            step++;
        }
        dir++;
        dir %= 4;
    }
    return  0;
}