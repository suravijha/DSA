class Solution {
public:
    double r;
    double x, y;

    Solution(double radius, double x_center, double y_center) {
        r = radius;

        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        while (true) {
            double a = ((double)rand() / RAND_MAX * 2 - 1) * r;
            double b = ((double)rand() / RAND_MAX * 2 - 1) * r;

            if (a * a + b * b <= r * r) {
                return {a + x, b + y};
            }
        }

        return {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */