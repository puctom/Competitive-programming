#include <bits/stdc++.h>

using namespace std;
int silnia(int a){
int w=1;
for(int i=1;i<=a;i++) w*=i;
return w;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<silnia(n);

    return 0;
}