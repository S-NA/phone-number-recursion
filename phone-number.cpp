#include <iostream>
#include <fstream>

unsigned long recursive_sum(unsigned long &a) {
  std::ofstream fp;
  fp.open("number.log", std::ios::app);
  fp << a << "\n";
  fp.close();

  unsigned long sum = 0;
  while (a != 0) {
      unsigned long digit = a % 10;
      a /= 10;
      sum += digit;
  }
  if (sum > 9) {
      sum = recursive_sum(sum);
  } else {
      fp.open("number.log", std::ios::app);
      fp << sum << "\n";
      fp.close();
      return sum;
  }
}

int main(void) {
  std::cout << "Enter your phone number: ";
  unsigned long number;
  std::cin >> number; /* This does not deal with letters. */
  if (std::cin.fail()) std::cout << "Ya loser, enter an integer.";
  unsigned long sum = recursive_sum(number);
  std::cout << "The summed: ";
  std::cout << sum;
}
