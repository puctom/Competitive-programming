#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a*b*c<<"\n"<<2*(a*b+b*c+c*a);
    return 0;
}