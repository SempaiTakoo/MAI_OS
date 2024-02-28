#include "kMeans.hpp"

int main() {
    std::vector<Point> data = {
        {8.0, 8.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 0.0},
        {9.0, 9.0},
        {9.0, 8.0}
    };
    int maxIterations = 100;
    int clustersCount = 2;

    auto start = std::chrono::steady_clock::now();

    std::vector<std::vector<Point>> result = kMeansClustering(data, clustersCount, maxIterations, 10);

    auto end = std::chrono::steady_clock::now();
    std::cout << "milliseconds: ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

    for (int i = 0; i < clustersCount; ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << i << ' ' << result[i][j].x << ' ' << result[i][j].y  << std::endl;
        }
    }
}