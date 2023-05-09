#include <iostream>

using namespace std;

int main() {
    int n;
    string results;
    cin>>n;
    cin>>results;
    int score = 0;
    for(int i=0; i<10;i++) {
        for(int j=0;j<n/10;j++) {
            if(results[i*(n/10) + j]=='N')
                break;
            if(j==(n/10)-1)
                score++;
        }
    }
    cout<<score<<"\n";
    return 0;
}