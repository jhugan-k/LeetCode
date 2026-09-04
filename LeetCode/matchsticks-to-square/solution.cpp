class Solution {
public:
    bool solve(vector<int>& matchsticks, int i, vector<int>& sides, int target) {
        if(i == matchsticks.size())
            return true;

        for(int j = 0; j < 4; j++) {
            if(sides[j] + matchsticks[i] > target)
                continue;

            if(j > 0 && sides[j] == sides[j-1])
                continue;

            sides[j] += matchsticks[i];

            if(solve(matchsticks, i + 1, sides, target))
                return true;

            sides[j] -= matchsticks[i];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;

        for(int x : matchsticks)
            sum += x;

        if(sum % 4 != 0)
            return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if(matchsticks[0] > target)
            return false;

        vector<int> sides(4, 0);

        return solve(matchsticks, 0, sides, target);
    }
};