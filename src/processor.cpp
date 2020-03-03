#include "processor.h"
#include "linux_parser.h"

#include <vector>

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
	std::vector<int> data = LinuxParser::CpuUtilization();
	std::vector<int> prevData = data_;

	int prevIdle = prevData[LinuxParser::CPUStates::kIdle_] \
				 + prevData[LinuxParser::CPUStates::kIOwait_];
	int idle = data[LinuxParser::CPUStates::kIdle_] \
	         + data[LinuxParser::CPUStates::kIOwait_];
	
	int prevNonIdle = prevData[LinuxParser::CPUStates::kUser_] \
					+ prevData[LinuxParser::CPUStates::kNice_] \
					+ prevData[LinuxParser::CPUStates::kSystem_] \
					+ prevData[LinuxParser::CPUStates::kIRQ_] \
					+ prevData[LinuxParser::CPUStates::kSoftIRQ_] \
					+ prevData[LinuxParser::CPUStates::kSteal_];
	int nonIdle = data[LinuxParser::CPUStates::kUser_] \
				+ data[LinuxParser::CPUStates::kNice_] \
				+ data[LinuxParser::CPUStates::kSystem_] \
				+ data[LinuxParser::CPUStates::kIRQ_] \
				+ data[LinuxParser::CPUStates::kSoftIRQ_] \
				+ data[LinuxParser::CPUStates::kSteal_];			
	 
	int prevTotal = prevIdle + prevNonIdle;
	int total = idle + nonIdle;
	
	int totald = total - prevTotal;
	int idled = idle - prevIdle;
	
	// Update the data
	data_ = data;
	
	return ((float)totald - (float)idled)/(float)totald;	
}

