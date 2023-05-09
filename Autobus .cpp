#include <bits/stdc++.h>

using namespace std;

const int mileprzystankow=1e5+5;
int pion,poziom,ileprzystankow;
tuple<int,int,int> przystanek[mileprzystankow]; // nr drogi pion, nr drogi poziom, ile pasazerow



const int p=21;
int tree[1<<p];
int pierwszylisc=1<<(p-1);

void wprowadz(int gdzie, int ile)
{
    gdzie+=pierwszylisc;
    tree[gdzie]=ile;
    gdzie=gdzie/2;
    while(gdzie>0)
    {
        tree[gdzie]=max(tree[2*gdzie],tree[2*gdzie+1]);
        gdzie/=2;
    }



}

int podajmax(int lewy, int prawy)
{
    int wynik;
    lewy+=pierwszylisc;
    prawy+=pierwszylisc;
    wynik=max(tree[lewy],tree[prawy]);

    while(lewy/2!=prawy/2)
    {
        if(lewy%2==0) wynik=max(wynik, tree[lewy+1]);
        if(prawy%2==1) wynik=max(wynik, tree[prawy-1]);
        lewy/=2;
        prawy/=2;
       // cout<<"Akt wynik: "<<wynik<<"\n";
    }

  // cout<<wynik<<"\n";

    return wynik;

}


void kompresuj()
{
    map <int,int> m;

    for(int i=0;i<ileprzystankow;i++)
    {
        m[get<0>(przystanek[i])]=0;
        m[get<1>(przystanek[i])]=0;
    }

    int ind=1;
    for(auto el: m)
        m[el.first]=ind++;

    for(int i=0;i<ileprzystankow;i++)
    {
        get<0>(przystanek[i])=m[get<0>(przystanek[i])];
        get<1>(przystanek[i])=m[get<1>(przystanek[i])];
    }



}

int main()
{


    cin>>pion>>poziom>>ileprzystankow;
    for(int i=0;i<ileprzystankow;i++)
    {

        cin>>get<0>(przystanek[i]);
        cin>>get<1>(przystanek[i]);
        cin>>get<2>(przystanek[i]);
    }

    kompresuj();

    sort(przystanek,przystanek+ileprzystankow);

    for(int i=0;i<ileprzystankow;i++)
    {
    //    cout<<"Przystanek nr: "<<i<<": el0: "<<get<0>(przystanek[i])<<", el1: "<<get<1>(przystanek[i])<<", el2: "<<get<2>(przystanek[i])<<"\n";
    }

    int wynik=0;

    for(auto prz: przystanek)
    {
       // cout<<"K: "<<get<0>(prz)<<", W: "<<get<1>(prz)<<"\n";
        int mozliwienajwiecej=podajmax(0, get<1>(prz));
      //  cout<<"Mozliwie najwiecej z przedzialu: "<<0<<", "<<get<1>(prz)<<" to: ";
        wprowadz(get<1>(prz),mozliwienajwiecej+get<2>(prz));
        wynik=max(wynik,mozliwienajwiecej+get<2>(prz));
      //  cout<<"Akt wynik, przeglad przyst: "<<wynik<<"\n";



    }

    cout<<wynik<<"\n";










    return 0;
}