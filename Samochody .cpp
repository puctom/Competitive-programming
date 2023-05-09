#include <iostream>

using namespace std;

int main()
{


   ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);
    int n;

    long long licznikzer=0,wynik=0;
    char s;
    cin>>n;
        for(int i=0;i<n;i++)
        {

            cin>>s;

            if(s=='0') licznikzer++;
            if(s=='1') wynik+=licznikzer;
        }
      cout<<wynik;

    return 0;
}