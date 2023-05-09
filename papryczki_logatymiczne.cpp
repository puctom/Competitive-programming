#include <bits/stdc++.h>
using namespace std;

int k, a;
int ans = 1;

int main() {
   scanf("%d", &k);
   
   for(int i = 0; i <= k; i++) {
       scanf("%d", &a);
       ans += (1 << i) * a;
   }
   printf("%d\n", ans);
}