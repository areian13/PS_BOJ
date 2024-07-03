#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int WrongCard(vector<int>& gnomes)
{
    int n = gnomes.size();

    for (int i = 0; i < n - 1; i++)
    {
        if (gnomes[i] + 1 != gnomes[i + 1])
            return i + 2;
    }
    return -1;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> gnomes(n);
        for (int i = 0; i < n; i++)
            cin >> gnomes[i];

        int result = WrongCard(gnomes);
        cout << result << '\n';
    }
}