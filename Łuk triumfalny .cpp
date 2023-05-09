#include <bits/stdc++.h>

using namespace std;

const int MAXile=3*1e5;
int ileskrzyzowan;
int a,b;
vector<int> G[MAXile];
bool visited[MAXile];

int check(int u, int k) // u- rozwazany wierzcholek, k - typ ekip
{   // zwraca dla wierzcholka ile potrzeba ekip wczesniej

    int sumadrzewa=0, iledzieci=0;
    visited[u]=true;
    //cout<<"\nDzialamy dla wierzcholka: "<<u<<"\n";
    for(int v=0;v<(int)G[u].size();v++)
    {

       if(visited[G[u][v]]==false)
       {

           //cout<<"Sprawdzamy syna u = "<<u<<" : "<<G[u][v]<<"\n";
           iledzieci++;
           sumadrzewa+=check(G[u][v],k);
       }

    }


    return max(0, iledzieci+sumadrzewa-k);
}



int main()
{
    cin>>ileskrzyzowan;

    for(int i=0;i<ileskrzyzowan-1;i++)
    {
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }



    int l=0,p=ileskrzyzowan,s;

    while(l!=p)
    {
        s=(l+p)/2;

        fill(visited,visited+ileskrzyzowan,false);

        if(check(0,s)>0)
        {
            l=s+1;
            //cout<<"s = "<<s<<" nie dziala, nowe: l="<<l<<",   p="<<p<<"\n";
        }
        else
        {
            p=s;
            //cout<<"s = "<<s<<" dziala, nowe: l="<<l<<",   p="<<p<<"\n";
        }

    }

    cout<<(l+p)/2<<"\n";

    return 0;
}