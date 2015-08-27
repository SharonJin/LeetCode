#define INT_MAX 0x7fffffff
class Solution {
public:
    int myAtoi(string str) {
        
        // if str is empty, return 0
        if(0 == str.length())
        {
            return 0;
        }
        
        // skip the whitespace characters in front of str
        // if str only contains whitespace, return 0
        int i=0;
        while(i<str.length() && str[i] == ' ')
        {
            i++;
        }
        if(i == str.length())
        {
            return 0;
        }
        
        bool isNegtive = false;
        if(str[i] == '-')
        {
            isNegtive = true;
            i++;
        }
        else if(str[i] == '+')
        {
            i++;
        }
        
        // skip whitespace after +/- cases
        /*while(i<str.length() && str[i] == ' ')
        {
            i++;
        }
        
        if(i == str.length())
        {
            return 0;
        }*/
        
        int result = 0;
        bool hasPoint = false;
        int preCheck = INT_MAX/10;
        int lastDig = INT_MAX - preCheck*10;
        
        while(i < str.length())
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                int val = str[i] - '0';
                if(result > preCheck || (result == preCheck && val > lastDig))
                {
                    result = INT_MAX;
                    if(isNegtive)
                    {
                        result =  ~result;
                    }
                    return result;
                }
                result = result *10 + (str[i]-'0');
                    
                i++;
            }
            else if(str[i] == '.')
            {
                i++;
                hasPoint = true;
                break;
            }
            else
            {
                break;
            }
        }
        while(hasPoint && i< str.length())
        {
            if(str[i] == '0')
            {
                i ++;
            }
            else
            {
                return 0;
            }
        }
        if(isNegtive)
        {
            return -1*result;
        }
        
        return result;
        
    }
};