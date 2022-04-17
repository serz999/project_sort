#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <list>
#include <random>
#include "sort_methods.h"
#include "TIMER.h"
#include <algorithm>

class SortTest : public ::testing::Test {
protected:
    void SetUp() override {
        Test::SetUp();
        auto gen = [this]() {
            return number_distance(mercenne_engine);
        };
        arr_10.resize(10);
        arr_100.resize(100);
        arr_1000.resize(1000);
        arr_10000.resize(10000);
        arr_100000.resize(100000);
        arr_250000.resize(250000);
        std::generate(arr_10.begin(), arr_10.end(), gen);
        std::generate(arr_100.begin(), arr_100.end(), gen);
        std::generate(arr_1000.begin(), arr_1000.end(), gen);
        std::generate(arr_10000.begin(), arr_10000.end(), gen);
        std::generate(arr_100000.begin(), arr_100000.end(), gen);
        std::generate(arr_250000.begin(), arr_250000.end(), gen);
    }
    void TearDown() override {
        Test::TearDown();
    }
public:
    std::vector<int> arr_10;
    std::vector<int> arr_100;
    std::vector<int> arr_1000;
    std::vector<int> arr_10000;
    std::vector<int> arr_100000;
    std::vector<int> arr_250000;
    std::vector<void *> arrays{&arr_10, &arr_100, &arr_1000, &arr_10000, &arr_10000, &arr_250000};
private:
    std::random_device rnd_device;
    std::mt19937 mercenne_engine{rnd_device()};
    std::uniform_int_distribution<int> number_distance{1, 1000000};
};

TEST(GoogleTestCi, Foo) {
    ASSERT_TRUE(true);
}

TEST_F(SortTest, bubble_sort_vec) {
    std::vector<int> vec = {99, 9, 3, 2, 12, 1, 6};
    bubble_sort(vec.begin(), vec.end());
    ASSERT_EQ(vec, std::vector<int>({1, 2, 3, 6, 9, 12, 99}));
}

TEST_F(SortTest, bubble_sort_string) {
    std::string MY_STRING = "dcabACB" ;
    bubble_sort(MY_STRING.begin(), MY_STRING.end());
    std::string MY_STRING2 = "ABCabcd" ;
    ASSERT_EQ(MY_STRING, MY_STRING2);
}

TEST_F(SortTest, bubble_sort_list) {
    std::list<int> list_a = { 2, 1, 5, 3, 4 };
    bubble_sort(list_a.begin(), list_a.end());
    std::list<int> list_b = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(list_a, list_b);
}

TEST_F(SortTest, insert_sort_vec) {
    std::vector<int> vec = {99, 9, 3, 2, 12, 1, 6};
    insert_sort(vec.begin(), vec.end());
    ASSERT_EQ(vec, std::vector<int>({1, 2, 3, 6, 9, 12, 99}));
}

TEST_F(SortTest, insert_sort_string) {
    std::string MY_STRING = "dcabACB" ;
    insert_sort(MY_STRING.begin(), MY_STRING.end());
    std::string MY_STRING2 = "ABCabcd" ;
    ASSERT_EQ(MY_STRING, MY_STRING2);
}

TEST_F(SortTest, insert_sort_list) {
    std::list<int> list_a = { 2, 1, 5, 3, 4 };
    insert_sort(list_a.begin(), list_a.end());
    std::list<int> list_b = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(list_a, list_b);
}

TEST_F(SortTest, merge_sort_vec) {
    std::vector<int> vec = {99, 9, 3, 2, 12, 1, 6};
    merge_sort(vec.begin(), vec.end());
    ASSERT_EQ(vec, std::vector<int>({1, 2, 3, 6, 9, 12, 99}));
}

TEST_F(SortTest, merge_sort_vec2) {
    std::vector<int> vec = {99, 9};
    merge_sort(vec.begin(), vec.end());
    ASSERT_EQ(vec, std::vector<int>({9, 99}));
}

TEST_F(SortTest, merge_sort_string) {
    std::string MY_STRING = "dcabACB" ;
    merge_sort(MY_STRING.begin(), MY_STRING.end());
    std::string MY_STRING2 = "ABCabcd" ;
    ASSERT_EQ(MY_STRING, MY_STRING2);
}

TEST_F(SortTest, merge_sort_list) {
    std::list<int> list_a = { 2, 1, 5, 3, 4 };
    merge_sort(list_a.begin(), list_a.end());
    std::list<int> list_b = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(list_a, list_b);
}

TEST_F(SortTest, quick_sort_vec) {
    std::vector<int> vec = {99, 9, 3, 2, 12, 1, 6};
    quick_sort(vec.begin(), vec.end());
    ASSERT_EQ(vec, std::vector<int>({1, 2, 3, 6, 9, 12, 99}));
}

TEST_F(SortTest, quick_sort_string) {
    std::string MY_STRING = "dcabACB" ;
    quick_sort(MY_STRING.begin(), MY_STRING.end());
    std::string MY_STRING2 = "ABCabcd" ;
    ASSERT_EQ(MY_STRING, MY_STRING2);
}

