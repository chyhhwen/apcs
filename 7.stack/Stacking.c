#include <stdio.h>

int main(void)
{
    struct item
    {
        int weight;
        int timeing;
    };
    struct item tmp;
    int min=0;
    int weight=0;
    int num;
    int i,j;
    scanf("%d",&num);
    struct item obj[num];
    for(i=0;i<num;i++)
    {
        scanf("%d",&obj[i].weight);
    }
    for(i=0;i<num-1;i++)
    {
        scanf("%d",&obj[i].timeing);
    }
    for(i=0;i<num;i++)
    {
        for(j=0;j<num-i-1;j++)
        {
            if(obj[j].weight*obj[j+1].timeing > obj[j+1].weight*obj[j].timeing)
            {
                tmp = obj[j];
                obj[j] = obj [j+1];
                obj[j+1] =tmp;
            }
        }
    }
    for(i=0;i<num-1;i++)
    {
        weight += obj[i].weight;
        min += weight * obj[i+1].timeing;
    }
    printf("%d\n",min);
    return 0;
}