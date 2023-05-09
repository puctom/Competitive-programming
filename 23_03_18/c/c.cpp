#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int n;
        cin>>n;
        int a[400000+9];
        for(int j=1;j<=2*n;j++) {
            cin>>a[j];
        }
        
            
        if(n==1) {
            cout<<min(abs(a[1]-a[2]), abs(a[1])+abs(a[2]))<<"\n";
            continue;
        }
        if(n==2) {
            int res0, res2, resEven;
            int closestTo2 = 0;
            res0 = res2 = resEven =0;
            for(int j=1;j<=4;j++) {
                res0+=abs(a[j]);
                res2+=abs(2-a[j]);
                resEven+=abs(1+a[j]);
                if(abs(2-a[j]) < abs(2-a[closestTo2]))
                    closestTo2 = j;
            }
            resEven=resEven - abs(1+a[closestTo2]) + abs(2-a[closestTo2]);
            cout<<min(res0,min(res2, resEven))<<"\n";
            continue;
        }
        if(n%2 == 1) {
            int res0 = 0;
            for(int j=1;j<=2*n;j++) {
                res0+=abs(a[j]);
            }
            cout<<res0<<"\n";
            continue;
        }
        if(n%2 == 0) {
            int res0, resEven;
            int closestTon = 0;
            res0 =resEven =0;
            for(int j=1;j<=2*n;j++) {
                res0+=abs(a[j]);
                resEven+=abs(1+a[j]);
                if(abs(n-a[j]) < abs(n-a[closestTon]))
                    closestTon = j;
            }
            resEven=resEven - abs(1+a[closestTon]) + abs(n-a[closestTon]);
            cout<<min(res0, resEven)<<"\n";
            continue;
        }
    }
}