#include <iostream>

using namespace std;
const int max_N = 105;
int a[max_N];
int main() {
    int t;
    cin>> t;
    for(int i=0;i<t;i++) {
        int n;
        cin>>n;
        bool res = false;
        for(int j=1;j<=n;j++) {
            cin>>a[j];
            if(a[j]<=j) {
                res = true;
                
            }

        }
        if(res == true) {
            cout<<"YES\n";
        }
        else {
            
            cout<<"NO\n";
        }

        


    }

    return 0;
}