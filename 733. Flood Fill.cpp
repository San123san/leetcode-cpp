class Solution {
public:
    bool fill(vector<vector<int>> & image, int sr, int sc, int color, int currColor){

        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != currColor){
            return false;
        }

        image[sr][sc] = color;

        bool up = fill(image, sr - 1, sc, color, currColor);
        bool down = fill(image, sr + 1, sc, color, currColor);
        bool left = fill(image, sr, sc - 1, color, currColor);
        bool right = fill(image, sr, sc + 1, color, currColor);

        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int currColor = image[sr][sc];

        if(currColor != color){
            fill(image, sr, sc, color, currColor);
        }

        return image;
    }
};
