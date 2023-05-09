#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t;
    cin>>t;
    int niezero;
    for(int i=t.size()-1;i>=0;i--)
        if(t[i]!='0') {niezero=i; break;}
      //  cout<<niezero<<endl;
    reverse(t.begin(), t.end());
    for(int i=t.size()-niezero-1;i<t.size();i++)
    cout<<t[i];
    return 0;
}