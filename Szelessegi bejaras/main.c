#include <stdio.h>
#include <stdlib.h>

int main()
{//szomszedsagi lista
    int p,el,n,m;
    FILE *fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("sikertelen allomany megnyitas");
    }
    fscanf(fin,"%i %i",&p,&el);
    int**szl;
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
    // szelessegi bejaras
    int *a,*szin,*d,*apa;
    a=(int*)calloc(p,sizeof(int));
    if(a==NULL)
    {
        printf("sikertelen");
    }
    szin=(int*)calloc(p+1,sizeof(int));
    if(szin==NULL)
    {
        printf("SIKERTELEN dinamikus helyfoglalas-1");
    }
    apa=(int*)calloc(p+1,sizeof(int));
    if(apa==NULL)
    {
        printf("SIKERTELEN dinamikus helyfoglalas-2");
    }
    d=(int*)calloc(p+1,sizeof(int));
    if(d==NULL)
    {
        printf("SIKERTELEN dinamikus helyfoglalas-3");
    }
    int eleje,vege,b,c;
    printf("adjon meg egy kezdo pontot");
    scanf("%i",&b);
    eleje=vege=0;
    a[0]=b;
    szin[a[0]]=1;
    d[eleje];
    apa[a[0]]=0;
    while(eleje<vege)
    {
        int elso=a[eleje];
        for(int i=0; i<szl[elso][0]; i++)
        {
            int jelenlegi=szl[elso][i];
            if(szin[jelenlegi]==0)
            {
                szin[jelenlegi]=1;
                d[jelenlegi]=d[elso]+1;
                ++vege;
                a[vege]=jelenlegi;
                apa[jelenlegi]=elso;
            }
        }
        ++eleje;
        szin[elso]=2;
    }
    printf("Szelessegi bejaras: ");
    for(int i=0; i<p; i++)
    {
        printf("%i",a[i]);
    }
    printf("\n");
    printf("Apa tomb: ");
    for(int i=1; i<p; i++)
    {
        printf("%i",apa[i]);
    }
    printf("\n");

}

