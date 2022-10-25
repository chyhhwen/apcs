#include <stdio.h>

int main(void)
{
    int n,d,pay,lastpay,ans;
    scanf("%d %d",&n,&d);
    ans=0;
    lastpay=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&pay);
        if(i == 1 || lastpay == -1)
        {
            lastpay = pay;
        }
        else
        {
            if((pay - lastpay) == d)
            {
                ans += d;
                lastpay = -1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}