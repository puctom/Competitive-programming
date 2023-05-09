#include <bits/stdc++.h>

using namespace std;
int dl;
const int mliczba=1e6;
vector <int> pozycje[mliczba+5];
int liczba;

void solve()
{
    int oczdl;
    int last=0;
    int znak;
    bool odp=true;

    cin>>oczdl;
    for(int i=0;i<oczdl;i++)
    {
        cin>>znak;
        auto it=lower_bound(pozycje[znak].begin(),pozycje[znak].end(),last);
        if(it==pozycje[znak].end())
            odp=false;
        else last=(*it)+1;

    }

    cout<<(odp ? "TAK" : "NIE")<<"\n";


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);




    cin>>dl;
    for(int i=0;i<dl;i++)
    {
        cin>>liczba;
        pozycje[liczba].push_back(i);
    }

    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}