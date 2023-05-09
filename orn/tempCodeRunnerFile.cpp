#include <iostream>

using namespace std;

int h[50005];
int hCopy[50005];
const int maxH = 1e6;
const int minH = -1e6;
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>h[i];
        hCopy[i] = h[i];
    }
    int result = 999999;
    int currentResult = 0;
    for(int i=0;i<n-1;i++) {
        if(i%2 == 0) {
            if(hCopy[i]<hCopy[i+1])
                continue;
            currentResult++;
            hCopy[i+1] = maxH;
        }
        else {
            if(hCopy[i]>hCopy[i+1])
                continue;
            currentResult++;
            hCopy[i+1] = minH;
        }
    }
    result = currentResult;
    currentResult = 0;
    for(int i=0;i<n-1;i++) {
        if(i%2 == 1) {
            if(h[i]<h[i+1])
                continue;
            currentResult++;
            h[i+1] = maxH;
        }
        else {
            if(h[i]>h[i+1])
                continue;
            currentResult++;
            h[i+1] = minH;
        }
    }
    result = min(result, currentResult);
    cout<<result<<"\n";
}