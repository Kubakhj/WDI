#include <iostream>

using namespace std;

int main()
{
    bool cyfr1[10];
    for(int i=0;i<10;i++)
    {
        cyfr1[i]=0;
    }
    bool cyfr2[10];
    for(int i=0;i<10;i++)
    {
        cyfr2[i]=0;
    }
    int a,b;
    cin>>a>>b;
    while(a!=0)
    {
   	cyfr1[a%10]=1;
    	a=a/10;
    }
    while(b!=0)
    {
    	cyfr2[b%10]=1;
    	b=b/10;
    }
    int licznik=0;
    for(int i=0;i<10;i++)
    {
    	if(cyfr1[i]==cyfr2[i]) licznik++;
    }
    if(licznik==10) cout<<"TAK!!!";
    else cout<<"nie";
}


