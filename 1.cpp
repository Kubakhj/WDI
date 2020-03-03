#include <iostream>

using namespace std;

int main()
{
    int Fib[1000];
    Fib[0]=1;
    Fib[1]=1;
    Fib[2]=2;
    int i=2;
    while(Fib[i]<1000000)

    {   cout<<Fib[i]<<endl;
        i++;
        Fib[i]=Fib[i-1]+Fib[i-2];
    }

    return 0;
}
