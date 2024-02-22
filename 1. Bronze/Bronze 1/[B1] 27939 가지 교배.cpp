#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<bool> PW(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char pw;
        cin >> pw;

        PW[i] = (pw == 'W');
    }

    int m, k;
    cin >> m >> k;

    int cntW = 0;
    for (int i = 0; i < m; i++)
    {
        bool isW = true;
        for (int j = 0; j < k; j++)
        {
            int s;
            cin >> s;

            isW &= PW[s];
        }
        cntW += isW;
    }

    char result = (cntW >= 1 ? 'W' : 'P');
    cout << result << '\n';
}