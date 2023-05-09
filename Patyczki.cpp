#include <bits/stdc++.h>

using namespace std;

const int milekolorow=55;
int ilekolorow;
int pomile,pomdl;
pair<int,int> t[3];
vector<pair<int,int>> pat;


bool upd(pair<int,int> para)
{
    
    for(int i=0;i<3;i++)
    {
        if(t[i].second==para.second)
        {
            t[i]=para;
            break;
        }
        if(i==2)
        {
            t[0]=t[1];
            t[1]=t[2];
            t[2]=para;
        }
    }
    sort(t,t+3);

    if(t[0].first!=-1&&t[0].first+t[1].first>t[2].first)
    {
        for(int j=0;j<3;j++)
        {
            cout<<t[0].second<<" "<<t[0].first<<" "<<t[1].second<<" "<<t[1].first<<" "<<t[2].second<<" "<<t[2].first<<"\n";
            return true;
        }
    }
    return false;


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>ilekolorow;
    for(int i=1;i<=ilekolorow;i++)
    {
        cin>>pomile;
        for(int j=0;j<pomile;j++)
        {
            cin>>pomdl;
            pat.push_back({pomdl,i});
        }
    }

    sort(pat.begin(),pat.end());
    t[0]={-1,-1};
    t[1]={-1,-1};
    t[2]={-1,-1};


    for(int i=0;i<pat.size();i++)
    {
        if(upd(pat[i])==true)
        {
            return 0;
        }
            
    }
    cout<<"NIE\n";



    return 0;
}