#include <bits/stdc++.h>

using namespace std;

const int mklockow=1e6;
int wys1[mklockow+5];
int wys2[mklockow+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    long long h1=0,h2=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>wys1[i];
        h1+=wys1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>wys2[i];
        h2+=wys2[i];
    }
   // cout<<h1<<"   "<<h2<<"\n";
    int nrostklocka1=n-1;
    int nrostklocka2=m-1;
    while(h1!=h2)
    {
        if(h1>h2)
        {
            h1-=wys1[nrostklocka1];
            nrostklocka1--;

        }
        else
        {
            h2-=wys2[nrostklocka2];
            nrostklocka2--;
        }
    }

    cout<<n+m-(nrostklocka1+nrostklocka2)-2<<"\n";







     return 0;
}