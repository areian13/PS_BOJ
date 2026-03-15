#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> div;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            div.push_back(i);
    }

    if (div.size() < k)
        cout << 0 << '\n';
    else
        cout << div[k - 1] << '\n';
}