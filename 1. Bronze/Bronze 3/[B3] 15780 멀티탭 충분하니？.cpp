#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;

        sum += (a + 1) / 2;
    }

    string result = (sum >= n ? "YES" : "NO");
    cout << result << '\n';
}