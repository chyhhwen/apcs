#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &v)
{
    for(auto i = v.begin();i<v.end();i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void test()
{
    /*一般宣告*/
    vector<int> v;
    v.reserve(10);
    for(int i=1;i<=10;i++)
    {
        v.push_back(i);
    }
    v.insert(v.begin()+2,11);
    print(v);
    v.erase(v.begin()+3);
    print(v);
    v.resize(20,-1);
    print(v);
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v.size() << endl;
    v.clear();
    if(v.empty())
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    /*複製v的頭到尾*/
    vector<int>v1(v.begin(),v.end());
    print(v1);
    /*n次輸入相同值*/
    vector<int>v2(10,100);
    print(v2);
    /*複製*/
    vector<int>v3(v2);
    print(v3);
}

int main()
{
    test();
    return 0;
}
