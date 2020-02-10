#include <iostream>
#include <queue>
#include <algorithm>
#include<fstream>
#include<vector>

using namespace std;

typedef struct t{
int a,b;
}

void javit(t[][20],int u,int apa[],int *min1)
{
    if(apa[u]<0)
    {
        int c=-apa[u];
        if(min1>t[u][c].b)
            min1=t[u][c].b;
        javit(t, c, apa, min1);
        t[u][c].f-=min1;
    }
    else
    {
        if(apa[u]>0)
        {
            int v=apa[u];
            if(min1>-a[v][u].f)
                min1=a[v][u].c-a[v][u].f;

        javitas(a, v, apa, minn);
        t[v][u].f+=min1;}
    }

}
int fordFulkerson()

int main(){

}
