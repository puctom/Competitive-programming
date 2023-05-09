#include <iostream>

using namespace std;

const int maxile=100000+2;
int a[maxile];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i+=2) cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=1;i<n;i+=2) cout<<a[i]<<" ";
    return 0;
}