#include <bits/stdc++.h>

using namespace std;
const int mnap=150;
string nap[mnap+5];

bool cmp(string a, string b)
{
//return (a.size() == b.size() ? a < b : a.size() < b.size());
return (a.size() == b.size() ? a< b : a.size()<b.size());
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>nap[i];

    sort(nap,nap+n,cmp);

    for(int i=0;i<n;i++)
        cout<<nap[i]<<"\n";

    return 0;
}