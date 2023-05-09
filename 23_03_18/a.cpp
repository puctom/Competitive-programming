#include <iostream>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int res=0;
        int dx = c-a;
        int dy = d-b;
        if(dy<0||dx>dy) {
            cout<<-1<<"\n";
            continue;
        }
        res = dy + (dy-dx);

        cout<<res<<"\n";
    }
    return 0;
}