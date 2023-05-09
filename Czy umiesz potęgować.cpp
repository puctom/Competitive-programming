#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    int r;
    r=a%10;
        if(r==0||r==1||r==6||r==5)
            cout<<r;
        if(r==4)
            if(b%2==0) cout<<6;
            else cout<<4;
        if(r==9)
              if(b%2==0) cout<<1;
            else cout<<9;
        if(r==2)
        {
        if(b%4==0) cout<<6;
        if(b%4==1) cout<<2;
        if(b%4==2) cout<<4;
        if(b%4==3) cout<<8;
        }

        if(r==8)
        {
        if(b%4==0) cout<<6;
        if(b%4==1) cout<<8;
        if(b%4==2) cout<<4;
        if(b%4==3) cout<<2;
        }
        if(r==3)
        {
        if(b%4==0) cout<<1;
        if(b%4==1) cout<<3;
        if(b%4==2) cout<<9;
        if(b%4==3) cout<<7;
        }

         if(r==7)
        {
        if(b%4==0) cout<<1;
        if(b%4==1) cout<<7;
        if(b%4==2) cout<<9;
        if(b%4==3) cout<<3;
        }



}