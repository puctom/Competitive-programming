#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        map<char, int> occ;
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++) {
            occ[s[j]]++;
        }
        // for(auto e: occ) {
        //     cout<<e.first<<"-> "<<e.second<<"\n";
        // }
        if(occ.size() >=3) {
            cout<<"4\n";
            continue;
        }
        if(occ.size() == 1) {
            cout<<"-1\n";
            continue;
        }
        if(occ.size() == 2) {
            if(occ[s[0]] == 2) {
                cout<<"4\n";
                continue;
            }
            else {
                cout<<"6\n";
            }
        }
        

    }

    return 0;
}

/*
#include <iostream>

using namespace std;

int main() {


    return 0;
}
*/