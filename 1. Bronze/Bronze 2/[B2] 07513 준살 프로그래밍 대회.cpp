#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int m;
        cin >> m;

        vector<string> words(m);
        for (auto& word : words)
            cin >> word;

        int n;
        cin >> n;

        printf("Scenario #%d:\n", tc);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;

            for (int j = 0; j < k; j++)
            {
                int t;
                cin >> t;

                printf("%s", words[t].c_str());
            }
            printf("\n");
        }
        printf("\n");
    }
}