#include <iostream>
#include <pxart/pxart.hpp>
#include <random>
int main() {
  using namespace std;
  pxart::mt19937 rng{random_device{}};

  const int N = 1000000000;
  int insides = 0;
  for (int i = 1; i <= N; ++i) {
    const auto x = pxart::uniform<float>(rng);
    const auto y = pxart::uniform<float>(rng);
    insides += (x * x + y * y <= 1);
  }
  const float estimated_pi = 4.0f * insides / N;
  cout << "random number: " << estimated_pi << '.' << endl;
}
