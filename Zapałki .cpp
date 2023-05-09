#include <bits/stdc++.h>

using namespace std;

const int mzap=1e6;
int h[mzap+5];
int ilezlewej[mzap+5];
int ilezprawej[mzap+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int liczbazapalek;
    cin>>liczbazapalek;

    for(int i=1;i<=liczbazapalek;i++)
    {
        cin>>h[i];

        if(i>1)
        {
            if(h[i-1]<=h[i]) ilezlewej[i]=ilezlewej[i-1]+1;
            else ilezlewej[i]=0;
        }
        //cout<<"Dla "<<i<<" zapalki, z lewej mamy: "<<ilezlewej[i]<<"\n";
    }
   // cout<<"\n";
    int odp=0;
    for(int i=liczbazapalek;i>=1;i--)
    {
        if(i<liczbazapalek)
        {
        if(h[i+1]<=h[i]) ilezprawej[i]=ilezprawej[i+1]+1;
        else ilezprawej[i]=0;
        }
      //  cout<<"Dla "<<i<<" zapalki, z praej mamy: "<<ilezprawej[i]<<"\n";

        odp=max(odp,1+ilezprawej[i]+ilezlewej[i]);
    }
    cout<<odp<<"\n";


    return 0;
}