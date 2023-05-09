#include <iostream>

using namespace std;
int main() {
    int t;
    cin>> t;
    for(int i=0;i<t;i++) {
        int n;
        cin>>n;
        int a;
        int xres = 0;
        for(int j=0;j<n;j++) {
            cin>>a;
            xres = xres ^ a;

        }
        if(n%2 == 0) {
            if(xres == 0) {
                cout<<"0\n";
                continue;
            }
            else {
                cout<<"-1\n";
                continue;
            }
        }
        else {
            cout<<xres<<"\n";
        }


    }

    return 0;
}