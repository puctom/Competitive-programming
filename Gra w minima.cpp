#include <bits/stdc++.h>

using namespace std;


const int mn=1e6+5;
int n;
int k[mn];
int w[mn];


int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>k[i];

    sort(k+1,k+n+1);

    w[1]=k[1];
    for(int i=2;i<=n;i++)
    {
        w[i]=max(w[i-1],k[i]-w[i-1]);
    }

    cout<<w[n]<<"\n";





    return 0;
}