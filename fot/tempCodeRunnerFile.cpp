#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int nMax = 3005;
vector<int> res[20];
int h[nMax];
int temp[nMax];
bool swapped[nMax];
int n;
map<int, int> mp;
bool isOk = false;

bool check() {
    for(int i=1;i<=n;i++) {
        if(h[i] != i)
            return false;
    }
    return true;

}
void myFill(bool arr[]) {
    for(int i=1;i<=n;i++)
        arr[i] = false;
}
void read() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>h[i];
        temp[i] = h[i];
    }
    sort(temp+1,temp+1+n);
    int cnt = 1;
    for(int i=1;i<=n;i++) {
        mp[temp[i]] = cnt++;
    }
    for(int i=1;i<=n;i++)
        h[i] = mp[h[i]];


}


int main() {
    
    
    read();
    
    int cnt = 0;
    isOk = check();
    while(isOk == false){
        myFill(swapped);
       
        for(int i=1;i<=n;i++) {
            if(swapped[i] == false && h[i] != i) {
                
                res[cnt].push_back(i);
                res[cnt].push_back(h[i]);
                swap(h[i], h[h[i]]);
                swapped[h[i]] = true;
                swapped[i] = true;
                
            }


                
        }
        isOk = check();
        cnt++;
    }

    cout<<cnt<<"\n";
    for(int i=0;i<cnt;i++) {
        cout<<res[i].size()<<"\n";
        for(int j=0;j<res[i].size()/2;j++)
            cout<<res[i][j*2]<<" ";
        for(int j=0;j<res[i].size()/2;j++)
            cout<<res[i][res[i].size()-1-2*j]<<" ";
        cout<<"\n";
    }

}