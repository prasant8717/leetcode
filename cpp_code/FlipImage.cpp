class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i = 0; i < image.size(); ++ i) {
            int k = 0;
            int j = image[i].size() - 1;
            for (; k < j; ++ k) {
                if (image[i][k] == image[i][j]) {
                    image[i][k] ^= 1;
                    image[i][j] ^= 1;
                }
                -- j;
            }
            if (k == j) {
                image[i][k] ^= 1;
            }
        }
        return image;        
    }
};
