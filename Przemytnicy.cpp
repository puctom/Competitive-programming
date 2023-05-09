#include <bits/stdc++.h>

using namespace std;

int a,b,c;
const long long inf=LONG_MAX;

long long odp;
const int milemetali=5*1e3+5;
const int mileprzemian=1e5+5;
int ilemetali, ileprzemian;
long long cenymetali[milemetali];
long long kosztprzemian[mileprzemian];
vector<int> G[milemetali]; //jakie mozna uzyskac
vector<int> G2[milemetali]; // przemiany powrotne
vector<int> W[milemetali];
vector<int> W2[milemetali];
vector<long long> c1;
vector<long long> c2;


vector<long long> dijkstra(vector<int> *Gsasiedzi, vector<int> *wagi)
{
    vector<long long> koszty(ilemetali+1,2e9+3);
    vector<bool> czybyl(ilemetali+1,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > Q;

    Q.push(make_pair(0,1));
    koszty[1]=0;

    while(Q.empty()==false)
    {
        int v=Q.top().second;
        long long cc=Q.top().first;
        Q.pop();

        if(czybyl[v]==true) continue;

        czybyl[v]=true;

        for(int i=0;i<Gsasiedzi[v].size();i++)
        {
            int u=Gsasiedzi[v][i];
            long long w=wagi[v][i];

            if(koszty[u]>w+cc) koszty[u]=w+cc;
            Q.push(make_pair(w+cc,u));

        }





    }



    return koszty;
}


int main()
{
    cin>>ilemetali;
    for(int i=1;i<=ilemetali;i++)
        cin>>cenymetali[i];

    cin>>ileprzemian;

    for(int i=0;i<ileprzemian;i++)
    {
        cin>>a>>b>>c;
        G[a].push_back(b);
        W[a].push_back(c);

        G2[b].push_back(a);
        W2[b].push_back(c);

    }

    c1=dijkstra(G,W);
    c2=dijkstra(G2,W2);

    odp=inf;
    for(int i=1;i<=ilemetali;i++)
    {
        odp=min(odp, (cenymetali[i]/2 + c1[i]+c2[i]));
    }

    cout<<odp<<"\n";

    return 0;
}