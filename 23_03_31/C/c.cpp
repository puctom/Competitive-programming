#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int max_N = 2e5+5;
int sufMin[max_N];
int a[max_N];
int main() {
    int t;
    cin>> t;
    for(int i=0;i<t;i++) {
        int n;
        long long remCost, swapCost;
        cin>>n>>remCost>>swapCost;
        for(int j=0;j<n;j++) {
            sufMin[j] = 1e9+5;
            cin>>a[j];
        }
        sort(a, a+n);
        sufMin[n] = 1e9+5;
        vector<int> seq;
        seq.push_back(0);
        long long res = 0;
        for(int j=0;j<n-1;j++) {
            if((j<1 || a[j]>a[j-1])) {
                seq.push_back(a[j]);
            }
            else {
                res += remCost;
            }
                
        }
        if(a[n-1] > seq[seq.size()-1])
            seq.push_back(a[n-1]);
            else {
                res += remCost;
            }
        for(int j=0;j<seq.size(); j++) {
            cout<<seq[j]<< " ";
        }
        for(int j=seq.size()-1;j>0; j--) {
            cout<<"Considering removal of "<<seq.size() - j <<" element vs. inserting: "<<  seq[j]-seq[j-1] -1 << " elems  ";
            long long remT = remCost * (seq.size() - j );
            if(j>1)
                res+= min( remT , swapCost * (seq[j]-seq[j-1] -1)) ;
            else {
                res+= min(remT + swapCost,  swapCost * (seq[j]-seq[j-1] -1));
            }
            cout<<res<<"\n";
            if(remT <= swapCost * (seq[j]-seq[j-1] -1)) {
                seq.pop_back();
            }
            
        }
        cout<<"\n"<<res<<"\n\n";

    }

    return 0;
}