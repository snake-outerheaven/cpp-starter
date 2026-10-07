#include <cstdlib>
int main() {
    int n = -3;
    double* p = static_cast<double*>(malloc(n * sizeof(double)));
    free(p);
}