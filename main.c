#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char str[1000];
    int i;
    int odd =0;
    int even = 0;
    scanf("%s",str);
    if(strlen(str) % 2 ==0)
    {
        for(i=0;i<strlen(str);i++)
        {
            if(i%2 == 0)
            {
                even += (int)(str[i])-48;
            }
            else
            {
                odd += (int)(str[i])-48;
            }
        }
    }
    else
    {
        for(i=0;i< strlen(str);i++)
        {
            if(i%2 == 0)
            {
                odd += (int)(str[i])-48;
            }
            else
            {
                even += (int)(str[i])-48;
            }
        }
    }
    printf("%d\n",abs(even-odd));
    return 0;
}