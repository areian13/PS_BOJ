#include <iostream>
#include <array>
#include <climits>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 4> subak;
    for (int i = 0; i < 4; i++)
        cin >> subak[i];

    array<int, 4> idx = { 0,1,2,3 };
    int result = INT_MAX;
    do
    {
        result = min(result, abs(subak[idx[0]] + subak[idx[1]] - (subak[idx[2]] + subak[idx[3]])));
        result = min(result, abs(subak[idx[0]] - (subak[idx[1]] + subak[idx[2]] + subak[idx[3]])));
    } while (next_permutation(idx.begin(), idx.end()));
    cout << result << '\n';
}