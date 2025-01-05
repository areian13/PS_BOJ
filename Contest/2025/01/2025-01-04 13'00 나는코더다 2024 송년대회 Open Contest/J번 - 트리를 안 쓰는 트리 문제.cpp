#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int k = n * 2 - 1;
    cout << k << '\n';

    vector<int> temp;
    for (int i = 0; i < n - 1; i++)
    {
        int s = i * n + i + 1;
        int e = s + n - 1;

        cout << s << ' ' << e << ' ' << i + 1 << ' ' << 1 << '\n';
        temp.push_back(e + 1);
    }
    temp.push_back(n * n);

    for (int i = 0; i < n; i++)
    {
        int s = temp[i];
        cout << s << ' ' << s << ' ' << n << ' ' << i + 1 << '\n';
    }
}