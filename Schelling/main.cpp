#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int **create2D(int n)
{
    int **a;
    n += 2;
    a = (int **)calloc(n,sizeof(int*));
    for(int i=0; i<n; ++i)
    {
        a[i] = (int*)calloc(n,sizeof(int));
    }
    return a;
}
void print2D(int **a, int n)
{
    for(int i=1; i<n+1; ++i)
    {
        for(int j=1; j<n+1; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void feltolt(int **a, int n)
{
    srand(time(0));
    for(int i=1; i<n+1; ++i)
    {
        for(int j=1; j<n+1; ++j)
        {
            a[i][j] = rand()%3;
        }
    }
}

struct statM
{
    int kek;
    int piros;
};
statM** create_statM(int n)
{
    statM **s;
    s = new statM* [n];
    for(int i=0; i<n; ++i)
    {
        s[i] = new statM[n];
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            s[i][j].kek = 0;
            s[i][j].piros = 0;
        }
    }
    return s;
}
void kiir_statM(statM **s,int n)
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cout << s[i][j].kek << ",";
            cout << s[i][j].piros << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void stats(statM **s,int **a,int n)
{
    int k;
    int l;
    for(int i=1; i<n+1; ++i)
    {
        for(int j=1; j<n+1; ++j)
        {
            s[i-1][j-1].kek = 0;
            s[i-1][j-1].piros = 0;
            k = i-1;
            l = j-1;
            switch (a[k][l])
            {
            case 1 :
                s[i-1][j-1].kek++;
                break;
            case 2 :
                s[i-1][j-1].piros++;
                break;
            }
            ++l;
            switch (a[k][l])
            {
            case 1 :
                s[i-1][j-1].kek++;
                break;
            case 2 :
                s[i-1][j-1].piros++;
                break;
            }
            ++l;
            switch (a[k][l])
            {
            case 1 :
                s[i-1][j-1].kek++;
                break;
            case 2 :
                s[i-1][j-1].piros++;
                break;
            }
            ++k;
            switch (a[k][l])
            {
            case 1 :
                s[i-1][j-1].kek++;
                break;
            case 2 :
                s[i-1][j-1].piros++;
                break;
            }
            ++k;
            switch (a[k][l])
            {
            case 1 :
                s[i-1][j-1].kek++;
                break;
            case 2 :
                s[i-1][j-1].piros++;
                break;
            }
            --l;
            switch (a[k][l])
            {
            case 1 :
                s[i-1][j-1].kek++;
                break;
            case 2 :
                s[i-1][j-1].piros++;
                break;
            }
            --l;
            switch (a[k][l])
            {
            case 1 :
                s[i-1][j-1].kek++;
                break;
            case 2 :
                s[i-1][j-1].piros++;
                break;
            }
            --k;
            switch (a[k][l])
            {
            case 1 :
                s[i-1][j-1].kek++;
                break;
            case 2 :
                s[i-1][j-1].piros++;
                break;
            }
        }
    }
}

int search_F(statM **s,int **a,int i,int j,int n)
{

    switch (a[i][j])
    {
    case 1: // 1=kek
    {

        if(s[i-1][j-1].kek < 3)
        {

            for(int k=1; k<n+1; ++k)
            {
                for(int l=1; l<n+1; ++l)
                {

                    if(s[k-1][l-1].kek >= 3 && a[k][l] == 0)
                    {
                        a[k][l] = a[i][j];
                        a[i][j] = 0;

                        stats(s,a,n);

                        return 0;
                    }
                }
            }
            return 1;
        }
        break;
    }
    case 2: // 2=piros
    {

        if(s[i-1][j-1].piros < 3)
        {
            for(int k=1; k<n+1; ++k)
            {
                for(int l=1; l<n+1; ++l)
                {
                    if(s[k-1][l-1].piros >= 3 && a[k][l] == 0)
                    {

                        a[k][l] = a[i][j];
                        a[i][j] = 0;
                        stats(s,a,n);
                        return 0;
                    }
                }
            }
            return 1;
        }
        break;
    }
    }
    return 0;
}

int main()
{
    int n=4;

    int **a = create2D(n);
    feltolt(a,n);
    print2D(a,n);
    statM **s = create_statM(n);

    stats(s,a,n);
    kiir_statM(s,n);
    int sum = 0;
    for(int i=1; i<n+1; ++i)
    {
        for(int j=1; j<n+1; ++j)
        {
            if(a[i][j] == 0)
            {
                continue;
            }
            sum += search_F(s,a,i,j,n);
        }
    }

    print2D(a,n);
    cout << endl << sum;

    return 0;
}
