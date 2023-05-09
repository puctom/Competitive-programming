#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k,w,m;

    cin>>k>>w>>m;

    if(k>=w) cout<<"0";
    else
    {

         cout<<(w-k+m-1)/m;
    }



    return 0;
}