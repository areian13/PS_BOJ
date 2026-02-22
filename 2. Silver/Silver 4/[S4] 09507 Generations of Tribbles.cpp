#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 67;
vector<long long> koong(MAX + 1);

int main()
{
    FastIO;

    koong[0] = koong[1] = 1;
    koong[2] = 2;
    koong[3] = 4;
    for (int i = 4; i <= MAX; i++)
        koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        cout << koong[n] << '\n';
    }
}