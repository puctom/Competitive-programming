#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>n;
        int a[n+2];

        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }

        if(a[1]!=a[n]) cout<<n-1<<endl;
        else
        for(int j=2;j<=(n+1)/2;j++)
        {
            if(a[j]==a[j-1]&&a[n+1-j]==a[n+2-j])
            {
            if(j==(n+1)/2) cout<<"BRAK"<<endl;
            continue;
            }
            else {cout<<n-j<<endl; break;}
        }




    }

    return 0;
}