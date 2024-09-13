#include <iostream>
#include <array>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 26> cnt = { 0, };
    while (true)
    {
        string line;
        getline(cin, line);

        if (cin.eof())
            break;

        for (char c : line)
        {
            if(c != ' ')
                cnt[c - 'a']++;
        }
    }

    int maxCnt = *max_element(cnt.begin(), cnt.end());
    string result = "";
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == maxCnt)
            result += (i + 'a');
    }
    cout << result << '\n';
}