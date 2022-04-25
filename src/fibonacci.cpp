#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }
    double result = pow(1 + sqrt(5), n) - pow(1 - sqrt(5), n);
    result = result / (pow(2, n) * sqrt(5));

    return static_cast<int64_t>(round(result));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    for (int i = 1; i < n; i++){
      fib_curr += fib_prev;
      fib_prev = fib_curr - fib_prev;
    }

    return fib_curr;
  }

  int64_t fib_recursive(int n){

    if (n <= 1) {
      return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache){

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }

    cache[n] = fib_recursive_memoization(n - 1, cache) + fib_recursive_memoization(n - 2, cache);

    return cache[n];
  }

  int64_t fib_matrix(int n){

    if (n <= 1) {
      return n;
    }

    Matrix2x2 matrix = std::array<std::array<int, 2>, 2>();
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 0;

    return matrix_power(matrix, n - 1)[0][1];
  }

}  // namespace assignment
