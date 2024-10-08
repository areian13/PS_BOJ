#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0;
    int right = 0;

    int sum = 0;
    int result = 0;
    while (true)
    {
        if (sum >= m)
            sum -= a[left++];
        else if (right == n)
            break;
        else
            sum += a[right++];

        if (sum == m)
            result++;
    }
    cout << result << '\n';
}