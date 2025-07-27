class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        stack<int> s;
        for (int i = 0; i <= heights.size(); ++ i) {
            while ((s.empty() == 0) &&
                   ((i == heights.size()) ||
                    (heights[s.top()] > heights[i]))) {
                int l = heights[s.top()];
                s.pop();
                int b = s.empty() ? i : i - s.top() - 1;
                if (area < (l * b))
                    area = l * b;
            }
            s.push(i);
        }
        return area;        
    }
};
