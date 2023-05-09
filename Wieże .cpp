#include <bits/stdc++.h>

using namespace std;
const int nmax=1000;
string w[nmax+2];
int pustew[nmax+2];
int pustek[nmax+2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int lpw=0,lpk=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        for(int j=0;j<n;j++)
        {
            if(w[i][j]=='W') break;
             if(j==n-1)
             {
             pustew[lpw]=i; lpw++;
           //  cout<<"Pusty wiersz znalezion: "<<i<<"\n";
             }

        }

    }

    for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
         {
             if(w[j][i]=='W') break;
             if(j==n-1)
             {
             pustek[lpk]=i;
             lpk++;
             }
         }
    }

   // for(int i=0;i<n;i++)
    //    cout<<pustew[i]<<"\n";

       for(int i=0;i<lpk;i++)
       {
           w[pustew[i]][pustek[i]]='W';
       }

     for(int i=0;i<n;i++)
    {
        cout<<w[i]<<"\n";
    }


    return 0;
}