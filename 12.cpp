#include <iostream>

using namespace std;
const int MAX=5;
int main()
{
    int T[MAX][MAX];

    for(int i=0;i<MAX;i++) ///Pomocnicze wypelnienie zerami
    {
        for(int j=0;j<MAX;j++)
        {
            T[i][j]=0;
        }
    }

    int n=1;
    int j=0;
    int i=0;
    for(int k=0;k<MAX/2;k++)
    {
    while(j<MAX-k)
    {
    	T[i][j]=n;
    	j++;
    	n++;
    }
    	j--;
    	i++;
    while(i<MAX-k)
    {
    	T[i][j]=n;
    	i++;
    	n++;
    }
    	i--;
    	j--;
    while(j>=k)///
    {
    	T[i][j]=n;
    	j--;
    	n++;
    }
    	j++;
    	i--;
    while(i>=1+k)
    {
    	T[i][j]=n;
    	i--;
    	n++;
    }
    i++;
    j++;
    }
    T[i][j]=n;
    for(int i=0;i<MAX;i++) ///Wyswietlanie tablicy
    {
        for(int j=0;j<MAX;j++)
        {
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
