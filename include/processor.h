#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

class Processor {
 public:
  float Utilization();  

 private:
  std::vector<int> data_ = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

#endif
