#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin>> n >> m;

    unordered_map<string, int> cnt;
    vector<string> result;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin>>word;

        if (word.size() < m)
            continue;

        cnt[word]++;
        if (cnt[word] == 1)
            result.push_back(word);
    }
    sort(result.begin(), result.end(),
        [&cnt](const string& a, const string& b)
        {
            if (cnt[a] != cnt[b])
                return cnt[a] > cnt[b];
            if (a.size() != b.size())
                return a.size() > b.size();
            return a < b;
        }
    );

    for (string& word : result)
        cout << word << ' ';
    cout << '\n';
}