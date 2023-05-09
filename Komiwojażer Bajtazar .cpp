#include <bits/stdc++.h>

using namespace std;

const int mn=3e5+5; // max wierzcholkow
const int mp=17; //log_2 n
int dis[mn]; //dystanse od korzenia
int lca[mp][mn];
int v1,v;
vector<int> G[mn];
int n,ile;
int wynik=0;
int vpop,vpoz;
int a,b; //pom do wczytu krawedzi

void dfs(int vstart, int vprzodek)
{
    lca[0][vstart]=vprzodek;
    for(auto u: G[vstart])
    {
        if(u!=vprzodek)
        {
            dis[u]=dis[vstart]+1;
            //cout<<"dis["<<u<<"] = "<<dis[u]<<"\n";
            dfs(u,vstart);
        }
    }
}

int query(int v1, int v2)
{
    if(dis[v1]<dis[v2]) swap(v1,v2);

    int log;
    //cout<<"Odleglosci od korzenia: v1: "<<dis[v1]<<"  v2: "<<dis[v2]<<"\n";
    for(log=1;(1<<log)<=dis[v1];log++) ;


    log--;
    //cout<<"log = "<<log<<"\n";
    //log - [log2dis]

    for(int i=log;i>=0;i--)
    {
        //cout<<"i = "<<i<<"  sprawdzamy czy: dis[v1]-(1<<i)>=dis[v2]  "<<dis[v1]<<" - "<<(1<<i)<<" >= "<<dis[v2]<<" \n";
        if(dis[v1]-(1<<i)>=dis[v2])
        {
            v1=lca[i][v1];
            //cout<<"Tak, wiec przestawilismy v1 na: "<<v1<<"\n";
        }
    }

    //cout<<"Po 1. petli: v1 = "<<v1<<" , v2 = "<<v2<<"\n";
    if(v1==v2) return v1;

    for(int i=log;i>=0;i--)
    {
        //cout<<"i = "<<i<<"  sprawdzamy czy przodkiem v2 ("<<v2<<") nie jest korzen i czy:  lca[i][v1]!=lca[i][v2] "<<lca[i][v1]<<" != "<<lca[i][v2]<<" \n";
        if(lca[i][v2]!=-1&&lca[i][v1]!=lca[i][v2])
        {
            v1=lca[i][v1];
            v2=lca[i][v2];
            //cout<<"Tak, wiec: nowe v1: "<<v1<<" nowe v2: "<<v2<<"\n";
        }

    }
    //cout<<"Zwracamy: "<<lca[0][v1]<<"\n";
    return lca[0][v1];

}




int main()
{

    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);

    }

    dfs(1,-1);

    for(int i=1;i<mp;i++)
    {
        for(int j=1;j<=n;j++)
        {
            lca[i][j]=lca[i-1][lca[i-1][j]];
        }
    }

   /* for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<"2^"<<j<<" -ty przodek: "<<i<<", to: "<<lca[j][i]<<"\n";
        }
        cout<<"\n";
    } */



    cin>>ile;
    cin>>vpop;

    for(int i=2;i<=ile;i++)
    {
        cin>>vpoz;
        //cout<<"Kolejne dystanse to: "<<dis[vpop]<<", "<<dis[vpoz]<<", "<<dis[wspolnyprzodek]<<"\n";
        int wspolnyprzodek=query(vpop,vpoz);
        //cout<<"Wspolny przodek ("<<vpop<<", "<<vpoz<<") to: "<<wspolnyprzodek<<"\n";
        wynik+=dis[vpop]+dis[vpoz]-2*dis[wspolnyprzodek];
        //cout<<"Aktualny wynik: "<<wynik<<"\n";
        vpop=vpoz;
    }

    cout<<wynik<<"\n";





    return 0;
}