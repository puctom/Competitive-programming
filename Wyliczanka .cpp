#include <bits/stdc++.h>

using namespace std;

int n;
const int mn=25;
int tsm[mn];
int kol[mn];
int nast[mn];
int pop[mn];
int temp;
int r[mn];

int NWD(int a,int b)
{
   // cout<<"NWD("<<a<<","<<b<<") = ";
    if(b>a) swap(a,b);
    int rsz=a%b;
    while(a%b!=0)
    {
        rsz=a%b;
        a=b;
        b=rsz;
    }
  //  cout<<b<<"\n";
    return b;
}




int main()
{
  /*  ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    */

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tsm[i];
        kol[tsm[i]]=i;
        pop[i]=i-1;
        nast[i]=i+1;

    }
    pop[1]=n;
    nast[n]=1;
    temp=1;
    int reszta;

    for(int i=1;i<=n;i++)
    {
      //  cout<<nast[i]<<"nast - "<<i<<" - pop "<<pop[i]<<"\n";
    }

    for(int i=1;i<=n;i++)
    {
        reszta=2;
        //cout<<"Startujemy od: "<<temp<<"\n";
        //cout<<"Ma wypasc: "<<kol[i]<<"\n";
        while(nast[temp]!=kol[i])
        {
          //  cout<<"nast["<<temp<<"]: "<<nast[temp]<<"!="<<kol[i]<<"\n";
            temp=nast[temp];
            reszta++;
        }

       // cout<<"Reszta z dzielenia k przez: "<<n+1-i<<" to: "<<reszta<<"\n";
        r[n+1-i]=reszta;
        //cout<<"Jako pierwsze wypadnie: "<<kol[i]<<"\n";
        pop[nast[kol[i]]]=pop[kol[i]];
        nast[pop[kol[i]]]=nast[kol[i]];
        //cout<<"Zmienione: pop["<<nast[kol[i]]<<"]="<<pop[nast[kol[i]]]<<" i nast["<<pop[kol[i]]<<"] = "<<nast[pop[kol[i]]]<<"\n";
        temp=nast[temp];
        //cout<<"TEMP: "<<temp<<"\n"; 5 2 3 1 5 4
    }

    int popmod=1;
    int popr=0;
    for(int i=2;i<=n;i++)
    {
       // cout<<"k == "<<r[i]<< "(mod "<<i<<") oraz k=="<<popr<<" (mod "<<popmod<<")\n";
        //cout<<"NWW("<<i<<","<<popmod<<") = "<<i*popmod/NWD(i,popmod)<<"\n";
        for(int j=0;j<=i;j++)
        {
           // cout<<"Sprawdzamy czy liczba: "<<j*popmod+popr<<" daje reszte: "<<r[i]<<" przez: "<<i<<"\n";
            if((j*popmod+popr-r[i])%i==0  )
            {
                popr=j*popmod+popr;
                break;
            }
            if(j==i)
            {
                cout<<"NIE\n";
                return 0;
            }

        }
      // cout<<"popmod -> "<<i*popmod/NWD(i,popmod)<<"\n";
        popmod=i*popmod/NWD(i,popmod);


    }
    if(popr==0)
    {
        cout<<popmod<<"\n";
        return 0;
    }

    cout<<popr<<"\n";


    return 0;
}