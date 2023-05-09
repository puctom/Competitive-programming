#include <bits/stdc++.h>

using namespace std;

const int mportow=5*1e3;

vector<int> G[2*mportow+5];
int ileportow;
int ilepolaczen;
int ileopowiesci;
int pomskad,pomdokad,pomdlugosc;
int odl[2*mportow+4];
const int milepodrozy=1e6+5;
struct podroz
{

    int dokad;
    int dlugosc;
    int nr;
};
vector<podroz> zeznanie[mportow+5];
bool czypodrozmozliwa[milepodrozy];

void bfs(int vstart)
{
    for(int i=1;i<=2*ileportow;i++)
        odl[i]=-1;

    queue<int> kolejka;
    odl[vstart]=0;
    kolejka.push(vstart);

    while(kolejka.empty()==false)
    {
        int x=kolejka.front();
        kolejka.pop();

        for(int i=0;i<G[x].size();i++)
        {
            if(odl[G[x][i]]==(-1))
            {
                odl[G[x][i]]=odl[x]+1;
                kolejka.push(G[x][i]);
            }
        }


    }



}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>ileportow>>ilepolaczen>>ileopowiesci; //ile opowiesci

    int p1,p2;
    for(int i=0;i<ilepolaczen;i++)
    {
        cin>>p1>>p2;
        G[p1].push_back(p2+ileportow);
        G[p2].push_back(p1+ileportow);
        G[p1+ileportow].push_back(p2);
        G[p2+ileportow].push_back(p1);

    }

    for(int i=1;i<=ileopowiesci;i++)
    {
        cin>>pomskad>>pomdokad>>pomdlugosc;
        zeznanie[pomskad].push_back({pomdokad,pomdlugosc,i});
    }


    for(int i=1;i<=ileportow;i++)
    {
        //cout<<"\nSprawdzamy zeznania z portu: "<<i<<"\n";
        if(zeznanie[i].size()>0&&G[i].size()>0)
        {
           // cout<<"Takich zeznan mamy: "<<zeznanie[i].size()<<"\n";
            bfs(i);
            //cout<<"Jestesmy po bfsie z wierzcholka: "<<i<<"\n";
            for(int j=0;j<zeznanie[i].size();j++)
            {
                //cout<<"Jestesmy juz w trakcie sprawdzania zeznan, zeznanie nr: "<<j<<"\n";
                if( odl[zeznanie[i][j].dokad+ ( (zeznanie[i][j].dlugosc%2==0 ? 0 : 1)*ileportow   )]!=(-1) )
                {
                    //cout<<"Polaczenie z portu: "<<i<<" do portu: "<<zeznanie[i][j].dokad+ ( (zeznanie[i][j].dlugosc%2==0 ? 0 : 1)*ileportow   );
                    //cout<<" istnieje i ma dlugosc: "<< odl[zeznanie[i][j].dokad+ ( (zeznanie[i][j].dlugosc%2==0 ? 0 : 1)*ileportow   )]<<"\n";
                    if(odl[zeznanie[i][j].dokad+ ( (zeznanie[i][j].dlugosc%2==0 ? 0 : 1)*ileportow   )]<=zeznanie[i][j].dlugosc)
                    {
                        czypodrozmozliwa[zeznanie[i][j].nr]=true;
                        //cout<<"Podroz nr: "<<zeznanie[i][j].nr<<" jest mozliwa.\n";
                    }

                }
            }



        }
    }

    for(int i=1;i<=ileopowiesci;i++)
        cout<<(czypodrozmozliwa[i]==true ? "TAK\n" : "NIE\n");







    return 0;
}