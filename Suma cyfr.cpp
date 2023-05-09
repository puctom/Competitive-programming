#include <bits/stdc++.h>

using namespace std;
int wyst[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,w=0;
    cin>>n>>k;
    int c;


        for(int i=0;i<n;i++)
        {
            cin>>c;
            wyst[c]++;
            w+=c;

        }

        for(int i=0;i<10;i++)
        {
            if(k>=wyst[i])
            {
                w+=wyst[i]*(9-i);
                k-=wyst[i];
            }
            else
            {
                w+=k*(9-i);
                k=0;
            }
        }
        cout<<w;
    return 0;
}