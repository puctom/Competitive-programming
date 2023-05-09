#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int t;
    cin>> t;
    for(int i=0;i<t;i++) {
        long long l, r;
        cin>>l>>r;
        int digL =ceil(log10(l));
        int digR =ceil(log10(r));

        if(digL != digR) {
            cout<<digL<<" "<< digR<<"\n";
            for(int j=0;j<digR;j++)
                cout<<9;
            cout<<"\n";
            continue;
        }

        for(int i=0;i<digL;i++) {
            int curL = l/ceil(pow(10,digL-i-1));
            int curR = r/ceil(pow(10,digL-i-1));
            cout<<i<<" : "<<curL << " "<<curR<<"\n";;
        }


    }

    return 0;
}