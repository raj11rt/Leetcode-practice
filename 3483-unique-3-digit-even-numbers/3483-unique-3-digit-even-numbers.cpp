class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        map<int, int> mp;

        for (int x : digits) {
            mp[x]++;
        }

        int ans = 0;

        // Choose last digit: must be even
        for (int last = 0; last <= 8; last += 2) {

            if (mp[last] == 0)
                continue;

            mp[last]--;

            // Choose first digit: cannot be 0
            for (int first = 1; first <= 9; first++) {

                if (mp[first] == 0)
                    continue;

                mp[first]--;

                // Choose middle digit
                for (int middle = 0; middle <= 9; middle++) {

                    if (mp[middle] > 0) {
                        ans++;
                    }
                }

                mp[first]++;
            }

            mp[last]++;
        }

        return ans;
    }
};