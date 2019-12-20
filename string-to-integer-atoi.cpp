class Solution {
public:
    int myAtoi(string str) {
        int preSpaceCount = 0;
        long ret = 0;
        bool isGetNonSapce = false;
        int sign = 1;
        int i = 0;
        for(; i < str.size();i++)
            if(str[i] != ' ')
                break;

        if(str[i] == '-'){
            i++;
            sign = -1;
        }
        else if(str[i] == '+'){
            i++;
            sign = 1;
        }

        for(; i < str.size(), str[i] <= '9' && str[i] >= '0';i++){
            ret = ret * 10 + str[i] - '0';
            if(ret >= 2147483648)
                if(sign == 1)return INT_MAX;
                else if(sign == -1)return INT_MIN;
        }

        ret *= sign;
        return ret;
    }
};
