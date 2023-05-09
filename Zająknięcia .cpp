#include <bits/stdc++.h>

using namespace std;

const int mdl=15e3+5;
int d1,d2;
int a[mdl];
int b[mdl];
int popwys1[mdl];
int popwys2[mdl];
int dp[2][mdl];
int memo[mdl];



int main()
{
    cin>>d1>>d2;
    for(int i=1;i<=d1;i++)
    {
        cin>>a[i];
        popwys1[i]=0;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]==a[j])
            {
                popwys1[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=d2;i++)
    {
        cin>>b[i];
        popwys2[i]=0;
        for(int j=i-1;j>=1;j--)
        {
            if(b[i]==b[j])
            {
                popwys2[i]=j;
                break;
            }
        }
    }

  /*  cout<<"Poprzednie wystapienia: \n";
    for(int i=1;i<=d1;i++)
        cout<<"i = "<<i<<" Poprzednie wystapienie znaku: "<<a[i]<<" to: "<<popwys1[i]<<"\n";

    for(int i=1;i<=d2;i++)
        cout<<"i = "<<i<<" Poprzednie wystapienie znaku: "<<b[i]<<" to: "<<popwys2[i]<<"\n";
*/
    int r;
    for(int i=1;i<=d1;i++)
    {
        r=i%2;
        //cout<<"Jestesmy w wierszu: "<<i<<", reszta: "<<r<<"\n";

        for(int j=1;j<=d2;j++)
        {

            if(a[i]==b[j]&&popwys1[i]>0&&popwys2[j]>0)
            {
                //cout<<"i = "<<i<<", j = "<<j<<"  - Ulepszamy o 2\n";
                dp[r][j]=memo[popwys2[j]]+2;
            }

            else
                dp[r][j]=0;

            dp[r][j]=max(max( dp[(i-1)%2][j],dp[r][j-1]   ), dp[r][j] );

        }
        for(int j=1;j<=d2;j++)
            if(a[i]==b[j])
            memo[j]=dp[(i-1)%2][j-1];


       // cout<<"\n";
    }

    cout<<dp[d1%2][d2]<<"\n";





    return 0;
}