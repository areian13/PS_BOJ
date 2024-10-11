#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_GO 10

struct Trie
{
    array<Trie*, MAX_GO> go;
    bool isOut;
    bool hasGo;

    Trie()
    {
        go.fill(nullptr);
        isOut = hasGo = false;
    }
    ~Trie()
    {
        for (int i = 0; i < MAX_GO; i++)
        {
            if (go[i] != nullptr)
                delete go[i];
        }
    }

    void Insert(string& s)
    {
        Insert(s.c_str());
    }
    void Insert(const char* key)
    {
        if (*key == '\0')
            isOut = true;
        else
        {
            int next = *key - '0';

            if (!go[next])
                go[next] = new Trie();

            hasGo = true;
            go[next]->Insert(key + 1);
        }
    }
    bool IsConsistent()
    {
        if (hasGo && isOut)
            return false;
        for (int i = 0; i < MAX_GO; i++)
        {
            if (go[i] != nullptr && !go[i]->IsConsistent())
                return false;
        }
        return true;
    }
};

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        Trie* trie = new Trie();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            trie->Insert(s);
        }

        string result = (trie->IsConsistent() ? "YES" : "NO");
        cout << result << '\n';
        delete trie;
    }
}