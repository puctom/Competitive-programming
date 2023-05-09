#include <bits/stdc++.h>

using namespace std;

const int mliczbapion=1e3;
const int mliczbapoziom=1e3;
int kosztpion[mliczbapion+4];
int kosztpoziom[mliczbapoziom+4];

int ciagkosztow[mliczbapion+mliczbapoziom+9];
int ilepion[mliczbapion+mliczbapoziom+9];

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    int liczbapion, liczbapoziom;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>liczbapion;
    cin>>liczbapoziom;

    for(int i=0;i<liczbapion-1;i++) cin>>kosztpion[i];
    for(int i=0;i<liczbapoziom-1;i++) cin>>kosztpoziom[i];

    kosztpion[liczbapion-1]=-39;
    kosztpoziom[liczbapoziom-1]=-30;


    //tylko odwrotnie
    sort(kosztpion,kosztpion+liczbapion-1,cmp);
   // for(int i=0;i<liczbapion;i++)
      //  cout<<kosztpion[i]<<"  ";


    sort(kosztpoziom,kosztpoziom+liczbapoziom-1,cmp);

    //³¹czenie w jeden ciag

    int idpion=0,idpoziom=0;

    while(idpion<=liczbapion-2 || idpoziom<=liczbapoziom-2)
    {
        if(kosztpion[idpion]<kosztpoziom[idpoziom])
        {
            if(idpion+idpoziom>0) ilepion[idpion+idpoziom]=ilepion[idpion+idpoziom-1];
            ciagkosztow[idpion+idpoziom]=kosztpoziom[idpoziom];
            idpoziom++;

          //  if(idpion+idpoziom==0) ilepion[idpion+idpoziom]=0;
        }
        else
        {
            if(idpion+idpoziom>0) ilepion[idpion+idpoziom]=ilepion[idpion+idpoziom-1]+1;
            if(idpion+idpoziom==0) ilepion[idpion+idpoziom]=1;
            ciagkosztow[idpion+idpoziom]=kosztpion[idpion];
            idpion++;

        }

    }




    int kosztcalk=0;

   /* for(int i=0;i<liczbapion+liczbapoziom-2;i++)
    {
        cout<<"Koszt "<<ciagkosztow[i]<<" - do tego miejsca zuzyto "<<ilepion[i]<<" cen z pionu \n";
    }


        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
*/

    for(int i=0;i<liczbapion+liczbapoziom-2;i++)
    {
       // cout<<"koszt calk= "<<kosztcalk<<" \nBadamy cene "<<ciagkosztow[i]<<"  przy i="<<i<<" \n";
        kosztcalk+=ciagkosztow[i];
       // cout<<"koszt calk= "<<kosztcalk<<" - pierwsze dodanie \n ";

        if(i>0)
        {
            if(ilepion[i]>ilepion[i-1])
            {
             //   cout<<"Wybralismy ciecie pionowe dodajemy "<<i-ilepion[i-1]<<" przeciec z poziomymi \n \n";
                kosztcalk+=(i-ilepion[i-1])*ciagkosztow[i];
            }
            else
            {
                //cout<<"Wybralismy ciecie poziome dodajemy "<<ilepion[i-1]<<" przeciec z pionowymi \n \n";
                kosztcalk+=(ilepion[i-1])*ciagkosztow[i];
            }

        }
    }


    /*
    for(int i=liczbapion+liczbapoziom-3;i>=0;i--)
    {
        kosztcalk+=ciagkosztow[i];
        if(i>=1&&i<liczbapion+liczbapoziom-3)
        {
            if(ilepion[i+1]>ilepion[i])
            {
                //mamy pionowa
                kosztcalk+=(liczbapion+liczbapoziom-2-ilepion[liczbapion+liczbapoziom-3]-((i+1)-ilepion[i]))*ciagkosztow[i];
            }
            else
            {
                kosztcalk+=(ilepion[liczbapion+liczbapoziom-3]-ilepion[i])*ciagkosztow[i];
            }

        }
        if(i==0)
        {
            if(ilepion[0]==0) kosztcalk+=ciagkosztow[i]*(ilepion[liczbapion+liczbapoziom-3]);
            else kosztcalk+=(liczbapion+liczbapoziom-2-ilepion[liczbapion+liczbapoziom-3])*ciagkosztow[i];
        }

    }
    */

    cout<<kosztcalk<<"\n";





    return 0;
}