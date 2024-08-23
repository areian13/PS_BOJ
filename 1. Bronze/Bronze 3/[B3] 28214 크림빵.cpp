#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k, p;
    cin >> n >> k >> p;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;

            cnt += (a == 0);
        }
        result += (cnt < p);
    }
    cout << result << '\n';
}