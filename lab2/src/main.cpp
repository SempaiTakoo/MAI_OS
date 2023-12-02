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

double distance(const Point p1, const Point p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

std::vector<std::vector<Point>> kMeansClustering(const std::vector<Point>& points, int k, int maxIterations) {
    int pointsCount = points.size();
    std::vector<Point> centroids(k);
    std::vector<int> clusterAssignments(pointsCount);
    std::mutex mutex;

    for (int i = 0; i < k; ++i) {
        centroids[i] = points[i];
    }

    for (int i = 0; i < maxIterations; ++i) {
        std::vector<int> clusterCounts(k, 0);
        std::vector<Point> newCentroids(k, {0.0, 0.0});
        std::vector<std::thread> threads;

        for (int i = 0; i < pointsCount; ++i) {
            threads.emplace_back([&, i]() {
                int closestCluster = 0;
                double closestDistance = std::numeric_limits<double>::max();
                for (int j = 0; j < k; ++j) {
                    double dist = distance(points[i], centroids[j]);
                    if (dist < closestDistance) {
                        closestDistance = dist;
                        closestCluster= j;
                    }
                }
                std::lock_guard<std::mutex> lock(mutex);
                clusterAssignments[i] = closestCluster;
                ++clusterCounts[closestCluster];
                newCentroids[closestCluster].x += points[i].x;
                newCentroids[closestCluster].y += points[i].y;
            });
        }

        for (auto& thread : threads) {
            thread.join();
        }

        for (int i = 0; i < k; ++i) {
            if (clusterCounts[i] > 0) {
                centroids[i].x = newCentroids[i].x / clusterCounts[i];
            }
        }
    }

    std::vector<std::vector<Point>> result(pointsCount);
    for (int i = 0; i < pointsCount; ++i) {
        result[clusterAssignments[i]].push_back(points[i]);
    }
    return result;
}

int main() {
    std::vector<Point> data = {
        {1.0, 1.0},
        {2.0, 2.0},
        {7.0, 7.0},
        {8.0, 8.0}
    };
    int maxIterations = 100;
    int clustersCount = 2;

    auto start = std::chrono::steady_clock::now();

    std::vector<std::vector<Point>> result = kMeansClustering(data, clustersCount, maxIterations);

    auto end = std::chrono::steady_clock::now();
    std::cout << "milliseconds: ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

    for (int i = 0; i < clustersCount; ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << i << ' ' << result[i][j].x << ' ' << result[i][j].y  << std::endl;
        }
    }
}
