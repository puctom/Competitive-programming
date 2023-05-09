#include <bits/stdc++.h>

using namespace std;

const int milemalpek=2e5+5;
const int mileruch=4e5+5;
int ilemalpek,ileruch;
int trzym[milemalpek][2];
bool czypuszczana[milemalpek][2];
int liczbaspojnych;
int odp[milemalpek];
bool czyzmiana;
    int czas;


vector<pair<int,int>> g;
vector<int> numerywspojnych[milemalpek];
int rodzic[milemalpek];

void makesets(int ile)
{
    for(int i=1;i<=ile;i++)
    {
        numerywspojnych[i].push_back(i);
        rodzic[i]=i;
    }

}

int finddsu(int w)
{
    return rodzic[w];
}

void uniondsu(int w1,int w2)
{
  //  cout<<"Chwila: "<<czas<<"  chcemy polaczyc wierzcholki: "<<w1<<" i "<<w2<<"\n";
    int nr1=finddsu(w1);
    int nr2=finddsu(w2);
  //  cout<<"Ich spojne to: "<<nr1<<" i: "<<nr2<<"\n";
    if(nr1==nr2) return;

    if(nr1==1)
    {
        for(int i=0;i<numerywspojnych[nr2].size();i++)
        {
            numerywspojnych[1].push_back(numerywspojnych[nr2][i]);
            odp[numerywspojnych[nr2][i]]=czas;
            rodzic[numerywspojnych[nr2][i]]=1;
        }
        numerywspojnych[nr2].clear();
    }
    else if(nr2==1)
    {
        for(int i=0;i<numerywspojnych[nr1].size();i++)
        {
            numerywspojnych[1].push_back(numerywspojnych[nr1][i]);
            odp[numerywspojnych[nr1][i]]=czas;
            rodzic[numerywspojnych[nr1][i]]=1;
        }
        numerywspojnych[nr1].clear();
    }
    else
    {
        if(numerywspojnych[nr1].size()>numerywspojnych[nr2].size())
            swap(nr1,nr2);

        for(int i=0;i<numerywspojnych[nr1].size();i++)
        {
            numerywspojnych[nr2].push_back(numerywspojnych[nr1][i]);
            rodzic[numerywspojnych[nr1][i]]=nr2;

        }
        numerywspojnych[nr1].clear();
    }


}


int main()
{



    cin>>ilemalpek>>ileruch;
    for(int i=1;i<=ilemalpek;i++)
    {
        for(int j=0;j<2;j++)
        cin>>trzym[i][j];
    }

    int nr,reka;
    for(int i=1;i<=ileruch;i++)
    {
        cin>>nr>>reka;
       // cout<<"W ruchu nr: "<<i<<" puszczamy wiazanie: "<<nr<<" - "<<trzym[nr][reka-1]<<"\n";
        g.push_back({nr,trzym[nr][reka-1]});
        czypuszczana[nr][reka-1]=1;
    }

    makesets(ilemalpek);

    for(int i=1;i<=ilemalpek;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(trzym[i][j]!=-1&&czypuszczana[i][j]!=1)
            {
                uniondsu(i, trzym[i][j]);
            }
        }
    }
   //cout<<"Pierwsze laczenia za nami\n";
    for(int i=1;i<=ilemalpek;i++)
        if(finddsu(i)==1) odp[i]=-1;

    int pop1,pop2;
    for(int i=g.size()-1;i>=0;i--)
    {
        czas=i;
        uniondsu(g[i].first,g[i].second);
    }
    for(int i=1;i<=ilemalpek;i++)
    {
        cout<<odp[i]<<"\n";
    }



    return 0;
}