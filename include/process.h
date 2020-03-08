#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();
  std::string User();
  std::string Command();
  float CpuUtilization() const;
  std::string Ram();
  long int UpTime();
  bool operator<(Process const& a) const;
  Process(int pid);

 private:
  int pid_;
  std::vector<std::string> stats_;
  std::string command_;
  std::string ram_;
  std::string user_;
  int uptime_;
  float cpu_;
};

#endif
