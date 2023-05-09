#include <bits/stdc++.h>

using namespace std;

const int mlb=1e6;
int dlugosc[mlb+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int licznik=0;
    while(1)
    {
        cin>>dlugosc[licznik];
        if(dlugosc[licznik]==0) break;
        licznik++;
        if(licznik>47) break;

    }
    sort(dlugosc,dlugosc+licznik);

    for(int i=2;i<licznik;i++)
    {
        if(dlugosc[i]<dlugosc[i-1]+dlugosc[i-2])
        {
            cout<<dlugosc[i]<<" "<<dlugosc[i-1]<<" "<<dlugosc[i-2]<<"\n";
            break;
        }


        else if(i==licznik-1) cout<<"NIE\n";
    }







    return 0;
}