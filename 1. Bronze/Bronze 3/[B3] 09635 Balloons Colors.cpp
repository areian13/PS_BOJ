#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Difficulty(bool isEasy, bool isHard)
{
    if (isEasy && isHard)
        return "BOTH";
    if (isEasy)
        return  "EASY";
    if (isHard)
        return "HARD";
    return "OKAY";
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        bool isEasy = false, isHard = false;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            isEasy |= ((i == 0) && num == x);
            isHard |= ((i == n - 1) && num == y);
        }

        string result = Difficulty(isEasy, isHard);
        cout << result << '\n';
    }
}