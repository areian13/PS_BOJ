#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    vector<bool> isBalloon(n, false);
    for (int i = 0; i < q; i++)
    {
        int l, k;
        cin >> l >> k;
        l--;

        for (int j = l; j < n; j += k)
            isBalloon[j] = true;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result += !isBalloon[i];
    cout << result << '\n';
}