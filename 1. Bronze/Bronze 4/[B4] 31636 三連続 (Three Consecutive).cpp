#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsOOO(string& s)
{
    int cnt = 0;
    for (char c : s)
    {
        if (c == 'o')
            cnt++;
        else
            cnt = 0;

        if (cnt == 3)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = (IsOOO(s) ? "Yes" : "No");
    cout << result << '\n';
}