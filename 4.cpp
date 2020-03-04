#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a=4,b=5;
    int dokl;
    cin>>dokl;
    for(int i=0;i<dokl;i++)
    {
    double c=(a+b)/2;
    if(exp(c*log(c))>2017)
    {
        b=c;
    }
    else a=c;
    }
    cout<<(a+b)/2;

    return 0;
}
