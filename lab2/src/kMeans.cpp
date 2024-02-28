#include "kMeans.hpp"

double distance(const Point p1, const Point p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

std::vector<std::vector<Point>> kMeansClustering(const std::vector<Point>& points, int k, int maxIterations, int maxThreads) {
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

        int j = 0;
        for (int i = 0; i < pointsCount; ++i) {
            if (threads.size() < maxThreads) {
                ++j;
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
                    // std::this_thread::sleep_for(std::chrono::milliseconds(20000));
                });
            } else {
                    threads[threads.size() - 1].join();
                    threads.pop_back();
                    --j;
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
                    // std::this_thread::sleep_for(std::chrono::milliseconds(20000));
                });
            }
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

    // for (int i = 0; i < result.size(); ++i) {
    //     for(int j = 0; j < result[i].size(); ++j) {
    //         std::cout << i << result[i][j].x << result[i][j].y << std::endl;
    //     }
    // }
    return result;
}
