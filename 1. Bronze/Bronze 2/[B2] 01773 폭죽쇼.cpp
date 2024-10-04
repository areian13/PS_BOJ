#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, c;
    cin >> n >> c;

    vector<bool> isExploded(c + 1, false);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        for (int j = k; j <= c; j += k)
            isExploded[j] = true;
    }

    int result = accumulate(isExploded.begin(), isExploded.end(), 0);
    cout << result << '\n';
}