TEST_F(SortTest, quick_sort_list) {
    std::list<int> list_a = { 2, 1, 5, 3, 4 };
    quick_sort(list_a.begin(), list_a.end());
    std::list<int> list_b = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(list_a, list_b);
}

TEST_F(SortTest, timer_bubble_sort) {
    Timer timer("bubble_sort");
    timer.start();
    bubble_sort(arr_10.begin(), arr_10.end());
    timer.stop( "bubble_sort", "arr_10");
    timer.start();
    bubble_sort(arr_100.begin(), arr_100.end());
    timer.stop( "bubble_sort", "arr_100");
    timer.start();
    bubble_sort(arr_1000.begin(), arr_1000.end());
    timer.stop( "bubble_sort", "arr_1000");
    timer.start();
    bubble_sort(arr_10000.begin(), arr_10000.end());
    timer.stop( "bubble_sort", "arr_10000");
    timer.start();
    bubble_sort(arr_100000.begin(), arr_100000.end());
    timer.stop( "bubble_sort", "arr_100000");
    timer.start();
    bubble_sort(arr_250000.begin(), arr_250000.end());
    timer.stop( "bubble_sort", "arr_250000");
    ASSERT_TRUE(true);
}

TEST_F(SortTest, timer_insert_sort) {
    Timer timer("insert_sort");
    timer.start();
    insert_sort(arr_10.begin(), arr_10.end());
    timer.stop( "insert_sort", "arr_10");
    timer.start();
    insert_sort(arr_100.begin(), arr_100.end());
    timer.stop( "insert_sort", "arr_100");
    timer.start();
    insert_sort(arr_1000.begin(), arr_1000.end());
    timer.stop( "insert_sort", "arr_1000");
    timer.start();
    insert_sort(arr_10000.begin(), arr_10000.end());
    timer.stop( "insert_sort", "arr_10000");
    timer.start();
    insert_sort(arr_100000.begin(), arr_100000.end());
    timer.stop( "insert_sort", "arr_100000");
    timer.start();
    insert_sort(arr_250000.begin(), arr_250000.end());
    timer.stop( "insert_sort", "arr_250000");
    ASSERT_TRUE(true);
}

TEST_F(SortTest, timer_merge_sort) {
    Timer timer("merge_sort");
    timer.start();
    merge_sort(arr_10.begin(), arr_10.end());
    timer.stop( "merge_sort", "arr_10");
    timer.start();
    merge_sort(arr_100.begin(), arr_100.end());
    timer.stop( "merge_sort", "arr_100");
    timer.start();
    merge_sort(arr_1000.begin(), arr_1000.end());
    timer.stop( "merge_sort", "arr_1000");
    timer.start();
    merge_sort(arr_10000.begin(), arr_10000.end());
    timer.stop( "merge_sort", "arr_10000");
    timer.start();
    merge_sort(arr_100000.begin(), arr_100000.end());
    timer.stop( "merge_sort", "arr_100000");
    timer.start();
    merge_sort(arr_250000.begin(), arr_250000.end());
    timer.stop( "merge_sort", "arr_250000");
    ASSERT_TRUE(true);
}

TEST_F(SortTest, timer_quick_sort) {
    Timer timer("quick_sort");
    timer.start();
    quick_sort(arr_10.begin(), arr_10.end());
    timer.stop( "quick_sort", "arr_10");
    timer.start();
    quick_sort(arr_100.begin(), arr_100.end());
    timer.stop( "quick_sort", "arr_100");
    timer.start();
    quick_sort(arr_1000.begin(), arr_1000.end());
    timer.stop( "quick_sort", "arr_1000");
    timer.start();
    quick_sort(arr_10000.begin(), arr_10000.end());
    timer.stop( "quick_sort", "arr_10000");
    timer.start();
    quick_sort(arr_100000.begin(), arr_100000.end());
    timer.stop( "quick_sort", "arr_100000");
    timer.start();
    quick_sort(arr_250000.begin(), arr_250000.end());
    timer.stop( "quick_sort", "arr_250000");
    ASSERT_TRUE(true);
}

TEST_F(SortTest, timer_std_sort) {
    Timer timer("std_sort");
    timer.start();
    std::sort(arr_10.begin(), arr_10.end());
    timer.stop( "std_sort", "arr_10");
    timer.start();
    std::sort(arr_100.begin(), arr_100.end());
    timer.stop( "std_sort", "arr_100");
    timer.start();
    std::sort(arr_1000.begin(), arr_1000.end());
    timer.stop( "std_sort", "arr_1000");
    timer.start();
    std::sort(arr_10000.begin(), arr_10000.end());
    timer.stop( "std_sort", "arr_10000");
    timer.start();
    std::sort(arr_100000.begin(), arr_100000.end());
    timer.stop( "std_sort", "arr_100000");
    timer.start();
    std::sort(arr_250000.begin(), arr_250000.end());
    timer.stop( "std_sort", "arr_250000");
    ASSERT_TRUE(true);
}