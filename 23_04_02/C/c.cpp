#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
const int inf = 1e9+9;
using namespace std;
vector<int> linCoef;

int findInRange(double lower, double upper) {
   // cout<<"We are looking for a cooficient in range ("<<lower<<", "<<upper<<") \n";
    int noRes = -inf;
    int left = 0;
    int right = linCoef.size()-1;
    int mid;
    while(left<=right) {
       // cout<<"l: "<<left<<" r: "<<right<<"\n";
        mid = (left+right)/2;
       // cout<<linCoef[mid]<<"\n";
        if(linCoef[mid] <= lower) {
            left = mid+1;
            continue;
        }
        else if(linCoef[mid] >= upper) {
            right = mid-1;
            continue;
        }
        else {
        //    cout<<"found: "<<linCoef[mid]<<"\n";;
            return linCoef[mid];
        }
    }
   // cout<<"not found\n";
    return noRes;
}
int main() {
    int t;
    cin>> t;
    for(int i=0;i<t;i++) {
        linCoef.clear();
        int lines, parabolas;
        cin>>lines>>parabolas;
        
        for(int j=0;j<lines;j++) {
            int c;
            cin>>c;
            linCoef.push_back(c);
        }
        sort(linCoef.begin(), linCoef.end());
        for(int j=0;j<parabolas;j++) {
            int a,b,c;
            cin>>a>>b>>c;
            if(c<0) {
                cout<<"NO\n";
                continue;
            }
            double a1, a2;
            a1=sqrt(a)*sqrt(c)*2+b;
            a2=-sqrt(a)*sqrt(c)*2+b;
           // cout<<"a2: "<<a2<<", a1: "<<a1<<"\n";
            int res;
            if(-inf == findInRange(a2, a1)) {
                cout<<"NO\n";
             
               continue;
            }
            else {
                    cout<<"YES\n"<<findInRange(a2, a1)<<"\n";
                   continue;
            }
            // if(b==0) {
            //     //symetric 
            //     if(-inf == findInRange(0, a1)) {
            //         if(-inf == findInRange(a2,0)) {
            //             cout<<"NO\n";
            //             continue;
            //         }  
            //         else {
            //             cout<<"YES\n"<<findInRange(a2, 0)<<"\n";
            //             continue;
            //         }
            //     } 
            //     else {
            //         cout<<"YES\n"<<findInRange(0, a1)<<"\n";
            //         continue;
            //     }
                
            // }
            // else if(b>0) {
            //     //on the LEFT
            //     if(-inf == findInRange(a2, a1)) {
            //                 cout<<"NO\n";
            //                 continue;
            //             }   
            //             else {
            //                 cout<<"YES\n"<<findInRange(a2, a1)<<"\n";
            //                 continue;
            //             }
                    
            // }
            // else {
            //     //on the right
            //     if(a2<0) {
            //         if(-inf == findInRange(a2, a1)) {
            //                 cout<<"NO\n";
            //                 continue;
            //             }   
            //             else {
            //                 cout<<"YES\n"<<findInRange(a2, a1)<<"\n";
            //                 continue;
            //             }
            //         } 
                
            //     else {
            //         if(-inf == findInRange(a2, a1)) {
            //                 cout<<"NO\n";
            //                 continue;
            //         } 
            //         else {
            //             cout<<"YES\n"<<findInRange(a2, a1)<<"\n";
            //             continue;
            //         }
            //     }

            // }
        }

        

    }

    return 0;
}