#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SCHOOL_SIZE 5
#define FACT_SCHOOL_SIZE 120

int Key(vector<pair<int, int>>& school)
{
    int result = 0;
    int fact = FACT_SCHOOL_SIZE / SCHOOL_SIZE;

    for (int i = 0; i < SCHOOL_SIZE - 1; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < SCHOOL_SIZE; j++)
            cnt += (school[j].second < school[i].second);
        result += cnt * fact;
        fact /= (SCHOOL_SIZE - 1 - i);
    }
    return result;
}

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[Find(v, p)] = Find(u, p);
}

void CountRoad(int n, vector<pair<int, int>>& school,
    vector<vector<pair<int, int>>>& roads, vector<int>& cnt)
{
    vector<int> p(n, -1);
    for (int i = 0; i < SCHOOL_SIZE; i++)
    {
        for (pair<int, int>& road : roads[school[i].second])
        {
            int u = road.first;
            int v = road.second;

            if (Find(u, p) == Find(v, p))
                continue;

            Union(u, v, p);
            cnt[i]++;
        }
    }
}

long long MinRoadCost(vector<pair<int, int>>& school, vector<int>& cnt)
{
    long long result = 0;
    for (int i = 0; i < SCHOOL_SIZE; i++)
        result += (long long)school[i].first * cnt[i];
    return result;
}

int main()
{
    FastIO;

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> roads(SCHOOL_SIZE);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        char z;
        cin >> u >> v >> z;
        u--, v--, z -= 'A';

        roads[z].push_back({ u,v });
    }

    vector<vector<int>> cnts(FACT_SCHOOL_SIZE, vector<int>(n, 0));
    vector<bool> isCalculated(FACT_SCHOOL_SIZE, false);

    while (q--)
    {
        vector<pair<int, int>> school(SCHOOL_SIZE);
        for (int i = 0; i < SCHOOL_SIZE; i++)
        {
            cin >> school[i].first;
            school[i].second = i;
        }
        sort(school.begin(), school.end());

        int key = Key(school);
        if (!isCalculated[key])
        {
            CountRoad(n, school, roads, cnts[key]);
            isCalculated[key] = true;
        }

        long long result = MinRoadCost(school, cnts[key]);
        cout << result << '\n';
    }
}