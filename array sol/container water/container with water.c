int maxArea(int*height, int*heightsize) {
    int max_water = 0;
    int lp = 0;
    int rp = heightsize - 1;

    while(lp<rp) {
        int width = rp - lp;
        int current_hight = (height[lp] < height[rp]) ? height[lp] : height[rp];
        int current_water = width * current_hight;
        max_water = (max_water > current_water) ? max_water : current_water;

        if(height[lp] < height[rp]) {
            lp ++;
        }
        else {
            rp --;
        }
    }
    return max_water;

}