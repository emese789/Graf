#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define inf 200000
int main()
{
    int **szl,**t,x,y,z,csomopontok,elekszama,*ut,*apa;
    FILE * fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyittas");
    }
    fscanf(fin,"%i%i",&csomopontok,&elekszama);
    t = (int **) calloc(csomopontok+1,sizeof(int*));
    if(t==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas");
    }
    for (int i = 1 ; i<=csomopontok ; i++)
    {
        t[i] = (int*) calloc(csomopontok+1,sizeof(int));
        if(t==NULL)
        {
            printf("Sikertelen dinamikus helyfoglalas");
        }
    }
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
    printf("e");
    for (int i = 1; i<csomopontok; i++)
        for (int j = 1 ; j<=csomopontok ; j++)
            t[i][j] = t[j][i]  = inf;
    printf("e");
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
    for (int i = 0 ; i<elekszama ; i++)
    {
        fscanf(fin,"%i%i%i",&x,&y,&z);
        t[x][y] = z;
    }


    for (int i = 1; i<=csomopontok ; i++)
    {
        printf("%i :",i);
        int k = 0;
        for (int j = 1 ; j<=csomopontok ; j++)
        {
            if (t[i][j] && t[i][j]!=inf)
            {
                k++;
                szl[i][k] = j;
                printf("%i ",szl[i][k]);
            }
        }
        szl[i][0] = k;
        printf("\n");
    }

    int kezd = 1;

    for (int i = 1 ; i<=csomopontok ; i++)
    {
        ut[i] = t[kezd][i];
    }

    ut[kezd] = 0;
    apa[kezd] = 0;
    int lep = 0;
    bool volt;
    printf("Eredeti:\n");
    for (int i = 1 ; i<=csomopontok ; i++)
    {
       printf("%i ",ut[i]);
    }
    printf("\n\n");
    do
    {
        volt = false;
        for (int i = 1 ; i<=csomopontok ; i++)
        {
            for (int j = 1 ; j<=szl[i][0] ; j++)
            {
                if (ut[i] + t[i][szl[i][j]] < ut[szl[i][j]])
                {
                    ut[szl[i][j]] = ut[i] + t[i][szl[i][j]];
                    apa[szl[i][j]] = i;
                    volt = true;
                }
            }
        }
        if (volt)
        {
            printf("%i:lepes\n",lep);
            for (int i = 1 ; i<=csomopontok ; i++)
            {
                printf("%i ",ut[i]);
            }
            printf("\n\n");
        }
        lep++;
    }
    while (volt && lep<csomopontok);


    if (volt && lep==csomopontok)
    {
        printf("\n\nHamis\n");
    }
    else
    {
        printf("\n\nIgaz\n");
    }

return 0;
}
