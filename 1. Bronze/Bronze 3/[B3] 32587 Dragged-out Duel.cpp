#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string a, b;
    cin >> n >> a >> b;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            continue;

        if (a[i] == 'R')
            cnt += (b[i] == 'S' ? +1 : -1);
        else if (a[i] == 'S')
            cnt += (b[i] == 'P' ? +1 : -1);
        else if (a[i] == 'P')
            cnt += (b[i] == 'R' ? +1 : -1);
    }

    bool result = (cnt > 0);
    if (result == true)
        cout << "victory" << '\n';
    else
        cout << "defeat" << '\n';
}