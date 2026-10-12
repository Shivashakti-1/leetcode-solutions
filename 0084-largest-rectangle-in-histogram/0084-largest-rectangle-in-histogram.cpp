class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int n=heights.size();  
        int maxArea=0;      

        for(int i=0;i<=n;i++)
        {
            int curr=(i==n)?0:heights[i];

            while(!st.empty() && heights[st.top()]>curr)
            {
                int height=heights[st.top()];
                st.pop();

                int width;
                if(st.empty())
                {
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                int area=height*width;
                maxArea=max(maxArea, area);
            }
            st.push(i);
        }

        return maxArea;
    }
};