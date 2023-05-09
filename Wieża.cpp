#include <bits/stdc++.h>

using namespace std;

const int msch=5*1e5;
const int mosob=5*1e5;

int wys[msch+5];
int wzrost[mosob+5];
int odp[mosob+5];

bool check(int rozwschodek, int aktwzrost)
{
    if(aktwzrost>wys[rozwschodek])
    {
       // cout<<"Osoba wys="<<aktwzrost<<" wejdzie na schodek "<<rozwschodek<<" o wysokosci: "<<wys[rozwschodek]<<"\n";
        return true;
    }


      //  cout<<"Osoba wys="<<aktwzrost<<" nie wejdzie na schodek "<<rozwschodek<<" o wysokosci: "<<wys[rozwschodek]<<"\n";

        return false;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int liczbasch, liczbaosob;
    cin>>liczbasch>>liczbaosob;
    int dotnajw=0;
    for(int i=0;i<liczbasch;i++)
    {
        cin>>wys[i];
        if(i>0)
        wys[i]=max(wys[i],wys[i-1]);

    }
   /* cout<<"\nZnowelizowane wysokosci schodkow:\n";
    for(int i=0;i<liczbasch;i++)
        cout<<i<<" "<<wys[i]<<"\n";
        */

    for(int i=0;i<liczbaosob;i++)
    {
       // cout<<"\n";
        int l=0,p=liczbasch;
        int sr;
        cin>>wzrost[i];
        while(l<p)
        {
            sr=(l+p)/2;
            if(check(sr, wzrost[i] )) l=sr+1;
            else p=sr;
        }

        odp[i]=(l+p)/2;


    }

    for(int i=0;i<liczbaosob;i++)
        cout<<odp[i]<<" ";











    return 0;
}