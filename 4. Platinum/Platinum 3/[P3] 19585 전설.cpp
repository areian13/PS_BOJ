#include <iostream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

template <typename T>
struct Trie
{
    using K = typename iterator_traits<typename T::iterator>::value_type;

    map<K, Trie<T>*> go;
    int cntGo;
    int cntOut;

    Trie()
    {
        cntGo = 0;
        cntOut = 0;
    }
    ~Trie()
    {
        for (auto it = go.begin(); it != go.end(); it++)
        {
            if (it->second != nullptr)
            {
                delete it->second;
                it->second = nullptr;
            }
        }
    }

    void Insert(typename T::iterator key, typename T::iterator end)
    {
        if (key == end)
        {
            cntOut++;
            return;
        }

        if (go[*key] == nullptr)
        {
            go[*key] = new Trie<T>();
            cntGo++;
        }

        go[*key]->Insert(key + 1, end);
    }
};

bool IsLegendName(string& name, Trie<string>* colorTrie, unordered_set<string>& nickSet)
{
    int d = name.size();
    for (int i = 0; i < d; i++)
    {
        if (colorTrie->go[name[i]] == nullptr)
            return false;
        if (colorTrie->go[name[i]]->cntOut > 0
            && nickSet.find(name.substr(i + 1)) != nickSet.end())
            return true;
        colorTrie = colorTrie->go[name[i]];
    }
    return false;
}

int main()
{
    FastIO;

    int c, n;
    cin >> c >> n;

    Trie<string>* colorTrie = new Trie<string>();
    for (int i = 0; i < c; i++)
    {
        string color;
        cin >> color;

        colorTrie->Insert(color.begin(), color.end());
    }

    unordered_set<string> nickSet;
    for (int i = 0; i < n; i++)
    {
        string nick;
        cin >> nick;

        nickSet.insert(nick);
    }

    int q;
    cin >> q;

    while (q--)
    {
        string name;
        cin >> name;

        string result = IsLegendName(name, colorTrie, nickSet) ? "Yes" : "No";
        cout << result << '\n';
    }

    delete colorTrie;
}