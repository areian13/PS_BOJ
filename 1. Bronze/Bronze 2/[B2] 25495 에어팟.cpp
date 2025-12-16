#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0, pre = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0 || a[i] != a[i - 1])
            pre = 2;
        else
            pre *= 2;

        result += pre;
        if (result >= 100)
        {
            result = 0;
            pre = 0;
        }
    }
    cout << result << '\n';
}