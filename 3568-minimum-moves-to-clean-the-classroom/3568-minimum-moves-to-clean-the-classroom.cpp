class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }

        int L = litters.size();
        int targetMask = (1 << L) - 1;

        vector<vector<vector<int>>> maxEnergy(m, vector<vector<int>>(n, vector<int>(1 << L, -1)));
        
        queue<tuple<int, int, int, int>> q;
        
        int initialMask = 0;
        for (int i = 0; i < L; ++i) {
            if (litters[i].first == startX && litters[i].second == startY) {
                initialMask |= (1 << i);
            }
        }

        q.push({startX, startY, initialMask, energy});
        maxEnergy[startX][startY][initialMask] = energy;

        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == targetMask) {
                    return moves;
                }

                if (e == 0) continue;

                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                        int nmask = mask;
                        if (classroom[nr][nc] == 'L') {
                            for (int i = 0; i < L; ++i) {
                                if (litters[i].first == nr && litters[i].second == nc) {
                                    nmask |= (1 << i);
                                    break;
                                }
                            }
                        }

                        int ne = e - 1;
                        if (classroom[nr][nc] == 'R') {
                            ne = energy;
                        }

                        if (ne > maxEnergy[nr][nc][nmask]) {
                            maxEnergy[nr][nc][nmask] = ne;
                            q.push({nr, nc, nmask, ne});
                        }
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};