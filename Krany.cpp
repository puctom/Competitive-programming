#include <bits/stdc++.h>

using namespace std;

const int mile=1e6+5;
int ile;
int ocz;
int temp[mile];
vector<int> kran;
int suma,sumapop;
double sr;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>ile>>ocz;
    for(int i=0;i<ile;i++)
    {
        cin>>temp[i];
        if(temp[i]>0)
            kran.push_back(temp[i]);
    }


    sort(kran.begin(),kran.end());

    if(kran.size()==0)
    {
        cout<<"0\n";
        return 0;
    }
        

    for(int i=int(kran.size()-1);i>=0;i--)
    {
       // cout<<"Akt suma: "<<suma<<" teraz rozwazymy temp: "<<kran[i]<<"\n";
        if(i==kran.size()-1)
        {
            if(kran[i]<ocz)
            {
                 cout<<"NIE\n";
                return 0;
            }
            else if(i==0)
            {
                cout<<"0\n";
                return 0;
            }
            suma=kran[i];
        }
        
        if(i<kran.size()-1)
        {
            suma+=kran[i];
            //cout<<"Akt suma: "<<suma<<" i najblizsza srednia: "<<double(suma)/(double(ile-i))<<"\n";
            if(double(suma)/(double(kran.size()-i))<ocz)
            {
                cout<<i+1<<"\n";
                return 0;
            }
             if(i==0)
                cout<<"0\n";
        }
    }

    return 0;
}