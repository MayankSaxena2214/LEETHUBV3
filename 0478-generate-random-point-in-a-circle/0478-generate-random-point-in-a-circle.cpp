class Solution {
public:
    double radius;
    double x;
    double y;
    Solution(double radius, double x_center, double y_center) {
        this->radius=radius;
        this->x=x_center;
        this->y=y_center;
    }
    
    vector<double> randPoint() {
        double length,theta;
        double rand1=(double)rand()/RAND_MAX;
        theta=2*rand1*(22/7.0);
        double rand2=(double)rand()/RAND_MAX;
        length=sqrt(rand2)*radius;
        double xcord=x+length*cos(theta);
        double ycord=y+length*sin(theta);
        return {xcord,ycord};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */