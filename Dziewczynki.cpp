#include <bits/stdc++.h>

using namespace std;
const int mxosob=1e6;
int osoba[mxosob+4];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int liczbaosob, zadanedziewczynki;
    cin>>liczbaosob>>zadanedziewczynki;

    for(int i=0;i<liczbaosob;i++)
        cin>>osoba[i];


    int wynik=liczbaosob+1;
    int l=0,p=0, licznik=0;

    for(int l=0;l<liczbaosob;licznik-=(osoba[l++]==0))
    {
        while(p<liczbaosob&&licznik<zadanedziewczynki)
        {
            licznik+=(osoba[p++]==0);
        }
        if(licznik==zadanedziewczynki) wynik=min(wynik,p-l);
    }

    if(wynik==liczbaosob+1) cout<<"NIE \n";
    else cout<<wynik-zadanedziewczynki<<"\n";







    return 0;
}