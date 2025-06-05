#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int l, n;
    double t;
    cin >> l >> n >> t;

    bool result = false;
    for (int i = 0; i < n; i++)
    {
        double f, b;
        cin >> f >> b;

        double ti = l / f + l / b;
        result |= (ti < t);
    }

    if (result == true)
        cout << "HOPE" << '\n';
    else
        cout << "DOOMED" << '\n';
}