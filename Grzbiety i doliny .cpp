#include <bits/stdc++.h>

using namespace std;

const int mn=1e3+4;

int h[mn][mn];
int zmianaw[]={0,1,1,1,0,-1,-1,-1};
int zmianak[]={-1,-1,0,1,1,1,0,-1};
int n;
bool visited[mn][mn];
int dolin=0,grzbietow=0;
int wys, swmx,swmn;

bool inside(int nrw,int nrk)
{

    return (1<=nrw&&nrw<=n&&1<=nrk&&nrk<=n);
}

bool czytoh(int nrw,int nrk)
{
    if(h[nrw][nrk]==wys) return true;

    else
    {
        swmx=max(swmx,h[nrw][nrk]);
        swmn=min(swmn,h[nrw][nrk]);
        return false;
    }

}



void bfs(int k, int w)
{
    visited[w][k]=true;

    queue<pair<int,int>> Q;
    Q.push({w,k});

    while(Q.empty()==false)
    {
        int aktw=Q.front().first;
        int aktk=Q.front().second;
        //cout<<"aktw: "<<aktw<<", aktk: "<<aktk<<"\n";
        Q.pop();

        visited[aktw][aktk]=true;

        for(int i=0;i<8;i++)
        {
            if(inside(aktw+zmianaw[i],aktk+zmianak[i])==true)
            {
                if(czytoh(aktw+zmianaw[i],aktk+zmianak[i])==true)
                {
                    if(visited[aktw+zmianaw[i]][aktk+zmianak[i]]==false)
                    {
                        visited[aktw+zmianaw[i]][aktk+zmianak[i]]=true;
                        Q.push({aktw+zmianaw[i],aktk+zmianak[i]});
                     //   cout<<"Dorzucono do kolejki i: "<<i<<" .\n";
                    }

                }
            }
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    //pierwszy wiersz, potem kolumna
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>h[i][j];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(visited[i][j]==true) continue;

            wys=h[i][j];
            swmx=h[i][j];
            swmn=h[i][j];
            //cout<<"Przed wywolaniem bfsu dla: i,j: "<<i<<" "<<j<<"\n";
            bfs(j,i);

            if(swmx==h[i][j]) grzbietow++;
            if(swmn==h[i][j]) dolin++;

        }
    }

    cout<<grzbietow<<" "<<dolin<<"\n";



    return 0;
}