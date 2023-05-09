#include <bits/stdc++.h>

using namespace std;

const int miletaksowek=500005;
long long m,d;
long long iletaksowek;
long long zasieg[miletaksowek];
long long aktpoz;
long long ostzasieg=-1;
long long wynik;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>m>>d;
    cin>>iletaksowek;
    long long wym=m-d;
    vector<long long> z;

    for(int i=1;i<=iletaksowek;i++)
        cin>>zasieg[i];

    sort(zasieg+1,zasieg+iletaksowek+1);

    for(int i=1;i<=iletaksowek;i++)
    {
        if(ostzasieg==-1&&zasieg[i]>=m-d)
        {
            ostzasieg=zasieg[i];
        }
        else
        {
            z.push_back(zasieg[i]);
        }
    }

    if(ostzasieg==-1)
    {
        cout<<"0\n";
        return 0;
    }
    else if(ostzasieg>=m+d)
    {
        cout<<"1\n";
        return 0;
    }

    long long iledod=d;


    for(int i=z.size()-1;i>=0;i--)
    {
        iledod-=max((long long)0,z[i]-iledod);

        if(-iledod>=m-d)
        {
            cout<<z.size()-i<<"\n";
            return 0;
        }
        if(-iledod*2+ostzasieg>=m-d)
        {
            cout<<z.size()-i+1<<"\n";
            return 0;

        }


    }




        //if(wynik!=0)
        cout<<wynik<<"\n";
        //else cout<<"NIE\n";




    return 0;
}