#include <bits/stdc++.h>

using namespace std;

int n,r;
const int k=755;
int tab[k][k];


int main()
{

    cin>>n>>r;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           // cout<<"i="<<i<<" j="<<j<"\n";
            cin>>tab[250+i][250+j];
        }

    }


    for(int i=251;i<=752;i++)
    {
        for(int j=251;j<=752;j++)
        {
            tab[i][j]=tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1]+tab[i][j];

          //  if(i<251+n&&j<251+n) cout<<"Pole "<<i<<", "<<j<<": "<<tab[i][j]<<"\n";
        }
    }
    for(int i=251;i<=n+250;i++)
    {
        for(int j=251;j<=n+250;j++)
        {
            cout<<tab[i+r][j+r]-tab[i-r-1][j+r]-tab[i+r][j-r-1]+tab[i-1-r][j-r-1]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}