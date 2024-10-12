#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 3'000
#define MOD 1'000'000'007

long long Facto(int n)
{
    static vector<long long> facto(MAX + 1);
    static bool isInited = false;

    if (!isInited)
    {
        isInited = true;

        facto[0] = facto[1] = 1;
        for (int i = 2; i <= MAX; i++)
            facto[i] = facto[i - 1] * i % MOD;
    }

    return facto[n];
}

struct Trie
{
    vector<Trie*> go;
    char c;
    int cntOut;
    int cntGo;

    Trie()
    {
        c = '\0';
        cntOut = 0;
        cntGo = 0;
    }
    ~Trie()
    {
        for (Trie* t : go)
            delete t;
    }

    void Insert(string::iterator key, string::iterator end)
    {
        if (key == end)
        {
            cntOut++;
            return;
        }

        Trie* next = nullptr;
        for (Trie* t : go)
        {
            if (t->c == *key)
                next = t;
        }

        if (next == nullptr)
        {
            next = new Trie();
            next->c = *key;
            cntGo++;

            go.push_back(next);
        }

        next->Insert(key + 1, end);
    }
};

long long CountCase(Trie* trie)
{
    long long result = Facto(trie->cntGo + trie->cntOut);
    for (Trie* t : trie->go)
    {
        result *= CountCase(t);
        result %= MOD;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    Trie* trie = new Trie();
    for (int i = 0; i < n; i++)
        trie->Insert(words[i].begin(), words[i].end());

    int result = CountCase(trie);
    cout << result << '\n';
    delete trie;
}