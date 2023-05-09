#include <bits/stdc++.h>

using namespace std;

const int mlsch=5*1e5;
const int mlosob=5*1e5;

int h[mlsch+5];
int wzrost[mlosob+5];

bool check(int wzrost, int hsprawdzane)
{
    if(wzrost<=hsprawdzane) return false;
    if(wzrost>hsprawdzane) return true;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int liczbaschodow;
    int liczbaosob;

    cin>>liczbaschodow>>liczbaosob;

    for(int i=1;i<=liczbaschodow;i++)
    {
        cin>>h[i];
        if(i>1) h[i]=max(h[i-1],h[i]);
    }

    for(int i=1;i<=liczbaosob;i++)
        cin>>wzrost[i];


    int l=1,p=liczbaschodow;
    int sr;


    for(int i=1;i<=liczbaosob;i++)
    {
      //  cout<<"Sprawdzamy osobe: "<<i<<"  o wzroscie: "<< wzrost[i]<<"    mozliwy przedzial to: "<<l<<" "<<p<<" \n";
        while(l<p&&p!=0)
        {

            sr=(l+p+1)/2;
          //  cout<<"Sprawdzamy przedzial: "<<l<<"  "<<p<<" i czy wejdzie na schodek nr: "<<sr<<" o h="<<h[sr]<<"\n";
            if(check(wzrost[i],h[sr])==true)
            {
                l=sr;
            //    cout<<"Wejdzie, zmieniamy przedzial na: "<<l<<"  "<<p<<"\n";
            }
            else
            {
                p=sr-1;
              //  cout<<"NIE wejdzie, zmieniamy przedzial na: "<<l<<"  "<<p<<"\n";

            }




        }
        if(p!=0) cout<<(l+p+1)/2<<" ";
        if(p==0) cout<<0<<" ";
       // cout<<"\n";
        p=(l+p+1)/2-1;
        l=1;

    }






    return 0;
}