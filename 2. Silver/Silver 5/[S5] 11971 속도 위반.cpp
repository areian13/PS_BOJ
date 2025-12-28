#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 100;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> limit(MAX + 1);
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        int d, l;
        cin >> d >> l;

        for (int j = 1; j <= d; j++)
            limit[pre + j] = l;
        pre += d;
    }

    int result = 0;
    pre = 0;
    for (int i = 0; i < m; i++)
    {
        int d, s;
        cin >> d >> s;

        for (int j = 1; j <= d; j++)
            result = max(result, s - limit[pre + j]);
        pre += d;
    }
    cout << result << '\n';
}