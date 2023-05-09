#include <bits/stdc++.h>

using namespace std;

const int milemiast=1e5+5;
int ilemiast,iledrog;
bool visited[milemiast];
int preorder[milemiast];
int low[milemiast];
vector<int> G[milemiast];
long long odp[milemiast];
int s[milemiast];
int a,b;
int idx=1;

void dfs(int v, int p=-1)
{
    vector<int> roz;
    roz.push_back(1);
    int above=0;

    visited[v]=true;
    preorder[v]=idx;
    low[v]=idx++;


    for(auto u: G[v])
    {
        if(u!=p)
        {
            if(visited[u]==true)
                low[v]=min(low[v],preorder[u]);
            else
            {
                dfs(u,v);
                s[v]+=s[u]+1;
                low[v]=min(low[v],low[u]);
                if(low[u]>=preorder[v])
                {
                    roz.push_back(s[u]+1);
                }
                else
                {
                    above+=s[u]+1;
                }


            }
        }

    }
    above+=ilemiast-(s[v]+1);

    roz.push_back(above);

    for(auto val: roz)
    {
        odp[v]+=val*1LL*(ilemiast-val);
    }


}



int main()
{
    cin>>ilemiast>>iledrog;

    for(int i=0;i<iledrog;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(1);

    for(int i=1;i<=ilemiast;i++)
    {
        cout<<odp[i]<<"\n";
    }


    return 0;
}