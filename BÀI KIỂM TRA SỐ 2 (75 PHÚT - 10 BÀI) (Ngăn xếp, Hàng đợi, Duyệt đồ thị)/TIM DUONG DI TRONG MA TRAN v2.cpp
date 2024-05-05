#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long hang;
    cin >> hang;
    long long a[hang][hang];
    for (long long i = 0; i < hang; i++)
    {
        for (long long j = 0; j < hang; j++)
            cin >> a[i][j];
    }
    // Tính xâu đường đi nhỏ nhất từ đầu đến các ô còn lại
    for (long long i = 0; i < hang; i++)
    {
        for (long long j = 0; j < hang; j++)
        {
            if (i == 0 && j != 0)
            { // Hang đầu tiên nhưng không phải cột đầu tiên
                a[i][j] = a[i][j - 1] * 2 + a[i][j];
            }
            else if (i != 0 && j == 0)
            { // Cột đầu tiên nhưng không phải hàng đầu tiên
                a[i][j] = a[i - 1][j] * 2 + a[i][j];
            }
            else if (i != 0 && j != 0)
            {
                a[i][j] = max(a[i - 1][j] * 2 + a[i][j], a[i][j - 1] * 2 + a[i][j]);
            }
        }
    }
    cout << hex << a[hang - 1][hang - 1] << endl;
}