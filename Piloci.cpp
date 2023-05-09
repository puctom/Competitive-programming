#include <bits/stdc++.h>

using namespace std;

deque<pair<int,int>> minima, maksima; // POMIAR  ,  INDEKS
int ilepomiarow,pomiar;
int tolerancja;
int odp=0;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>tolerancja>>ilepomiarow;
    int lewy=0;

    for(int i=0;i<ilepomiarow;i++)
    {
        cin>>pomiar;

        while(minima.size()>0&&minima.front().first>=pomiar)
            minima.pop_front();

        minima.push_front({pomiar,i});

        while(maksima.size()>0&&maksima.front().first<=pomiar)
            maksima.pop_front();

        maksima.push_front({pomiar,i});


       // cout<<"Obecnie poczatki to: \nminimum, wartosc: "<<minima.back().first<<" indeks: "<<minima.back().second;
        //cout<<"\nmaksimum, wartosc: "<<maksima.back().first<<" indeks: "<<maksima.back().second<<"\n";


        while(maksima.back().first-minima.back().first>tolerancja)
        {
            //cout<<"Nie mieszcza sie w tolerancji, wiec usuwamy\n";
            if(maksima.back().second==lewy) maksima.pop_back();
            if(minima.back().second==lewy) minima.pop_back();
            lewy++;
            //cout<<"Po usuwaniu, wskaznik lewy: "<<lewy<<"  a i: "<<i<<" , odl: "<<i-lewy+1<<"\n";
        }
        //cout<<"Obecnie poczatki to: \nminimum, wartosc: "<<minima.back().first<<" indeks: "<<minima.back().second;
        //cout<<"\nmaksimum, wartosc: "<<maksima.back().first<<" indeks: "<<maksima.back().second<<"\n";
        //cout<<"Lewy: "<<lewy<<",  i: "<<i<<"  odl: "<<i-lewy+1<<"\n";
        odp=max(odp,i-lewy+1);
        //cout<<"\n";

    }
    cout<<odp<<"\n";





    return 0;
}