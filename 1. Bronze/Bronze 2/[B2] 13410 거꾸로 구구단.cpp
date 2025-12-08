#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int result = 0;
    for (int i = 1; i <= k; i++)
    {
        string p = to_string(n * i);
        reverse(p.begin(), p.end());
        result = max(result, stoi(p));
    }
    cout << result << '\n';
}