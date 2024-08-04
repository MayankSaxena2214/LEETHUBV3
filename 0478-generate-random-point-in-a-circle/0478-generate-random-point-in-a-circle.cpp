class Solution {
public:
    double radius,xr,yr;
    Solution(double radius, double x_center, double y_center) {
        this->radius=radius;
        xr=x_center;
        yr=y_center;
    }
    
    vector<double> randPoint() {
        double length,theta;
        double rand1=(double)rand()/RAND_MAX;
        theta=rand1*2*M_PI;
        double rand2=(double)rand()/RAND_MAX;
        length=sqrt(rand2)*radius;
        double x=xr+length*cos(theta);
        double y=yr+length*sin(theta);
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */