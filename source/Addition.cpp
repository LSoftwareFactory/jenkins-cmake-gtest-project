#include "Addition.h"
#include <iostream>
#include <thread>
#include <random>
#include <chrono>

namespace zf {
namespace sample {

Addition::Addition(int id) : id_(id) {
  std::cout << "Addition Constructor " << id << std::endl;
}

Addition::~Addition() {}

  
int Addition::add(int a, int b) { 
  
// wait random time
  std::mt19937_64 eng{std::random_device{}()};  // or seed however you want
  std::uniform_int_distribution<> dist{10, 100};
  std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});

  return a + b;
}
int Addition::addID(int val) { return add(val,id_); }
int Addition::addOne(int val) { return add(val,1); }
int Addition::addTwo(int val) { return add(val,2); }

} // namespace sample
} // namespace zf
