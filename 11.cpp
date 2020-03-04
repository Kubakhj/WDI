#include <iostream>
using namespace std;

int main()
{
    bool T[10000];
    int N;
    cin>>N;
    for(int i=0;i<N;i++) ///Wype³nianie tablicy jedynkami
    {
        T[i]=true;
    }
    for(int i=2;i*i<N;i++)
    {
        if(T[i])
        {
            int j=i+i;
        while(j<N)
        {
            T[j]=false;
            j+=i;
        }
        }
    }

    for(int i=2;i<N;i++)
    {
        if(T[i])
        {
            cout<<i<<endl;
        }
}
}
