#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        cnt += (a * 5 - b * 3 > 40);
    }

    string result = to_string(cnt) + (cnt == n ? "+" : "");
    cout << result << '\n';
}