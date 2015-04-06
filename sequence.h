#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include <vector>
#include <string>

struct Sequence
{
  Sequence(int B = 0);
  ~Sequence() { }

  void set_base(int B);

  int get_size();
  std::string get_numbers();
  std::string get_zeroes();

  int base;
  std::vector<int> numbers;
  std::vector<int> zeroes;
  int true_size;
  int exponent;
  bool neg_one;
};


#endif
