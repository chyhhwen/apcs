#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define true 1
#define false 0
typedef int bool;
int data[10000][2];
int member[10000] = {0};
bool child[10000] = {false};
int n;
int blood_distance = 0;

int big(int x,int y)
{
    if(x >= y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int change(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int distance(int node)
{
    int depth,j;
    if(member[node] == 0)
    {
        return 0;
    }
    else if(member[node] == 1)
    {
        for(j=0;j<n-1;j++)
        {
            if(data[j][0] == node)
            {
                return distance(data[j][1])+1;
            }
        }
    }
    else
    {
        int deep1=0,deep2=0;
        for(j=0;j<n-1;j++)
        {
            if(data[j][0] == node)
            {
                depth = distance(data[j][1])+1;
                if(depth > deep1)
                {
                    change(&depth,&deep1);
                }
                if(depth > deep2)
                {
                    deep2 = depth;
                }
            }
        }
        blood_distance = big(blood_distance,deep1 + deep2);
        return deep1;
    }
}

int main(void)
{
    int i;
    int root;
    int deepest;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d %d",&data[i][0],&data[i][1]);
        member[data[i][0]]++;
        child[data[i][1]] = true;
    }
    for(i=0;i<n;i++)
    {
        if(child[i] == false)
        {
            root = i;
            break;
        }
    }
    deepest = distance(root);
    blood_distance = big(deepest,blood_distance);
    printf("%d",blood_distance);
    return 0;
}