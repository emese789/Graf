#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct el
{
    int kezd;
    int veg;
    int suly;
} el;


int *d;
void topo_LRU(el*,int ,int*,int*,int*,int,int);

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
    el*elek;
    elek=(el*)calloc(elekszama+1,sizeof(el));
    if(elek==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=1; i<=elekszama; ++i)
    {
        fscanf(fin,"%i%i%i",&elek[i].kezd,&elek[i].veg,&elek[i].suly);
    }
    /*int **szl;
    szl=(int**)calloc(csomopontok+1,sizeof(int*));
    if(szl==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=1; i<=csomopontok; ++i)
    {
        szl[i]=(int*)calloc(csomopontok,sizeof(int));
        if(szl[i]==NULL)
        {
            printf("Sikertelen dinamikus helyfoglalas");
        }
    }

    int n,m;
    for(int i=1; i<=elekszama; ++i)
    {
        fscanf(fin,"%i%i",&m,&n);
        szl[m][0]++;
        szl[m][szl[m][0]]=n;
    }*/
    int*apa,*topo;
    apa=(int*)calloc(csomopontok+1,sizeof(int));
    if(apa==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    d=(int*)calloc(csomopontok+1,sizeof(int));
    if(d==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    topo=(int*)calloc(csomopontok+1,sizeof(int));
    if(topo==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=1; i<=csomopontok; ++i)
    {
        fscanf(fin,"%i",&topo[i]);
    }
    topo_LRU(elek,1,topo,d,apa,elekszama,csomopontok);

    for(int i=1; i<=csomopontok; ++i)
    {
        printf("%i ",d[i]);
    }
    return 0;
}

void topo_LRU(el*elek,int s,int*topo,int*d,int*apa,int elekszama,int csomopontok)
{
    for(int i=1;i<=csomopontok;++i)
    {
        d[i]=INT_MAX;
    }
    d[s]=0;
    apa[s]=0;
    int is=1;
    while(topo[is]!=s)
    {
        is++;
    }
    int sulyuv;
    for(int i=is; i<=csomopontok-1; ++i)
    {
        int u=topo[i];
        for(int j=1; j<=elekszama; ++j)
        {

            if(elek[j].kezd==u)
            {
                int v=elek[j].veg;
                sulyuv=elek[j].suly;
                if(d[u]+sulyuv<d[v])
                {
                    apa[v]=u;
                    d[v]=d[u]+sulyuv;
                }
            }
        }
    }
}
