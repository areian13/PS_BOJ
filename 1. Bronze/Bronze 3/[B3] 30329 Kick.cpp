#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountKicks(string& s)
{
    int n = s.size();

    string kick = "kick";
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i + j < n && j < 4; j++)
        {
            if (s[i + j] != kick[j])
                break;
            if (j == 3)
            {
                result++;
                i += 2;
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = CountKicks(s);
    cout << result << '\n';
}