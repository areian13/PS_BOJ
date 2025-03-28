#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int result = 0;
    while (true)
    {
        string s;
        getline(cin, s);

        if (!cin) // cin.eof()로 하면 틀리는건 테케 문제;
            break;

        int n = s.size();
        for (int i = 0; i < n - 3; i++)
            result += s.substr(i, 4) == "joke";
    }
    cout << result << '\n';
}