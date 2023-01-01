#include <bits/stdc++.h>
using namespace std;
void fix()
{
    int put[3];
    for(int i=0;i<3;i++)
    {
        cin >> put[i];
    }
    vector<int> man;
    for(int i=1;i<=put[0];i++)
    {
        man.push_back(i);
    }
    int time = 0;
    for(int i=0;i<=put[2];i++)//5
    {
        for(int j=0;j<put[1];j++)//2
        {
            if(time == (put[0] - i))
            {
                time -= (put[0] - i);
            }
            time++;
        }
        time --;
        if(i == put[2])
        {
            cout << man[time];
        }
        man.erase(man.begin()+(time));
    }
}
int main()
{
    fix();
    return 0;
}