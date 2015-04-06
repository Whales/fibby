#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "sequence.h"

int main()
{
  int start, end;
  std::string filename;

  std::cout << "Start: ";
  std::cin >> start;
  std::cout << "End: ";
  std::cin >> end;
  std::cout << "Filename: ";
  std::cin >> filename;

  std::ofstream fout;
  if (!filename.empty() && filename != "-") {
    fout.open( filename.c_str() );
    if (!fout.is_open()) {
      std::cout << std::endl << "Couldn't open " << filename << " for writing.";
      std::cout << std::endl;
      return 1;
    }
  }

  std::vector<Sequence> seq;
  for (int i = start; i <= end; i++) {
    Sequence tmp_seq(i);
    seq.push_back(tmp_seq);
  }

/*
  for (int i = 0; i < seq.size(); i++) {
    std::stringstream sout;
    sout << seq[i].base << ": " << seq[i].get_size() << " " <<
            seq[i].true_size;
    if (seq[i].neg_one) {
      sout << " !!!";
    }
    sout << std::endl;
    sout << seq[i].get_numbers() << std::endl;
    sout << seq[i].get_zeroes() << std::endl << std::endl;
    if (fout.is_open()) {
      fout << sout.str();
    } else {
      std::cout << sout.str();
    }
  }
*/

  std::stringstream sout;
  sout << "Bases " << start << " - " << end << std::endl;
  sout << "Length:" << std::endl;
  for (int i = 0; i < seq.size(); i++) {
    sout << seq[i].get_size() << " ";
  }

  sout << std::endl << std::endl;
  sout << "Loops:" << std::endl;
  for (int i = 0; i < seq.size(); i++) {
    sout << seq[i].zeroes.size() << " ";
  }

  sout << std::endl << std::endl;
  sout << "Loop length:" << std::endl;
  for (int i = 0; i < seq.size(); i++) {
    sout << seq[i].true_size << " ";
  }

  sout << std::endl << std::endl;
  sout << "Contains (-1, 0):" << std::endl;
  for (int i = 0; i < seq.size(); i++) {
    if (seq[i].neg_one) {
      sout << seq[i].base << " ";
    }
  }

/*
  sout << std::endl << std::endl;
  sout << "Length / Base:" << std::endl;
  for (int i = 0; i < seq.size(); i++) {
    int div = seq[i].get_size() * 1000;
    div /= seq[i].base;
    sout << div / 1000 << "." << div % 1000 << " ";
  }

  sout << std::endl << std::endl;
  sout << "Loop length / Base:" << std::endl;
  for (int i = 0; i < seq.size(); i++) {
    int div = seq[i].true_size * 1000;
    div /= seq[i].base;
    sout << div / 1000 << "." << div % 1000 << " ";
  }
*/

  sout << std::endl << std::endl;
  sout << "Full data:" << std::endl;
  for (int i = 0; i < seq.size(); i++) {
    sout << seq[i].base << ": " << seq[i].get_size() << " (" <<
            seq[i].zeroes.size() << "; " << seq[i].true_size << ")";
    if (seq[i].exponent != 0) {
      sout << " [" << seq[i].exponent << "]";
    }
    if (seq[i].neg_one) {
      sout << " !!!";
    }
    sout << std::endl;
  }

  sout << std::endl << std::endl;
  sout << "Sequences:" << std::endl;
  for (int i = 0; i < seq.size(); i++) {
    sout << seq[i].base << ":" << std::endl;
    sout << seq[i].get_numbers() << std::endl << std::endl;
  }

  if (fout.is_open()) {
    fout << sout.str();
  } else {
    std::cout << sout.str();
  }

  return 0;
}
