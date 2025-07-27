class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = 1;
        for(; (w * w) < area; ++ w);
        while (area % w)
            -- w;
        int l = (area / w);
        if (l < w)
            return {w, l};
        return {l, w};
    }
};
