#include <bits/stdc++.h>

using namespace std;

int d,k;
int pomb; // ile b do danego miejsca
int rdod; //ile b potrzeba spod c
string s;
stack<int> b; // stos pozycji b
stack<pair<int,int>> c; // stos c, pozycja ile przed nia liter b
vector<vector<int>> odp;

int main()
{
    cin>>d>>k;
    cin>>s;

    for(int i=0;i<d;i++)
    {
      //  cout<<"Jestesmy na pozycji i="<<i<<" litera: "<<s[i]<<"\n";

        if(s[i]=='b')
        {
            b.push(i);
            pomb++;
        }

        if(s[i]=='c')
        {
            c.push({i,pomb});
            pomb=0;
        }

      //  cout<<"Sprawdzenie czy umiescimy ruch, c.empty()="<<c.empty()<<",  pomb = "<<pomb<<"\n";
        if(c.empty()==false&&pomb+c.top().second>=k)
        {
          vector<int> ruch;
          //  cout<<"Stos c jest niepusty i mamy wystarczajaco b\n";
            rdod=k-pomb;
            while(pomb-- >0)
            {
                ruch.push_back(b.top()+1);
                b.pop();
            }
           // cout<<"Do ruchu dodalismy pomb b\n";
            ruch.push_back(c.top().first+1);
            pomb=c.top().second-rdod;
            c.pop();
           // cout<<"Do ruchu dodalismy 1 c\n";
            while(rdod-- >0)
            {
                ruch.push_back(b.top()+1);
                b.pop();
            }
           // cout<<"Do ruchu dodalismy k-pomb b\n";
            //cout<<"pomb = "<<++pomb<<"\n";

        odp.push_back(ruch);
        }


    }


    reverse(odp.begin(),odp.end());

    for(auto ruchy: odp)
    {

        reverse(ruchy.begin(),ruchy.end());
        //cout<<"Odwrocono ruch\n";
        for(auto numery:ruchy)
        {
            cout<<numery<<" ";
        }
        cout<<"\n";

    }




    return 0;
}