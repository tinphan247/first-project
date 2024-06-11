#include "project.h"
int main()
{
	{
		Class* CTT = NULL;
		int menu;
		NamHoc* N;
		Semester* H;
		ListNamHoc L;
		L.phead = NULL;
		ListClass* DS=new ListClass();
		//them sinh vien
		int sl_SV;
		string mssv,FirstName,LastName,Gender,DateofBirth, cccd;
		SinhVien* newSV = new SinhVien;
		ListSV ListS;
		InitList(ListS);

		ListCourses ListC;
		InitList(ListC);
		Course* newCourse = new Course;
		string id,CourseName,ClassName,GVName,wDay,Session;
		int AcademicYear,Credits;
		int sl_Courses;
		string temp;
		DS->head =NULL;
		do
		{
			cout << "Nhap vao yeu cau muon lam:" << endl;
			cout << "(1):khoi tao 1 nam hoc moi" << endl;
			cout << "(2):Chon 1 nam hoc roi tao 1 hco ki moi trong nam hoc do" << endl;
			cout << "(3):Them 1 lop moi vao danh sach cac lop" << endl;
			cout << "(4):Xem danh sach cac lop" << endl;
			cout << "(5):Them sinh vien vao lop" << endl;
			cout << "(6) Them khoa hoc"<<endl;
			cout << "(7) Xoa 1 khoa hoc"<<endl;
			cin >> menu;
			if (menu == 1)
			{
				taonamhoc(L, N);
			}
			else if (menu == 2)
			{
				taohocky(H, L);
			}
			else if (menu == 3)
			{
			 themlopmoivaodanhsachcaclop(CTT, DS);
			}
			else if (menu == 4)
			{
				xemdanhsachcaclop(DS);
			}
			else if (menu == 5)
			{
				cout<<"Nhap so luong sinh vien: ";
				cin>>sl_SV;
				for(int i = 0; i < sl_SV;i++){
					newSV = CreateSV(mssv,FirstName,LastName,Gender,DateofBirth,cccd);
					AddSinhVien(ListS,newSV);
					newSV = NULL;
					system("cls");
					OutputListStudents(ListS);
					delete newSV;
				}
			}
			else if(menu == 6){
				cout<<"Nhap so luong khoa hoc: ";
				cin>>sl_Courses;
				for(int i = 0;i < sl_Courses;i++){
				newCourse = InputCourse(id,CourseName,ClassName,GVName,AcademicYear,Credits,wDay,Session);
				AddCourse(ListC,newCourse);
				newCourse = NULL;
				system("cls");
				OutputListCourses(ListC);
				delete newCourse;
				}
			}
		else if(menu == 7){
			cout<<"Nhap id khoa hoc muon xoa: ";
			cin>>temp;
			RemoveCourse(ListC,Find_ID(ListC,temp));
			OutputListCourses(ListC);
		}
		} while (menu != 0);
	}
}