#include <bits/stdc++.h>
using namespace std;
int x;
int y;
int ans[10][10];
vector<int> temp[10];
int swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return 0;
}
int trun()
{
    for(int i=0;i<y;i++)//2
    {
        for(int j=0;j<x;j++)//3
        {
            int put = temp[x-j-1][i];
            ans[i][j] = put;
        }
    }
    for(int j=0;j<x;j++)
    {
        temp[j].clear();
    }
    for(int i=0;i<y;i++)
    {
        temp[i].clear();
        for(int j=0;j<x;j++)
        {
            temp[i].push_back(ans[i][j]);
        }
    }
    return 0;
}
int updown()
{
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            int put = temp[y-i-1][j];
            ans[i][j] = put;
        }
    }
    for(int i=0;i<y;i++)
    {
        temp[i].clear();
        for(int j=0;j<x;j++)
        {
            temp[i].push_back(ans[i][j]);
        }
    }
    return 0;
}
void printans()
{
    cout << y <<  " "<< x << endl;
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
void fix()
{
    int size;
    cin >> y >> x >> size;
    for(int i=0;i<y;i++)
    {
        for(int j=0;j<x;j++)
        {
            cin >> ans[i][j];
            temp[i].push_back(ans[i][j]);
        }
    }
    int put = 0;
    for(int i=0;i<size;i++)
    {
        cin >> put;
        switch (put)
        {
            case 0:
                swap(x,y);
                trun();
                break;
            case 1:
                updown();
                break;
        }
    }
    printans();
}
int main()
{
    fix();
    return 0;
}