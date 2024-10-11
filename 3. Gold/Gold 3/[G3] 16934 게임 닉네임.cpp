#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Trie
{
    map<char, Trie*> go;
    int cntOut;

    Trie()
    {
        cntOut = 0;
    }
    ~Trie()
    {
        for (auto it = go.begin(); it != go.end(); it++)
            delete go[it->first];
    }

    pair<string::iterator, int> Insert(string::iterator key, string::iterator end)
    {
        if (key == end)
        {
            cntOut++;
            return { end,cntOut };
        }

        auto it = make_pair(end, 0);
        if (go[*key] == nullptr)
        {
            go[*key] = new Trie();
            it = { key,0 };
        }

        auto temp = go[*key]->Insert(key + 1, end);
        if (it.first == end)
            it = temp;
        return it;
    }

};

int main()
{
    FastIO;

    int n;
    cin >> n;

    Trie* trie = new Trie();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        auto it = trie->Insert(s.begin(), s.end());
        if (it.first == s.end())
        {
            string result = s;
            if (it.second > 1)
                result += to_string(it.second);

            cout << result << '\n';
        }
        else
        {
            string result = s.substr(0, it.first - s.begin() + 1);
            cout << result << '\n';
        }
    }
    delete trie;
}