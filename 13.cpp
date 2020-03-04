#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int MAX=2;
bool niep(int n)
{
    while(n>0)
    {
        if(((n%10)%2)==0) return false;
        n=n/10;
    }
    return true;
}
bool kazd(int B[MAX][MAX])
{
    int i=0;
    int j=0;
        while((i<MAX)&&(j<MAX))
    {
        if (niep(B[i][j]))
        {
            i++;
            j=0;
        }
        j++;
    }
    if(i==MAX) return true;
    else return false;
}
int main()
{
    srand(time(NULL));
    int T[MAX][MAX];

    for(int i=0;i<MAX;i++) ///  WYPELNIANIE TABLICY LOSOWYMI LICZBAMI
    {
    for(int j=0;j<MAX;j++)
    {
        T[i][j]=(rand()%100)+1;
    }
    }

    for(int i=0;i<MAX;i++) ///WYSWIETLENIE TABLICY
    {
    for(int j=0;j<MAX;j++)
    {
        cout<<T[i][j]<<" ";
    }
    cout<<endl;
    }
    if(kazd(T)) cout<<"tak";


    return 0;
}
