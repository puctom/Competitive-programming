#include <iostream>

using namespace std;

int d,n;
int dl,a;
const int p=21;
int tree[1<<p];
int lazy[1<<p];
int nrpierwszegoliscia=1<<(p-1);



void apply(int numerw, int wartosc)
{
    tree[numerw]=max(tree[numerw],wartosc);
    if(numerw<nrpierwszegoliscia)
        lazy[numerw]=wartosc;

}
void build(int numerw)
{
    numerw/=2;
    while(numerw>0)
    {
        tree[numerw]=max(tree[2*numerw],tree[2*numerw+1]);
        numerw/=2;
    }
    //dzielenie na 2
}
void push(int numerw)
{
    for(int wykl=p-1;wykl>0;wykl--)
    {
        int pom=numerw>>wykl;
        if(lazy[pom]>0)
        {
            apply(2*pom,lazy[pom]);
            apply(2*pom+1,lazy[pom]);
            lazy[pom]=0;
        }
    }
    // dzielenie przez wykladnik
}

void ustawmaks(int l,int p, int nowymaks)
{
    l+=nrpierwszegoliscia;
    p+=nrpierwszegoliscia;
    int poml=l;
    int pomp=p;
    // F1
    push(l);
    push(p);

    //F2
    apply(l,nowymaks);
    apply(p,nowymaks);
    while(l/2!=p/2)
    {
        if(l%2==0) apply(l+1,nowymaks);
        if(p%2==1) apply(p-1,nowymaks);
        l/=2;
        p/=2;
    }

    //F3
    build(poml);
    build(pomp);

}
int query(int l,int p)
{
    l+=nrpierwszegoliscia;
    p+=nrpierwszegoliscia;
    //F1
    push(l);
    push(p);
    //F2
    int odp;
    odp=max(tree[l],tree[p]);

    while(l/2!=p/2)
    {
        if(l%2==0) odp=max(odp, tree[l+1]);
        if(p%2==1) odp=max(odp,tree[p-1]);
        l/=2;
        p/=2;
    }

    return odp;


}

int main()
{
    cin>>d>>n;
    int wynik=0;
    for(int i=1;i<=n;i++)
    {
        cin>>dl>>a;
        //cout<<"Dodajemy klocek na przedziale: "<<a<<" do "<<a+dl<<"\n";
       // cout<<"Aktualne maksimum na tym przedziale to: "<<query(a,a+dl-1)<<"\n";
        ustawmaks(a, a+dl-1,query(a,a+dl-1)+1);

    }
    cout<<query(0,d-1)<<"\n";

    return 0;
}