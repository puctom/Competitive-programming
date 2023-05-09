#include <bits/stdc++.h>

using namespace std;

const int mileb=25e4+5;
int ileb;
int h[mileb];
int d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>ileb;

    for(int i=1;i<=ileb;i++)
    {
        cin>>d>>h[i];
    }

    int licznik=0;
    stack<int> s;

    s.push(-1); //stos rozpoczetych wysokosci

    for(int i=1;i<=ileb;i++)
    {
        if(s.empty()==false&&s.top()<h[i])
        {
            licznik++;
            s.push(h[i]);
        }
        else if(s.empty()==false&&s.top()>h[i])
        {
            while(s.empty()==false&&s.top()>h[i])
                s.pop();

            if(s.empty()==false&&s.top()<h[i])
            {
                licznik++;
                s.push(h[i]);
            }
        }
    }

    cout<<licznik<<"\n";










    return 0;
}