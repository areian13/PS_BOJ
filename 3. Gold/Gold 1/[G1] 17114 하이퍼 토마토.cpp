#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int メ, モ, ャ, ヤ, ュ, ユ, ョ, ヨ, ラ, リ, ル;
};

array<int, 22> dメ = { +1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> dモ = { 0,0,+1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> dャ = { 0,0,0,0,+1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> dヤ = { 0,0,0,0,0,0,+1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> dュ = { 0,0,0,0,0,0,0,0,+1,-1,0,0,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> dユ = { 0,0,0,0,0,0,0,0,0,0,+1,-1,0,0,0,0,0,0,0,0,0,0 };
array<int, 22> dョ = { 0,0,0,0,0,0,0,0,0,0,0,0,+1,-1,0,0,0,0,0,0,0,0 };
array<int, 22> dヨ = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,+1,-1,0,0,0,0,0,0 };
array<int, 22> dラ = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,+1,-1,0,0,0,0 };
array<int, 22> dリ = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,+1,-1,0,0 };
array<int, 22> dル = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,+1,-1 };

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
    for (int メ = 0; メ < w; メ++)
    {
        for (int モ = 0; モ < v; モ++)
        {
            for (int ャ = 0; ャ < u; ャ++)
            {
                for (int ヤ = 0; ヤ < t; ヤ++)
                {
                    for (int ュ = 0; ュ < s; ュ++)
                    {
                        for (int ユ = 0; ユ < r; ユ++)
                        {
                            for (int ョ = 0; ョ < q; ョ++)
                            {
                                for (int ヨ = 0; ヨ < p; ヨ++)
                                {
                                    for (int ラ = 0; ラ < o; ラ++)
                                    {
                                        for (int リ = 0; リ < n; リ++)
                                        {
                                            for (int ル = 0; ル < m; ル++)
                                            {
                                                if (map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ][リ][ル] == 1)
                                                    Q.push({ メ,モ,ャ,ヤ,ュ,ユ,ョ,ヨ,ラ,リ,ル });
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
        int メ = Q.front().メ;
        int モ = Q.front().モ;
        int ャ = Q.front().ャ;
        int ヤ = Q.front().ヤ;
        int ュ = Q.front().ュ;
        int ユ = Q.front().ユ;
        int ョ = Q.front().ョ;
        int ヨ = Q.front().ヨ;
        int ラ = Q.front().ラ;
        int リ = Q.front().リ;
        int ル = Q.front().ル;
        Q.pop();

        for (int i = 0; i < 22; i++)
        {
            int nメ = メ + dメ[i];
            int nモ = モ + dモ[i];
            int nャ = ャ + dャ[i];
            int nヤ = ヤ + dヤ[i];
            int nュ = ュ + dュ[i];
            int nユ = ユ + dユ[i];
            int nョ = ョ + dョ[i];
            int nヨ = ヨ + dヨ[i];
            int nラ = ラ + dラ[i];
            int nリ = リ + dリ[i];
            int nル = ル + dル[i];

            if (nメ < 0 || nメ >= w ||
                nモ < 0 || nモ >= v ||
                nャ < 0 || nャ >= u ||
                nヤ < 0 || nヤ >= t ||
                nュ < 0 || nュ >= s ||
                nユ < 0 || nユ >= r ||
                nョ < 0 || nョ >= q ||
                nヨ < 0 || nヨ >= p ||
                nラ < 0 || nラ >= o ||
                nリ < 0 || nリ >= n ||
                nル < 0 || nル >= m
                )
                continue;
            if (map[nメ][nモ][nャ][nヤ][nュ][nユ][nョ][nヨ][nラ][nリ][nル] != 0)
                continue;

            map[nメ][nモ][nャ][nヤ][nュ][nユ][nョ][nヨ][nラ][nリ][nル] = map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ][リ][ル] + 1;
            Q.push({ nメ,nモ,nャ,nヤ,nュ,nユ,nョ,nヨ,nラ,nリ,nル });
        }
    }

    int result = 0;
    for (int メ = 0; メ < w; メ++)
    {
        for (int モ = 0; モ < v; モ++)
        {
            for (int ャ = 0; ャ < u; ャ++)
            {
                for (int ヤ = 0; ヤ < t; ヤ++)
                {
                    for (int ュ = 0; ュ < s; ュ++)
                    {
                        for (int ユ = 0; ユ < r; ユ++)
                        {
                            for (int ョ = 0; ョ < q; ョ++)
                            {
                                for (int ヨ = 0; ヨ < p; ヨ++)
                                {
                                    for (int ラ = 0; ラ < o; ラ++)
                                    {
                                        for (int リ = 0; リ < n; リ++)
                                        {
                                            for (int ル = 0; ル < m; ル++)
                                            {
                                                if (map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ][リ][ル] == 0)
                                                    return -1;

                                                result = max(result, map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ][リ][ル] - 1);
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
    for (int メ = 0; メ < w; メ++)
    {
        map[メ] = new int********* [v];
        for (int モ = 0; モ < v; モ++)
        {
            map[メ][モ] = new int******** [u];
            for (int ャ = 0; ャ < u; ャ++)
            {
                map[メ][モ][ャ] = new int******* [t];
                for (int ヤ = 0; ヤ < t; ヤ++)
                {
                    map[メ][モ][ャ][ヤ] = new int****** [s];
                    for (int ュ = 0; ュ < s; ュ++)
                    {
                        map[メ][モ][ャ][ヤ][ュ] = new int***** [r];
                        for (int ユ = 0; ユ < r; ユ++)
                        {
                            map[メ][モ][ャ][ヤ][ュ][ユ] = new int**** [q];
                            for (int ョ = 0; ョ < q; ョ++)
                            {
                                map[メ][モ][ャ][ヤ][ュ][ユ][ョ] = new int*** [p];
                                for (int ヨ = 0; ヨ < p; ヨ++)
                                {
                                    map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ] = new int** [o];
                                    for (int ラ = 0; ラ < o; ラ++)
                                    {
                                        map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ] = new int* [n];
                                        for (int リ = 0; リ < n; リ++)
                                        {
                                            map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ][リ] = new int[m];
                                            for (int ル = 0; ル < m; ル++)
                                                cin >> map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ][リ][ル];
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

    for (int メ = 0; メ < w; メ++)
    {
        for (int モ = 0; モ < v; モ++)
        {
            for (int ャ = 0; ャ < u; ャ++)
            {
                for (int ヤ = 0; ヤ < t; ヤ++)
                {
                    for (int ュ = 0; ュ < s; ュ++)
                    {
                        for (int ユ = 0; ユ < r; ユ++)
                        {
                            for (int ョ = 0; ョ < q; ョ++)
                            {
                                for (int ヨ = 0; ヨ < p; ヨ++)
                                {
                                    for (int ラ = 0; ラ < o; ラ++)
                                    {
                                        for (int リ = 0; リ < n; リ++)
                                            delete map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ][リ];
                                        delete map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ][ラ];
                                    }
                                    delete map[メ][モ][ャ][ヤ][ュ][ユ][ョ][ヨ];
                                }
                                delete map[メ][モ][ャ][ヤ][ュ][ユ][ョ];
                            }
                            delete map[メ][モ][ャ][ヤ][ュ][ユ];
                        }
                        delete map[メ][モ][ャ][ヤ][ュ];
                    }
                    delete map[メ][モ][ャ][ヤ];
                }
                delete map[メ][モ][ャ];
            }
            delete map[メ][モ];
        }
        delete map[メ];
    }
    delete map;
}