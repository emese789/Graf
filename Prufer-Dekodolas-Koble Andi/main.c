#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin=fopen("be.txt","rt");
    int i, j,n;
    fscanf(fin,"%d",&n);
    int * prufer=(int*)calloc(n,sizeof(int));
    for(int i=1; i<n; i++)
    {
        fscanf(fin,"%d",&prufer[i]);
    }
    fclose(fin);
    printf("Prufer kodja: ");
    for(int i=1; i<n; ++i)
    {
        printf("%d ", prufer[i]);
    }
    printf("\n");

    int * fokszam=(int*)calloc(n+1,sizeof(int));
    for(i=1; i<=n ; ++i)
    {
        fokszam[i] = 1;
        for(j=1; j<n; ++j)
        {
            if (prufer[j] == i)
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
            if (fokszam[j] == 1)
            {
                printf("%d  %d\n",prufer[i], j);
                fokszam[prufer[i]]--;
                fokszam[j]--;
                break;
            }
        }
    }
    for (i = 1; i <=n; ++i)
    {
        if (fokszam[i] == 1)
        {
            printf("%d  ",i);
        }
    }
    free(fokszam);
        free(prufer);
        return 0;
    }

