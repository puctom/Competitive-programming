#include <bits/stdc++.h>

using namespace std;

const int mdni=1e6;
int tmin[mdni+5];
int tmx[mdni+5];


int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    list <pair<int,int>> lista;

    int n; //liczba dni
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>tmin[i]>>tmx[i];

    int wynik=1;

    int numer=1;

    for(int i=1;i<=n;i++)
    {
        //zrzucenie ostatnich
        while(lista.empty()==false&&lista.back().second<=tmin[i])
            lista.pop_back();

        lista.push_back({i,tmin[i]});
        // dodanie wiodącego

        while(lista.front().second>tmx[i])
        {

            if(lista.front().first==numer) lista.pop_front();
            numer++;
        }



        wynik=max(wynik,i-numer+1);
    }
    cout<<wynik<<"\n";



    return 0;
}