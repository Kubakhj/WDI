
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int MAX=2;
bool zawp(int n)
{
    while(n>0)
    {
        if(((n%10)%2)==0) return true;
        n=n/10;
    }
    return false;
}
int main()
{
    srand(time(NULL));
    int T[MAX][MAX];

    for(int i=0;i<MAX;i++) //  WYPELNIANIE TABLICY LOSOWYMI LICZBAMI
    {
    for(int j=0;j<MAX;j++)
    {
        T[i][j]=(rand()%100)+1;
    }
    }

    for(int i=0;i<MAX;i++) // WYSWIETLENIE TABLICY
    {
    for(int j=0;j<MAX;j++)
    {
        cout<<T[i][j]<<" ";
    }
    cout<<endl;
    }

    int i=0;
    int j=0;
    int licznik=0;

    while(i<MAX)
    {
        if(zawp(T[i][j]))
        {
            j++;
        }
        else
        {
            i++;
            j=0;
        }
        if(j==MAX)
        {
            cout<<"ISTNIEJE";
            break;
        }
    }
    return 0;
}

