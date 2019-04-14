#include "IndustryDepartment.h"

void IndustryDepartment::WriteToFile() {
	std::ofstream fout;
	fout.open(PATH, std::ios_base::app);

}
void IndustryDepartment::readFromFile() {};
int IndustryDepartment::calcNumOfSubjects() {
	return 0;
};