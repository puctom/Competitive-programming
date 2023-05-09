#include <bits/stdc++.h>

using namespace std;

const int mn=5*1e5+5;
int liczbaprac, dopbunt;
double odp=0;
vector <int> G[mn]; // zbiory podwladnych
int szef;
double morale[mn];
double rozm[mn];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>liczbaprac>>dopbunt;

    for(int i=2;i<=liczbaprac;i++)
    {
        cin>>szef;
        G[szef].push_back(i);
    }

    for(int v=liczbaprac;v>=1;v--)
    {
        rozm[v]=1; //rozmiar poddrzewa v, start od 1
        morale[v]=(G[v].size()==0 ? 1 : 0);

        for(auto u: G[v])
        {
            rozm[v]+=rozm[u];
        }


        for(auto u: G[v])
        {
            morale[v]=max(morale[v],min( morale[u] , rozm[u]/(rozm[v]-1) ));
        }

            if(rozm[v]>dopbunt)
        {
            odp=max(odp,morale[v]);
        }



    }

    cout<<setprecision(8)<<odp<<"\n";



    return 0;
}