#include <iostream>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include<limits>
#define Max 10000
using namespace std;

int main()
{
    FILE*fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyitas");
    }
    int csomopontok, elekszama;
    fscanf(fin, "%i%i",&csomopontok,&elekszama);
    int**t;
    t=(int**)calloc(csomopontok+1,sizeof(int*));
    if(t==NULL)
    {
        printf("Sikertelen dinamikus helyfogalals-1");
    }
    for(int i=1; i<=csomopontok; i++)
    {
        t[i]=(int*)calloc(csomopontok+1,sizeof(int));
        if(t==NULL)
        {
            printf("Sikertelen dinamikus helyfoglalas-2");
        }
    }
    for(int i=1; i<csomopontok; i++)
    {
        for(int j=1; j<=csomopontok; j++)
        {
            t[i][j]=t[j][i]=Max;
        }
    }
    int * apa,*ut;
    apa=(int*)calloc(csomopontok+1,sizeof(int));
    if(apa==NULL)
    {
        printf("Sikeretelen dinamikus helyfoglalas-3");
    }
    ut=(int*)calloc(csomopontok+1,sizeof(int));
    if(ut==NULL)
    {
        printf("Sikeretelen dinamikus helyfoglalas-3");
    }
    int *latott;
    latott=(int*)calloc(csomopontok+1, sizeof(int));
    if(latott==NULL)
    {
        printf("Sikertelen dinamikus helyfoglalas-4");
    }
    int x,y,z;
    for(int i=1; i<=elekszama; i++)
    {
        fscanf(fin,"%d%d%d",&x,&y,&z);
        t[x][y]=z;
    }
    int kezd=1,poz;
    for(int i=1; i<=csomopontok; i++)
    {
        ut[i]=t[kezd][i];
        apa[i]=kezd;
    }
    latott[kezd]=1;
    for(int i=1; i<=csomopontok; i++)

    {
        int mini=Max;
        for(int j=1; j<=csomopontok; j++)
        {
            if(!latott[j]&&ut[j]<mini &&ut[j]!=Max)
            {
                mini=ut[j];
                poz=j;
            }
            for(int k=1; k<=csomopontok; k++)
                if (!latott[k] && t[poz][k]!=Max)
                    if (ut[k] > t[poz][k] + ut[poz])
                    {
                        ut[k] = t[poz][k] + ut[poz];
                        apa[k] = poz;
                    }
            latott[poz]=1;
        }
    }
    return 0;
}
