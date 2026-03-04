#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, w;
    cin >> n >> w;

    int result = max((n * 10) + (n >= 3 ? 20 : 0) + (n == 5 ? 50 : 0) - (w > 1'000 ? 15 : 0), 0);
    cout << result << '\n';
}