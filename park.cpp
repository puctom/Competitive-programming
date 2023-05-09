#include <bits/stdc++.h>
//https://szkopul.edu.pl/problemset/problem/vFeShEOnczXpanZEaYQpDnus/site/?key=statement
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,mxl=0,mxp=0;
    cin>>n;
    int w[n+10],l[n+10],p[n+10];

    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        if(w[i]>mxl) mxl=w[i];
        l[i]=mxl;
    }

    for(int i=n;i>=1;i--)
    {
        if(w[i]>mxp)  mxp=w[i];
        p[i]=mxp;
    }
    for(int i=1;i<=n;i++)
        cout<<l[i]<<" "<<p[i]<<endl;











    return 0;
}