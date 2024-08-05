#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 50'000

int main()
{
    FastIO;

    array<int, MAX + 1> t = { 0, };

    int l1, r1, l2, r2, k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;

    for (int i = l1; i <= r1; i++)
        t[i]++;
    for (int i = l2; i <= r2; i++)
        t[i]++;
    t[k]--;

    int result = 0;
    for (int i = 1; i <= MAX; i++)
        result += (t[i] == 2);
    cout << result << '\n';
}