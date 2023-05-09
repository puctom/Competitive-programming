#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char kk;
    int w;
    cin>>kk>>w;
    int k=kk-96;


    if((k==1&&w==1)||(k==8&&w==1)||(k==1&&w==8)||(k==8&&w==8))
    cout<<3;
    else
    {
        if((k==1||k==8)||(w==1||w==8)) cout<<5;
        else cout<<8;
    }


    return 0;
}