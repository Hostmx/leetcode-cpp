class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int len1 = nums1.size();
            int len2 = nums2.size();
            vector<int> nums12;
            int i = 0;
            int j = 0;
            while(i + j< (len1 + len2) )
            {
                if(i < len1 && j < len2)
                    nums1[i] < nums2[j] ? nums12.push_back(nums1[i++]) : nums12.push_back(nums2[j++]);
                else if(i < len1 && j >= len2)
                    nums12.push_back(nums1[i++]);
                else if(j < len2 && i >= len1 )
                    nums12.push_back(nums2[j++]);
            }
            return (nums12[(len1 + len2 - 1) /2] + nums12[(len1 + len2) /2]) /2.0;
        }
};
