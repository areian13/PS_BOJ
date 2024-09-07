#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int ��, ��, ��, ��, ��, ��, ��, ��, ��, ��, ��;
};

array<int, 22> d�� = { +1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> d�� = { 0,0,+1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> d�� = { 0,0,0,0,+1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> d�� = { 0,0,0,0,0,0,+1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> d�� = { 0,0,0,0,0,0,0,0,+1,-1,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> d�� = { 0,0,0,0,0,0,0,0,0,0,+1,-1,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> d�� = { 0,0,0,0,0,0,0,0,0,0,0,0,+1,-1,0,0,0,0,0,0,0,0 };
array<int, 22> d�� = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,+1,-1,0,0,0,0,0,0 };
array<int, 22> d�� = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,+1,-1,0,0,0,0 };
array<int, 22> d�� = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,+1,-1,0,0 };
array<int, 22> d�� = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,+1,-1 };

int BFS(int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w,
    int*********** map/*, vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>>& map*/)
{
    /*int w = map.size();
    int v = map[0].size();
    int u = map[0][0].size();
    int t = map[0][0][0].size();
    int s = map[0][0][0][0].size();
    int r = map[0][0][0][0][0].size();
    int q = map[0][0][0][0][0][0].size();
    int p = map[0][0][0][0][0][0][0].size();
    int o = map[0][0][0][0][0][0][0][0].size();
    int n = map[0][0][0][0][0][0][0][0][0].size();
    int m = map[0][0][0][0][0][0][0][0][0][0].size();*/

    queue<Pos> Q;
    for (int �� = 0; �� < w; ��++)
    {
        for (int �� = 0; �� < v; ��++)
        {
            for (int �� = 0; �� < u; ��++)
            {
                for (int �� = 0; �� < t; ��++)
                {
                    for (int �� = 0; �� < s; ��++)
                    {
                        for (int �� = 0; �� < r; ��++)
                        {
                            for (int �� = 0; �� < q; ��++)
                            {
                                for (int �� = 0; �� < p; ��++)
                                {
                                    for (int �� = 0; �� < o; ��++)
                                    {
                                        for (int �� = 0; �� < n; ��++)
                                        {
                                            for (int �� = 0; �� < m; ��++)
                                            {
                                                if (map[��][��][��][��][��][��][��][��][��][��][��] == 1)
                                                    Q.push({ ��,��,��,��,��,��,��,��,��,��,�� });
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    while (!Q.empty())
    {
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        int �� = Q.front().��;
        Q.pop();

        for (int i = 0; i < 22; i++)
        {
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];
            int n�� = �� + d��[i];

            if (n�� < 0 || n�� >= w ||
                n�� < 0 || n�� >= v ||
                n�� < 0 || n�� >= u ||
                n�� < 0 || n�� >= t ||
                n�� < 0 || n�� >= s ||
                n�� < 0 || n�� >= r ||
                n�� < 0 || n�� >= q ||
                n�� < 0 || n�� >= p ||
                n�� < 0 || n�� >= o ||
                n�� < 0 || n�� >= n ||
                n�� < 0 || n�� >= m
                )
                continue;
            if (map[n��][n��][n��][n��][n��][n��][n��][n��][n��][n��][n��] != 0)
                continue;

            map[n��][n��][n��][n��][n��][n��][n��][n��][n��][n��][n��] = map[��][��][��][��][��][��][��][��][��][��][��] + 1;
            Q.push({ n��,n��,n��,n��,n��,n��,n��,n��,n��,n��,n�� });
        }
    }

    int result = 0;
    for (int �� = 0; �� < w; ��++)
    {
        for (int �� = 0; �� < v; ��++)
        {
            for (int �� = 0; �� < u; ��++)
            {
                for (int �� = 0; �� < t; ��++)
                {
                    for (int �� = 0; �� < s; ��++)
                    {
                        for (int �� = 0; �� < r; ��++)
                        {
                            for (int �� = 0; �� < q; ��++)
                            {
                                for (int �� = 0; �� < p; ��++)
                                {
                                    for (int �� = 0; �� < o; ��++)
                                    {
                                        for (int �� = 0; �� < n; ��++)
                                        {
                                            for (int �� = 0; �� < m; ��++)
                                            {
                                                if (map[��][��][��][��][��][��][��][��][��][��][��] == 0)
                                                    return -1;

                                                result = max(result, map[��][��][��][��][��][��][��][��][��][��][��] - 1);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    FastIO;

    int m, n, o, p, q, r, s, t, u, v, w;
    cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;

    /*vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> map(w,
        vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>(v,
            vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>(u,
                vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>(t,
                    vector<vector<vector<vector<vector<vector<vector<int>>>>>>>(s,
                        vector<vector<vector<vector<vector<vector<int>>>>>>(r,
                            vector<vector<vector<vector<vector<int>>>>>(q,
                                vector<vector<vector<vector<int>>>>(p,
                                    vector<vector<vector<int>>>(o,
                                        vector<vector<int>>(n,
                                            vector<int>(m)
                                        )
                                    )
                                )
                            )
                        )
                    )
                )
            )
        )
    );*/

    int*********** map = new int********** [w];
    for (int �� = 0; �� < w; ��++)
    {
        map[��] = new int********* [v];
        for (int �� = 0; �� < v; ��++)
        {
            map[��][��] = new int******** [u];
            for (int �� = 0; �� < u; ��++)
            {
                map[��][��][��] = new int******* [t];
                for (int �� = 0; �� < t; ��++)
                {
                    map[��][��][��][��] = new int****** [s];
                    for (int �� = 0; �� < s; ��++)
                    {
                        map[��][��][��][��][��] = new int***** [r];
                        for (int �� = 0; �� < r; ��++)
                        {
                            map[��][��][��][��][��][��] = new int**** [q];
                            for (int �� = 0; �� < q; ��++)
                            {
                                map[��][��][��][��][��][��][��] = new int*** [p];
                                for (int �� = 0; �� < p; ��++)
                                {
                                    map[��][��][��][��][��][��][��][��] = new int** [o];
                                    for (int �� = 0; �� < o; ��++)
                                    {
                                        map[��][��][��][��][��][��][��][��][��] = new int* [n];
                                        for (int �� = 0; �� < n; ��++)
                                        {
                                            map[��][��][��][��][��][��][��][��][��][��] = new int[m];
                                            for (int �� = 0; �� < m; ��++)
                                                cin >> map[��][��][��][��][��][��][��][��][��][��][��];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int result = BFS(m, n, o, p, q, r, s, t, u, v, w, map);
    cout << result << '\n';

    for (int �� = 0; �� < w; ��++)
    {
        for (int �� = 0; �� < v; ��++)
        {
            for (int �� = 0; �� < u; ��++)
            {
                for (int �� = 0; �� < t; ��++)
                {
                    for (int �� = 0; �� < s; ��++)
                    {
                        for (int �� = 0; �� < r; ��++)
                        {
                            for (int �� = 0; �� < q; ��++)
                            {
                                for (int �� = 0; �� < p; ��++)
                                {
                                    for (int �� = 0; �� < o; ��++)
                                    {
                                        for (int �� = 0; �� < n; ��++)
                                            delete map[��][��][��][��][��][��][��][��][��][��];
                                        delete map[��][��][��][��][��][��][��][��][��];
                                    }
                                    delete map[��][��][��][��][��][��][��][��];
                                }
                                delete map[��][��][��][��][��][��][��];
                            }
                            delete map[��][��][��][��][��][��];
                        }
                        delete map[��][��][��][��][��];
                    }
                    delete map[��][��][��][��];
                }
                delete map[��][��][��];
            }
            delete map[��][��];
        }
        delete map[��];
    }
    delete map;
}