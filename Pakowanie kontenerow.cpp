#include <bits/stdc++.h>

using namespace std;


const int milerozm=1e3+5;
int ilepudelek;
int ilerozm;
int ilekontenerow[milerozm];
vector<int> wartosci[milerozm];
int r,c;
int wynik;
bool czymozna=true;

bool cmp(int w1,int w2)
{
    return w2<w1;
}

void solve()
{

    for(int i=0;i<milerozm;i++)
    {
      //  cout<<"\nSprawdzamy rozmiar i="<<i<<"\n";
       // cout<<"wartosci["<<i<<"].size()="<<wartosci[i].size()<<"\n";
        if(ilekontenerow[i]>wartosci[i].size())
        {
           // cout<<"Nie mozna\n";
            czymozna=false;
            return;
        }

        sort(wartosci[i].begin(),wartosci[i].end(),cmp);


        while(ilekontenerow[i]-->0)
        {
           wynik+=wartosci[i].back();
           //cout<<"Dodajemy do wyniku, obecnie: "<<wynik<<"\n";
           wartosci[i].pop_back();
        }

        for(int j=wartosci[i].size()-1;j-1>=0;j=j-2)
        {
            //cout<<"Laczmy pudelka, wszak: wartosci[i].size()="<<wartosci[i].size()<<"\n";
            wartosci[i+1].push_back(wartosci[i][j]+wartosci[i][j-1]);

        }






    }

}

int main()
{
    cin>>ilepudelek;
    for(int i=0;i<ilepudelek;i++)
    {
        cin>>r>>c;
        wartosci[r].push_back(c);
    }
    cin>>ilerozm;
    for(int i=0;i<ilerozm;i++)
    {
        cin>>r>>c;
        ilekontenerow[r]=c;
    }



    solve();

    if(czymozna==true)
    {
        cout<<wynik<<"\n";
    }
    else cout<<"NIE\n";





    return 0;
}