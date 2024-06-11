#ifndef _PROJECT_H
#define _PROJECT_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
	string wDay;
};
struct Course
{
	string id;
	string courseName;
	string teacherName;
	string ClassName;
	int Credits;
	int maxStudents = 50;
	int academicYear;
	string wDay;
	string session;
	Course* next;
};
struct 	ListCourses

{
	Course* head;
	Course* tail;
	int size;
};
struct SinhVien
{
	string mssv;
	string ten;
	string ho;
	string gender;
	Date birth;
	string cccd;
	SinhVien* next;
	ListCourses* Lc;
	string ClassName;
};
struct ListSV
{
	SinhVien* phead;
	SinhVien* ptail;
	int size;
};
struct Class
{
	ListSV* ds;
	string ClassName;
	Class* next;
};
struct ListClass
{
	Class* head;
};
struct Semester
{
	int thutu;
	string Ngaybatdau;
	string Ngayketthuc;
	Semester* next;
	ListCourses* lc;
};

struct NamHoc
{
	string ngaybatdau;
	Semester* Hocky;
	NamHoc* next;
};
struct ListNamHoc
{
	NamHoc* phead;
};


bool kiemtrangaysinh(int ngay, int thang, int nam);
string dayofweek(int day, int month, int year);
Date str_to_date(string str);
void taosv(string &MSSV, string& ten, string& ho, string& gender, int& ngay, int& thang, int& nam, string &cccd);
void themsvvaolop(Class*& lop, string &MSSV, string& ten, string &ho, string& gender, int& ngay, int& thang, int& nam, string& cccd);
void taonamhoc(ListNamHoc& L, NamHoc*& N);
void taohocky(Semester*& H, ListNamHoc& L);
void themlopmoivaodanhsachcaclop(Class*& CTT,ListClass*& DS);
void xemdanhsachcaclop(ListClass*& DS);
void xemdanhsachkhoahoc(ListCourses*& LC);
void xoasvkhoikhoahoc(ListCourses*& LC);	
//void xembangdiemcua1khoahoc(Student*& st, Course*& c, ListStudent*& lst);
//void xemdanhsachhocvientrongkhoa(Course*& c);
//tin
SinhVien* CreateSV(string MSSV, string ten, string ho, string gender,string birth, string cccd);
void InitList(ListSV &List);
void AddSinhVien(ListSV& List,SinhVien* newSV);
void OutputListStudents(ListSV List);
//7
void InitList(ListCourses &list);
Course* InputCourse(string id,string CourseName,string ClassName,string GVName,int AcademicYear,int Credits,string wDay,string Session);
void AddCourse(ListCourses& List,Course* newCourse);
void RemoveCourse(ListCourses& List,Course* course);
Course* Find_ID(ListCourses List, string id);
void OutputListCourses(ListCourses List);

#endif