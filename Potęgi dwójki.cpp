#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int i=0;
    while(n>0)
    {
        long long poww=pow(2,i);
        cout<<poww <<"\n";
        i++;
        n/=2;
    }
    return 0;
}