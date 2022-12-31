#include <bits/stdc++.h>
using namespace std;
void fix()
{
    int n,trun;
    cin >> n >> trun;
    int num[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> num[i][j];
        }
    }

    int x=(n-1)/2,y=x;
    cout << num[x][y];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<(i==n-1 ? 3 : 2);j++)
        {
            for(int k=0;k<i;k++)
            {
                if(trun==0) x-=1;
                else if(trun==1) y-=1;
                else if(trun==2) x+=1;
                else if(trun==3) y+=1;
                cout << num[y][x];
            }
            trun++;
            if(trun==4) trun=0;
        }
    }
}
int main()
{
    fix();
    return 0;
}