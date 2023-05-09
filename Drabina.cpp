#include <bits/stdc++.h>
using namespace std;

/*

15
3 2
3 1
4 2
1 1
23 3
17 3
2 1
2 2
12 2
9 2
4 1
9 1
11 2
45 3
9 3


*/


const int mn=1e6+3;
const int mp=31;
int potegi[mp];
int liczbyf[mn];
int q;

int pomh,pommod;

struct zapytanie
{
    int wys;
    int p;
};

struct zapytanie pytanie[mn];

void obliczpotegi()
{
    potegi[0]=1;
    for(int i=1;i<mp;i++)
        potegi[i]=2*potegi[i-1];
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    obliczpotegi();
    cin>>q;

    liczbyf[0]=1;
        liczbyf[1]=1;
        for(int j=2;j<mn;j++)
            liczbyf[j]=(liczbyf[j-1]+liczbyf[j-2])%potegi[30];

    for(int i=1;i<=q;i++)
    {
        cin>>pomh>>pommod;
        pytanie[i].wys=pomh;
        pytanie[i].p=pommod;
        cout<<liczbyf[pytanie[i].wys]%potegi[pytanie[i].p]<<"\n";

    }





    return 0;
}