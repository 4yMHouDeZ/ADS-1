// Copyright 2022 NNTU-CS
#include <cstdint>
#include <math.h>
#include <iostream>
#include "alg.h"


bool checkPrime(uint64_t value) {
  for (uint64_t i = 2; i < (uint64_t)sqrt(value) + 1; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t i = 2;

  while (n != 0) {
    if (checkPrime(i)) {
      n--;
    }
    i++;
  }

  return i;
}

uint64_t nextPrime(uint64_t value) {
  do {
    value++;
  } while (!checkPrime(value));
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t prev;
  uint16_t count = 0;
  for (uint64_t i = lbound; i < hbound; i++) {
    if (checkPrime(i)) {
      if (!prev) {
        prev = i;
      } else if (i - prev == 2) {
        count++;
      }
    }
  }
  return count;
}