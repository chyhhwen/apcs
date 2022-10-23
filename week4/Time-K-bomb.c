#include<stdio.h>

struct node
{
    int data;
    int next;
};
struct node player[200000];

int main(void)
{
    int N;
    int M;
    int K;
    int explosion = 0;
    int i;
    int num = 0;
    int now = 0;
    int previous = 0;
    scanf("%d %d %d",&N,&M,&K);
    for(i=0;i<N-1;i++)
    {
        player[i].data = i+1;
        player[i].next = i+1;
    }
    player[i-1].data = N;
    player[i-1].next = 0;
    while(explosion < K)
    {
        num = num+1;
        if(num == M)
        {
            player[previous].next = player[now].next;
            num = 0;
            N = N-1;
            explosion++;
        }
        previous = now;
        now = player[now].next;
    }
    printf("%d\n",player[now].data);
    return 0;
}