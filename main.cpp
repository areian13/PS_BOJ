#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long MinPunish(vector<long long>& r)
{
    int n = r.size();

    array<long long, 2> sum = { 0,0 };
    for (int i = 0; i < n; i++)
        sum[i % 2] += r[i];

    return min(sum[0], sum[1]);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<long long> r(n);
    for (int i = 0; i < n; i++)
        cin >> r[i];

    long long result = MinPunish(r);
    cout << result << '\n';
}