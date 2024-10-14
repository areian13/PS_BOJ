#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> words(n + 1);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    sort(words.begin(), words.end(),
        [](const string& a, const string& b)
        {
            if (a.size() != b.size())
                return a.size() < b.size();
            return a < b;
        }
    );

    for (int i = 1; i <= n; i++)
    {
        if (words[i] != words[i - 1])
            cout << words[i] << '\n';
    }
}