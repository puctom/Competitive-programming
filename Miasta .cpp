#include <bits/stdc++.h>

using namespace std;

const int mmiast=1e6;
int kierunek[mmiast+5];
int ilewlewo[mmiast+5];
int ilewprawo[mmiast+5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int liczbamiast;
    cin>>liczbamiast;

    for(int i=1;i<liczbamiast;i++)
        cin>>kierunek[i];


    for(int i=1;i<liczbamiast;i++)
    {

        if(kierunek[i]>0)
        {
            ilewlewo[i+1]=ilewlewo[i]+1;
        }
        else ilewlewo[i+1]=0;
      //  cout<<"Z miasta "<<i+1<<" mozna dojechac do "<<ilewlewo[i+1]<<" miast w lewo\n.";
    }

    for(int i=liczbamiast-1;i>=1;i--)
    {

        if(kierunek[i]!=1)
        {
            ilewprawo[i]=ilewprawo[i+1]+1;
        }
        else ilewprawo[i]=0;
      //  cout<<"Z miasta "<<i+1<<" mozna dojechac do "<<ilewlewo[i+1]<<" miast w lewo\n.";
    }

    for(int i=1;i<=liczbamiast;i++)
    {
        cout<<ilewlewo[i]+ilewprawo[i]<<" ";
    }


    return 0;
}