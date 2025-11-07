#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<bool> h(n);
    for (int i = 0; i < k; i++)
    {
        int d;
        cin >> d;
        h[d - 1] = true;
    }
    h[0] = true;

    int result = 1;
    for (int i = 1; i < n; i++)
    {
        h[i] = (h[i] || !h[i - 1]);
        result += h[i];
    }
    cout << result << '\n';
}