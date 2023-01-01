#include <bits/stdc++.h>
#define max 1024
using namespace std;
bool judge(int a,int b)
{
    if(a > 96)
    {
        if(b > 96)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if(b < 96)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
void fix()
{
    int k = 0;
    int m = 0;
    char put[max];
    vector<int> check;
    cin >> k;
    cin >> put;
    m = 0;
    for(int i=0;i<strlen(put);i++)
    {
        if(i != 0)
        {
            if(judge(put[i],put[i-1]))
            {
                check.push_back(m);
                m = 1;
            }
            else
            {
                m += 1;
            }
        }
        else
        {
            m += 1;
        }
        if(i == (strlen(put) - 1))
        {
            check.push_back(m);
            m = 1;
        }
    }
    for(auto i = check.begin();i!=check.end();i++)
    {
        cout << *i << " ";
    }
}
int main()
{
    fix();
    return 0;
}