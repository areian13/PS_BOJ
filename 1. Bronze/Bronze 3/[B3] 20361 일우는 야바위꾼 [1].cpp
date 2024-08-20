#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, x, k;
    cin >> n >> x >> k;
    x--;

    vector<bool> isBall(n, false);
    isBall[x] = true;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        swap(isBall[a], isBall[b]);
    }

    int result = max_element(isBall.begin(), isBall.end()) - isBall.begin();
    cout << result + 1 << '\n';
}