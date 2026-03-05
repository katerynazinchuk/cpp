#include <iostream>
#include <string>
#include "Fixed.hpp"

// test system

static int tests_passed = 0;
static int tests_failed = 0;

void check(bool condition, const std::string& test_name) {
  if (condition) {
    std::cout << "✅ PASS: " << test_name << std::endl;
    tests_passed++;
  } else {
    std::cout << "❌ FAIL: " << test_name << std::endl;
    tests_failed++;
  }
}

void print_results() {
  std::cout << "\n─────────────────────" << std::endl;
  std::cout << "passed: " << tests_passed << std::endl;
  std::cout << "failed: " << tests_failed << std::endl;
  std::cout << "─────────────────────" << std::endl;
}

/* ------------------ ex02 tests ------------------ */

void test_comparison() {
  std::cout << "\n--- comparison operators ---" << std::endl;
  Fixed a(10);
  Fixed b(5);
  Fixed c(10);

  check(a > b,  "10 > 5  == true");
  check(b < c,    "5 < 10  == true");
  check(a >= c,    "10 >= 10 == true");
  check(b <= c,    "5 <= 10  == true");
  check(a == c,    "10 == 10 == true");
  check(a != b,    "10 != 5  == true");
  // false cases
  check(!(b > a),  "5 > 10  == false");
  check(!(a < b),  "10 < 5  == false");
  check(!(a != c), "10 != 10 == false");
}

void test_arithmetic() {
  std::cout << "\n--- arithmetic operators ---" << std::endl;
  Fixed a(10);
  Fixed b(5);

  check((a + b).toInt() == 15, "10 + 5 == 15");
  check((a - b).toInt() == 5, "10 - 5 == 5");
  check((a * b).toInt() == 50, "10 * 5 == 50");
  check((a / b).toInt() == 2, "10 / 5 == 2");
}

void test_increment() {
  std::cout << "\n--- increment/decrement ---" << std::endl;
  Fixed a(5);

  // pre-increment
  Fixed pre = ++a;
  check(pre.toFloat() == 5.00390625f, "++a returns 5 + epsilon");
  check(a.toFloat() == 5.00390625f,   "a after ++a == 5 + epsilon");

  // post-increment
  Fixed post = a++;
  check(post.toFloat() == 5.00390625f,  "a++ returns old value");
  check(a.toFloat() == 5.0078125f,      "a after a++ == 5 + 2 * epsilon");

  // pre-decrement
  check((--a).toFloat() == 5.00390625f, "--a returns previous");
  check(a.toFloat() == 5.00390625f,     "a after --a correct");

  // post-decrement
  Fixed postd = a--;
  check(postd.toFloat() == 5.00390625f, "a-- returns old value");
  check(a.toFloat() == 5.0f,            "a after a-- == 5");
}

void test_min_max() {
  std::cout << "\n--- min/max ---" << std::endl;
  Fixed a(10);
  Fixed b(5);

  check(Fixed::min(a, b) == b, "min(10, 5) == 5");
  check(Fixed::max(a, b) == a, "max(10, 5) == 10");
}

int main(void) {
  std::cout << "=== Fixed ex02 tests ===" << std::endl;

  test_comparison();
  test_arithmetic();
  test_increment();
  test_min_max();

  print_results();
  return (tests_failed > 0 ? 1 : 0);
}
