#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int n, k;
        cin>>n>>k;
        if(k==0) {
            for(int j=0;j<n;j++) 
                cout<<-100<<" ";
            cout<<"\n";
            continue;
        }
        int temp = 0;
        int rem = -1;
        int pos = -1;
        for(int j=0;j<n;j++) {
            temp+=(n-j);
            if(temp >= k) {
                pos = j;
                rem = k - (temp - (n-j));
                break;
            }
        }
       // cout<<"pos: "<<pos<<", rem: "<<rem<<"\n";
        for(int j=0;j<n;j++) {
            if(j<pos)
                cout<<"1000 ";
            else if(j==pos) 
                cout<<rem<<" ";
            else if(j<pos+rem)
                cout<<"-1 ";
            else cout<<-32<<" ";
            
        }
        cout<<"\n";
    }


    return 0;
}
