#include "project.h"
bool kiemtrangaysinh(int ngay, int thang, int nam)
{
	if (ngay < 1 || ngay > 31 || thang < 1 || thang >12 || nam < 1)
	{
		return false;
	}
	if (thang == 2)
	{
		if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
		{
			if (ngay > 29)
			{
				return false;
			}
		}
		else
		{
			if (ngay > 28)
			{
				return false;
			}
		}
	}
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
	{
		if (ngay > 30)
		{
			return false;
		}
	}
	else
	{
		if (ngay > 31)
		{
			return false;
		}
	}
	return true;
}
string dayofweek(int day, int month, int year) {
    // Lưu trữ các giá trị đặc biệt tương ứng với từng tháng
    static int month_values[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

    // Nếu tháng là tháng 1 hoặc 2, giảm năm đi 1
    if (month < 3) {
        year -= 1;
    }

    // Áp dụng công thức Zeller's Congruence để tính ngày của tuần
    int result = (year + year / 4 - year / 100 + year / 400 + month_values[month - 1] + day) % 7;
	string wDay;
    // Kết quả từ 0 đến 6, với 0 là Chủ Nhật, 1 là Thứ Hai, và tiếp tục...
    switch (result)
	{
	case 0:
		wDay = "Sun";
		break;
	case 1:
		wDay = "Mon";
		break;
	case 2:
		wDay = "Tue";
		break;
	case 3:
		wDay = "Wed";
		break;
	case 4:
		wDay = "Thu";
		break;
	case 5:
		wDay = "Fri";
		break;
	case 6:
		wDay = "Sat";
		break;
	}
	return wDay;
}
Date str_to_date(string str){
	Date date;
	stringstream ss(str);
	string token;

	getline(ss,token,'/');
	date.day = stoi(token);

	getline(ss,token,'/');
	date.month = stoi(token);

	getline(ss,token,'/');
	date.year = stoi(token);

	date.wDay = dayofweek(date.day,date.month,date.year);

	return date;
}
SinhVien* CreateSV(string MSSV, string ten, string ho, string gender,string birth, string cccd){
	SinhVien* newSV = new SinhVien;
	cout<<"Nhap MSSV: ";
	cin>>MSSV;
	cin.ignore();
	cout<<"Nhap ten: ";
	getline(cin,ten);
	cout<<"Nhap ho: ";
	getline(cin,ho);
	cout<<"Nhap gioi tinh (MALE/FEMALE): ";
	cin>>gender;
	cout<<"Nhap ngay thang nam sinh (dd/mm/yyyy): ";
	cin>>birth;
	cout<<"Nhap CCCD: ";
	cin>>cccd;
	
	newSV->mssv = MSSV;
	newSV->ten = ten;
	newSV->ho = ho;
	newSV->gender = gender;
	newSV->birth = str_to_date(birth);
	newSV->cccd = cccd;
	newSV->next = NULL;
	return newSV;
}
void InitList(ListSV &List){
	List.phead = NULL;
	List.ptail = NULL;
	List.size = 0;
}
void AddSinhVien(ListSV& List,SinhVien* newSV){
	if(newSV == NULL) return;
	if(List.phead == NULL){
		List.phead = newSV;
		List.ptail = newSV;
	}else{
		List.ptail->next = newSV;
		List.ptail = newSV;
	}
	List.size++;
}
void OutputListStudents(ListSV List) {
    if (List.phead == NULL) {
        cout << "Danh sach trong." << endl;
        return;
    }
    
    // Tạo đường kẻ ngang
    cout << setfill('-') << setw(95) << "-" << endl;
    
    // Tiêu đề
    cout << setfill(' ') << setw(10) << "MSSV"
         << "|" << setw(15) << "Ten"
         << "|" << setw(15) << "Ho"
         << "|" << setw(10) << "Gender"
         << "|" << setw(15) << "Ngay sinh"
         << "|" << setw(15) << "CCCD" << endl;
    
    // Tạo đường kẻ ngang tiếp theo
    cout << setfill('-') << setw(95) << "-" << endl;
    
    SinhVien* current = List.phead;
    while (current != NULL) {
        cout << setfill(' ') << setw(10) << current->mssv
             << "|" << setw(15) << current->ten
             << "|" << setw(15) << current->ho
             << "|" << setw(10) << current->gender
             << "|" << setw(15) << (to_string(current->birth.day) + "/" + to_string(current->birth.month) + "/" + to_string(current->birth.year))
             << "|" << setw(15) << current->cccd << endl;
        current = current->next;
    }
    
    // Tạo đường kẻ ngang cuối cùng
    cout << setfill('-') << setw(95) << "-" << endl;
}
// void taosv(string& MSSV, string &ten, string &ho, string& gender, int& ngay, int& thang, int& nam, string &cccd)
// {
// 	cin.ignore();
// 	cout << "Nhap vao ho cua sinh vien:";
// 	getline(cin, ho);
	
// 	cout << "Nhap vao ten cua sinh vien:";
// 	getline(cin, ten);
	
// 	cout << "Nhap vao mssv:";
// 	getline(cin, MSSV);
	
// 	do
// 	{
// 		cout << "Nhap vao gioi tinh sinh vien (Male/Female):";
// 		getline(cin, gender);
// 	} while (gender!= "Male" && gender!= "Female");
// 	do
// 	{
// 		cout << "Nhap vao ngay thang nam sinh cua sinh vien:" << endl;
// 		cout << "Nhap vao ngay:";
// 		cin >> ngay;
// 		cout << "Nhap vao thang:";
// 		cin >> thang;
// 		cout << "Nhap vao nam:";
// 		cin >> nam;
// 		if (kiemtrangaysinh(ngay, thang, nam) == false)
// 		{
// 			cout << "Ngay sinh khong hop le,vui long nhap lai" << endl;
// 		}
// 	} while (kiemtrangaysinh(ngay, thang, nam) == false);
// 	cout << "Nhap vao so cccd cua sinh vien:";
// 	cin.ignore();
// 	getline(cin, cccd);
// }
void themsvvaolop(Class*& lop, string& MSSV, string& ten, string& ho, string& gender, int& ngay, int& thang, int &nam, string& cccd) {
	if (lop->ds == NULL) 
	{
		lop->ds = new ListSV();
		lop->ds->phead = lop->ds->ptail = nullptr;
	}
	SinhVien* temp = lop->ds->phead;
	SinhVien* new_sv = new SinhVien();
	new_sv->mssv = MSSV;
	new_sv->ten = ten;
	new_sv->ho = ho;
	new_sv->gender = gender;
	new_sv->birth.day = ngay;
	new_sv->birth.month = thang;
	new_sv->birth.year = nam;
	new_sv->cccd = cccd;
	new_sv->next = nullptr;

	if (temp == nullptr)
	{
		lop->ds->phead = lop->ds->ptail = new_sv;
	}
	else 
	{
		lop->ds->ptail->next = new_sv;
		lop->ds->ptail = new_sv;
	}
	//cout <<ho<< new_sv->ho <<"kk"<< endl;
}
void taonamhoc(ListNamHoc& L, NamHoc*& N)
{
	N = new NamHoc();
	cout << "Nhap vao thoi gian hoc(VD:2020-2021):";
	cin >> N->ngaybatdau;
	if (L.phead == NULL)
	{
		L.phead = N;
	}
	else
	{
		NamHoc* temp = L.phead;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = N;
	}
	N->next = NULL;
	N->Hocky = NULL;
}
void taohocky(Semester*& H, ListNamHoc& L)
{
	H = new Semester();
	cout << "Chon nam hoc:" << endl;
	NamHoc* temp = L.phead;
	while (temp != NULL)
	{
		cout << temp->ngaybatdau << endl;
		temp = temp->next;
	}
	cin.ignore();
	getline(cin,H->Ngaybatdau);
	cout << "Chon thu tu cua hoc ki(1-3):";
	do
	{
		cin >> H->thutu;
		if (H->thutu < 1 || H->thutu>3)
		{
			cout << "Hoc ky khong hop le,vui long nhap lai" << endl;
		}
	} while (H->thutu < 1 || H->thutu>3);
	cout << "Nhap vao ngay bat dau(VD 01/01/2024):";
	cin >> H->Ngaybatdau;
	cout << "Nhap vao ngay ket thuc(VD 01/01/2024):";
	cin >> H->Ngayketthuc;
	H->next = NULL;
	temp = L.phead;
	while (temp != NULL)
	{
		if (temp->ngaybatdau== H->Ngaybatdau)
		{
			if (temp->Hocky == NULL)
			{
				temp->Hocky = H;
			}
			else
			{
				Semester* temphocky = temp->Hocky;
				while (temphocky != NULL)
				{
					temphocky = temphocky->next;
				}
				temphocky->next = H;
			}
			cout << "Da them 1 hoc ky vao nam hoc " << temp->ngaybatdau << endl;
			break;
		}
		temp = temp->next;
	}
}
//Yêu cầu số 9
void themlopmoivaodanhsachcaclop(Class*& CTT, ListClass*& DS)
{
	CTT = new Class();
	cout << "Nhap vao ten lop: ";
	cin >> CTT->ClassName;
	CTT->next = NULL;
	if (DS->head == NULL)
	{
		DS->head = CTT;
	}
	else
	{
		Class* temp = DS->head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = CTT;
	}

	cout << "Da them 1 lop moi vao danh sach cac lop" << endl;
}
void xemdanhsachcaclop(ListClass*& DS)
{
	cout << "Danh sach cac lop:" << endl;
	Class* temp = DS->head;
	while (temp != NULL)
	{
		cout << temp->ClassName << endl;
		temp = temp->next;
	}
}
void xemdanhsachkhoahoc(ListCourses*& LC)
{
	cout << "Danh sach cac khoa hoc hien tai:" << endl;
	Course* temp = LC->head;
	while (temp != NULL)
	{
		cout << temp->courseName << endl;
		temp = temp->next;
	}
}
//Yeu cau 12
//void xoasvkhoikhoahoc(ListCourses*& LC)
//{
//	char arr[50];
//	cout << "Chon khoa hoc muon xoa hoc sinh:" << endl;
//	Course* temp = LC->head;
//	while (temp != NULL)
//	{
//		cout << temp->courseName << endl;
//	}
//	cin.getline(arr, 50);
//	temp = LC->head;
//	while (temp != NULL)
//	{
//		if (strcmp(temp->courseName, arr) == 0)
//		{
//			break;
//		}
//		temp = temp->next;
//	}
//	cout << "Chon ten sinh vien muon xoa:" << endl;
//	SinhVien* phu = temp->dssv->phead;
//	while (phu != NULL)
//	{
//		cout << phu->ten << endl;
//		phu = phu->next;
//	}
//	char ten[50];
//	cin.getline(ten, 50);
//	phu = temp->->phead;
//	SinhVien* prephu = NULL;
//	while (phu != NULL)
//	{
//		if (phu->ten== ten)
//		{
//			if (phu == temp->dssv->phead)
//			{
//				temp->dssv->phead = temp->dssv->phead->next;
//				delete phu;
//			}
//			else
//			{
//				prephu->next = phu->next;
//				delete phu;
//			}
//			break;
//		}
//		prephu = phu;
//		phu = phu->next;
//	}
//}
//void xemdanhsachhocvientrongkhoa(Course*& c)
//{
//	SinhVien* temp = c->dssv->phead;
//	cout << "Danh sach hoc vien cua khoa hoc la:" << endl;
//	while (temp != NULL)
//	{
//		cout << temp->ho << " " << temp->ten << endl;
//		temp = temp->next;
//	}
//}
//void xembangdiemcua1khoahoc(Student*&st,Course*& c,ListStudent*&lst)
//{
//	Student* temp = lst->head;
//	while (temp != NULL)
//	{
//		Course* phu = temp->enrolledCourses.head;
//		while (phu != NULL)
//		{
//			if (strcmp(phu->courseName,c->courseName)==0)
//			{
//				cout << temp->firstName << " " << temp->lastName << ":" << endl;
//				cout<<"Diem cong:" <<temp->courseMark.otherMark<< endl;
//				cout << "Diem giua ki:" << temp->courseMark.midtermMark << endl;
//				cout << "Diem cuoi ki:" << temp->courseMark.finalMark << endl;
//				cout << "Diem tong ket:" << temp->courseMark.totalMark << endl;
//			}
//			phu = phu->next;
//		}
//		temp = temp->next;
//	}
//}
// 7. Thêm một khóa học vào học kỳ này: id khóa học, tên khóa học, tên lớp, tên giáo viên,
// số tín chỉ, số lượng sinh viên tối đa trong khóa học (mặc định là 50), ngày học
// trong tuần và buổi học mà khóa học sẽ được thực hiện (THÁNG / TUE / WED / THU /
// Thứ Sáu/Thứ Bảy, S1 (07:30), S2 (09:30), S3(13:30) và S4 (15:30)). Một khóa học sẽ được giảng dạy trong
// chỉ một buổi trong một tuần.
void InitList(ListCourses &list){
	list.head = NULL;
	list.tail = NULL;
	list.size = 0;
}
Course* InputCourse(string id,string CourseName,string ClassName,string GVName,int AcademicYear,int Credits,string wDay,string Session){
	Course* newCourse = new Course;
	cout<<"Nhap khoa hoc"<<endl;
	cout<<"Nhap id khoa hoc: ";
	cin>>id;
	cin.ignore();
	cout<<"Nhap ten khoa hoc: ";
	getline(cin,CourseName);
	cout<<"Nhap ten lop: ";
	cin>>ClassName;
	cin.ignore();
	cout<<"Nhap ten Giao Vien: ";
	getline(cin,GVName);
	cout<<"Nhap Academic Year: ";
	cin>>AcademicYear;
	cout<<"Nhap so tin chi: ";
	cin>>Credits;
	cout<<"Nhap week day (Mon/Tue...): ";
	cin>>wDay;
	cout<<"Nhap Session [S1 (07:30), S2 (09:30), S3(13:30), S4 (15:30)]: ";
	cin>>Session;
	newCourse->id = id;
    newCourse->courseName = CourseName;
    newCourse->teacherName = GVName;
    newCourse->ClassName = ClassName; 
	newCourse->academicYear=AcademicYear;
    newCourse->Credits = Credits; 
    newCourse->wDay = wDay;
    newCourse->session = Session;
    newCourse->next = NULL;
    return newCourse;
}

void AddCourse(ListCourses& List,Course* newCourse){
	if (newCourse == NULL) return;
    if (List.head == NULL) {
        List.head = newCourse;
        List.tail = newCourse;
    } else {
        List.tail->next = newCourse;
        List.tail = newCourse;
    }
    List.size++;
}
void RemoveCourse(ListCourses& List,Course* course){
	if(List.head == NULL){
		return;
	}
	else if(List.head == course){
		List.head = course->next;
		if(List.tail == course){
			List.tail = NULL;
		}
	}else{
		// duyet list tim course
		Course* cur = List.head;
		while(cur!= NULL && cur->next != course){
			cur = cur->next;
		}
		//luc nay cur->next = course hoac cur == NULL
		if(cur->next == course){
			cur->next = course->next;
			if(List.tail == course){
				List.tail = cur;
			}
		}else{ // luc nay cur = NULL -> ko tim thay course
			return;
		}
	}
}
Course* Find_ID(ListCourses List, string id){
	Course* cur = List.head;
	while(cur != NULL &&  cur->id != id){
		cur = cur ->next;
	}
	return cur;
}
void OutputListCourses(ListCourses List) {
    if (List.head == NULL) {
        cout << "Danh sach trong." << endl;
        return;
    }
    
    // Tạo đường kẻ ngang
    cout << setfill('-') << setw(120) << "-" << endl;
    
    // Tiêu đề
    cout << setfill(' ') << setw(10) << "ID"
         << "|" << setw(20) << "Ten khoa hoc"
         << "|" << setw(15) << "Lop"
         << "|" << setw(20) << "Giao vien"
         << "|" << setw(10) << "So tin chi"
         << "|" << setw(15) << "SL sinh vien"
         << "|" << setw(10) << "Ngay hoc"
         << "|" << setw(15) << "Buoi hoc" << endl;
    
    // Tạo đường kẻ ngang tiếp theo
    cout << setfill('-') << setw(120) << "-" << endl;
    
    Course* current = List.head;
    while (current != NULL) {
        cout << setfill(' ') << setw(10) << current->id
             << "|" << setw(20) << current->courseName
             << "|" << setw(15) << current->ClassName
             << "|" << setw(20) << current->teacherName
             << "|" << setw(10) << current->Credits
             << "|" << setw(15) << "50" // Số lượng sinh viên tối đa, mặc định là 50
             << "|" << setw(10) << current->wDay
             << "|" << setw(15) << current->session << endl;
        current = current->next;
    }
    
    // Tạo đường kẻ ngang cuối cùng
    cout << setfill('-') << setw(120) << "-" << endl;
}


