#include <bits/stdc++.h>

using namespace std;

const int mdlug=1e6;
char dane[mdlug+5];
char ocz[mdlug+6];

const int mpotega=21;
int tree[1<<mpotega];
int nrplisc=1<<(mpotega-1);

vector <int> pozycjeznakow[555];

int zapytanie(int lewy ,int prawy )
{
    int ans=0;
    lewy+=(nrplisc+1);
    prawy+=(nrplisc+1);

    ans=tree[lewy];
    if(lewy!=prawy) ans+=tree[prawy];

    while(lewy/2!=prawy/2)
    {
        if(lewy%2==0) ans+=tree[lewy+1];
        if(prawy%2==1) ans+=tree[prawy-1];
        lewy/=2;
        prawy/=2;
    }

    return ans;
}

void wprowadz(int pozycja)
{
    pozycja+=nrplisc;
    while(pozycja>0)
    {
        tree[pozycja]+=1;
        pozycja/=2;
    }
}


int main()
{
  //  ios_base::sync_with_stdio(0);
 //   cout.tie(0);
   // cin.tie(0);
    int dlugosc;
    cin>>dlugosc;

    for(int i=1;i<=dlugosc;i++)
        cin>>dane[i];

    for(int i=1;i<=dlugosc;i++)
    {
        cin>>ocz[i];
        pozycjeznakow[ocz[i]].push_back(i);
    }

    for(char i='A';i<='Z';i++)
    {
        reverse(pozycjeznakow[i].begin(),pozycjeznakow[i].end());

    }
   // cout<<"Po odwroceniu.\n";
    long long wynik=0;
    int oczpozycja;
    for(int i=1;i<=dlugosc;i++)
    {
       // cout<<i<<"\n";
        oczpozycja=pozycjeznakow[dane[i]].back();
      //  cout<<"Rozpatrujemy pozycje: "<<i<<" znak: "<<dane[i]<<" a jego najblizsza pozycja to: "<<oczpozycja<<"\n";
        wynik+=(oczpozycja-i)+zapytanie(oczpozycja , dlugosc);

        wprowadz(oczpozycja);
        pozycjeznakow[dane[i]].pop_back();
    }


    cout<<wynik<<"\n";




    return 0;
}