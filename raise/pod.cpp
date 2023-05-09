#include <iostream>

using namespace std;

const int maxN = 5e5+5;
int s[maxN];
int minLeft[maxN];
int maxLeftIdx[maxN];
int maxRight[maxN];
int result[maxN];
int n, k;

void check(int range, int k) {
    
    if(k>=3) {
        if(maxLeftIdx[range] != range) {
            return true;
        }
        else {
            return check(range-1, k-1);
        }
    }


}

int main() {
    
    
    cin>>n>>k;
    minLeftIdx[1] = 1;
    maxLeftIdx[1] = 1;
    maxRightIdx[n-1] = n;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        if(i>1) {
            if(s[i] > s[maxLeftIdx[i-1]]) {
                maxLeftIdx[i] = i;
            }
            else 
                maxLeftIdx[i] = maxLeftIdx[i-1];
            if(s[i] < s[minLeftIdx[i-1]]) {
                minLeftIdx[i] = i;
            }
            else
                minLeftIdx[i] = minLeftIdx[i-1];
        }
    }
    for(int i=n-1;i>=0;i--) {
        if(i<n-1) {
            if(s[i] > s[maxRightIdx[i-1]]) {
                maxRightIdx[i] = i;
            }
            else
                maxRightIdx[i] = maxRightIdx[i+1];
        }
    }

    

    check(n, k);

        

    return 0;
}