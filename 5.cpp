#include <iostream>

using namespace std;
int ciag(int n)
{
    return n*n+n+1;
}
int main()
{
    int n;
    cin>>n;
    int i=n-1;
    while(i>0)
    {
    if(n%ciag(i)==0)
    {
        //cout<<"Jest wielokrotnoscia a"<<i<<", ("<<ciag(i)<<" * "<<n/ciag(i)<<" = "<<n<<")";
        return 0;
    }
    i--;
    }
    //cout<<"Nie jest wielokrotnoscia!";

    return 0;
}
