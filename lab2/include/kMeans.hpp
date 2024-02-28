#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
#include <chrono>

struct Point {
    double x;
    double y;
};

double distance(const Point p1, const Point p2);
std::vector<std::vector<Point>> kMeansClustering(const std::vector<Point>& points, int k, int maxIterations, int maxThreads);
