#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    long int a[n][2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> a[i][j];
    bool dd = false;
    long int sum = 0;
    long int maxSum = 0;
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            sum = a[i][1] - a[i][0];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    else if (k == 2) {
        for (int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if((a[i][1] < a[j][0]) || (a[i][0] > a[j][1]))
                {
                    dd = true;
                    sum = a[i][1] - a[i][0] + a[j][1] - a[j][0];
                }
                if (sum > maxSum)
                    maxSum = sum;
            }
        }
    }
    else if (k == 3) {
        for (int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                for (int m = j+1; m < n; m++) {
                    if(((a[i][1] < a[j][0]) || (a[i][0] > a[j][1])) ||
                        ((a[i][1] < a[m][0]) || (a[i][0] > a[m][1])) ||
                        ((a[j][1] < a[m][0]) || (a[j][0] > a[m][1])))
                    {
                        dd = true;
                        sum = a[i][1] - a[i][0] + a[j][1] - a[j][0] + a[m][1] - a[m][0];
                    }
                    if (sum > maxSum)
                        maxSum = sum;
                }
            }
        }
    }

    if (dd == true)
        cout << maxSum;
    else cout << -1;

    return 0;
}
