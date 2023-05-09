#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int n;
        cin>>n;
        int a[200000+9];
        int minOc = 33333333;
        int nonZer = 0;
        for(int j=0;j<n;j++) {
            cin>>a[j];
        }
        sort(a,a+ n);
        minOc = a[0];
        int minNonOC = -1;
        int minNonZeroOc = 33333333;
        for(int j=0;j<n;j++) {
            if(minNonOC == -1 && j<n-1 && a[j+1]-a[j] >1)
                minNonOC = a[j]+1;
            if(a[j] != 0)
                nonZer++;
            if(minNonZeroOc == 33333333 && a[j]!=0)
                minNonZeroOc = a[j];
        }
        if(minNonOC == -1)
            minNonOC = a[n-1]+1;
        int zer = n - nonZer;
        //cout<<"minOc: " <<minOc<<", minnonOc: "<<minNonOC<<"\n"<<", minNonZeroOc: "<<minNonZeroOc;
        if(zer <= (n+1)/2) {
            cout<<"0\n";
            continue;
        }
        if(nonZer > 1 && a[n-1] != minNonZeroOc) {
            cout<<min(minNonOC, minNonZeroOc)<<"\n";
            continue;
        }
        cout<<minNonOC<<"\n";




    }
}