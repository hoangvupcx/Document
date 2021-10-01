﻿#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
Node* first;

void init(); // Khởi tạo danh sách rỗng
void Process_List(); // Duyệt chương trình
void Process_List_Chan(); // Xuất các Node có chữ số chẵn
Node* Search(int x); // Tìm kiếm
void Insearch_First(int x); // Thêm đầu
void Insearch_Last(int x); // Thêm cuối
int Delete_First(); // Xóa đầu
int Delete_Last(); // Xóa cuối

int main()
{
	int chon;
	int x;
	bool input = false;
	do
	{
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Khoi tao danh sach." << endl;
		cout << "2. Xuat danh sach." << endl;
		cout << "3. Xuat cac Node co chu so chan." << endl;
		cout << "4. Tim kiem." << endl;
		cout << "5. Them vao dau danh sach." << endl;
		cout << "6 . Them vao cuoi danh sach." << endl;
		cout << "7. Xoa dau danh sach." << endl;
		cout << "8. Xoa cuoi danh sach." << endl;
		cout << "9. Thoat." << endl;
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			cout << "Khoi tao danh sach thanh cong. " << endl;
			input = true;
			break;
		case 2:
			if (input)
			{
				cout << "Danh sach dang luu tru la: " << endl;
				Process_List();
			}
			else
				cout << "Vui long khoi tao danh sach truoc." << endl;
			break;
		case 3:
			if (input)
			{
				cout << "Danh sach dang luu tru cac Node chan la: " << endl;
				Process_List_Chan();
			}
			else
				cout << "Vui long khoi tao danh sach truoc." << endl;
			break;
		case 4:
			if (input)
			{
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				if (Search(x) != NULL)
					cout << x << " co trong danh sach." << endl;
				else
					cout << x << " khong co trong danh sach." << endl;
			}
			else
				cout << "Vui long khoi tao danh sach truoc." << endl;
			break;
		case 5:
			if (input)
			{
				cout << "Nhap gia tri can them: ";
				cin >> x;
				Insearch_First(x);
				cout << "Them vao dau thanh cong. Chon xuat mang de xem ket qua." << endl;
			}
			else
				cout << "Vui long khoi tao danh sach truoc." << endl;
			break;
		case 6:
			if (input)
			{
				cout << "Nhap gia tri can them: ";
				cin >> x;
				Insearch_Last(x);
				cout << "Them vao dau thanh cong. Chon xuat mang de xem ket qua." << endl;
			}
			else
				cout << "Vui long khoi tao danh sach truoc." << endl;
			break;
		case 7:
			if (input)
			{
				if (Delete_First())
					cout << "Xoa thanh cong. Chon xuat danh sach de xem ket qua." << endl;
				else
					cout << "Xoa khong thanh cong." << endl;
			}
			else
				cout << "Vui long khoi tao danh sach truoc." << endl;
			break;
		case 8:
			if (input)
			{
				if (Delete_Last())
					cout << "Xoa thanh cong.Chon xuat danh sach de xem ket qua." << endl;
				else
					cout << "Xoa khong thanh cong." << endl;
			}
			else
				cout << "Vui long khoi tao danh sach truoc." << endl;
			break;
		default:
			cout << "Ban chon thoat. Bye bye ^^.";
			break;
		}
		_getch();
	} while (chon >= 1 && chon <= 8);
	return 0;
}

void init()
{
	first = NULL;
}

void Insearch_First(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

void Insearch_Last(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node* q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

void Process_List()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}

void Process_List_Chan()
{
	Node* p = first;
	for (p = first; p != NULL; p = p->link)
	{
		if (p->info % 2 == 0)
			cout << p->info << endl;
	}
}

Node* Search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
		p = p->link;
	return p;
}

int Delete_First()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

int Delete_Last()
{
	if (first != NULL)
	{
		Node* p, *q;
		p = first;
		q = NULL;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}