#include "DataBase.h"

//void BD::WriteToFile() {
//	std::ofstream fout;
//	fout.open(PATH, std::ios_base::app);
//	fout << "{";										// ������ (1)	
//	for (int ind = 0; ind < Container.size(); ind++) {
//
//		Department* Elem_Department = Container[ind];
//
//		fout << "{" << Elem_Department->getNameOfDep() << ":{" << Elem_Department->getSaEC() << "},{"; //������ (2),(3)
//		for (int i = 0; i < Elem_Department->getNumOfSub(); i++) {
//			InIt* ElemInfoOfParts = Elem_Department->getInfo();
//			Subdepartment SubDepElm = ElemInfoOfParts->getVecSubDep(i);
//
//			fout << SubDepElm.getNameOfSubdep() << ":{"; //������ (4)
//
//			for (int j = 0; j < SubDepElm.getNumOfDisciplines(); j++) {
//				Discipline DiscElem = SubDepElm.getVecDisc(j);
//				fout << DiscElem.name << ":<" <<
//					DiscElem.numberOfTeachers << ">";
//				if (j != /*j <*/ SubDepElm.getNumOfDisciplines() - 1) //????
//					fout << ";";
//				else
//					fout << "}";						// ����� (4)
//			}
//			if (i != Elem_Department->getNumOfSub() - 1) //?????
//				fout << "/";
//			else
//				fout << "}";							// ����� (3)					
//		}
//
//		if (Elem_Department->getClass() == "IND") {
//			fout << ",{";								// ������ (3)
//			for (int i = 0; i < Elem_Department->getNumOfOrganizations(); i++) {
//				InIt* ElemInfoOfParts = Elem_Department->getInfo();
//				Organization SubDepElm = ElemInfoOfParts->getVecOrganizations(i);
//
//				fout << SubDepElm.getNameOfOrganization() << ":{";		// ������ (4)
//
//				for (int j = 0; j < SubDepElm.getNumOfDisciplines(); j++) {
//					Discipline DiscElem = SubDepElm.getVecDisc(j);
//					fout << DiscElem.name << ":<" <<
//						DiscElem.numberOfTeachers << ">";
//					if (j != /*j <*/ SubDepElm.getNumOfDisciplines() - 1) //????
//						fout << ";";
//					else
//						fout << "}";									// ����� (4)
//				}
//				if (i != Elem_Department->getNumOfSub() - 1) //?????
//					fout << "/";
//				else
//					fout << "}";						// ����� (3)
//			}
//		}
//
//		if (ind == Container.size() - 1)
//			fout << "}";																				// ����� (2)
//		else
//			fout << "&";
//	}
//	fout << "}";								// ����� (1)
//}
