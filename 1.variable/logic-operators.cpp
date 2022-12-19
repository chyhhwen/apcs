#include "bits/stdc++.h"
using namespace std;
int fix()
{
    int a[3];
    char result[3];

    for(int i=0;i<3;i++)
    {
        cin >> a[i];
    }

    if(a[0] > 0){a[0] = 1;}
    if(a[1] > 0){a[1] = 1;}

    if((a[0] & a[1]) == a[2]){result[0] = 'Y';}
    else{result[0] = 'N';}
    if((a[0] | a[1]) == a[2]){result[1] = 'Y';}
    else{result[1] = 'N';}
    if((a[0] ^ a[1]) == a[2]){result[2] = 'Y';}
    else{result[2] = 'N';}

    if(result[0] == 'Y'){cout << "AND" << endl;}
    if(result[1] == 'Y'){cout << "OR" << endl;}
    if(result[2] == 'Y'){cout << "XOR" << endl;}

    if(result[0] == 'N' && result[1] == 'N' && result[2] == 'N')
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
int main()
{
    fix();
    return 0;
}
