#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p=0, el=0;
    FILE *fin;
    fin=fopen("be.txt","rt");
    if(!fin)
    {
        printf("Sikertelen allomanymegnyitas");

    }
    fscanf(fin,"%i %i",&p,&el);
    int **v, *a;
    v=(int**)calloc(el+2,sizeof(int*));
    if(v==NULL)
    {
        printf("Sikertelen helyfoglalas1");
    }
    for(int i=1; i<=el; i++)
    {
        v[i]=(int*)calloc(3,sizeof(int));
        if(v[i]==NULL)
        {
            printf("Sikertelen helyfoglalas2");
        }
    }
    a=(int*)calloc(p+2,sizeof(int));
    if(a==NULL)
    {
        printf("Sikertelen helyfoglalas3");
    }

    for(int i=1; i<=el; i++)
    {
        for(int j=1; j<=2; ++j)
        {
            fscanf(fin,"%i",&v[i][j]);
            printf("%i ",v[i][j]);
            a[v[i][j]]++;
        }
        printf("\n");
    }

    fclose(fin);
    for(int i=1; i<=p+1; i++)
    {
        printf("%i -> %i\n",i,a[i]);
    }
    printf("\n");
    for(int i=1; i<=p; i++)
    {
        int min=p+10;
        for(int j=1; j<=el; j++)
        {
            if(a[j]==1 && j<min)
            {
                a[j]--;
                min=j;
            }
        }
        for(int k=1; k<=el; k++)
        {
            if(v[k][1]==min)
            {
                a[v[k][2]]--;
                printf("%i ",v[k][2]);
                v[k][1]=v[k][2]=0;
            }
            if(v[k][2]==min)
            {
                a[v[k][1]]--;
                printf("%i ",v[k][1]);

                v[k][1]=v[k][2]=0;
            }
        }
    }
    free(a);
    for(int i=1; i<el; i++)
    {
        free(v[i]);
    }
    free(v);
    return 0;
}
