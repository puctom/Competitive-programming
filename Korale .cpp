#include <bits/stdc++.h>

using namespace std;

const int mn=2e5+5;
int n;
int x;
vector<int> ciag;
vector<int> rciag;
long long hasze[mn];
long long rhasze[mn];
long long potegip[mn];
long long p=29;
long long mod=1e9+9;
long long wynik=0;
vector<int> rozw;


void obliczpotegi(int m)
{
    potegip[0]=1;
    potegip[1]=p;
    for(int i=2;i<=m;i++)
    {
        potegip[i]=potegip[i-1]*p%mod;
    }
}

void obliczhaszepref(vector<int> c)
{
    hasze[0]=0;
    for(int i=1;i<=c.size();i++)
    {
        hasze[i]=(((hasze[i-1]*p)%mod)+c[i])%mod;
    }
}

void robliczhaszepref(vector<int> rc)
{
    rhasze[0]=0;
    for(int i=1;i<=rc.size();i++)
    {
        rhasze[i]=(((rhasze[i-1]*p)%mod)+rc[i])%mod;

    }


}

int liczhasze(int l,int p)
{
    int odp=0;
    odp=((hasze[p]-(hasze[l-1]*potegip[p-l+1])%mod)+mod)%mod;
    return odp;
}

int rliczhasze(int l,int p)
{
    int odp=0;
    odp=((rhasze[p]-(rhasze[l-1]*potegip[p-l+1])%mod)+mod)%mod;
    return odp;
}



int main()
{
    cin>>n;
    obliczpotegi(n);

    ciag.push_back(0);
    rciag.push_back(0);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        ciag.push_back(x);
        rciag.push_back(x);
    }
    reverse(rciag.begin()+1,rciag.begin()+n+1);
  /*  for(int i=0;i<=n;i++)
    {
        cout<<i<<" wyraz rciagu: "<<rciag[i]<<"\n";
    }
    cout<<"\n";
    */
    obliczhaszepref(ciag);
    robliczhaszepref(rciag);
/*
   for(int i=0;i<=n;i++)
    {
        cout<<"Hasz do miejsca nr: "<<i<<" wynosi: "<<hasze[i]<<"\n";
    }
    for(int i=0;i<=n;i++)
    {

        cout<<"RHasz do miejsca nr: "<<i<<" wynosi: "<<rhasze[i]<<"\n";
    }

     cout<<"\n";
     /*/
    for(int i=1;i<=n;i++)
    {
        set<pair<int,int>> s;
        for(int j=1;j+i<=n+1;j+=i)
        {
            pair<int,int> hasz={liczhasze(j,j+i-1),rliczhasze(n-(j+i-1)+1,n-j+1)};
            if(hasz.first>hasz.second)
                swap(hasz.first,hasz.second);
            /*/cout<<"Jestesmy w miejscu: (DL) i="<<i<<", j="<<j<<" j+i-1="<<j+i-1;
            cout<<",   n-(j+i-1)-1 = "<<n-(j+i-1)+1<<",  n-j-1 = "<<n-j+1<<"  i nasza para to (SL1, SL_odw): "<<hasz.first<<"  "<<hasz.second<<"\n";
            /*/
            s.insert(hasz);
        }

        if(s.size()>wynik)
        {
            wynik=s.size();
            rozw.clear();
            rozw.push_back(i);
        }
        else if(s.size()==wynik)
            rozw.push_back(i);


      //  cout<<"Akt (i="<<i<<"): "<<wynik<<"\n";

    }

   // cout<<"Wynik: "<<wynik<<" osiagalny przez: "<<rozw.size()<<" dlugosci\n";
   cout<<wynik<<" "<<rozw.size()<<"\n";
    for(auto w: rozw)
        cout<<w<<" ";






    return 0;
}