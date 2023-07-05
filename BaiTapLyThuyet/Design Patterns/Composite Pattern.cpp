#include <iostream>
#include <vector>
using namespace std;

//Lớp cha, ITem có thể là Folder, cũng có thể là File
//Nếu ITem là Folder thì Item có thể chứa Folder khác hoặc File
//Nếu ITem là File thì không thể chứa Folder hoặc File khác

class CItem {
protected:
public:
	virtual void add(CItem*) {};
	virtual float getSize() { return 1; };

};

//Lớp con Folder
class CFolder : public CItem {
private:
	vector <CItem*> list;
public:
	void add(CItem* item) {
		list.push_back(item);
	}
	float getSize() {
		float total = 0;
		for (auto x : list)
			total += x->getSize();
		return total;
	}
};

//Lớp con CFile
class CFile : public CItem {
private:
	float size;
public:
	CFile(float k) {
		size = k;
	}
	float getSize() {
		return size;
	}
};

int main() {
	CItem* folder1 = new CFolder;
	CItem* folder2 = new CFolder;
	CItem* file1 = new CFile(10);

	folder1->add(file1);
	folder1->add(folder2);
	folder2->add(file1);
	
	CItem* file2 = new CFile(20);
	folder2->add(file2);

	cout << "Ket qua 1: " << folder1->getSize() << endl; //40
	//------------------------------

	CItem* file3 = new CFile(10);

	folder1->add(file3);

	cout << "Ket qua 2a: " << folder1->getSize() << endl; //50
	cout << "Ket qua 2b: " << folder2->getSize() << endl; //30
	//-------------------------------

	file2 = new CFile(30);
	folder1->add(file2);
	folder1->add(file1);
	folder2->add(file3);

	cout << "Ket qua 3a: " << folder1->getSize() << endl; //100
	cout << "Ket qua 3b: " << folder2->getSize() << endl; //40
	//-------------------------------

	CItem* file4 = new CFile(50);

	folder2->add(file4);
	file4 = new CFile(40);
	folder1->add(file4);
	folder1->add(file2);
	folder2->add(folder1); //Dòng này lỗi, vì thêm folder1 vào folder2 thì folder2 lại được thêm vào folder1
							//=> Vòng lặp vô tận
	

	cout << "Ket qua 4a: " << folder1->getSize() << endl; //420
	cout << "Ket qua 4b: " << folder2->getSize() << endl; //260
	return 0;
}