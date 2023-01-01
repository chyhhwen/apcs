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
int push(int m,int k)
{
    if(m == k)
    {
        return 0;
    }
    else if(m > k)
    {
        return 1;
    }
    else
    {
        return -1;
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
                check.push_back(push(m,k));
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
            check.push_back(push(m,k));
        }
    }
    int ans = 0;
    int temp = 0;
    for(int i=0;i < check.size();i++)
    {
        if(check[i] > -1)// 0 1
        {
            if(check[i] == 0)// 0
            {
                temp += k;
            }
            else// 1
            {
                if(i == 0)
                {
                    temp = k;
                }
                else if(i == check.size() - 1)//01 11
                {
                    if(check[i - 1] == 0)
                    {
                        if(temp > ans)
                        {
                            temp += k;
                            ans = temp;
                        }
                    }
                }
                else //110 111
                {
                    if(check[i + 1] == 0)//10
                    {
                        temp += k;
                    }
                    else//11
                    {
                        if(temp > ans)
                        {
                            temp += k;
                            ans = temp;
                        }
                        temp = 0;
                    }
                }
            }
        }
        else// -1
        {
            if(temp > ans)
            {
                ans = temp;
            }
            temp = 0;
        }
    }
    cout << ans;
}
int main()
{
    fix();
    return 0;
}