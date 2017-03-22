using namespace std;

class CountDig
{
public:
    static int nbDig(int n, int d);
};

int CountDig::nbDig(int n, int d) {
    int total = 0;
    for (int i = 0; i <= n; i++) {
        string str = to_string(i*i);
        total += count(str.begin(), str.end(), d + '0');
    }
    return total;
}