#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long max_M = 300009;

int main() {
    ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
    long long  t;
    cin>> t;
    for(long long  i=0;i<t;i++) {
        long long  n,m;
        cin>>n>>m;
        vector<long long > cols[max_M+5];
        long long  rowSum[max_M];
        for(long long  j=0;j<n;j++) {
            rowSum[j] = 0;
            for(long long  k=0;k<m;k++) {
                if(j==0)
                    cols[k].clear();
                long long  a;
                cin>>a;
                cols[k].push_back(a);
            }
        }
        for(long long  j=0;j<m;j++) {
            sort(cols[j].begin(), cols[j].end());
            // for(long k=0;k<n;k++) {
            //     cout<<cols[j][k]<<" ";
            // }
            // cout<<"\n";
        }
        for(long long  j=0;j<m;j++) {
            for(long long  k=0;k<n;k++) {
                rowSum[k]+=cols[j][k];
            }
        }
        long long  res = 0;
        for(long long  k=0;k<n;k++) {
         //   cout<<"rs["<<k<<"] = "<<rowSum[k]<<" * "<<n-1-2*(n-1-k)<<"\n";
            res+=(long long )rowSum[k]*(n-1-2*(n-1-k));
        }
        cout<<res<<"\n";
        


    }

    return 0;
}