#include <bits/stdc++.h>

using namespace std;

const int mliczbapoziomow=3*1e5;
const int mliczbakrazkow=3*1e5;
int poziomy[mliczbapoziomow+4];
int krazki[mliczbakrazkow+4];
int minima[mliczbapoziomow+4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int liczbapoziomow, liczbakrazkow;
    cin>>liczbapoziomow>>liczbakrazkow;
    int numer=0;
    int wynik=0;
    for(int i=0;i<liczbapoziomow;i++)
    {
        cin>>poziomy[i];
        if(i==0) minima[i]=poziomy[i];
        else minima[i]=min(minima[i-1],poziomy[i]);
    }

    for(int i=0;i<liczbakrazkow;i++)
        cin>>krazki[i];

    for(int i=liczbapoziomow-1;i>=0;i--)
    {
      //  cout<<"Sprawdzamy krazek "<<krazki[numer]<< " na poziom "<<i+1<<" o minimum "<<minima[i]<<"\n \n";
        if(krazki[numer]<=minima[i]) numer++;
        if(numer==liczbakrazkow)
        {
            wynik=i+1;
            break;
        }
    }

    cout<<wynik<<"\n";


    return 0;
}