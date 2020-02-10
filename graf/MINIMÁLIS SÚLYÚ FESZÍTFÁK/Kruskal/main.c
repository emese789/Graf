#include <stdio.h>
#include <stdlib.h>

typedef struct el
{
    int kezd;
    int veg;
    int suly;
}el;

void kruskal(int,int,el*,int*);
void rendezsuly(el*,int);
void egyesit(int*,int,int,int);

int main()
{
    FILE * fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    int csomopontok,elekszama;
    fscanf(fin,"%i%i",&csomopontok,&elekszama);
    el*elek=(el*)calloc(elekszama+1,sizeof(el));
    if(elek==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=1;i<=elekszama;++i)
    {
        fscanf(fin,"%i%i%i",&elek[i].kezd,&elek[i].veg,&elek[i].suly);
        printf("%i %i %i\n",elek[i].kezd,elek[i].veg,elek[i].suly);
    }
    int *fa;
    fa=(int*)calloc(csomopontok+1,sizeof(int));
    if(fa==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    kruskal(csomopontok,elekszama,elek,fa);
    return 0;
}

void kruskal(int csomopontok,int elekszama,el* elek,int*fa)
{
    for(int i=1;i<=csomopontok;++i)
    {
        fa[i]=i;
    }
    rendezsuly(elek,elekszama);
    int osszsuly=0;
    for(int i=1;i<=elekszama;++i)
    {
        int egyik=fa[elek[i].kezd];
        int masik=fa[elek[i].veg];
        if(egyik!=masik)
        {
            osszsuly=osszsuly+elek[i].suly;
            egyesit(fa,csomopontok,egyik,masik);
        }
    }
    printf("%i ",osszsuly);

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

void egyesit(int * fa,int csomopontok,int egyik,int masik)
{
    for(int i=1;i<=csomopontok;++i)
    {
        if(fa[i]==masik)
        {
            fa[i]=egyik;
        }
    }
}
