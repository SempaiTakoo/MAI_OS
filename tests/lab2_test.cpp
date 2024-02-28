#include <iostream>
#include <algorithm>
#include <gtest/gtest.h>

#include "kMeans.hpp"


void TestkMeans(int maxIterations, int clustersCount, std::vector<Point>& data, std::vector<std::vector<Point>>& correct, int maxThreads) {

    auto start = std::chrono::steady_clock::now();

    std::vector<std::vector<Point>> result = kMeansClustering(data, clustersCount, maxIterations, maxThreads);

    auto end = std::chrono::steady_clock::now();

    for (int i = 0; i < clustersCount; ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            ASSERT_EQ(result[i][j].x, correct[i][j].x);
            ASSERT_EQ(result[i][j].y, correct[i][j].y);
        }
    }

    std::cout << "Threads: " << maxThreads << " milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

}

TEST(kMeans, ONE) {
    std::vector<Point> data = {
        {0.0, 0.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {8.0, 8.0},
        {9.0, 9.0},
        {9.0, 8.0}
    };
    std::vector<std::vector<Point>> correct = {
        {
            {0.0, 0.0},
            {1.0, 1.0},
            {1.0, 0.0}
        }, {
            {8.0, 8.0},
            {9.0, 9.0},
            {9.0, 8.0}
        }
    };

    TestkMeans(100, 2, data, correct, 1);
}

TEST(Time, ONE) {
    std::vector<Point> data = {
        {0.0, 0.0},
        {1.0, 1.0},
        {1.0, 0.0},
        {8.0, 8.0},
        {9.0, 9.0},
        {9.0, 8.0},
        {100.0, 100.0},
        {101.0, 101.0},
        {101.0, 100.0},
    };
    std::vector<std::vector<Point>> correct = {
        {
            {0.0, 0.0},
            {1.0, 1.0},
            {1.0, 0.0}
        }, {
            {100.0, 100.0},
            {101.0, 101.0},
            {101.0, 100.0}
        }, {
            {8.0, 8.0},
            {9.0, 9.0},
            {9.0, 8.0}
        }
    };
    TestkMeans(100, 3, data, correct, 1);
    TestkMeans(100, 3, data, correct, 2);
    TestkMeans(100, 3, data, correct, 9);
}
