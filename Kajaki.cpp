#include <bits/stdc++.h>

using namespace std;

const int mucz=3*1e4;
int waga[mucz+5];

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int limitob,lucz;
    cin>>limitob>>lucz;

    for(int i=1;i<=lucz;i++)
        cin>>waga[i];

    sort(waga+1,waga+lucz+1,cmp);

   // for(int i=1;i<=lucz;i++)
  //      cout<<waga[i];

    int licznikwcisnietych=0;
    for(int i=1;i<lucz-licznikwcisnietych;i++)
    {
       // cout<<"Sprawdzamy czy waga "<<i<<" + waga "<<licznikwcisnietych+1<<". najlzejszego"<<"="<<waga[i]<<"+"<<waga[lucz-licznikwcisnietych];
      //  cout<<" miesci sie w limice "<<limitob<<"\n \n";
        if(waga[i]+waga[lucz-licznikwcisnietych]<=limitob) licznikwcisnietych++;
    }

    cout<<lucz-licznikwcisnietych<<"\n";


    return 0;
}