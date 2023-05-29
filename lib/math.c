#include "math.h"

const int num_iteracoes = 20;

double atan(double x) {
  double sum = 0.0;
  double term = x;
  double divisor = 1.0;

  for (int i = 0; i < 10; i++) {
    sum += term / divisor;
    term *= -x * x;
    divisor += 2.0;
  }

  return sum;
}

static inline double power_of_two(int n) {
  double result = 1.0;
  for (int i = 0; i < n; i++) {
    result *= 2.0;
  }
  return result;
}

double cos(double x) {
  x *= M_PI / 180.0;

  double y = 1.0; 
  double z = x;   
  double factor = 1.0;

  for (int i = 0; i < num_iteracoes; i++) {
    double angle = atan(power_of_two(-i));
    double cosh = factor * cos(angle);
    double sinh = factor * sin(angle);

    if (z >= 0) {
      z -= angle;
      y -= sinh;
    } else {
      z += angle;
      y += sinh;
    }

    factor *= cosh;
  }

  return y;
}

double sin(double x){
  double y = 0.0;
  double z = x;
  double factor = 1.0;

  for (int i = 0; i < num_iteracoes; i++) {
    double tmp = z;
    if (z < 0){
      z += factor;
    }
    else{
      z -= factor;
      factor *= 0.5;
      y += z;
      z *= 0.5;
    }
  }

  return y;
}

double tan(double x){
  return sin(x) / cos(x);
}

double sqrt(double x) {
    if (x == 0.0)
        return 0.0;

    double prev_result = x;
    double result = 0.5 * (prev_result + x / prev_result);

    while (result != prev_result) {
        prev_result = result;
        result = 0.5 * (prev_result + x / prev_result);
    }

    return result;
}
