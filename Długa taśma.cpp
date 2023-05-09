#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6;
int a[maxn+3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int najmn=1e9;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        najmn=min(najmn, a[i]);

    }
    double najmn2=najmn;
    cout<<setprecision(2)<<fixed<<najmn2;

    return 0;
}