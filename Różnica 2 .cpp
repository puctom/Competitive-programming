#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,r;
    cin>>n>>r;
    int czy,a,liczbapar=0;

    set<int> liczby;

        for(int i=0;i<n;i++)
        {
            cin>>czy;

            cin>>a;
            if(czy==1)
            {
                liczby.insert(a);
                if(liczby.find(a-r)!=liczby.end()) liczbapar++;
                if(liczby.find(a+r)!=liczby.end()) liczbapar++;
            }

            else
            {
                liczby.erase(a);
                if(liczby.find(a-r)!=liczby.end()) liczbapar--;
                if(liczby.find(a+r)!=liczby.end()) liczbapar--;

            }

            liczbapar!=0 ? cout<<"TAK\n" : cout<<"NIE\n";


        }
    return 0;
}