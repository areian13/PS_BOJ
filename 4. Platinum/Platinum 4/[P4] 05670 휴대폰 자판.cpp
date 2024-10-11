#include <iostream>
#include <array>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_GO 26

struct Trie
{
    array<Trie*, MAX_GO> go;
    bool isOut;
    int cntGo;

    Trie()
    {
        go.fill(nullptr);
        isOut = false;
        cntGo = 0;
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
            int next = *key - 'a';

            if (go[next] == nullptr)
            {
                go[next] = new Trie();
                cntGo++;
            }

            go[next]->Insert(key + 1);
        }
    }

    int CountTyping(string& s)
    {
        int result = 1;
        Trie* curr = go[s[0] - 'a'];
        for (int i = 1; s[i] != '\0'; i++)
        {
            if (curr->cntGo != 1 || curr->isOut)
                result++;
            curr = curr->go[s[i] - 'a'];
        }
        return result;
    }
};

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        vector<string> words(n);
        Trie* trie = new Trie();
        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
            trie->Insert(words[i]);
        }

        double result = 0;
        for (int i = 0; i < n; i++)
            result += trie->CountTyping(words[i]);
        result /= n;

        printf("%.2lf\n", result);
        delete trie;
    }
}