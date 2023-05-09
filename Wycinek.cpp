#include <bits/stdc++.h>

using namespace std;
const int mdl=1e6;
pair<long long,int> sumy[mdl+3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dl,os;
    cin>>dl>>os;
    int liczba;
    long long dotsuma=0;
    for(int i=1;i<=dl;i++)
    {
        cin>>liczba;
        dotsuma+=liczba;
        sumy[i]=make_pair(dotsuma,i);
    }
    sort(sumy,sumy+dl+1);


    int j=0,wynik=0;


    for(int i=0;i<=dl;i++)
    {
        while(j<=dl&&sumy[j].first-sumy[i].first<=os) j++;
        if(j>=1&&sumy[j-1].first-sumy[i].first==os)
        wynik=max(wynik, sumy[j-1].second-sumy[i].second);

    }
        if(wynik==0) cout<<"BRAK \n";
        else cout<<wynik<<"\n";


    return 0;
}