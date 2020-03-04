#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX=4;

int main()
{
    srand(time(NULL));
    int T[MAX][MAX];

    for(int i=0;i<MAX;i++) // WYPELNIANIE TABLICY LOSOWYMI LICZBAMI
    {
    	for(int j=0;j<MAX;j++)
    	{
        	T[i][j]=(rand()%10)+1;
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

    int sumamax=0;
    int suma=0;
    int a;

    for(int i=0;i<MAX;i++) //najlepszy wiersz
    {
        for(int j=0;j<MAX;j++)
        {
            suma+=T[i][j];
        }
        if(suma>sumamax)
        {
            sumamax=suma;
            a=i;
            suma=0;
        }
    }
    int b;
    for(int j=0;j<MAX;j++) //najlepsza kolumna
    {
        for(int i=0;i<MAX;i++)
        {
            suma+=T[i][j];
        }
        if(suma>sumamax)
        {
            sumamax=suma;
            b=j;
            suma=0;
        }
    }
    cout<<endl<<a<<" "<<b;

    return 0;
}
