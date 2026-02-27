#include <iostream>
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


void test_int_constructor() {
  std::cout << "\n--- int constructor ---" << std::endl;
  Fixed a(10);
  check(a.toInt() == 10, "Fixed(10).toInt() == 10");
  check(a.toFloat() == 10.0f, "Fixed(10).toFloat() == 10.0f");
}

void test_float_constructor() {
  std::cout << "\n--- float constructor ---" << std::endl;
  Fixed a(42.42f);
  check(a.toInt() == 42, "Fixed(42.42f).toInt() == 42");
  // перевіряємо що близько до 42.42 а не точно
  float diff = a.toFloat() - 42.42f;
  if (diff < 0) diff = -diff;  // абсолютне значення
  check(diff < 0.01f, "Fixed(42.42f).toFloat() близько до 42.42f");
}

void test_negative() {
  std::cout << "\n--- negative numbers ---" << std::endl;
  Fixed a(-5);
  check(a.toInt() == -5, "Fixed(-5).toInt() == -5");
  Fixed b(-3.5f);
  check(b.toFloat() == -3.5f, "Fixed(-3.5f).toFloat() == -3.5f");
}

int main(void) {
  std::cout << "=== Fixed ex00 tests ===" << std::endl;

  test_int_constructor();
  test_float_constructor();
  test_negative();

  print_results();
  return (tests_failed > 0 ? 1 : 0);
}