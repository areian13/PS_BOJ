#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanLearn(int learnSpell, int wordSpell)
{
    for (int i = 0; i < 26; i++)
    {
        if ((wordSpell & 1 << i) && !(learnSpell & 1 << i))
            return false;
    }
    return true;
}

int CountLearnSpell(char lastSpell, int learnSpell, int l, int k, vector<int>& wordsSpell)
{
    if (k < 5)
        return 0;

    int n = wordsSpell.size();

    if (l == k)
    {
        int result = 0;
        for (int i = 0; i < n; i++)
            result += CanLearn(learnSpell, wordsSpell[i]);
        return result;
    }

    int result = 0;
    for (char c = lastSpell + 1; c <= 'z'; c++)
    {
        if (learnSpell & (1 << (c - 'a')))
            continue;

        learnSpell |= (1 << (c - 'a'));
        result = max(result, CountLearnSpell(c, learnSpell, l + 1, k, wordsSpell));
        learnSpell &= ~(1 << (c - 'a'));
    }
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<string> words(n);
    vector<int> wordsSpell(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];

        for (char spell : words[i])
            wordsSpell[i] |= (1 << (spell - 'a'));
    }

    int learnSpell = 0;
    learnSpell |= 1 << ('a' - 'a');
    learnSpell |= 1 << ('n' - 'a');
    learnSpell |= 1 << ('t' - 'a');
    learnSpell |= 1 << ('i' - 'a');
    learnSpell |= 1 << ('c' - 'a');

    int result = CountLearnSpell('a' - 1, learnSpell, 5, k, wordsSpell);
    cout << result << '\n';
}