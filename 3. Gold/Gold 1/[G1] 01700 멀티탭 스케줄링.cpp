#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> order(k);
    vector<vector<int>> orderSeqs(k + 1);
    for (int i = 0; i < k; i++)
    {
        cin >> order[i];
        orderSeqs[order[i]].push_back(i);
    }

    for (int i = 1; i <= k; i++)
        reverse(orderSeqs[i].begin(), orderSeqs[i].end());

    int result = 0;
    vector<bool> isPlugged(k + 1, false);
    vector<int> plug;
    for (int i = 0; i < k; i++)
    {
        if (isPlugged[order[i]])
        {
            orderSeqs[order[i]].pop_back();
            continue;
        }

        if (plug.size() < n)
        {
            isPlugged[order[i]] = true;
            plug.push_back(order[i]);
            orderSeqs[order[i]].pop_back();
            continue;
        }

        result++;

        int outPlug = -1;
        int outPlugIdx = -1;
        int lastPlug = -1;
        for (int j = 0; j < plug.size(); j++)
        {
            if (orderSeqs[plug[j]].empty())
            {
                outPlug = plug[j];
                outPlugIdx = j;
                break;
            }
            else if (orderSeqs[plug[j]].back() > lastPlug)
            {
                outPlug = plug[j];
                outPlugIdx = j;
                lastPlug = orderSeqs[plug[j]].back();
            }
        }

        isPlugged[outPlug] = false;
        plug.erase(plug.begin() + outPlugIdx);

        isPlugged[order[i]] = true;
        plug.push_back(order[i]);
        orderSeqs[order[i]].pop_back();
    }
    cout << result << '\n';
}