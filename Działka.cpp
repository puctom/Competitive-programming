#include <bits/stdc++.h>

using namespace std;

const int mdl=2e3+5;
int dl;
bool uz[mdl][mdl]; //uzytecznosc wiersz : kolumna
int h[mdl][mdl]; //wysokosc prostokata o dolnym polu : w wierusz
int wynik=0;


int polewwierszui(int h[])
{
    //dla kazdego elementu h tablicy musimy znalezc L i P

    vector<int> L(dl+1,0);
    vector<int> P(dl+1,0);
    int odp=0;
    stack<pair<int,int>> s; // wys, indeks
    s.push({-1,0});

    for(int i=1;i<=dl;i++)
    {
        while(s.empty()==false&&s.top().first>=h[i])
            s.pop();

        L[i]=s.top().second;
        s.push({h[i],i});
    }

    while(s.empty()==false)
        s.pop();

    s.push({-1,dl+1});
    for(int i=dl;i>=1;i--)
    {
        while(s.empty()==false&&s.top().first>=h[i])
            s.pop();

        P[i]=s.top().second;
        s.push({h[i],i});

    }

    for(int i=1;i<=dl;i++)
    {
        odp=max(odp,h[i]*(P[i]-L[i]-1));
    }


    return odp;


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>dl;
     //cout<<mdl;

     for(int i=1;i<=dl;i++)
     {
         for(int j=1;j<=dl;j++)
         {
             cin>>uz[i][j];
             h[i][j]=(uz[i][j]==1) ?  0 : h[i-1][j]+1  ;
         }

     }
     /*
     cout<<"\nWyswietlanie h: \n\n";
     for(int i=1;i<=dl;i++)
     {
          for(int j=1;j<=dl;j++)
            cout<<h[i][j]<<" ";

        cout<<"\n";
     }
*/

    for(int i=1;i<=dl;i++)
    {
        wynik=max(wynik, polewwierszui(h[i]));
    }

    cout<<wynik<<"\n";



    return 0;
}