#include <iostream>
#include <cmath>
using namespace std;
long double pierw(long double a,long double eps)
{
 long double c=a;
 long double b=1;
 while(fabs(c-b)>eps)
 {
     b=(b+c)/2;
     c=a/b;
 }
 return (b+c)/2;
}
int main()
{
    long double a;
    long double b=1;
    long double eps;
    cout<<"Podaj liczbe: ";
    cin>>a;
    cout<<endl<<"Podaj dokladnosc: ";
    cin>>eps;
    cout<<pierw(a,eps);

    return 0;
}
