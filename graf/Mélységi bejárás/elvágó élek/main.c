#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int elvagoel(int**,int,int,int*,int*,int*);

int main()
{
    FILE * fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyittas");
    }
    int csomopontok,elekszama;
    fscanf(fin,"%i%i",&csomopontok,&elekszama);
    int **a;
    a=(int**)calloc(csomopontok+1,sizeof(int*));
    if(a==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=1; i<=csomopontok; ++i)
    {
        a[i]=(int*)calloc(csomopontok,sizeof(int));
        if(a[i]==NULL)
        {
            printf("Sikertelen dinamikus helyfoglalas");
        }
    }
    int m,n;
    for(int i=1;i<=elekszama;++i)
    {
        fscanf(fin,"%i%i",&m,&n);
        a[m][0]++;
        a[m][a[m][0]]=n;
        a[n][0]++;
        a[n][a[n][0]]=m;
    }
    int *szin,*apa,*szint;
    szin=(int*)calloc(csomopontok+1,sizeof(int));
    if(szin==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    apa=(int*)calloc(csomopontok+1,sizeof(int));
    if(apa==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    szint=(int*)calloc(csomopontok+1,sizeof(int));
    if(szint==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    elvagoel(a,1,1,apa,szin,szint);
    return 0;
}

int elvagoel(int**a,int v,int sz,int*apa,int*szin,int*szint)
{
    szin[v]=1;
    szint[v]=sz;
    int RFminVM=INT_MAX,UminVM;
    for(int i=1;i<=a[v][0];++i)
    {
        int w=a[v][i];
        if(szin[w]==0)
        {
            apa[w]=v;
            UminVM=elvagoel(a,w,sz+1,apa,szin,szint);
            if(UminVM<sz)
            {
                if(UminVM<RFminVM)
                {
                    RFminVM=UminVM;
                }
            }
            else
            {
                if(szin[w]==1)
                {
                    if(szint[w]<sz-1)
                    {
                        if(szin[w]<RFminVM)
                        {
                            RFminVM=szint[w];
                        }
                    }
                }
            }
        }
    }
    szin[v]=2;
    if(apa[v]!=0)
    {
        if(RFminVM==INT_MAX)
        {
            printf("%i %i\n", apa[v],v);
        }
    }
    return RFminVM;
}
