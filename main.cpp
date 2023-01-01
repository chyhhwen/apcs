#include <bits/stdc++.h>
#define max 1024
using namespace std;
void fix()
{
    char str[max];
    int ans[2];
    cin >> str;
    ans[0] = 0;
    ans[1] = 0;
    for(int i=0;i< strlen(str);i++)
    {
        ans[i%2] += (str[i] - 48);
    }
    cout << abs(ans[0] - ans[1]);
}
int main()
{
    fix();
    return 0;
}