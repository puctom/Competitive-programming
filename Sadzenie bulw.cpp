#include <bits/stdc++.h>

using namespace std;
const int mxn=1e5+5;
int poj[mxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int lpol;
    int lbulw;
    long long wynik=0;
    cin>>lpol;
    for(int i=0;i<lpol;i++)
    {
        cin>>poj[i];
    }
    sort(poj,poj+lpol);
    cin>>lbulw;
    for(int i=lpol-1;i>=0;i--)
    {
        if(lbulw>=poj[i])
        {
           wynik+=(poj[i]*poj[i]) ;
           lbulw-=poj[i];
        }
        else
        {
            wynik+=lbulw*lbulw;
             break;
        }
           

    }
    cout<<wynik<<"\n";



    return 0;
}