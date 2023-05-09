#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int t;
    cin>> t;
    for(int i=0;i<t;i++) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int  minPos = -1;
        char minChar = '{';
        for(int j=n-1;j>=0;j--) {
            //cout<<(int)s[j]<<" " << (int)minChar  <<"\n";
            if(s[j] < minChar) {
                minChar = s[j];
                minPos = j;
            }
        }
       // cout<<minPos<<" "<<minChar<<"\n";
        string res = minChar + s.erase(minPos, 1);
        cout<<res<<"\n";

    }

    return 0;
}