#include <iostream>
#include <map>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Trie
{
    map<string, Trie*> go;

    ~Trie()
    {
        for (auto it = go.begin(); it != go.end(); it++)
            delete go[it->first];
    }

    void Insert(vector<string>& s)
    {
        Insert(s.begin(), s.end());
    }
    void Insert(vector<string>::iterator key, vector<string>::iterator end)
    {
        if (key == end)
            return;

        if (go[*key] == nullptr)
            go[*key] = new Trie();
        go[*key]->Insert(key + 1, end);
    }

    void Print(int d)
    {
        for (auto it = go.begin(); it != go.end(); it++)
        {
            for (int i = 0; i < d; i++)
                cout << "--";
            cout << (*it).first << '\n';
            go[it->first]->Print(d + 1);
        }
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
        int k;
        cin >> k;

        vector<string> words(k);
        for (int i = 0; i < k; i++)
            cin >> words[i];

        trie->Insert(words);
    }

    trie->Print(0);
    delete trie;
}