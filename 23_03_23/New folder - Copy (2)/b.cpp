#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        long long n;
        cin>>n;
        long long res = ceil((sqrt(n)-1.0)/2);
        //cout<<"We r checking if "<<(2*res+1)*(2*res+1)<< " > "<<n<<"\n";
        if((2*res+1)*(2*res+1) < n)
            res++;
        long long res2 = ceil(sqrt(n)*1.0/2);
        
        //cout<<"We r checking if "<<4*(res2)*(res2)<< " > "<<n<<"\n";
        if(4*(res2)*(res2) <= n-1)
            res2++;
        res = min(2*res, 2*res2-1);
        cout<<res<<"\n";
    }

    return 0;
}