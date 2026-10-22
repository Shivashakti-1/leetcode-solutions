class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        int k=0;
        string curr="";

        for(char ch : s)
        {
            if(isdigit(ch))
            {
                k=k*10+(ch-'0');
            }

            else if(ch=='[')
            {
                countStack.push(k);
                stringStack.push(curr);

                k=0;
                curr="";
            }

            else if(ch==']')
            {
                int repeat = countStack.top();
                countStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                string decode="";

                for(int i=0;i<repeat;i++)
                {
                    decode+=curr;
                }
                curr=prev+decode;
            }

            else{
                curr+=ch;
            }
        }

        return curr;
    }
};