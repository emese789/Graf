#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct elek
{
    int kezd;
    int veg;
} elek;
typedef struct graf
{
    int *pontok;
    elek* elek;
} graf;

void melysegibejaras(graf*, int,int);
void melysegimenet (graf*, int, int, int*, int*, int*, int*, int,int);

int main()
{
    int elekszama, csomopontok;
    FILE*fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyitas!1");
    }
    fscanf(fin,"%i%i",&csomopontok,&elekszama);
    graf*g;
    g=(graf*)calloc(1,sizeof(graf));
    if(g==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas1");
    }
    g->pontok=(int*)calloc(csomopontok+1,sizeof(int));
    if(g->pontok==NULL)
    {
        printf("sikertelen dinamikus helyfoglalas2");
    }
    for(int i=0; i<csomopontok; i++)
    {
        g->pontok[i]=i;
    }
    g->elek=(elek*)calloc(elekszama+1, sizeof(elek));
    if(g->elek==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas3");
    }
    for(int i=1; i<elekszama; i++)
    {
        fscanf(fin,"%i%i",&g->elek[i].kezd,&g->elek[i].veg);
        printf("%i %i\n",g->elek[i].kezd,g->elek[i].veg);

    }
    fclose(fin);
    melysegibejaras(g,csomopontok,elekszama);
    free(g->pontok);
    free(g->elek);
    free(g);
    return 0;
}
void melysegibejaras(graf*g,int csomopontok, int elekszama)
{
    int  *szin, *apa, *elert, *elhagy;
    szin=(int*)calloc(csomopontok+1, sizeof(int));
    if(szin==NULL)
    {
        printf("sikertelen dinamikus helyfoglalas4");
    }
    apa=(int*)calloc(csomopontok+1,sizeof(int));
    if(apa==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas5");
    }
    elhagy=(int*)calloc(csomopontok+1,sizeof(int));
    if(elhagy==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas6");
    }
    elert=(int*)calloc(csomopontok+1,sizeof(int));
    if(elert==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas7");
    }
    int ido=0;
    for(int i=1; i<=csomopontok; ++i)
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
void melysegimenet(graf*g, int csomopontok,int elekszama,int*szin,int*apa,int*elert,int*elhagy,int ido ,int csomopont)
{
    printf("%i", csomopont);
    szin[csomopont]=1;
    ++ido;
    elert[csomopont]=ido;
    for(int i=1; i<elekszama; i++)
    {
        if(g->elek[i].kezd==csomopont && szin[g->elek[i].veg]==0)
    {
        apa[g->elek[i].veg]=g->elek[i].kezd;
            melysegimenet(g, csomopontok,elekszama,szin, apa, elert,elhagy, ido, g->elek[i].veg);
            printf("%i",csomopont);
        }
    }

    szin[csomopont]=2;
    ++ido;
    elhagy[csomopont]=ido;
}

