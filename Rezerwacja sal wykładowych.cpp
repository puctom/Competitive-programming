#include <bits/stdc++.h>

using namespace std;

const int mn=1e4+5;
int n;
int czas[mn];
pair<int,int> film[mn];


bool cmp(pair<int,int> f1,pair<int,int> f2)
{
    return f1.second<f2.second;
}

bool sprawdz(int i,int typ)
{
    if(film[typ].second<=film[i].first)
        return true;
    else return false;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>film[i].first>>film[i].second;
    }

    sort(film+1,film+n+1,cmp);
/*
    cout<<"Nowa kolejnosc\n";
    for(int i=0;i<=n;i++)
        cout<<"Film nr: "<<i<<", p: "<<film[i].first<<", k: "<<film[i].second<<"\n";
*/

    for(int i=1;i<=n;i++)
    {
        int lewy=0,prawy=i-1;
        int srodek;

        while(lewy<prawy)
        {
            srodek=(lewy+prawy+1)/2;
            if(sprawdz(i, srodek)==true)
            {
                lewy=srodek;
            }
            else
            {
                prawy=srodek-1;
            }
        }
        int j=(lewy+prawy+1)/2;

        czas[i]=max(czas[i-1],film[i].second-film[i].first+czas[j]);

        //cout<<"i="<<i<<", czas["<<i<<"] = "<<czas[i]<<"\n";
    }

    cout<<czas[n]<<"\n";


    return 0;
}