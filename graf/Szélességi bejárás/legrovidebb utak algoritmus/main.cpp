#include <stdio.h>
#include <stdlib.h>

void kiir_LRU(int,int*);

int main()
{
    //szomszedsagi lista
    int p,el,n,m;
    FILE * fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyittas!");
    }
    fscanf(fin,"%i%i",&p,&el);
    int **szl;
    szl=(int**)calloc(p+1,sizeof(int*));
    if(szl==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for(int i=0; i<=p; ++i)
    {
        szl[i]=(int*)calloc(p,sizeof(int));
        if(szl[i]==NULL)
        {
            printf("Sikertelen dinamikus helyfoglalas");
        }
    }
    for(int i=1; i<=el; ++i)
    {
        fscanf(fin,"%i%i",&m,&n);
        szl[m][0]++;
        szl[m][szl[m][0]]=n;
        szl[n][0]++;
        szl[n][szl[n][0]]=m;
    }
    fclose(fin);
    for(int i=1; i<=p; ++i)
    {
        printf("%i ",i);
        int j=0;
        while(szl[i][j]!=0)
        {
            printf("%i ",szl[i][j]);
            ++j;
        }
        printf("\n");
    }
    //szelessegi bejaras
    int *a,*szin,*d,*apa;
    a=(int*)calloc(p,sizeof(int));
    if(a==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    szin=(int*)calloc(p+1,sizeof(int));
    if(szin==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    apa=(int*)calloc(p+1,sizeof(int));
    if(apa==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    d=(int*)calloc(p+1,sizeof(int));
    if(d==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    int e,v,b,c;
    printf("Melyik pontból induljon a szelessegi bejaras? ");
    scanf("%i",&b);
    e=v=0;
    a[0]=b;
    szin[a[0]]=1;
    d[e]=0;
    apa[a[0]]=0;
    while(e<=v)
    {

        int elso=a[e];
        for(int i=1;i<=szl[elso][0];++i)
        {
            int jelenlegi=szl[elso][i];
            if(szin[jelenlegi]==0)
            {
                szin[jelenlegi]=1;
                d[jelenlegi]=d[elso]+1;
                ++v;
                a[v]=jelenlegi;
                apa[jelenlegi]=elso;
            }
        }
        ++e;
        szin[elso]=2;
    }
    printf("Szelessegi bejaras:");
    for(int i=0; i<p; ++i)
    {
        printf("%i ",a[i]);
    }
    printf("\n");
    printf("Apa tomb: ");
    for(int i=1; i<=p; ++i)
    {
        printf("%i ",apa[i]);
    }
    printf("\n");
    printf("Tavolsag a kezdoponttol: \n");
    for(int i=1; i<=p; ++i)
    {
        printf("Az %i pont %i elnyi tavolsagra van \n",i,d[i]);
    }
    //legrovidebb utak
    printf("Melyik pontba szeretned kiszamolni a legrovidebb utat? ");
    scanf("%i",&c);
    printf("A legrovidebb ut: ");
    kiir_LRU(c,apa);
    for(int i=0; i<=p; ++i)
    {
        free(szl[i]);
    }
    free(szl);
    free(apa);
    free(a);
    free(szin);

    return 0;
}

void kiir_LRU(int i,int *apa)
{
    if(apa[i]!=0)
        kiir_LRU(apa[i],apa);
    printf("%i ",i);
}
