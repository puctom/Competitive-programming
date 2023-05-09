#include <bits/stdc++.h>

using namespace std;

const int milekontodw=1e5+5;
int ilekont,ileodw;
int poj[milekontodw],mas[milekontodw];


bool sprawdz(int typile)
{
    //cout<<"\n\nSprawdzamy typ: "<<typile<<"\n";
    int pom;
    priority_queue<int> q; // kolejka wolnych miejsc w kontenerach
    for(int i=1;i<=ilekont;i++)
        q.push(poj[i]);

    for(int i=typile;i>=1;i--)
    {
        //cout<<"Chcemy wstawic odwaznik nr: "<<i<<" masa: "<<mas[i]<<"\n";
        //cout<<"Na ten moment najwieksza dostepna pojemnosc: "<<q.top()<<"\n";
        if(mas[i]>q.top())
            return false;
        if(mas[i]<=q.top())
        {
            pom=q.top();
            q.pop();
            q.push(pom-mas[i]);
        }

    }

    //cout<<"Liczba "<<typile<<" dziala\n";

    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>ilekont>>ileodw;

    for(int i=1;i<=ilekont;i++)
        cin>>poj[i];
    for(int i=1;i<=ileodw;i++)
        cin>>mas[i];

    sort(mas+1,mas+ileodw+1); // postrotwane rosnaco

    int lewy=0, prawy=ileodw,s;

    while(lewy<prawy)
    {
        s=(lewy+prawy+1)/2;
        //cout<<"Sprawdzamy s = "<<s<<"\n";

        if(sprawdz(s)==true)
        {
            lewy=s;
        }
        else
        {
            prawy=s-1;
        }




    }

    cout<<(lewy+prawy)/2<<"\n";




    return 0;
}