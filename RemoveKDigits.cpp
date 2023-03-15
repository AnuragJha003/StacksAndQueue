/*logic: In stack push an element if it is bigger than top of the stack
For Example:- num = "1211" and k = 2
insert first element stack=1
1211 here 1(stack top) < 2 so take it stack=12 k=2
1211 here 2(stack top) > 1 so remove all elements greater than 1 alongside reducing k ,then take 1 stack=11 k = 1
1211 here 1(stack top) =1 so take it stack=111 k=1
since k!=0 take out k elements from stack stack=11 k=0
Result:- 11 */
class Solution {
public:
string removeKdigits(string num, int k) {
        if(num.length()==k)return "0";
        // get all eligible elements in a stack
	stack<char> s;
        for(char c:num){
            while(k && !s.empty() && int(s.top())>int(c)){s.pop();k--;} 
            s.push(c);
        } 
        //if still no change in k then remove k elements
        if(k) while(k--){s.pop();}
        // remove leading 0s ,if present
        stack<char> t;
        while(!s.empty()){t.push(s.top());s.pop();}
        while(t.top()=='0'&&t.size()!=1)t.pop();
        //return the answer
        num="";
        while(!t.empty()){num.push_back(t.top());t.pop();}
        return num;
    }
};
https://leetcode.com/problems/remove-k-digits/
