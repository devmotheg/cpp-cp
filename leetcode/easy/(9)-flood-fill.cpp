/* Solution #1 */

class Solution {
    void fill(vector<vector<int>>& image, int r, int c, int start, int color) {
        if (r < 0 || r >= image.size() ||
            c < 0 || c >= image[0].size() ||
            image[r][c] != start || image[r][c] == color) return;
        
        image[r][c] = color;
        
        fill(image, r + 1, c, start, color);
        fill(image, r - 1, c, start, color);
        fill(image, r, c + 1, start, color);
        fill(image, r, c - 1, start, color);
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        
        fill(image, sr, sc, start, color);
        
        return image;
    }
};

/* Solution #2 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc], m = image.size(), n = image[0].size();
        stack<pair<int, int>> fill; fill.push({ sr, sc });
        
        if (old != color)
            while (!fill.empty()) {
                int r, c; tie(r, c) = fill.top(); fill.pop();
                image[r][c] = color;
                
                for (auto p : (vector<vector<int>>) {
                    { r + 1, c },
                    { r - 1, c },
                    { r, c + 1 },
                    { r, c - 1 }
                })
                    if (p[0] >= 0 && p[0] < m && p[1] >= 0 && p[1] < n && image[p[0]][p[1]] == old)
                        fill.push({ p[0], p[1] });
            }
        
        return image;
    }
};

/* Solution #3 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start = image[sr][sc];
        
        queue<pair<int, int>> fill; fill.push({ sr, sc });
        
        while (!fill.empty()) {
            int r, c; tie(r, c) = fill.front(); fill.pop();
            
            if (r == -1 || r == image.size() ||
                c == -1 || c == image[0].size() ||
                image[r][c] != start || image[r][c] == color) continue;
            
            image[r][c] = color;
            
            fill.push({ r + 1, c });
            fill.push({ r - 1, c });
            fill.push({ r, c + 1 });
            fill.push({ r, c - 1 });
        }
        
        return image;
    }
};
