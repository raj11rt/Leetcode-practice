class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int cnt = 0;
        int sr = 0, sc = 0;

        vector<vector<int>> id(n, vector<int>(m, -1));

        // Find S and number every L
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int allMask = (1 << cnt) - 1;

        // {i, j, currentEnergy, mask, time}
        queue<tuple<int, int, int, int, int>> q;

        q.push({sr, sc, energy, 0, 0});

        // vis[i][j][mask] = maximum energy
        // with which we reached this state
        vector<vector<vector<int>>> vis(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << cnt, -1)
            )
        );

        vis[sr][sc][0] = energy;

        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto [i, j, currEnergy, mask, time] = q.front();
            q.pop();

            // All litter collected
            if (mask == allMask) {
                return time;
            }

            for (int k = 0; k < 4; k++) {

                int ni = i + di[k];
                int nj = j + dj[k];

                // Outside classroom
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                    continue;
                }

                // Wall
                if (classroom[ni][nj] == 'X') {
                    continue;
                }

                // Moving costs 1 energy
                int newEnergy = currEnergy - 1;

                if (newEnergy < 0) {
                    continue;
                }

                int newMask = mask;

                // Pick up litter
                if (classroom[ni][nj] == 'L') {
                    newMask |= (1 << id[ni][nj]);
                }

                // Recharge
                if (classroom[ni][nj] == 'R') {
                    newEnergy = energy;
                }

                // We only need to visit this state if
                // we arrive with MORE energy than before.
                if (newEnergy > vis[ni][nj][newMask]) {

                    vis[ni][nj][newMask] = newEnergy;

                    q.push({
                        ni,
                        nj,
                        newEnergy,
                        newMask,
                        time + 1
                    });
                }
            }
        }

        return -1;
    }
};