#include <iostream>

using namespace std;
const long mod = 1e9+7;
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        long long n;
        cin>>n;
        //cout<<"test no. "<<i<<"\n";
        long long res = 1;
        res=(res*n)%mod;
        res=(res*(n-1))%mod;
        for(long long j=1;j<=n;j++) {
            //cout<<res<<"\n";
            res=(res*j)%mod;
        }
        cout<<res<<"\n";;
    }
    return 0;
}