#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c) cout<<a<<" + "<<b<<" == "<<c<<"\n";
    if(a-b==c) cout<<a<<" - "<<b<<" == "<<c<<"\n";
    if(a*b==c) cout<<a<<" * "<<b<<" == "<<c<<"\n";
    if(b!=0) {if(a/b==c) cout<<a<<" / "<<b<<" == "<<c<<"\n";}
    if(b!=0) {if(a%b==c) cout<<a<<" % "<<b<<" == "<<c<<"\n";}

    return 0;
}