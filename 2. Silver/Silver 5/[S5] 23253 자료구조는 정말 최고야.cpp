#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    bool result = true;
    for (int i = 0; i < m; i++)
    {
        int k, p;
        cin >> k >> p;

        bool flag = true;
        for (int i = 1; i < k; i++)
        {
            int a;
            cin >> a;
            flag &= (p > a);
            p = a;
        }
        result &= flag;
    }

    cout << (result ? "Yes" : "No") << '\n';
}