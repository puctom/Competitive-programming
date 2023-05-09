#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int t;
    cin>> t;
    for(int i=0;i<t;i++) {
        int n;
        cin>>n;
        if(n%2 == 0) {
            cout<<"-1\n";
            continue;
        }
        int k = log2(n);
        cout<<k<<"\n";
        for(int j=k;j>=1;j--) {
            if(n&(1<<j)) {
                cout<<2<<" ";
            }
            else {
                cout<<1<<" ";
            }
        }
        cout<<"\n";


    }

    return 0;
}