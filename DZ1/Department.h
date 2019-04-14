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

	virtual InfoOfSubdepartment getVector(int index) = 0;
	virtual std::string getSaEC() = 0;
	virtual int getnumOfSub() = 0;
	virtual std::string getNOD() = 0;
	virtual int calcNumOfSubjects() = 0;
	virtual void readFromFile() = 0;
	virtual void WriteToFile() = 0;
private:

};
