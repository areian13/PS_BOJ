#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long r, k, m;
    cin >> r >> k >> m;

    long long result = (r >> min(m / k, 63LL));
    cout << result << '\n';
}