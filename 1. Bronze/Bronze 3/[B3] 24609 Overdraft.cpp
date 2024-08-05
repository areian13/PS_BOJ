#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        sum += t;
        result = max(result, -sum);
    }
    cout << result << '\n';
}