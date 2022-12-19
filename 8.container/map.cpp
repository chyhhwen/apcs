#include <iostream>
#include <map>
#include <string>
using namespace std;

void print(map<int,int> &m)
{
    for(auto i = m.find(1);i != m.end();i++)
    {
        cout << i -> first << " " << (*i).second << endl;
    }
}

void test()
{
    map<int,int> m;
    for(int i=0;i<=9;i++)
    {
        m[i]=i+1;
    }
    print(m);
    cout << m.count(10) << endl;
    cout << m.size() << endl;
    //m.clear();
    m.erase(2);
    print(m);
    m.insert({10,8});
    print(m);
}

int main()
{
    test();
    return 0;
}
