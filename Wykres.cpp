#include <bits/stdc++.h>

using namespace std;

const int mn=1e6+5;
int n;
int wynik[mn];
int dp[mn][3];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>wynik[i];

    for(int i=0;i<3;i++)
    {
        if(wynik[0]==i)
            dp[0][wynik[0]]=1;
        else dp[0][wynik[0]]=0;
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            //cout<<"nasza cyfra to: "<<wynik[i]<<", sprawdzamy czy jest rowna j="<<j<<"\n";
            if(wynik[i]!=j)
                dp[i][j]=dp[i-1][j];
            else
            {
               //cout<<"nasza cyfra to: "<<wynik[i]<<"\n";
                if(wynik[i]==0) dp[i][wynik[i]]=1;
                if(wynik[i]==1)
                {
                    dp[i][wynik[i]]=max( 1,1+dp[i-1][wynik[i]-1]);
                    //cout<<"wynik = 1, sprawdzamy liczbe: 1+dp[i-1][wynik[i]-1]="<<1+dp[i-1][wynik[i]-1]<<"\n";
                }
                if(wynik[i]==2)
                {
                   // cout<<"wynik = 2, sprawdzamy liczby: dp[i-1][wynik[i]-1] = dp["<<i-1<<"]["<<wynik[i]-1<<"]: "<<dp[i-1][wynik[i]-1]<<"\n oraz: ";
                   // cout<<"dp[i-1][wynik[i]-2] = "<<"dp["<<i-1<<"]["<<wynik[i]-2<<"]: "<<dp[i-1][wynik[i]-2]<<"\n";
                    dp[i][wynik[i]]=max( 1,max(1+dp[i-1][wynik[i]-1], 1+dp[i-1][wynik[i]-2] ));
                }


            }



        }



    }

    int odp=0;
    for(int i=0;i<3;i++)
        odp=max(odp,dp[n-1][i]);

    cout<<odp<<"\n";


    return 0;
}