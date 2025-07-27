class Solution {
public:
    void fill(vector<vector<int>>& img, int sr, int sc,
              int c, int cl) {
        int d[5] = { -1, 0, 1, 0, -1 };
        int m = img.size();
        int n = img[0].size();
        if ((sr < 0) || (sr >= m) ||
            (sc < 0) || (sc >= n) ||
            (img[sr][sc] != c) || (img[sr][sc] == cl))
                return;
        img[sr][sc] = cl;
        for (int i = 0; i < 4; ++ i) {
            fill(img, sr + d[i], sc + d[i + 1], c, cl);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c = image[sr][sc];
        fill(image, sr, sc, c, color);
        return image;        
    }
};
