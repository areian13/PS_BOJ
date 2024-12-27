#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10

int main()
{
    FastIO;

    array<int, MAX> w;
    for (int i = 0; i < MAX; i++)
        cin >> w[i];
    sort(w.begin(), w.end());

    array<int, MAX> k;
    for (int i = 0; i < MAX; i++)
        cin >> k[i];
    sort(k.begin(), k.end());

    int ws = accumulate(w.end() - 3, w.end(), 0);
    int ks = accumulate(k.end() - 3, k.end(), 0);
    cout << ws << ' ' << ks << '\n';
}