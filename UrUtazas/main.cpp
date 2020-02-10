#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    int u, v;//u-v el, w-suly
    int w;
}EL;

void printElek(EL* elek, int m);
int** szomszedsagiLista_iranyitott(EL* elek, int n, int m);
void printSzL(int** SzL, int n);
void beszuro_rendezes(int*a,int start, int n);
int kivesz_min(int* Q, int n, int* tav);
int eleme(int* Q, int n, int v);
int dijkstra(EL* elek, int n, int m, int s, int** SzL);

int main()
{
    int s=2;
    FILE * fin=fopen("elek.txt","rt");
    if(!fin){
        printf("file error");
        return 0;
    }
    int n,m;
    fscanf(fin,"%i%i",&n,&m);
    EL*elek=(EL*)malloc(m*sizeof(EL));
    for(int i=0; i<m; i++){
        fscanf(fin,"%i%i%i",&elek[i].u,&elek[i].v, &elek[i].w);
    }
    fclose(fin);

    printf("Szomszedsagi lista:\n");
    int** SzL=szomszedsagiLista_iranyitott(elek,n,m);
    printSzL(SzL,n);

    printf("\nEllista:\n");
    printElek(elek,m);

    printf("\nLegrovidebb utak %i-bol:\n", s);
    int* d=dijkstra(elek,n,m,s,SzL);
    for(int i=1; i<=n; i++){
        printf("%i: ", i);
        if(d[i]==INT_MAX){
            printf("-\n");
        }
        else{
            printf("%i\n", d[i]);
        }
    }
    return 0;
}

int dijkstra(EL* elek, int n, int m, int s, int** SzL){
    int* d=(int*)calloc(n+1,sizeof(int));
    int* apa=(int*)calloc(n+1,sizeof(int));
    int* Q=(int*)malloc(n*sizeof(int));
    for(int i=1; i<=n; i++){
        d[i]=INT_MAX;
        Q[i-1]=i;
    }
    d[s]=0;
    apa[s]=0;
    for(int i=0; i<n; i++){
        int u=kivesz_min(Q,n-i,d);
        if(u==0){
            break;
        }
        for(int j=1; j<=SzL[u][0]; j++){
            int v=SzL[u][j];
            if(eleme(Q,n-i,v)){
                for(int k=0; k<m; k++){
                    if((elek[k].u==u && elek[k].v==v) || (elek[k].u==v && elek[k].v==u)){
                        if(d[u] + elek[k].w < d[v]){
                            d[v]=d[u] + elek[k].w;
                            apa[v]=u;
                        }
                    }
                }
            }
        }
    }
    return d;
}

int eleme(int* Q, int n, int v){
    for(int i=0; i<n; i++){
        if(Q[i]==v)
            return 1;
    }
    return 0;
}

int kivesz_min(int* Q, int n, int* tav){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(tav[Q[i]]>tav[Q[j]]){
                int v=Q[i];
                Q[i]=Q[j];
                Q[j]=v;
            }
        }
    }
    int ertek=Q[0];
    for(int i=0; i<n-1; i++){
        Q[i]=Q[i+1];
    }
    return ertek;
}

int** szomszedsagiLista_iranyitott(EL* elek, int n, int m){
    int**SzL=(int**)malloc((n+1)*sizeof(int*));
    for(int i=0; i<=n; i++){
        SzL[i]=(int*)calloc(1,sizeof(int));
    }
    for(int i=0; i<m; i++){
        int bal,jobb;
        bal=elek[i].u;
        jobb=elek[i].v;
        int* t=(int*)realloc(SzL[bal],(SzL[bal][0]+2)*sizeof(int));
        SzL[bal]=t;
        SzL[bal][0]++;
        SzL[bal][SzL[bal][0]]=jobb;
    }
    for(int i=1; i<=n; i++){
        beszuro_rendezes(SzL[i],1,SzL[i][0]);
    }
    return SzL;
}

void printSzL(int** SzL, int n){
    for(int i=1; i<=n; i++){
        printf("%i - %i: ",i, SzL[i][0]);
        for(int j=1; j<=SzL[i][0]; j++){
            printf("%i ", SzL[i][j]);
        }
        printf("\n");
    }
}

void beszuro_rendezes(int*a,int start, int n){
    for(int i=start; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(a[i]>a[j]){
                int v=a[i];
                a[i]=a[j];
                a[j]=v;
            }
        }
    }
}

void printElek(EL* elek, int m){
    for(int i=0; i<m; i++){
        printf("\t%i-%i: %i\n", elek[i].u, elek[i].v, elek[i].w);
    }
    printf("\n");
}
