#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int result = (k - n + 1) / n;
    cout << result << '\n';
}