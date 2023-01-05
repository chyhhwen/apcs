#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> line[100];
int connect()
{

    return 0;
}
void fix()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            int push;
            cin >> push;
            line[i].push_back(push);
        }
    }
    connect();
}
int main()
{
    fix();
    return 0;
}