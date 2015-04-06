#include "sequence.h"
#include <sstream>

Sequence::Sequence(int B)
{
  set_base(B);
}

void Sequence::set_base(int B)
{
  base = B;
  true_size = 0;
  exponent = 0;
  neg_one = false;
  numbers.clear();
  zeroes.clear();

  if (base > 0) {
    numbers.push_back(0);
    numbers.push_back(1);
    zeroes.push_back(1);
    bool done = false;
    while (!done) {
      int last   = numbers[ numbers.size() - 1 ];
      int second = numbers[ numbers.size() - 2 ];
      int next_num = last + second;
      next_num %= base;
      if (next_num == 0) {
        if (last == 1) {
          done = true;
        } else {
          zeroes.push_back( last );
          if (exponent == 0) {
            exponent = last;
          }
          if (last == base - 1) {
            neg_one = true;
          }
        }
      }
      if (!done) {
        numbers.push_back( next_num );
      }
    }
    true_size = numbers.size() / zeroes.size();
  }
}

int Sequence::get_size()
{
  return numbers.size();
}

std::string Sequence::get_numbers()
{
  std::stringstream ret;
  for (int i = 0; i < numbers.size(); i++) {
    ret << numbers[i];
    if (i < numbers.size() - 1) {
      ret << " ";
    }
  }
  return ret.str();
}

std::string Sequence::get_zeroes()
{
  std::stringstream ret;
  for (int i = 0; i < zeroes.size(); i++) {
    ret << zeroes[i];
    if (i < zeroes.size() - 1) {
      ret << " ";
    }
  }
  return ret.str();
}
