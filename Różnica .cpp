#include <bits/stdc++.h>

using namespace std;

const int ma=30;
int dl;
string s;
vector<int> wyst[ma];
int wynik;

vector<int> wspolny(char z1,char z2)
{
    vector<int> zlacz;
    int wsk1=0,wsk2=0;

    while(wsk1<wyst[(int)(z1-'a')].size()-1||wsk2<wyst[(int)(z2-'a')].size()-1)
    {
        if(wyst[(int)(z1-'a')][wsk1]<wyst[(int)(z2-'a')][wsk2])
        {
            zlacz.push_back(1);
            wsk1++;
        }
        else
        {
            zlacz.push_back(-1);
            wsk2++;
        }


    }


    return zlacz;
}


int solve(vector<int> poz)
{
    bool czyjestzly=true;
    int ob=0;
    int odp=0;
   // cout<<"Rozwiazujemy dla poz.size()="<<poz.size()<<"\n";
    for(int i=0;i<poz.size();i++)
    {
       // cout<<"poz["<<i<<"] = "<<poz[i]<<"\n";
        if(poz[i]==-1)
            czyjestzly=false;
        if(ob+poz[i]<0)
        {
            ob=0;
            czyjestzly=true;
        }
        else
        {
            ob+=poz[i];

        }



            odp=max(odp,ob-czyjestzly);
           // cout<<"Obecny wynik: "<<odp<<"\n";


    }
    return odp;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>dl;
    cin>>s;

 //   cout<<"Wczytano slowo\n";


    for(int i=0;i<dl;i++)
    {
     //   cout<<"chcemy wpisac do indexu: "<<(int)(s[i]-'a')<<"\n";
        wyst[(int)(s[i]-'a')].push_back(i);
    }


  //  cout<<"Wpisano wystapienia\n";
    for(int i=0;i<=(int)('z'-'a');i++)
    wyst[i].push_back(dl+10);

    for(char i='a';i<='z';i++)
    {
        for(char j='a';j<='z';j++)
        {

            if(i==j||wyst[(int)(i-'a')].size()==1||wyst[(int)(j-'a')].size()==1)
                continue;
        //    cout<<"\nSprawdzimy pare: "<<i<<" "<<j<<"\n";
            wynik=max(wynik, solve(wspolny(i,j)));
         //   cout<<"\n\n\nWynik teraz: "<<wynik<<"\n\n";

        }
    }
    cout<<wynik<<"\n";








    return 0;
}