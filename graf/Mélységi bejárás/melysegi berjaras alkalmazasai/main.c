#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void melysegimenet(int**,int,int,int*,int*,int*,int*,int,int);
void melysegibejaras(int**,int,int);
int*topologikus,t=0;
    int kor=0;
int main()
{
    FILE *fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyittas");
    }
    int csomopontok,elekszama,n,m;
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
    for(int i=1; i<=elekszama; ++i)
    {
        fscanf(fin,"%i%i",&m,&n);
        a[m][0]++;
        a[m][a[m][0]]=n;

    }
    fclose(fin);
    topologikus=(int*)calloc(csomopontok+1,sizeof(int));
    if(topologikus==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    melysegibejaras(a,csomopontok,elekszama);
    printf("Topologikus sorrend: ");
    for(int i=1;i<=csomopontok;++i)
    {
        printf("%i ",topologikus[i]);
    }
    free(topologikus);
    for(int i=1; i<=csomopontok; ++i)
    {
        free(a[i]);
    }
    free(a);
    printf("\n");
    return 0;

}

void melysegibejaras(int**a,int csomopontok,int elekszama)
{
    int *szin,*apa,*eler,*elhagy,ido=0;
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
    eler=(int*)calloc(csomopontok+1,sizeof(int));
    if(eler==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    elhagy=(int*)calloc(csomopontok+1,sizeof(int));
    if(elhagy==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    int komp=0;
    for(int i=1; i<=csomopontok; ++i)
    {
        if(szin[i]==0)
        {
            komp++;
            melysegimenet(a,csomopontok,elekszama,szin,apa,eler,elhagy,ido,i);
        }
    }
    printf("Osszefuggo komponensek szama: %i\n",komp);
    if(kor==0)
    {
        printf("A graf kormentes!\n");
    }
    else
    {
        printf("A grafan van kor!\n");
    }
    free(szin);
    free(apa);
    free(elhagy);
    free(eler);
}

void melysegimenet(int**a,int csomopontok,int elekszama,int*szin,int*apa,int*eler,int*elhagy,int ido,int u)
{
    //printf("%i ",u);
    szin[u]=1;
    ++ido;
    eler[u]=ido;
    for(int i=1; i<=a[u][0]; ++i)
    {
        int v=a[u][i];

        if(szin[v]==0)
        {
            printf("%i -> %i fa el\n",u,v);
            apa[v]=u;
            melysegimenet(a,csomopontok,elekszama,szin,apa,eler,elhagy,ido,v);
        }
        if(szin[v]==1)
        {
            printf("%i -> %i visszamutato el\n",u,v);
            kor=1;
        }
    }
    szin[u]=2;
    ++ido;
    elhagy[u]=ido;
    topologikus[csomopontok-t++]=u;
}
