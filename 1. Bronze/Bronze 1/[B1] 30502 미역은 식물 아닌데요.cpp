#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> isPlant(n + 1, { -1,-1 });
    for (int i = 0; i < m; i++)
    {
        int a;
        char b;
        bool c;
        cin >> a >> b >> c;

        isPlant[a][b != 'P'] = c;
    }

    array<int, 2> result;
    for (int i = 1; i <= n; i++)
    {
        result[0] += (isPlant[i][0] == 1 && isPlant[i][1] == 0);
        result[1] += !(isPlant[i][0] == 0 || isPlant[i][1] == 1);
    }
    cout << result[0] << ' ' << result[1] << '\n';
}