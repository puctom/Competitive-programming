#include <bits/stdc++.h>

using namespace std;

const int mn=1e6+5;
int n;
int liczba[mn];
int dp[mn];
int wynik;
int pomm=-1e6-6;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>liczba[i];

    for(int i=0;i<n;i++)
    {
        pomm=-1e6-6;
        for(int j=1;(j<=6&&i-j>=0);j++)
        {
            pomm=max(pomm,dp[i-j]);
        }
      //  cout<<"pomm = "<<pomm<<"\n";
        if(i>0)
        dp[i]=pomm+liczba[i];
        else dp[i]=liczba[i];
       // cout<<"dp["<<i<<"] = "<<dp[i]<<"\n";
    }

    cout<<dp[n-1]<<"\n";




    return 0;
}