#include <stdio.h>
#include <stdlib.h>

typedef struct el
{
    int kezd;
    int veg;
}el;

typedef struct graf
{
    int *pontok;
    el* elek;
}graf;
int *topologikus,t=0,elhagy;

void melysegibejaras(graf*,int,int);
void melysegimenet(graf*,int,int,int*,int*,int*,int*,int,int);

int main()
{
    int elekszama,csomopontok;
    FILE*fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
     printf("Sikertelen allomanymegnyittas");
    }
    fscanf(fin,"%i%i",&csomopontok,&elekszama);
    graf*g;
    g=(graf*)calloc(1,sizeof(graf));
    if(g==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    g->pontok=(int*)calloc(csomopontok+1,sizeof(int));
    if(g->pontok==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=1;i<=csomopontok;++i)
    {
        g->pontok[i]=i;
    }
    g->elek=(el*)calloc(elekszama+1,sizeof(el));
    if(g->elek==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=1;i<=elekszama;++i)
    {
        fscanf(fin,"%i%i",&g->elek[i].kezd,&g->elek[i].veg);
        printf("%i %i\n",g->elek[i].kezd,g->elek[i].veg);
    }
    //!!!!!!!!!
    topologikus=(int*)calloc(csomopontok+1,sizeof(int));
    if(topologikus==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    fclose(fin);
    melysegibejaras(g,csomopontok,elekszama);
    free(g->pontok);
    free(g->elek);
    free(g);
    printf("\nTopologikus sorrend: ");
    for(int i=1;i<=csomopontok;++i)
    {
        printf("%i ",topologikus[i]);
    }
    free(topologikus);
    return 0;
}

void melysegibejaras(graf*g,int csomopontok,int elekszama)
{
    int*szin,*apa,*elert;
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
    elhagy=(int*)calloc(csomopontok+1,sizeof(int));
    if(elhagy==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    elert=(int*)calloc(csomopontok+1,sizeof(int));
    if(elert==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    int ido=0;
    for(int i=1;i<=csomopontok;++i)
    {
        if(szin[i]==0)
        {
            melysegimenet(g,csomopontok,elekszama,szin,apa,elert,elhagy,ido,i);
        }
    }
    free(szin);
    free(apa);
    free(elhagy);
    free(elert);
}

void melysegimenet(graf*g,int csomopontok,int elekszama,int* szin,int* apa,int* elert,int* elhagy,int ido,int csomopont)
{
    printf("%i ",csomopont);
    szin[csomopont]=1;
    ++ido;
    elert[csomopont]=ido;
    for(int i=1;i<=elekszama;++i)
    {
        if(g->elek[i].kezd==csomopont && szin[g->elek[i].veg]==0)
        {
            apa[g->elek[i].veg]=g->elek[i].kezd;
            melysegimenet(g,csomopontok,elekszama,szin,apa,elert,elhagy,ido,g->elek[i].veg);
        }
    }
    szin[csomopont]=2;
    ++ido;
    elhagy[csomopont]=ido;
    //!!!!!!!!!
    topologikus[csomopontok-t++]=csomopont;
}

