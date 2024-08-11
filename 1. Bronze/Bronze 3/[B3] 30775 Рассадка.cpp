#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, k;
    cin >> m >> k;

    long long result = 0;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;

        result += n;
    }
    result = (result - 1) / m + 1;

    cout << result << '\n';
}