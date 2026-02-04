#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int QC;
    cin >> QC;

    for (int qc = 1; qc <= QC; qc++)
    {
        int m;
        cin >> m;

        int result = 6 * 60 + (m / 50) * 12 + 6;
        if (result > 24 * 60)
            printf("-1\n");
        else
        {
            result %= 24 * 60;
            printf("%02d:%02d\n", result / 60, result % 60);
        }
    }
}