#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHavingSame(vector<string>& words)
{
    unordered_map<string, bool> has;
    for (string& word : words)
    {
        if (has[word])
            return true;
        has[word] = true;
    }
    return false;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<string> words(n);
        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
            reverse(words[i].begin(), words[i].end());
        }

        int result = 0;
        while (true)
        {
            if (IsHavingSame(words))
            {
                result--;
                break;
            }

            bool empty = false;
            for (string& word : words)
            {
                word.pop_back();
                empty |= (word == "");
            }
            if (empty)
                break;

            result++;
        }
        cout << result << '\n';
    }
}