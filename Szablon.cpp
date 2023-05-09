#include <bits/stdc++.h>

using namespace std;

string s;

vector<int> pfsf;// Dlugosc najwiekszego prefiksosufiksu konczacego sie w miejscu i slowa s;
vector<int> kmp(string s)
{
    vector<int> pref(s.size()+1,-1);

    for(int i=0,j=-1; i<s.size();i++)
    {
        while(j>=0&&s[j]!=s[i]) j=pref[j];
            pref[i+1]=++j;
    }

    return vector<int>(pref.begin()+1,pref.end());
}

bool dziala(int dlugosc)
{
    //cout<<"\n\n\nSprawdzana dlugosc: "<<dlugosc<<" slowo pom: "<< s.substr(0,dlugosc)+'#'+s<<"\n";
    vector<int> pff=kmp(s.substr(0,dlugosc)+'#'+s);

  /*  for(int i=0;i<pff.size();i++)
    {
        cout<<"i: "<<i<<": pff: "<<pff[i]<<"\n";

    }
*/
    int nin=pff.size()-dlugosc;
  //  cout<<"nin: "<<nin<<"\n\n";
    for(int i=pff.size()-2;i>dlugosc;i--)
    {

        if(pff[i]==dlugosc) nin=i-dlugosc+1;
       // cout<<"W petli: aktualny nin: "<<nin<<" a i: "<<i<<"\n";
        if(nin>i) return false;
    }
    return true;

}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>s;

    pfsf=kmp(s);

  /*  for(int i=0;i<pfsf.size();i++)
    {
        cout<<i<<": "<<pfsf[i]<<"\n";
    }
*/
    vector<int> proby;
    for(int i=s.size();i>0;i=pfsf[i-1])
        proby.push_back(i);


   /* cout<<"Dostepne proby:\n";
    for(int i=0;i<proby.size();i++)
        cout<<"i="<<i<<": "<<proby[i]<<"\n";
*/
    for(int i=proby.size()-1;i>=0;i--)
    {
        if(i<proby.size()-1&&proby[i]<=proby[i+1]*2)
            continue;

        if(dziala(proby[i]))
        {
            cout<<proby[i]<<"\n";
            return 0;
        }

    }

    return 0;
}