#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct
{
    int u,v,w;//w-suly
} EL;

void rendezes_suly(EL*, int);
void merge(int*, int,int,int);
void csere(EL&,EL&);
int main()
{
    int n,m;
    int a,b;
    FILE *fin;
    fin=fopen("elek.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyitas");
        return 0;
    }

    fscanf(fin,"%i%i", &n, &m);
    EL* elek=new EL[n+1];
    int *fa=new int[m+1];
    for(int j=0; j<=m; j++)
    {
        fa[j]=j;
    }
    for(int i=0; i<n; i++)
    {
        fscanf(fin, "%i%i%i",elek[i].u,elek[i].v,elek[i].w);

    }
    fclose(fin);
    rendezes_suly(elek,n);
    printf("Ellista:\n");
    for(int i=1; i<=n; i++)
    {
        cout<<elek[i].u<<" "<<elek[i].v<<" " <<elek[i].w<<"\n";
    }

    int ossz_suly=0;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<fa[j]<<" "<<endl;
        }
        a=fa[elek[i].u];
        b=fa[elek[i].v];
        if(a!=b)
        {
            ossz_suly=ossz_suly+elek[i].w;
            cout<<elek[i].u<<elek[i].v<<elek[i].w<<endl;
            merge(fa,n,a,b);
        }
    }
    printf("Osszsuly:%i\n",ossz_suly);
    free(elek);
    return 0;
}


void rendezes_suly(EL*elek,int n)
{
    int i,j;
    for( i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(elek[j].w>elek[j+1].w)
                csere(elek[j],elek[j+1]);

        }
    }
}
void merge(int *fa, int n, int u, int v)
{
    for(int i=1; i<=n; i++)
    {
        if(fa[i]==v)
        {
            fa[i]=u;
        }
    }
}

void csere(EL&xp,EL&yp)
{
    EL temp=xp;
    xp=yp;
    yp=temp;
}
