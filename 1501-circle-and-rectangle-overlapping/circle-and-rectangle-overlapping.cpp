class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        x1 -= xc, x2 -= xc, y1 -= yc, y2 -= yc;
        int d = 0;
        d += (x1 > 0) ? x1 * x1 : 0;
        d += (x2 < 0) ? x2 * x2 : 0;
        d += (y1 > 0) ? y1 * y1 : 0;
        d += (y2 < 0) ? y2 * y2 : 0;
        return r * r >= d;
    }
};