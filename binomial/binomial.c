/* Dynamic Parogramming 1st. */
/*   Binomial Coefficient    */

#include <stdio.h>
#include <stdlib.h>

int binomial(int **arr, int n, int k);

int main(int argc, char** argv)
{
    int** map;
    int n, k;
    int i, m;
    int answer;
    
    if(argc < 3)
    {
        printf("./binomial n k\n");
        return -1;
    }
    
    n = atoi(argv[1]);
    k = atoi(argv[2]);

    answer = binomial(map, n, k);

    printf("\n%dC%d is %d\n", n, k, answer);

    return 0;
}

int binomial(int **arr, int n, int k)
{
    int i, m;

    arr = (int **)malloc(sizeof(int *) * (n+1));
    for(i = 0; i < n+1; i++)
        arr[i] = (int *)malloc(sizeof(int *) * (k+1));

    for(i = 0; i < n+1; i++)
    {
        for(m = 0; m < i+1; m++)
        {
            if(i == m || m == 0)
                arr[i][m] = 1;
            else if(i > m && m > 0)
                arr[i][m] = arr[i-1][m-1] + arr[i-1][m];
                        
        }
    }

    for(i = 0; i < n+1; i++)
    {
        for(m = 0; m < i+1; m++)
        {
            if(arr[i][m] != 0)
                printf("%d\t", arr[i][m]);
        }
        printf("\n");
    }

    return arr[n][k];
}
