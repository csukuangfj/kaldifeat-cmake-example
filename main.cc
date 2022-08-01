// main.cc
//
// Copyright (c)  2022  Xiaomi Corporation (authors: Fangjun Kuang)

#include "kaldifeat/csrc/feature-fbank.h"

int main() {
  kaldifeat::FbankOptions opts;
  std::cout << opts.ToString() << "\n";
  return 0;
}
