#include <stdio.h>
#include <stdlib.h>

int main()
{
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
    for(int i=0; i<=p; ++i)
    {
        free(szl[i]);
    }
    free(szl);
    return 0;
}


