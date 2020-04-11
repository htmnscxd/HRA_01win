#include <bits/stdc++.h>
using namespace std;

#define N 5000

void printMaxSumSub(int **mat, int n, int k)
{
    if (k > n) return;
    int stripSum[n][n];

    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += mat[i][j];
        stripSum[0][j] = sum;

        for (int i = 1; i < n - k + 1; i++)
        {
            sum += (mat[i + k - 1][j] - mat[i - 1][j]);
            stripSum[i][j] = sum;
        }
    }

    int max_sum = INT_MIN, *pos = NULL;

    for (int i = 0; i < n - k + 1; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
            sum += stripSum[i][j];

        if (sum > max_sum)
        {
            max_sum = sum;
            pos = &(mat[i][0]);
        }

        for (int j = 1; j < n - k + 1; j++)
        {
            sum += (stripSum[i][j + k - 1] - stripSum[i][j - 1]);

            if (sum > max_sum)
            {
                max_sum = sum;
                pos = &(mat[i][j]);
            }
        }
    }

    cout << max_sum;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int **mat = new int*[n];
    for(int i = 0; i < n; i++)
        mat[i] = new int[n];
    for (int i =0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    printMaxSumSub(mat,n, k);

    return 0;
}
