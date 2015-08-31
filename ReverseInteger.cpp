#define INT_MAX 0x7fffffff
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int curVar =0;
        int lastDig = INT_MAX % 10;
        int preCheck = INT_MAX / 10;
        int nLastDig = (~INT_MAX) %10;
        int nPreCheck = (~INT_MAX) /10;
        while(x !=0)
        {
            curVar = x % 10;
            if(curVar == 0 && res == 0)
            {
                x /= 10;
                continue;
            }
            if(res > preCheck || (res == preCheck && curVar > lastDig))
            {
                return 0;
            }
            if(res < nPreCheck || (res == nPreCheck  && curVar < nLastDig))
            {
                return 0;
            }
            res = res*10 + curVar;
            x /= 10;
        }
        return res;
    }
};