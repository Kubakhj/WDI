/* Three numbers make complete number, if they are made only from 10 digits - 0,,...9.
In complete number every digit appear only once.
A square is complete, if any of its 3 corners make complete number.
Write Function that search complete square in an given T[N][N] array.
Function must return minimal side length of that square.
If complete square doesn't exist function returns -1.
*/
///Code by Jakub S³owiak
#include <iostream>
#include <iomanip>
using namespace std;
const int N=4;
bool complete(int a, int b, int c) // Function checks if three numbers generate "complete" number
{
    int T[10];
    for(int i=0;i<10;i++)
    {
        T[i]=0;
    }
    while(a!=0)
    {
        T[a%10]++;
        a=a/10;
    }
    while(b!=0)
    {
        T[b%10]++;
        b=b/10;
    }
    while(c!=0)
    {
        T[c%10]++;
        c=c/10;
    }
    int i=0;
    while(i<10)
    {
        if(T[i]!=1) return false;
        i++;
    }
    return true;
}
bool completesquare(int A,int B,int C,int D) //Function checks if the square is "complete" ( A,B,C,D are numbers in all corners of the square )
{
    if ((complete(A,B,C)) || (complete(A,B,D)) || (complete(A,C,D)) || (complete(B,C,D))) return true;
    return false;
}
int mincompsquare(int T[N][N]) //Function returns the minimal length of complete square found in an array ( or -1 if the square doesn't exist )
{
    for(int b=2;b<=N;b++)
    {
        for(int w=0;w<N+1-b;w++)
        {
            for(int k=0;k<N+1-b;k++)
            {
                if(completesquare(T[w][k],T[w][k+b-1],T[w+b-1][k],T[w+b-1][k+b-1])) return b;
            }

        }
    }
    return -1;
}
int main()
{
    int T[N][N];
    cout<<"Fill your "<<N<<"x"<<N<<" array: "<<endl;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>T[i][j];
        }
    }

    cout<<"Your array: "<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Minimal side length of complete square found in the array: "<<mincompsquare(T);
    return 0;
}
