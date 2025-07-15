#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int p = 0;
    bool result = true;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        result &= (a >= p);
        p = a;
    }

    if (result)
        cout << "yes" << '\n';
    else
        cout << "no" << '\n';
}