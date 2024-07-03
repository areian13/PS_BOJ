#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> vote(n, 0);
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int score;
                cin >> score;

                vote[i] += score;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (vote[result] < vote[i])
                result = i;
        }
        cout << result + 1 << '\n';
    }
}