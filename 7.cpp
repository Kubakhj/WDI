#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int a,b;
    a=sqrt(n);
    if(a*a==n)
    {
        cout<<a<<" i "<<a;
        return 0;
    }
    a--;
    while(a>0)
    {
    if(n%a==0)
    {
        cout<<n/a<<" i "<<a;
        return 0;
    }
    a--;
    }

    return 0;
}
