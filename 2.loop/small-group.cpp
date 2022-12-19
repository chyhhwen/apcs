#include "bits/stdc++.h"
using namespace std;
int fix()
{
    int group[2][50000];
    int a = 0;
    int first = 0;
    int find = 0;
    int time = 0;
    int ans = 0;
    cin >> a;
    for(int i=0;i<a;i++)
    {
        group[0][i] = i;
        cin >> group[1][i];
    }
    while(time != a)
    {
        first = 0;
        find = 0;
        int check = a - 1;
        for(int i=0;i<a;i++)
        {
            if(group[1][i] != -1)
            {
                first = group[1][i];
                find = i;
                group[1][i] = -1;
                check -= 1;
                break;
            }
        }
        if(check == a - 1)
        {
            ans -= 1;
        }
        while(true)
        {
            time += 1;
            if(first == find)
            {
                ans += 1;
                break;
            }
            for(int i=0;i<a;i++)
            {
                if(group[1][i] == find)
                {
                    group[1][i] = -1;
                    find = group[0][i];
                }
            }
        }
    }
    return ans;
}
int main()
{
    cout << fix();
    return 0;
}
