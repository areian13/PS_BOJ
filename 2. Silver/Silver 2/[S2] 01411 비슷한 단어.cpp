#include <iostream>
#include <vector>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsSimilarString(string& a, string& b)
{
    int k = a.size();
    
    array<char, 26> atob = { '\0', };
    array<char, 26> btoa = { '\0', };

    for (int i = 0; i < k; i++)
    {
        int c1 = a[i] - 'a';
        int c2 = b[i] - 'a';

        if (atob[c1] == '\0' && btoa[c2] == '\0')
        {
            atob[c1] = b[i];
            btoa[c2] = a[i];
        }
        else if (atob[c1] != b[i] || btoa[c2] != a[i])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    int result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            result += IsSimilarString(words[i], words[j]);
    }
    cout << result << '\n';
}