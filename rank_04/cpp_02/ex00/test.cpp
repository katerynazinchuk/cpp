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

void test_default_constructor() {
  std::cout << "\n--- default constructor ---" << std::endl;
  Fixed a;
  check(a.getRawBits() == 0, "initial value is 0");
}

void test_set_get() {
  std::cout << "\n--- setRawBits / getRawBits ---" << std::endl;
  Fixed a;
  a.setRawBits(42);
  check(a.getRawBits() == 42, "setRawBits(42) → getRawBits() == 42");
  a.setRawBits(-10);
  check(a.getRawBits() == -10, "setRawBits(-10) → getRawBits() == -10");
}

void test_copy_constructor() {
  std::cout << "\n--- copy constructor ---" << std::endl;
  Fixed a;
  a.setRawBits(42);
  Fixed b(a);
  check(b.getRawBits() == 42, "copy has same value");
  a.setRawBits(100);
  check(b.getRawBits() == 42, "copy is independent from original");
}

void test_copy_assignment() {
  std::cout << "\n--- copy assignment ---" << std::endl;
  Fixed a;
  Fixed b;
  a.setRawBits(99);
  b = a;
  check(b.getRawBits() == 99, "assignment copies value");
  a.setRawBits(0);
  check(b.getRawBits() == 99, "assigned copy is independent");
}

void test_self_assignment() {
  std::cout << "\n--- self assignment ---" << std::endl;
  Fixed a;
  a.setRawBits(55);
  Fixed* ptr = &a;
  a = *ptr;
  check(a.getRawBits() == 55, "self assignment keeps value");
}

int main(void) {
  std::cout << "=== Fixed ex00 tests ===" << std::endl;

  test_default_constructor();
  test_set_get();
  test_copy_constructor();
  test_copy_assignment();
  test_self_assignment();

  print_results();
  return (tests_failed > 0 ? 1 : 0);
}