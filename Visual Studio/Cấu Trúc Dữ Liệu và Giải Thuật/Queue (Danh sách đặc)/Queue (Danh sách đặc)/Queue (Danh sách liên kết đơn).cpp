#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int info;
	Node *link;
};
Node *rear, *front;

void init(); // Khởi tạo Queue rỗng
void Push(int x); // Thêm phần tử vào Queue
int Pop(int &x); // Lấy phần tử ra khỏi Queue
int Empty(); // Kiểm tra Queue rỗng
void DeleteAll(); // Xóa tất cả các phần tử trong Queue


int main()
{
	int x, chon;
	bool input = false;
	do
	{
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Khoi tao Queue." << endl;
		cout << "2. Them 1 phan tu vao hang doi." << endl;
		cout << "3. Lay 1 phan tu trong hang doi." << endl;
		cout << "4. Kiem tra hang doi rong." << endl;
		cout << "5. Xoa toan bo hang doi." << endl;
		cout << "6. Thoat." << endl;
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			cout << "Khoi tao Queue thanh cong. " << endl;
			input = true;
			break;
		case 2:
			if (input)
			{
				cout << "Nhap phan tu can them: ";
				cin >> x;
				Push(x);
				cout << "Da them " << x << " vao hang doi thanh cong.\n";
			}
			else
				cout << "Vui long khoi tao Queue truoc." << endl;
			break;
		case 3:
			if (input)
			{
				if (Pop(x))
					cout << "Gia tri lay ra duoc tu hang doi la " << x << endl;
				else
					cout << "Khong the lay ra duoc tu hang doi.\n";
			}
			else
				cout << "Vui long khoi tao Queue truoc." << endl;
			break;
		case 4:
			if (input)
			{
				if (Empty)
					cout << "Hang doi dang rong.\n";
				else
					cout << "Hang doi dang co phan tu.\n";
			}
			else
				cout << "Vui long khoi tao Queue truoc." << endl;
			break;
		case 5:
			if (input)
			{
				DeleteAll();
			}
			else
				cout << "Hang doi chua khoi tao, nen khong co phan tu de xoa." << endl;
			break;
		default:
			cout << "Ban chon thoat. Bye bye ^^.";
		}
		_getch();
	} while (chon >= 1 && chon <= 5);
	return 0;
}

void init()
{
	rear = NULL;
	front = NULL;
}

void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int Pop(int &x)
{
	if (front == NULL) // Hàng đợi rỗng
		return 0;
	else
	{
		Node* p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
}

int Empty()
{
	if (front == NULL)
		return 1;
	return 0;
}

void DeleteAll()
{
	if (front != NULL) // Hàng đợi rỗng
	{
		while (front != NULL)
		{
			Node *p = front;
			front = front->link;
			delete p;
		}
		cout << "Xoa hang doi thanh cong." << endl;
	}
}