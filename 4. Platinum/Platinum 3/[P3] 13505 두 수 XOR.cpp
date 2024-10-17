#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

template <typename T, typename K>
struct Trie
{
    unordered_map<K, Trie<T, K>*> go;
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
            go[*key] = new Trie<T, K>();
            cntGo++;
        }

        go[*key]->Insert(key + 1, end);
    }
};

string MaxXorStr(string& s, Trie<string, char>* trie)
{
    int d = s.size();

    string result = "";
    for (int i = 0; i < d; i++)
    {
        int next = s[i] - '0';
        if (trie->go[!next + '0'] != nullptr)
        {
            result += '1';
            trie = trie->go[!next + '0'];
        }
        else if (trie->go[next + '0'] != nullptr)
        {
            result += '0';
            trie = trie->go[next + '0'];
        }
    }
    return result;
}

string To31Bit(int n)
{
    string result = "";
    for (int i = 0; i < 31; i++)
    {
        result += n % 2 + '0';
        n /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    Trie<string, char>* trie = new Trie<string, char>();
    string maxBit(31, '0');
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        string bit = To31Bit(a);
        trie->Insert(bit.begin(), bit.end());
        maxBit = max(maxBit, MaxXorStr(bit, trie));
    }

    int result = stoi(maxBit, nullptr, 2);
    cout << result << '\n';
    delete trie;
}