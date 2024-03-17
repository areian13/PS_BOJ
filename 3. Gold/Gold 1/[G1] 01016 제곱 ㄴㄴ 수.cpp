#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountNoSquare(long long min, long long max)
{
    int n = max - min + 1;

    vector<bool> isNoSqr(n, true);
    for (long long i = 2; i * i <= max; i++)
    {
        long long sqr = i * i;
        long long start = min / sqr + (min % sqr != 0);

        for (long long j = start; sqr * j <= max; j++)
            isNoSqr[sqr * j - min] = false;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result += isNoSqr[i];
    return result;
}

int main()
{
    FastIO;

    long long min, max;
    cin >> min >> max;

    int result = CountNoSquare(min, max);
    cout << result << '\n';
}