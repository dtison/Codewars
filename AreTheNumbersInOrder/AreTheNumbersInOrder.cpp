#include <limits>
using namespace std;
// Pure functional recursive
bool ascendingOrder(const vector<int> & arr, const int index, const int max) {
    if (arr[index] < max) return false;
    if (index == arr.size() - 1) return true;
    return ascendingOrder(arr, index + 1, arr[index]);
}
bool isAscOrder(std::vector<int> arr)
{
    return ascendingOrder(arr, 0, numeric_limits<int>::min());
}