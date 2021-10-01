// Hash Table - Kết nối trực tiếp
#include <iostream>
#include <conio.h>
using namespace std;
#define M 11

struct Node
{
	int key;
	Node * next;
};
Node * z;
Node * heads[M];

void init(); // Khởi tạo Hash Table
int hashK(int k); // Trả về cho người dùng biết khóa k thuộc heads thứ mấy
void insert(int k); // Thêm phần tử vào Hash Table
Node *search(int k); // Tìm kiếm phần tử trong Hash Table
void outputBucket(Node *b); // Xuất các giá trị của 1 địa chỉ bất kì
void outputHashTable(); // Xuất toàn bộ Hash Table
void deleteBucket(Node *&b); // Xóa các giá trị của 1 địa chỉ bất kì
void deleteHashTable(); // Xóa toàn bộ Hash Table
void deleteKey(int k); // Xóa 1 giá trị bất kì trong Hash Table
void DeleteAfter(Node *&k); // Xóa giá trị đầu trong Hash Table
void DeleteHead(Node *&k); // Xóa giá trị trị trong Hash Table

int main()
{
	int chon, k;
	bool input = false;
	bool del = false;
	do
	{
		system("cls");
		cout << "MENU." << endl;
		cout << "1. Khoi tao." << endl;
		cout << "2. Them 1 phan tu vao Hash Table." << endl;
		cout << "3. Tim kiem 1 phan tu trong Hash Table." << endl;
		cout << "4. Xuat 1 Bucket." << endl;
		cout << "5. Xuat toan bo Hash Table." << endl;
		cout << "6. Xoa toan bo 1 Bucket." << endl;
		cout << "7. Xoa toan bo Hash Table." << endl;
		cout << "8. Xoa 1 gia tri bat ki." << endl;
		cout << "9. Thoat." << endl;
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			cout << "Khoi tao Hash Table thanh cong." << endl;
			input = true;
			break;
		case 2:
			if (input)
			{
				cout << "Nhap gia tri can them: ";
				cin >> k;
				insert(k);
				cout << "Them vao thanh cong. Chon xuat de xem ket qua." << endl;
			}
			else
				cout << "Vui long khoi tao Hash Table truoc." << endl;
			break;
		case 3:
			if (input)
			{
				cout << "Nhap gia tri can tim: ";
				cin >> k;
				if (search(k) == z)
					cout << "Gia tri can tim khong co trong Hash Table." << endl;
				else
					cout << "Gia tri can tim khong co trong Hash Table." << endl;
			}
			else
				cout << "Vui long khoi tao Hash Table truoc." << endl;
			break;
		case 4:
			if (input)
			{
				do {
					cout << "Ban can xuat cac gia tri trong Bucket thu may: ";
					cin >> k;
					if (k < 0 && k > M - 1)
						cout << "Nhap sai. Nhap lai!" << endl;
				} while (k < 0 && k > M - 1);
				cout << "Cac gia tri cua Bucket thu " << k << " la: ";
				outputBucket(heads[k]);
			}
			else
				cout << "Vui long khoi tao Hash Table truoc." << endl;
			break;
		case 5:
			if (input)
			{
				outputHashTable();
			}
			else
				cout << "Vui long khoi tao Hash Table truoc." << endl;
			break;
		case 6:
			if (input)
			{
				do {
					cout << "Ban can xoa cac gia tri trong Bucket thu may: ";
					cin >> k;
					if (k < 0 && k > M - 1)
						cout << "Nhap sai. Nhap lai!" << endl;
				} while (k < 0 && k > M - 1);
				deleteBucket(heads[k]);
				cout << "Da xoa thanh cong Bucket " << k << endl;
			}
			else
				cout << "Vui long khoi tao Hash Table truoc." << endl;
			break;
		case 7:
			if (input)
			{
				deleteHashTable();
				cout << "Xoa thanh cong Hash Table." << endl;
				del = true;
			}
			else
				cout << "Vui long khoi tao Hash Table truoc." << endl;
			break;
		case 8:
			if (input)
			{
				cout << "Nhap gia tri can xoa: ";
				cin >> k;
				deleteKey(k);
				cout << "Xoa thanh cong. Chon xuat de xem ket qua." << endl;
			}
			else
				cout << "Vui long khoi tao Hash Table truoc." << endl;
			break;
		default:
			if (del)
				cout << "Thoat." << endl;
			else
				cout << "Hash Table chua duoc huy cap phat." << endl;
		}
		_getch();
	} while (chon >= 1 && chon <= 8);
	return 0;
}

void init() // Khởi tạo bảng
{
	z = new Node;
	z->next = z;
	for (int i = 0; i < M; i++)
		heads[i] = z;
}

int hashK(int k) // Trả về cho người dùng biết khóa k thuộc heads thứ mấy
{
	return k % M;
}

void insert(int k) // Thêm phần tử vào bảng
{
	int index = hashK(k);
	Node *t = heads[index];
	Node * x = new Node;
	x->key = k;
	z->key = k;
	if (t->key >= k)
	{
		x->next = t;
		heads[index] = x;
	}
	else
	{
		Node *p = t->next;
		while (p->key < k)
		{
			t = t->next;
			p = t->next;
		}
		t->next = x;
		x->next = p;
	}
}

Node *search(int k) // Tìm kiếm phần tử trong bảng
{
	int index = hashK(k);
	Node *t = heads[index];
	z->key = k;
	while (t->key < k)
		t = t->next;
	if (t->key != k)
		return z; // Không tìm thấy
	return t; // Tìm thấy
}

void outputBucket(Node *b) // Xuất các giá trị của 1 địa chỉ bất kì
{
	Node *t = b;
	while (t != z)
	{
		cout << t->key << " ";
		t = t->next;
	}
}

void outputHashTable() // Xuất toàn bộ Hash Table
{
	for (int i = 0; i < M; i++)
	{
		cout << "head[" << i << "] = ";
		outputBucket(heads[i]);
		cout << endl;
	}
}

void deleteBucket(Node *&b) // Xóa các giá trị của 1 địa chỉ bất kì
{
	Node *t = b;
	while(t != z)
	{
		Node *s = t;
		t = t->next;
		delete s;
	}
	b = z;
}

void deleteHashTable() // Xóa toàn bộ Hash Table
{
	for (int i = 0; i < M; i++)
		deleteBucket(heads[i]);
}

void deleteKey(int k) // Xóa 1 giá trị bất kì trong Hash Table
{
	int index = hashK(k);
	Node *p = heads[index];
	Node *t = p;
	while (p != z && p->key != k)
	{
		t = p; // Lưu lại địa chỉ của phần tử trước đó
		p = p->next;
	}
	if (p == z)
		cout << k << " khong tim thay trong Hash Table." << endl;
	else if (p == heads[index])
		DeleteHead(heads[index]);
	else
		DeleteAfter(t);
}

void DeleteHead(Node *&k)
{
	if (k != z)
	{
		Node *p = k;
		k = k->next;
		delete p;
	}
}

void DeleteAfter(Node *&k)
{
	Node *p = k->next;
	if (p != z)
	{
		k->next = p->next;
		delete p;
	}
}

