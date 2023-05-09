#include <bits/stdc++.h>

using namespace std;

const int mwymiar=1e3+4;
int tab[mwymiar][mwymiar];
int tabpom[mwymiar][mwymiar];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int wymiar,zmiany;
    cin>>wymiar;

    for(int i=1;i<=wymiar;i++)
    {
        for(int j=1;j<=wymiar;j++)
        {
            cin>>tab[j][i];
        }
    }

    cin>>zmiany;
    int x1,y1,x2,y2;

    for(int i=1;i<=zmiany;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        tabpom[x1][y1]++;
        tabpom[x2+1][y1]--;
        tabpom[x1][y2+1]--;
        tabpom[x2+1][y2+1]++;
    }


 /*   cout<<"Tabelka pomocnicza, pola sum prefiksowych:\n";

    for(int i=0;i<=wymiar+1;i++)
    {
        for(int j=0;j<=wymiar+1;j++)
            cout<<tabpom[j][i]<<" ";

        cout<<"\n";
    }


    cout<<"Tabelka pomocnicza, liczby zmian: \n";
    */
    for(int i=1;i<=wymiar;i++)
    {
        for(int j=1;j<=wymiar;j++)
        {
            tabpom[j][i]=tabpom[j][i]+tabpom[j][i-1]+tabpom[j-1][i]-tabpom[j-1][i-1];
          //  cout<<tabpom[j][i]<<" ";
        }
       // cout<<"\n";
    }
     //   cout<<"Tabelka ostateczna\n";
    for(int i=1;i<=wymiar;i++)
    {
        for(int j=1;j<=wymiar;j++)
        {
            cout<<(tab[j][i]+tabpom[j][i])%2<<" ";
        }
        cout<<"\n";
    }

    return 0;
}