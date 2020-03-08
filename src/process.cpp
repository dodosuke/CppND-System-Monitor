#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;
using std::stoi;

Process::Process(int pid) : pid_(pid) {
	stats_ = LinuxParser::ProcStat(pid);
	command_ = LinuxParser::Command(pid);
	ram_ = to_string(stoi(LinuxParser::Ram(pid))/1024);
	user_ = LinuxParser::User(pid);
	uptime_ = stoi(stats_[21]) / sysconf(_SC_CLK_TCK);
	
	float totalTime = stoi(stats_[13])
					 + stoi(stats_[14])
					 + stoi(stats_[15])
					 + stoi(stats_[16]);
	float seconds = LinuxParser::UpTime() - uptime_;
	cpu_ = totalTime / sysconf(_SC_CLK_TCK) / seconds;
}

int Process::Pid() { 
	return pid_;
}

float Process::CpuUtilization() const {
	return cpu_;
}

string Process::Command() { 
	return command_;
}

string Process::Ram() {
	return ram_;
}

string Process::User() {
	return user_;
}

long int Process::UpTime() { 
	return uptime_;
}

bool Process::operator<(Process const& a) const { 
	return CpuUtilization() > a.CpuUtilization();
}
