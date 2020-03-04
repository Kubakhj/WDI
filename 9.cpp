#include <iostream>

using namespace std;

int main()
{
    int n,podst;
    cin>>n>>podst;
    string nowa="";

    while(n!=0)
    {
        if(n%podst<9)
        {
        nowa+='0'+n%podst;
        }
        else
        {
            nowa+='7'+n%podst;
        }
        n=n/podst;
    }

    for(int i=0;i<nowa.length()/2;i++)
    {
        swap(nowa[i],nowa[nowa.length()-1-i]);
    }

cout<<nowa;


    return 0;
}
