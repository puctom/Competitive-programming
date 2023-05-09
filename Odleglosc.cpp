#include <bits/stdc++.h>

using namespace std;
const int mn=1e6;
int a[mn+5];
int ilemxmoznadod[mn+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int wynik=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            ilemxmoznadod[i]=a[i];
        }
        if(i>1)
        {
           ilemxmoznadod[i]=max(ilemxmoznadod[i-1]+1,a[i]);
        }

        wynik=max(wynik, ilemxmoznadod[i]+a[i]);



    }
    cout<<wynik<<"\n";
    return 0;
}