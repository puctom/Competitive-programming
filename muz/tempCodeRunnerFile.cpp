#include <iostream>
#include <math.h>

using namespace std;

int bitsOn[1000000+2];

int main() {
    bitsOn[1] = 1;
    bitsOn[2] =1 ;
    for(int i=1;i<=1000000;i++) {
        if(i - (i & (-i)) == 0) {
            bitsOn[i] = 1;
            continue;
        }
        int highest = floor(log2(i));
        
        bitsOn[i] = 1 + bitsOn[i-(1<<highest)];
       // cout<<"i: "<<i<<", high: " <<highest<< " bits:" <<bitsOn[i]<<"\n";
    }
    int n;
    cin>>n;
    int result = 0;
    int idx = 0;
    while(result < n) {
        result += bitsOn[idx+1];
        idx++;
    }

    if(result == n)
        cout<<idx;
    else 
        cout<<idx-1;
     cout<<"\n";
    int surplus = result-n;
    bool fixed = false;
    //cout<<"surplus: "<<surplus<<endl;
    for(int i=idx;i>=1;i--) {
        if(fixed == false && bitsOn[i] == surplus) {
            fixed = true;
            continue;
        }
        cout<<i<<" ";
            
    }

    return 0;
}