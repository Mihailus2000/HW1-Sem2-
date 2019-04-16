#include "BaseDepartment.h"

//void BaseDepartment::WriteToFile() {
//	std::ofstream fout;
//	fout.open(PATH, std::ios_base::app);
//	fout << "{" << this->nameOfDepartment << ":{" << this->SaEC << "},{";
//	for (int i = 0; i < numOfSubdepartments; i++) {
//		fout << Subdepartments[i].nameOfSubdep << ":{";
//		for (int j = 0; j < Subdepartments[i].numOfDisciplines; j++) {
//			fout << Subdepartments[i].Disciplines[j].name << ":<" <<
//				Subdepartments[i].Disciplines[j].numberOfTeachers << ">";
//			if (j != j < Subdepartments[i].numOfDisciplines - 1)
//				fout << ";";
//			else
//				fout << "}";
//		}
//		if (i != numOfSubdepartments - 1)
//			fout << "/";
//		else
//			fout << "}";
//	}
//
//}

void BaseDepartment::readFromFile(/*std::string*/) {}

int BaseDepartment::calcNumOfSubjects() {
	return 0;
}