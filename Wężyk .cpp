#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i%2==0) cout<<n*i+j+1<<" ";
            else cout<<n*(i+1)-j<<" ";
        }
        cout<<"\n";
    }

    return 0;
}