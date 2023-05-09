#include <bits/stdc++.h>

using namespace std;

int liczbamiast;
const int mxlm=5*1e4;
long long odl[mxlm+5];
//int dlugosccalk=0;
//int dystodzer[mxlm+5];
long long odp;

long long dist(int miasto1,int miasto2)
{
    if(miasto2>miasto1) swap(miasto1,miasto2);

   // odp=min(odl[miasto1]-odl[miasto2], odl[liczbamiast-1]-(odl[miasto1]-odl[miasto2]));
    //cout<<"\nKrotszy dystans miedzy miastem nr "<<miasto1<<" a miastem nr: "<<miasto2<<" to: "<<odp<<"\n";
   // return odp;
    return min(odl[miasto1]-odl[miasto2], odl[liczbamiast-1]-(odl[miasto1]-odl[miasto2]));

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>liczbamiast;

    for(int i=0;i<liczbamiast;i++)
    {
        cin>>odl[i];

        if(i>0) odl[i]+=odl[i-1];


    }
long long wynik=0;
 int j=0;
    for(int i=0;i<liczbamiast;i++)
    {



        while(dist(i,j)<dist(i,(j+1)%liczbamiast))
        j=(j+1)%liczbamiast;
         //  cout<<"Sprawdzilismy polaczenia dla miast nr "<<i<<" oraz "<<j<<"\n";




        wynik=max(wynik, dist(i,j));
    }


    cout<<wynik<<"\n";



    return 0;
}