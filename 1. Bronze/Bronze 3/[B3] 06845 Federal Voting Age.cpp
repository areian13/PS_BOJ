#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int HashDate(int y, int m, int d)
{
    return y * 1000 + m * 100 + d;
}

bool CanVote(int y, int m, int d)
{
    return HashDate(y, m, d) <= HashDate(1989, 2, 27);
}

int main()
{
    FastIO;

    int hashTime = 1989 * 1000 + 2 * 100 + 27;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int y, m, d;
        cin >> y >> m >> d;

        string result = CanVote(y, m, d) ? "Yes" : "No";
        cout << result << '\n';
    }
}