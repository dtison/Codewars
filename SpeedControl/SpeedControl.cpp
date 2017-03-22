#include <algorithm>
#include <numeric>
using namespace std;

class GpsSpeed
{
public:
    static int gps(int s, std::vector<double> &x);
};

vector<double> ConvertToRelativeDistances(vector<double> &x) {
    vector<double> distances;
    if (x.size() > 1) {
        for (auto ix = x.begin(); ix != x.end() - 1; ++ix) {
            distances.push_back(ix[1] - ix[0]);
        }
    }
    return distances;
}

int GpsSpeed::gps(int s, std::vector<double> &x) {
    vector<double> distances = ConvertToRelativeDistances(x);
    return accumulate(distances.begin(), distances.end(), 0, [s](int a, double distance) {
        return max (a, static_cast<int>(distance * 3600.0 / s));
    });
}