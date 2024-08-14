#include <iostream>
#include <array>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int D(int p, array<int, 9> gradeCut)
{
    for (int i = 0; i < 9; i++)
    {
        if (p <= gradeCut[i])
            return i + 1;
    }
    return -1;
}

int main()
{
    FastIO;

    array<int, 9> gradeCut = { 4,11,23,40,60,77,89,96,100 };

    int n, k;
    cin >> n >> k;

    vector<int> result(k);
    for (int i = 0; i < k; i++)
    {
        int g;
        cin >> g;

        result[i] = D(g * 100 / n, gradeCut);
    }

    for (int i = 0; i < k; i++)
        cout << result[i] << ' ';
    cout << '\n';
}