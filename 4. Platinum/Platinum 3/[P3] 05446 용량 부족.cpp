#include <iostream>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

template <typename T, typename K>
struct Trie
{
    unordered_map<K, Trie<T, K>*> go;
    int cntGo;
    int cntOut;
    bool canDelete;
    bool willDelete;

    Trie()
    {
        cntGo = 0;
        cntOut = 0;
        canDelete = false;
        willDelete = false;
    }
    ~Trie()
    {
        for (auto it = go.begin(); it != go.end(); it++)
            delete it->second;
    }

    void Insert(typename T::iterator key, typename T::iterator end,
        bool canDelete)
    {
        this->canDelete = canDelete;

        if (key == end)
        {
            willDelete = canDelete;
            cntOut++;
            return;
        }

        if (go[*key] == nullptr)
        {
            go[*key] = new Trie<T, K>();
            cntGo++;
        }

        go[*key]->Insert(key + 1, end, canDelete);
    }

    int CountMinDelete()
    {
        int result = 0;
        if (willDelete && !canDelete)
            result++;
        else if (canDelete)
            return 1;

        for (auto it = go.begin(); it != go.end(); it++)
            result += it->second->CountMinDelete();
        return result;
    }
};

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        Trie<string, char>* trie = new Trie<string, char>();

        int n1;
        cin >> n1;

        for (int i = 0; i < n1; i++)
        {
            string s;
            cin >> s;

            trie->Insert(s.begin(), s.end(), true);
        }

        int n2;
        cin >> n2;

        for (int i = 0; i < n2; i++)
        {
            string s;
            cin >> s;

            trie->Insert(s.begin(), s.end(), false);
        }

        int result = trie->CountMinDelete();
        cout << result << '\n';
        delete trie;
    }
}