#include <bits/stdc++.h>
using namespace std;

const int miledolow=2e6+5;
int glebokosc[miledolow]; // wi
int iledolow;  // n
int dlugosc;  // d
long long ileworkow;  // p
long long sumaglebokosci[miledolow];
long long sumanadlugosci;
long long sumapom;
list<pair<int,long long>> q;  // lewy, suma na dlugosci

void upd(int prawy,long long &sumanadlugosci)
{
    sumanadlugosci+=glebokosc[prawy];
    if(prawy-dlugosc>=1)
        sumanadlugosci-=glebokosc[prawy-dlugosc];


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>iledolow>>ileworkow>>dlugosc;

    for(int i=1;i<=iledolow;i++)
    {
        cin>>glebokosc[i];
       // sumaglebokosci[i]=sumaglebokosci[i-1]+glebokosc[i];
    }


    int lewy=1;
    int wynik=dlugosc;

    for(int prawy=1;prawy<=iledolow;prawy++)
    {

        upd(prawy,sumanadlugosci);

        //  PRZESUWANIE PRAWEGO
        while(!q.empty()&&q.back().second<=sumanadlugosci)
            q.pop_back();

        q.push_back({prawy-dlugosc+1,sumanadlugosci});

        sumapom+=glebokosc[prawy];

        while(sumapom-q.front().second>ileworkow)
        {
            sumapom-=glebokosc[lewy];
            lewy++;
            if(q.empty()==false&&q.front().first<lewy)
                q.pop_front();
        }


        wynik=max(wynik,prawy-lewy+1);

    }

    cout<<wynik<<"\n";




    return 0;
}