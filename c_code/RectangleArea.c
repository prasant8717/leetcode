int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int ar = (ax2 - ax1) * (ay2 - ay1);
    int br = (bx2 - bx1) * (by2 - by1);
    int x = ax2 < bx2 ? ax2 : bx2;
    x = x - (ax1 < bx1 ? bx1 : ax1);
    int y = ay2 < by2 ? ay2 : by2;
    y = y - (ay1 < by1 ? by1 : ay1);
    int dr = (x > 0 ? x : 0) * (y > 0 ? y : 0);
    return ar + br - dr;
}
