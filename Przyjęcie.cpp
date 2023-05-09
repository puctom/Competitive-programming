#include <bits/stdc++.h>

using namespace std;

const int mxrodz=1e5;

bool czyposaiadany[mxrodz+5];
//bool czyzly[mxrodz+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int liczbarodz;
    cin>>liczbarodz;
    int rodz;

    for(int i=0;i<liczbarodz;i++)
    {
        cin>>rodz;
        czyposaiadany[rodz]=true;

    }



     for(int i=1;i<=1e5;i++)
     {
         bool czyzla=false;

         for(int j=i;j<=1e5;j+=i)
         {
             if(czyposaiadany[j]==true)
             {
                 czyzla=true;
                 break;
             }


         }
         if(czyzla==false)
         {
             cout<<i<<"\n"; break;
         }

         else
         {
             if(i==1e5) cout<<i+1<<"\n";
         }
     }





    return 0;
}