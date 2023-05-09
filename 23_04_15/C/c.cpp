#include <iostream>
#include <set>
#include <vector>

using namespace std;
const int maxN = 2e5+5;
int a[maxN];
set<int> ac;
int find(int n, int a[], int sought, bool last = false) {
    if(last == false) {
        for(int i=0;i<n;i++) {
            if(a[i] == sought)
                return i;
        }
        return -1;
    }
    else {
        for(int i=n -1 ;i>=0;i--) {
            if(a[i] == sought)
                return i;
        }
        return -1;
    }
}

int mex( set<int> a, int n) {
  //  cout<<a.size()<<"\n\n";
    vector<int> v ;
    v.clear();
    copy(a.begin(), a.end(), std::back_inserter(v));
    for(int i=0;i<v.size();i++) {
     //   cout<<i<<"\n";
        if(v[i] != i)
            return i;
    }

    return v.size();
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin>>n;
        ac.clear();
        for(int j=0;j<n;j++)  {
            cin>>a[j];
            ac.insert( a[j]);
        }
            
        int oldMEX = mex(ac, n);
      //  cout<<"OldMEX: "<<oldMEX<<"\n";
        int firstNew = find(n, a, oldMEX+1);
        int lastNew = find(n, a, oldMEX+1, true);
       // cout<<"f: "<<firstNew<<", l: "<<lastNew<<"\n";
        if(firstNew == -1) {
            if(oldMEX != n) {
                cout<<"Yes\n";
                continue;

            }
            else
            cout<<"No\n";

        }
        else {
            set<int> replaced;
            replaced.clear();
            for(int j =0;j<n;j++) {
                if(j>=firstNew && j<=lastNew)
                    replaced.insert(oldMEX);
                else {
                    replaced.insert(a[j]);
                }

            }
            if(mex(replaced, n) == oldMEX+1)
                cout<<"Yes\n";
            else 
                cout<<"No\n";
        }
    }

    return 0;
}