#include <iostream>

using namespace std;
const int max_N = 105;
int a[max_N];
int main() {
    int t,n;
    cin>>t;
    for(int i =0; i<t;i++) {
        for(int j=0;j<max_N;j++) {
            a[j] = 0;
        }
        cin>>n;
        for(int j=1;j<=n;j++)
            cin>>a[j];
        int last = (a[1]%2!=0);
        int cur;
        int res = 0;
        //cout<<last;
        for(int j=2;j<=n;j++) {
            cur = (a[j]%2!=0);
            if(cur != last) {
                last = cur;
                continue;
            }
                
            res++;
            
        }
        cout<<res<<"\n";


    }
    
    return 0;
}