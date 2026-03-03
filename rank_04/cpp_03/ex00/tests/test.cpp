#include <iostream>
#include <cassert>
# include "../ClapTrap.hpp"

static int tests_passed = 0;
static int tests_failed = 0;

void check(bool condition, const std::string& test_name) {
  if (condition) {
    std::cout << "  PASS: " << test_name << std::endl;
    tests_passed++;
  } else {
    std::cout << "  FAIL: " << test_name << std::endl;
    tests_failed++;
  }
}

void print_results() {
  std::cout << "\n─────────────────────────────" << std::endl;
  std::cout << "passed: " << tests_passed << std::endl;
  std::cout << "failed: " << tests_failed << std::endl;
  std::cout << "─────────────────────────────" << std::endl;
}

// ── test groups ───────────────────────────────────────────────

void test_construction() {
  std::cout << "\n--- construction ---" << std::endl;

  ClapTrap ct("Alice");
  check(ct.getName() == "Alice",       "name is Alice");
  check(ct.getHitPoints() == 10,       "hit_points starts at 10");
  check(ct.getEnergyPoints() == 10,    "energy_points starts at 10");
  check(ct.getAttackDamage() == 0,     "attack_damage starts at 0");
}

void test_attack() {
  std::cout << "\n--- attack ---" << std::endl;

  ClapTrap ct("Bob");
  ct.attack("Enemy");
  check(ct.getEnergyPoints() == 9,  "attack costs 1 EP");

  // витрачаємо всі EP
  ClapTrap broke("Broke");
  for (int i = 0; i < 10; i++)
    broke.attack("dummy");
  check(broke.getEnergyPoints() == 0, "after 10 attacks EP is 0");

  // атака при 0 EP — нічого не змінюється
  broke.attack("dummy");
  check(broke.getEnergyPoints() == 0, "attack at EP=0 does nothing");
}

void test_take_damage() {
  std::cout << "\n--- takeDamage ---" << std::endl;

  ClapTrap ct("Carol");
  ct.takeDamage(3);
  check(ct.getHitPoints() == 7,  "takeDamage(3) reduces HP to 7");

  // важливий edge case: HP не може стати від'ємним
  // unsigned int при відніманні більшого числа "обертається" до гігантського числа
  // тому нам треба захист в реалізації
  ClapTrap dead("Dead");
  dead.takeDamage(100);
  check(dead.getHitPoints() == 0, "takeDamage(100) clamps HP to 0");
}

void test_be_repaired() {
  std::cout << "\n--- beRepaired ---" << std::endl;

  ClapTrap ct("Dave");
  ct.takeDamage(5);    // HP = 5
  ct.beRepaired(3);    // HP = 8
  check(ct.getHitPoints() == 8,     "beRepaired(3) adds 3 HP");
  check(ct.getEnergyPoints() == 9,  "beRepaired costs 1 EP");

  ClapTrap broke("Broke");
  for (int i = 0; i < 10; i++)
    broke.attack("dummy");
  int hp_before = broke.getHitPoints();
  broke.beRepaired(5);
  check(broke.getHitPoints() == hp_before, "beRepaired at EP=0 does nothing");

  ClapTrap dead("Dead");
  dead.takeDamage(10);
  dead.beRepaired(5);
  check(dead.getHitPoints() == 0, "beRepaired at HP=0 does nothing");
}

// ── entry point ───────────────────────────────────────────────

int main() {
  std::cout << "=== ClapTrap tests ===" << std::endl;

  test_construction();
  test_attack();
  test_take_damage();
  test_be_repaired();

  print_results();
  return (tests_failed > 0 ? 1 : 0);
}