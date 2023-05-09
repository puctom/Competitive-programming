#include <bits/stdc++.h>

using namespace std;

const int mn=1e5+5;
int n;
int w[mn];
int wynik;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        wynik+=w[i];
    }


    sort(w,w+n);

    for(int i=0;i<n/2;i++)
    {
        wynik+=w[n-1-i]-w[i];

    }
    cout<<wynik<<"\n";

    return 0;
}