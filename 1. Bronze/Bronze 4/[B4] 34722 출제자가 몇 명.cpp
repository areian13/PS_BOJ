#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanProblem(int s, int c, int a, int r)
{
    if (s >= 1'000) return true;
    if (c >= 1'600) return true;
    if (a >= 1'500) return true;
    return (r != -1 && r <= 30);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int s, c, a, r;
        cin >> s >> c >> a >> r;

        result += CanProblem(s, c, a, r);
    }
    cout << result << '\n';
}