#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

class Department {
public:
	Department() = default;
	~Department() = default;

	virtual int calcNumOfSubjects() = 0;
	virtual void readFromFile() = 0;
	virtual void WriteToFile() = 0;
private:

};
