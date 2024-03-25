#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace chrono;

double ctime_in_sec() {
    auto currentTime = system_clock::now();
    auto duration = currentTime.time_since_epoch();
    return duration_cast<milliseconds>(duration).count() / 1000.0;
}

std::vector<int> range(int n) {
    std::vector<int> result;
    for (int i = 0; i < n; ++i) result.push_back(i);
    return result;
}

int main() {
    double startTime = ctime_in_sec();

    int sum = 0;
    for (auto i: range(500000))
        sum = sum + i;

    double endTime = ctime_in_sec();
    double elapsedTime = endTime - startTime;
    cout << "Elapsed time: " << elapsedTime << " seconds" << endl;

    return 0;
}