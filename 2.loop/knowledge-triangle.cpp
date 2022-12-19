#include "bits/stdc++.h"
using namespace std;
int a[4];
void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int fix()
{
    float b[2];

    cout << "three line , like:3 4 5" << endl;
    for(int i=0;i<3;i++)
    {
        cin >> a[i];
    }

    if(a[0] > a[1]){swap(a[0],a[1]);}
    if(a[1] > a[2]){swap(a[1],a[2]);}
    if(a[0] > a[1]){swap(a[0],a[1]);}

    a[3] = a[0] + a[1];

    if(a[3] <= a[2])
    {
        cout << "no";
        return 0;
    }

    b[0] = pow(a[0],2) + pow(a[1],2);
    b[1] = pow(a[2],2);

    if(b[0] < b[1])
    {
        cout << "Obtuse";
    }
    else
    {
        if(b[0]!=b[1])
        {
            cout << "Acute";
        }
        else
        {
            cout << "Right";
        }
    }
}
int main()
{
    fix();
    return 0;
}
