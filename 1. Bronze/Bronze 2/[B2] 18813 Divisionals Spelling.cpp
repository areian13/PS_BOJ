#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanSolve(int m, string& word)
{
    vector<bool> isUsed(m, false);
    for (char alp : word)
    {
        if (('A' <= alp && alp <= 'A' + m - 1) && !isUsed[alp - 'A'])
            isUsed[alp - 'A'] = true;
        else
            return false;
    }
    return true;

}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;

        result += CanSolve(m, word);
    }
    cout << result << '\n';
}