#include <bits/stdc++.h>

using namespace std;

int d;
long long wynik=0;
string s;
vector<long long> p;
vector<long long> ss;


vector<long long> kmp(string s)
{
    int j=-1;
    vector<long long> pref(s.size()+1,-1);
    for(int i=0;i<s.size();i++)
    {

        while(j>=0&&s[j]!=s[i])
        {
            j=pref[j];
        }
        pref[i+1]=++j;
     //   cout<<"pref["<<i+1<<"] = "<<pref[i+1]<<"\n";
    }


    return vector<long long>(pref.begin(),pref.end());



}




int main()
{
    cin>>d;
    cin>>s;
    s=s;


    p=kmp(s);

    for(int i=0;i<s.size();i++)
    {
      //  cout<<"i = "<<i<<"\n";
      //  cout<<"p["<<i+1<<"] = "<<p[i+1]<<"\n";
        //szukamy najkrotszych prefiksosufiksow
        if(p[i+1]==0)
        {

            ss.push_back(i+1);
        }

        else
        {
         //   cout<<"p["<<i+1<<"] = "<<p[i+1]<<" i ss["<<p[i+1]<<" = "<<ss[p[i+1]]<<"\n";
            ;
            ss.push_back(ss[p[i+1]-1]);
        }
        //cout<<"Dlugosc najkrotszego prefiksosufiksu ze slowa 1..."<<i+1<<": ss["<<i<<"] = "<<ss.back()<<"\n";
        if(ss.back()<=(i+1)/2)
        {
            //cout<<"\ndodalismy "<<i+1-ss.back()<<"\n\n";
            wynik+=i+1-ss.back();
        }





    }

    cout<<wynik<<"\n";










    return 0;
}