#include <bits/stdc++.h>

using namespace std;
int sprawdzacz=0;


const int mwymogi=1e6;
int ile[mwymogi+3];
int zapotrz[mwymogi+3];
int stan[mwymogi+3];
int kolor[mwymogi+3];


void sprawdzian(int aktkolor,int corobim)
{
    if(zapotrz[aktkolor]==stan[aktkolor]) sprawdzacz--;
    stan[aktkolor]+=corobim;
    if(zapotrz[aktkolor]==stan[aktkolor]) sprawdzacz++;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dl, wk,wkolor;
    long long wymdlugosc=0;
    cin>>dl>>wk;

    for(int i=0; i<wk;i++)
    {
        cin>>ile[i];
        wymdlugosc+=ile[i];

    }

    for(int i=0;i<wk;i++)
    {
        cin>>wkolor;
        zapotrz[wkolor]=ile[i];
    }

    for(int i=0;i<dl;i++) cin>>kolor[i];
    int wynik=0;
    if(wymdlugosc>dl)
    {
        //cout<<0<<"\n";
        goto koniec;
    }


    for(int i=0;i<wymdlugosc;i++)
    {
        sprawdzian(kolor[i],1);
    }


    for(int i=wymdlugosc-1;i<dl;i++)
    {
        if(i>=wymdlugosc)
        {
            sprawdzian(kolor[i],1);
            sprawdzian(kolor[i-wymdlugosc],-1);

        }

        if(sprawdzacz==wk) wynik++;
    }










    koniec:;
    cout<<wynik<<"\n";
    return 0;
}