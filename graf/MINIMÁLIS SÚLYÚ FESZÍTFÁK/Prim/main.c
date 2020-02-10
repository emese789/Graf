#include <stdio.h>
#include <stdlib.h>


typedef struct el
{
    int kezd;
    int veg;
    int suly;
    int vagas;
} el;


int kivesz_vagasbol_min(el*,int);
void rendezsuly(el*,int);
void prim(el*,int,int ,int ,int*,int*,int**);

int main()
{
    FILE * fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyittas");
    }
    FILE * fin2;
    fin2=fopen("be2.txt","rt");
    if(!fin2)
    {
        printf("Sikertelen allomanymegnyittas");
    }
    int csomopontok,elekszama;
    fscanf(fin,"%i%i",&csomopontok,&elekszama);
    el*elek=(el*)calloc(elekszama+1,sizeof(el));
    if(elek==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=1; i<=elekszama; ++i)
    {
        fscanf(fin,"%i%i%i%i",&elek[i].kezd,&elek[i].veg,&elek[i].suly,&elek[i].vagas);
        //printf("%i %i %i\n",elek[i].kezd,elek[i].veg,elek[i].suly);
    }
    fclose(fin);
    int *fa,*apa,n,m;
    fa=(int*)calloc(csomopontok+1,sizeof(int));
    if(fa==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    apa=(int*)calloc(csomopontok+1,sizeof(int));
    if(apa==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    int **szl;
    szl=(int**)calloc(csomopontok+1,sizeof(int*));
    if(szl==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=0; i<=csomopontok; ++i)
    {
        szl[i]=(int*)calloc(csomopontok,sizeof(int));
        if(szl[i]==NULL)
        {
            printf("Sikertelen dinamikus helyfoglalas");
        }
    }

    for(int i=1; i<=elekszama; ++i)
    {
        fscanf(fin2,"%i%i",&m,&n);
        szl[m][0]++;
        szl[m][szl[m][0]]=n;
        szl[n][0]++;
        szl[n][szl[n][0]]=m;
    }

    fclose(fin2);
    prim(elek,csomopontok,elekszama,1,fa,apa,szl);
    return 0;
}

void prim(el*elek,int csomopontok,int elekszama,int r,int*fa,int*apa,int**szl)
{

    fa[r]=1;
    apa[r]=0;
    int **sz_m;
    sz_m=(int**)calloc(csomopontok+1,sizeof(int*));
    for(int i=1;i<=csomopontok;++i)
    {
        sz_m[i]=(int*)calloc(csomopontok+1,sizeof(int));
    }
    rendezsuly(elek,elekszama);
    for(int i=1; i<=elekszama; ++i)
    {
        sz_m[elek[i].kezd][elek[i].veg]=i;
        sz_m[elek[i].veg][elek[i].kezd]=i;
        if((elek[i].kezd==r) || (elek[i].veg==r))
        {
            elek[i].vagas=1;
        }
        else
        {
            elek[i].vagas=0;
        }
    }
    int osszsuly=0,csatolt_pont=0;
    for(int lepes=1;lepes<=csomopontok-1;++lepes)
    {

        int i=kivesz_vagasbol_min(elek,elekszama);
        printf("%i,%i,%i\n",elek[i].kezd,elek[i].veg,elek[i].suly);
        osszsuly+=elek[i].suly;
        if(fa[elek[i].kezd]==1)
        {
            csatolt_pont=elek[i].veg;
            apa[csatolt_pont]=elek[i].kezd;
        }
        else
        {
            csatolt_pont=elek[i].kezd;
            apa[csatolt_pont]=elek[i].veg;
        }
        int szpont=0,szel=0;
        fa[csatolt_pont]=1;
        for(int j=1;j<=szl[csatolt_pont][0];++j)
        {
            szpont=szl[csatolt_pont][j];
            szel=sz_m[csatolt_pont][szpont];
            if(fa[szpont]==1)
            {
                elek[szel].vagas=0;
            }
            else
            {
                elek[szel].vagas=1;
            }
        }
    }
    printf("Osszsuly: %i",osszsuly);

}

int comp(const void *ap,const void *bp)
{
    int a=((el*)ap)->suly,b=((el*)bp)->suly;
    return (a>b)-(a<b);
}
void rendezsuly(el*elek,int elekszama)
{
    qsort(elek,elekszama,sizeof(el),comp);
}

int kivesz_vagasbol_min(el*elek,int elekszama)
{
    for(int i=1;i<=elekszama;++i)
    {
        if(elek[i].vagas==1)
        {
            return i;
        }
    }
}
