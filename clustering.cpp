#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x;
    double y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

std::vector<Point> kMeansClustering(std::vector<Point>& points, int k) {
    int pointsCount = points.size();

    std::vector<Point> clusters(k);
    for (int i = 0; i < pointsCount; ++i) {
        clusters[i] = points[i];
    }


}

int main() {

    return 0;
}
