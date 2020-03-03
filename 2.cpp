#include <iostream>

using namespace std;

int main()
{
    int Fib[10000];
    Fib[0]=1;
    Fib[1]=1;
    int n;
    int i=1;
    cin>>n;
    while(Fib[i]*Fib[i-1]<=n)
    {
    if((Fib[i])*(Fib[i-1])==n)
    {
        cout<<"TAK!";
        break;
    }
    Fib[i+1]=Fib[i]+Fib[i-1];
    i++;
    }

    return 0;
}
