#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int LoopABC(string& s)
{
    int n = s.size(), i = 0;
    int result = 0;
    while (true)
    {
        result++;
        for (int j = 0; j < 26; j++)
        {
            if (s[i] - 'a' == j)
                i++;
            if (i == n)
                return result;
        }
    }
    return -1;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int result = LoopABC(s);
    cout << result << '\n';
}