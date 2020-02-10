#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Maxx 10000



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
    int **t;
    t = (int **) calloc(csomopontok+1,sizeof(int *));
    if(t==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for (int i = 1 ; i<=csomopontok ; i++)
    {
        t[i] = (int *) calloc(csomopontok+1,sizeof(int));
        if(t==NULL)
        {
            printf("Sikertelen dinamikus helyfoglalas");
        }
    }
    for (int i = 1; i<csomopontok; i++)
        for (int j = 1 ; j<=csomopontok ; j++)
            t[i][j] = t[j][i]  = Maxx;
    int*apa,*ut;
    apa=(int*)calloc(csomopontok+1,sizeof(int));
    if(apa==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    ut=(int*)calloc(csomopontok+1,sizeof(int));
    if(ut==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    int *latott;
    latott=(int*)calloc(csomopontok+1,sizeof(int));
    if(latott==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    int x,y,z;
    for (int i = 1 ; i<=elekszama ; i++)
    {
        fscanf(fin,"%d%d%d",&x,&y,&z);
        t[x][y] = z;
    }
    int kezd = 1,poz;

    for (int i = 1; i<=csomopontok ; i++)
    {
        ut[i] = t[kezd][i];
        apa[i] = kezd;
    }
    latott[kezd] = 1;

    for (int i = 1 ; i<=csomopontok ; i++)
    {
        int mini = Maxx;
        for (int j = 1 ; j<=csomopontok ; j++)
            if (!latott[j] && ut[j]<mini && ut[j]!=Maxx)
            {
                mini = ut[j];
                poz = j;
            }
        for (int k = 1 ; k<=csomopontok ; k++)
            if (!latott[k] && t[poz][k]!=Maxx)
                if (ut[k] > t[poz][k] + ut[poz])
                {
                    ut[k] = t[poz][k] + ut[poz];
                    apa[k] = poz;
                }
        latott[poz] = 1;
    }
    /*
        for (int i = 2; i<=n ; i++)
            printf("%d.pont\t%d tavolsagra van %d tol \t %d pontbol erkeztunk\n",i,ut[i],kezd,apa[i]);
    */
    for (int i = 2; i<=csomopontok ; i++)
        if (ut[i]==Maxx)
            printf("%d ",0);
        else
            printf("%d ",ut[i]);

    return 0;
}

