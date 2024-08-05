#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int result = 0;
        for (int i = 1; i < n - 1; i++)
            result += (v[i - 1] < v[i] && v[i] > v[i + 1]);
        cout << result << '\n';
    }
}