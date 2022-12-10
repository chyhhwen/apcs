#include <stdio.h>
#include <stdlib.h>
int height[100000]={0};

long ans(int n)
{
    long total = 0;
    int i;
    for(i=1;i<=n;i++)
    {
        total = total + height[i];
    }
    return total;
}

int main(void)
{
    int n;
    int temp,i,j;
    int Parent_node[100000]={0};
    int num_of_subnode[100000]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num_of_subnode[i]);
        for(j=0;j<num_of_subnode[i];j++)
        {
            scanf("%d", &temp);
            Parent_node[temp] = i;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(Parent_node[i] == 0)
        {
            printf("%d\n",i);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(num_of_subnode[i] == 0)
        {
            int level = 0;
            int temp_node = Parent_node[i];
            while(temp_node != 0)
            {
                level++;
                if(level > height[temp_node])
                {
                    height[temp_node] = level;
                }
                temp_node = Parent_node[temp_node];
            }
        }
    }
    printf("%d",ans(n));
    return 0;