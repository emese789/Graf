#include <stdio.h>
//pruffervissza
int main()
{
    FILE * f = fopen("be.txt","r");
    int i, j, n;
    fscanf(f, "%d", &n);
    int * pruffer =(int*)calloc(n,sizeof(int));
    for(int i=1; i<n; ++i)
    {
        fscanf(f,"%d", &pruffer[i]);
    }
    fclose(fin);
    printf("Prufer kod: ");
    for(int i=1; i<n; ++i)
    {
        printf("%d ", pruffer[i]);
    }
    printf("\n");

    int * fokszam=(int*)calloc(n+1,sizeof(int));
    for(i=1; i<=n ; ++i)
    {
        fokszam[i] = 1;
        for(j=1; j<n; ++j)
        {
            if (pruffer[j] == i)
            {
                fokszam[i]++;
            }
        }
    }
    fokszam[n+1]--;
    printf("Fokszam: ");
    for(i=1; i<=n; ++i)
    {
        printf("%d ",fokszam[i]);
    }
    printf("\n");
    printf("Ellista: \n");
    for (i=1; i<n+2; ++i)
    {
        for(j=1; j<n+2; ++j)
        {
            if (fokszam[j] == 1){
                printf("%d  %d\n",pruffer[i], j);
                fokszam[pruffer[i]]--;
                fokszam[j]--;
                break;
            }
        }
    }
    for (i = 1; i <=n; ++i){
        if (fokszam[i] == 1){printf("%d  ",i);}
    }
    free(fokszam):
    free(pruffer);
    return 0;
}
