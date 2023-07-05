#pragma once
/* Dinh nghia lop DocGia */
class DocGia {
private:
	char* MaDG; // mã độc giả, ex. “11120”
	char* HoTen; // Họ tên
	char* NgayExpire; // Ngày hết hạn, ex. “01/10/2023”
	int SachMuon; // Số sách mượn trong tháng
	char* LoaiDG; // Loại độc giả (“Thuong”, “VIP”)
public:
	//Constructors
	DocGia();
	DocGia(char* ma, char* ten, char* hethan, int muon, char* loai);
	DocGia(const DocGia& d);
	~DocGia();
	//Nhập thông tin độc giả
	void Nhap();
	//Xuất thông tin độc giả
	void Xuat();
	//Hàm tính phí
	float TinhPhi();
	DocGia& operator=(const DocGia& other);
	bool operator>(const DocGia& other);
	bool hetHanTruoc552023();
};
