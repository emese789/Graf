#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct EL
{
    int kezdopont;
    int vegpont;
    int szuly;
} EL;

typedef struct SULYMATRIX
{
    int **matrix;
} SULYMATRIX;
void lru(int i, int j, int**ut);
int main()
{
    FILE *fin;
    EL * elek;
    SULYMATRIX m;
    int elekszam, csomopot, i, j,k,**ut;
    fin=fopen("be.txt","rt");
    fscanf(fin,"%i%i",&csomopot,&elekszam);
    elek=(EL*) calloc(elekszam,sizeof(EL));
    for (i=0; i<elekszam; ++i)
    {
        fscanf(fin,"%i%i%i",&elek[i].kezdopont,&elek[i].vegpont,&elek[i].szuly);
        printf("%i %i %i\n",elek[i].kezdopont,elek[i].vegpont,elek[i].szuly);
    }
    ut=(int **) calloc((csomopot+1),sizeof(int*));
    for (i=0;i<=csomopot;++i){
        ut[i]=(int*) calloc((csomopot+1),sizeof(int));
    }
    m.matrix=(int **) calloc((csomopot+1),sizeof(int*));
    for (i=0; i<=csomopot; ++i)
    {
        m.matrix[i]=(int *) calloc((csomopot+1),sizeof(int));
    }
    for (i=1; i<=csomopot; ++i)
    {
        for (j=1; j<=csomopot; ++j)
        {
            if ( i == j )
            {
                m.matrix[i][j]=0;
            }
            else
            {
                m.matrix[i][j]=INT_MAX;
            }
        }
    }
    for (i=1; i<=csomopot; ++i)
    {
        for (j=1; j<=csomopot; ++j)
        {
            printf("%i ",m.matrix[i][j]);
        }
        printf("\n");
    }
    for (i=0; i<elekszam; ++i)
    {
        m.matrix[elek[i].kezdopont][elek[i].vegpont]=elek[i].szuly;
    }
    printf("\n\n\n\n");
    for (i=1; i<=csomopot; ++i)
    {
        for (j=1; j<=csomopot; ++j)
        {
            printf("%i ",m.matrix[i][j]);
        }
        printf("\n");
    }
    for (i=1;i<=csomopot;++i){
        for (j=1;j<=csomopot;++j){
            if(i != j ){
                if (m.matrix[i][j] == INT_MAX){
                     ut[i][j]=0;
                }
                else{
                    ut[i][j]=i;
                }
            }
        }
    }
    for (k=1; k<=csomopot; ++k)
    {
        for(i=1; i<=csomopot; ++i)
        {
            for (j=1; j<=csomopot; ++j)
            {
                if (k != i && k != j && m.matrix[i][k] != INT_MAX && m.matrix[k][j] != INT_MAX)
                {
                    if ((m.matrix[i][k] + m.matrix[k][j]) < m.matrix[i][j])
                    {
                        m.matrix[i][j] = (m.matrix[i][k]+m.matrix[k][j]);
                        ut[i][j]=ut[k][j];
                    }
                }
            }
        }
    }
    printf("\n\n\n\n\n");
    for (i=1; i<=csomopot; ++i)
    {
        for (j=1; j<=csomopot; ++j)
        {
            printf("%i ",m.matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    for (i=1; i<=csomopot; ++i)
    {
        for (j=1; j<=csomopot; ++j)
        {
            printf("%i: ",m.matrix[i][j]);
            if (ut[i][j])
                lru(i,j,ut);
            printf("\n");

        }
        printf("\n");
    }
    return 0;
}

void lru(int i, int j, int**ut){
    if(i!=j){
        lru(i,ut[i][j], ut);
    }
    printf("%i ", j);
}
