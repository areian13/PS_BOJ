#include <iostream>
#include <array>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Trie
{
    array<Trie*, 2> go;
    int cntGo;
    int cntOut;

    Trie()
    {
        go.fill(nullptr);
        cntGo = 0;
        cntOut = 0;
    }
    ~Trie()
    {
        for (Trie* t : go)
        {
            if (t != nullptr)
                delete t;
        }
    }

    void Insert(string::iterator key, string::iterator end)
    {
        if (key == end)
        {
            cntOut++;
            return;
        }

        int next = *key - '0';
        if (go[next] == nullptr)
        {
            go[next] = new Trie();
            cntGo++;
        }

        go[next]->Insert(key + 1, end);
    }
    void Delete(string::iterator key, string::iterator end)
    {
        if (key == end)
        {
            cntOut--;
            return;
        }

        int next = *key - '0';
        go[next]->Delete(key + 1, end);

        if (key + 1 == end && go[next]->cntOut == 0 ||
            key + 1 != end && go[next]->cntGo == 0)
        {
            delete go[next];
            go[next] = nullptr;
            cntGo--;
        }
    }
};

string MaxXORStr(string& str, Trie* trie)
{
    int d = str.size();

    string result = "";
    for (int i = 0; i < d; i++)
    {
        bool next = str[i] - '0';
        if (trie->go[next] == nullptr && trie->go[!next] == nullptr)
        {
            result += string(d - i, '1');
            break;
        }

        if (trie->go[!next] != nullptr)
        {
            result += '1';
            trie = trie->go[!next];
        }
        else
        {
            result += '0';
            trie = trie->go[next];
        }
    }
    return result;
}

string Bin31(int x)
{
    string result = "";
    for (int i = 0; i < 31; i++)
    {
        result += x % 2 + '0';
        x /= 2;
    }
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    Trie* trie = new Trie();
    string r(31, '0');
    trie->Insert(r.begin(), r.end());
    for (int i = 0; i < n; i++)
    {
        int t, x;
        cin >> t >> x;

        string s = Bin31(x);
        if (t == 1)
            trie->Insert(s.begin(), s.end());
        else if (t == 2)
            trie->Delete(s.begin(), s.end());
        else if (t == 3)
        {
            int result = stoi(MaxXORStr(s, trie), nullptr, 2);
            cout << result << '\n';
        }
    }
}