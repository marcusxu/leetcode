class Solution {
public:
    int calculate(string s) {
        stack<int> myStack;
        char sign = '+';
        int num = 0,res=0;
        for (int i = 0; i < s.size(); i++){
            if (isdigit(s[i]))
                num = num * 10 + s[i] - '0';
            if (((!isdigit(s[i])) && (!isspace(s[i])))||(i==s.size()-1)){
                if (sign == '+')
                    myStack.push(num);
                if (sign == '-')
                    myStack.push(num*-1);
                if (sign == '*'){
                    num = myStack.top()*num;
                    myStack.pop();
                    myStack.push(num);
                }
                if (sign == '/'){
                    num = myStack.top() / num;
                    myStack.pop();
                    myStack.push(num);
                }
                sign = s[i];
                num = 0;
            }
        }
        while (!myStack.empty()){
            res += myStack.top();
            myStack.pop();
        }
        return res;
    }
};