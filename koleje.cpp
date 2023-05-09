#include <bits/stdc++.h>

using namespace std;

const int p=17;
int tree[1<<p];
int lazy[1<<p];
int nrpierwszegoliscia=1<<(p-1);
int n, m, z;
int pc,k,ile;

void apply(int numerw,int wartosc) // W PUNKCIE
{
    tree[numerw]+=wartosc;
    if(numerw<nrpierwszegoliscia)
        lazy[numerw]+=wartosc;
}

void build(int numerw) // CALA SCIEZKA
{
    numerw/=2;
    while(numerw>0)
    {
        tree[numerw]=max(tree[2*numerw], tree[2*numerw+1]);
        numerw/=2;
    }
}

void push(int numerw)
{
    for(int wykl=p-1;wykl>0;wykl--)
    {
        int aktnr= numerw >> wykl;
        if(lazy[aktnr]>0)
        {
            apply(aktnr*2, lazy[aktnr]);
            apply(aktnr*2+1, lazy[aktnr]);
            lazy[aktnr]=0;
        }

    }
}
void insertpp(int l, int p, int wartosc)
{
    l+=nrpierwszegoliscia;
    p+=nrpierwszegoliscia;
    int poml=l;
    int pomp=p;
    //F1 - pushowanie
    push(l);
    push(p);
    //F2 - wprowadzanie
    apply(l, wartosc);
    if(l!=p) apply(p, wartosc);
    while(l/2!=p/2)
    {
        if(l%2==0) apply(l+1, wartosc);
        if(p%2==1) apply(p-1, wartosc);
        l/=2;
        p/=2;
    }


    //F3 -budowa
    build(poml);
    build(pomp);
}

int query(int l, int p)
{
    l+=nrpierwszegoliscia;
    p+=nrpierwszegoliscia;
    int odp;
    // F1
    push(l);
    push(p);
    //F2
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

void wyswietl()
{
    cout<<"\n\n";
    int pom=1;
    for(int i=1;i<nrpierwszegoliscia*2;i++)
    {
        cout<<tree[i]<<","<<lazy[i]<<"    ";

        if( ((i+1)>>pom) ==1)
        {
            cout<<"\n";
            pom++;
        }
    }
    cout<<"\n\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>z;
   // wyswietl();
    while(z--)
    {
      //  wyswietl();
        cin>>pc>>k>>ile;
        k--;
       // cout<<"Maks na przedziale: "<<pc<<" do "<<k<<" to: "<<query(pc,k)<<"\n";
        if(query(pc-1,k-1)+ile>m)
        {
            cout<<"N\n";
        }
        else
        {
            cout<<"T\n";
            insertpp(pc-1,k-1,ile);
        }
      //  wyswietl();

    }
    cout<<"\n";



    return 0;
}