class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int up = 0;
        for(auto num : nums)
        {
            if(num > up)
                up = num;
        }
        int down = 1;
        while(down<up)
        {
            int sum = 0;
            int mid = (down + up - 1)/2;
            for(auto num : nums)
                sum += num / mid + (num % mid > 0 ? 1 : 0);

            if(sum <= threshold)
                up = mid;
            else
                down = mid + 1;
        }
        return down;
    }
};
