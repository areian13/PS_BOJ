#include <iostream>
#include <climits>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k, n;
    cin >> k >> n;

    int sum = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        sum += a;
        minPrice = min(minPrice, a);
    }

    string result = (sum - minPrice >= k ? "YES" : "NO");
    cout << result << '\n';
}