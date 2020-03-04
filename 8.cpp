#include <iostream>

using namespace std;

int main()
{
    double pole=0;
    int k,n;
    cin>>k>>n;

    for(int i=0;i<n;i++)
    {
    	pole+=(double)1/((double)i/n+1+(k-1)/n)*(k-1)/n;
    }
    cout<<pole;

    return 0;
}
