#include <stdio.h>
#include<string.h>

int main()
{
    FILE *fp;
    fp = fopen("C:\\Users\\USER\\Desktop\\apcs\\week6\\input1.txt","r");
    int hit[100];
    char str[2];
    int base[3] = {0};
    int i,j,k;
    int a;
    int b = 0;
    int out = 0;
    int score = 0;
    int how_many = 0;
    int current = 0;
    for(i=0;i<9;++i)
    {
        fscanf(fp," %d",&a);
        for(j=0;j<a;j++)
        {
            fscanf(fp,"%s",str);
            if(strcmp("FO",str) == 0 || strcmp("GO",str) == 0 || strcmp("SO",str) == 0)
            {
                hit[j*9+i] = 0;
            }
            else if(strcmp("1B",str) == 0)
            {
                hit[j*9+i] = 1;
            }
            else if(strcmp("2B",str) == 0)
            {
                hit[j*9+i] = 2;
            }
            else if(strcmp("3B",str) == 0)
            {
                hit[j*9+i] = 3;
            }
            else
            {
                hit[j*9+i] = 4;
            }
        }
    }
    fscanf(fp,"%d",&b);
    while(current < b)
    {
        switch (hit[how_many])
        {
            case  1:
                if(base[2] == 1)
                {
                    score+=1;
                }
                base[2]=base[1];
                base[1]=base[0];
                base[0]=1;
                break;
            case  2:
                if(base[2] == 1)
                {
                    score+=1;
                }
                if(base[1] == 1)
                {
                    score+=1;
                }
                base[2]=base[0];
                base[0]=0;
                base[1]=1;
                break;
            case  3:
                if(base[2] == 1)
                {
                    score+=1;
                }
                if(base[1] == 1)
                {
                    score+=1;
                }
                if(base[0] == 1)
                {
                    score+=1;
                }
                base[1]=0;
                base[0]=0;
                base[2]=1;
                break;
            case  4:
                if(base[2] == 1)
                {
                    score+=1;
                }
                if(base[1] == 1)
                {
                    score+=1;
                }
                if(base[0] == 1)
                {
                    score+=1;
                }
                score+=1;
                base[0]=0;
                base[1]=0;
                base[2]=0;
                break;
            default:
                out+=1;
                if(out == 3)
                {
                    out = 0;
                    base[0]=0;
                    base[1]=0;
                    base[2]=0;
                }
                current+=1;
                break;
        }
        how_many+=1;
        printf("%d",score);
        return 0;
    }
}