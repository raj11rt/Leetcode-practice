class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];

        // Sequential prefix sum
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1)
                ans += nums[i];
            else
                break;
        }

        sort(nums.begin(), nums.end());

        // Find ans
        int i = 0;
        while (i < n && nums[i] < ans)
            i++;

        // Keep checking whether ans exists.
        // If found, skip ALL duplicates and increase ans once.
        while (i < n && nums[i] == ans) {
            int current = ans;

            while (i < n && nums[i] == current)
                i++;

            ans++;
        }

        return ans;
    }
};