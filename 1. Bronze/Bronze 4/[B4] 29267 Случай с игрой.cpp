#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int cur = 0, pre = 0;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;

        if (a == "save")
            pre = cur;
        else if (a == "load")
            cur = pre;
        else if (a == "shoot")
            cur--;
        else if (a == "ammo")
            cur += k;

        cout << cur << '\n';
    }
}