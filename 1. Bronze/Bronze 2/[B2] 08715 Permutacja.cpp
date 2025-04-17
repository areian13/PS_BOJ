#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<bool> has(n, false);
    bool result = true;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a--;

        if (!(0 <= a && a <= n - 1) || has[a])
        {
            result = false;
            break;
        }
        has[a] = true;
    }

    if (result == true)
        cout << "TAK" << '\n';
    else
        cout << "NIE" << '\n';
}