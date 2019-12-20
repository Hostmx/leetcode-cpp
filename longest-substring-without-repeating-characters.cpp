// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int i=0,j,max=0;
//         unordered_set<char> subStr;
//         for(j = 0;j< s.size();j++){
//             while(subStr.find(s[j]) != subStr.end())
//                 subStr.erase(s[i++]);
//             subStr.insert(s[j]);
//             if(j-i+1 > max)
//                 max = j-i+1;
//         }
//         return max;
//     }
// }; //36ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j,max=0;
        int subStr[256] = {0};
        for(j = 0;j< s.size();j++){
            while(subStr[static_cast<int>(s[j])])
                subStr[static_cast<int>(s[i++])] = 0;
            subStr[static_cast<int>(s[j])] = 1;
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
}; // 4ms
