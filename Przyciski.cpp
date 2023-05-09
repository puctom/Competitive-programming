#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int op,liczba[n],pmx=0,nmx=0;

    for(int i=0;i<n;i++)
        {
        liczba[i]=0;

        }

   //     for(int i=0;i<m;i++)





        for(int i=0;i<m;i++)
        {
cin>>op;

            if(op==n+1)
            {
               pmx=nmx;
               //nmx=0;
               continue;
          }
           

               if(liczba[op-1]<=pmx) liczba[op-1]=pmx;
               
                liczba[op-1]++;
               nmx=max(liczba[op-1],nmx);
               continue;
            

            


        }

        for(int w=0;w<n;w++)
        {
            if(liczba[w]<pmx) cout<<pmx<<" ";
            else cout<<liczba[w]<<" ";
        }

        cout<<endl;
    return 0;
}