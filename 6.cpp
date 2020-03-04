#include <iostream>

using namespace std;
int rewers(int n)
{
    int b=0;
    int a=n;
    while(n>0)
    {
        b+=n%10;
        b*=10;
        n=n/10;
    }
    return b/10;
}
bool palindrom(int n)
{
    if(rewers(n)==n) return 1;
    return 0;
}
int dectobin(int n)
{
    int b=0;

    while(n!=0)
    {
        b+=n%2;
        n=n/2;
        b=10*b;
    }
    return rewers(b/10);

}

int main()
{
    int n;
    cout<<"Podaj liczbe:";
    cin>>n;
    if(palindrom(n)) cout<<endl<<"Jest to palindrom w systemie dziesietnym";
    cout<<endl<<"Twoja liczba w systemie binarnym: "<<dectobin(n);
    if(palindrom(dectobin(n))) cout<<endl<<"Jest to palindrom w systemie dziesietnym";
    return 0;
}
