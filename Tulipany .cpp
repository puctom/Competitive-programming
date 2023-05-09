#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m=15000;
    int n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    set<int> wystepujace;
    int nr;
        for(int i=0;i<n;i++)
        {
            cin>>nr;
            wystepujace.insert(nr);
        }


        cout<<15000-wystepujace.size();

    return 0;
}