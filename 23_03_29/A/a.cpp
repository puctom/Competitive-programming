#include <iostream>

using namespace std;

int lucky(int j) {
    int res = -1;
    int minD = 10;
    int maxD = -1;
    while(j>0) {
        int d = j%10;
        minD = min(minD, d);
        maxD = max(maxD, d);
        j/=10;
    }

    return maxD-minD;
}

int main() {
    ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

    int t;
    cin>> t;
    for(int i=0;i<t;i++) {
        int l,r;
        cin>>l>>r;
        if(r-l>=90) {
            int m = l/100;
            if(m*100+90>=l) {
                cout<<m*100+90<<"\n";
                continue;
            }
            else {
                cout<<m*100+109<<"\n";
                continue;
            }
        }
            int res = -1;
            int maxans = -1;
        for(int j=l;j<=r;j++) {
           // cout<<j<<" L: "<<lucky(j)<<"\n";
           int cur = lucky(j);
            if(cur > maxans) {
                res = j;
                maxans = cur;
            }

        }
        cout<<res<<"\n";


    }

    return 0;
}