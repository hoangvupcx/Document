#include <iostream>
#include < conio.h>
#define MAX 100
using namespace std;
int rear, front;
int a[MAX];

void init(); // Khởi tạo Queue
int PushTT(int a[], int &rear, int& front, int x); // Thêm phần tử vào Queue bàng PPTT
int PopTT(int a[], int &rear, int& front, int& x); // Lấy phần tử ra khỏi Queue bằng PPTT
int PushV(int a[], int &rear, int& front, int x); // Thêm phần tử vào Queue bàng PPV
int PopV(int a[], int &rear, int& front, int& x); // Lấy phần tử ra khỏi Queue bằng PPV

int main()
{
	int x, chon;
	bool input = false;
	do
	{
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Khoi tao Queue." << endl;
		cout << "2. Them phan tu bang phuong phap tinh tien." << endl;
		cout << "3. Xoa phan tu bang phuong phap tinh tien." << endl;
		cout << "4. Them phan tu bang phuong phap vong." << endl;
		cout << "5. Xoa phan tu bang phuong phap vong." << endl;
		cout << "Thoat." << endl;
		cout << "Ban chon: ";
		cin >> chon; 
		switch(chon)
			{
		case 1:
			init();
			cout << "Khoi tao Queue thanh cong." << endl;
			input = true;
			break;
		case 2:
			if (input)
			{
				cout << "Nhap gia tri can them: " ;
				cin >> x;
				if (PushTT(a, x, rear, front))
					cout << "Da them vao Queue thanh cong. " << endl;
				else
					cout << "Queue da day. Khong the them." << endl;
			}
			else
				cout << "Vui long khoi tao Queue truoc." << endl;
			break;
		case 3:
			if (input)
			{
				if (PopTT(a, rear, x, front))
					cout << "Gia tri vua lay ra khoi Queue la: " << x << endl;
				else
					cout << "Queue dang rong. Khong the lay." << endl;
			}
			else
				cout << "Vui long khoi tao Queue truoc." << endl;
			break;
		case 4:
			if (input)
			{
				cout << "Nhap gia tri can them: " << endl;
				cin >> x;
				if (PushV(a, x, rear, front))
					cout << "Da them vao Queue thanh cong. " << endl;
				else
					cout << "Queue da day. Khong the them." << endl;
			}
			else
				cout << "Vui long khoi tao Queue truoc." << endl;
			break;
		case 5:
			if (input)
			{
				if (PopV(a, rear, x, front))
					cout << "Gia tri vua lay ra khoi Queue la: " << x << endl;
				else
					cout << "Queue dang rong. Khong the lay." << endl;
			}
			else
				cout << "Vui long khoi tao Queue truoc." << endl;
			break;
		default:
			cout << "Ban chon thoat. Bye bye ^^." << endl;
			}
		_getch();
	} while (chon >= 1 && chon <= 5);
	return 0;
}

void init()
{
	rear = -1;
	front = -1;
}

int PushTT(int a[], int &rear, int& front, int x)
{
	if (rear - front == MAX - 1) // Queue đầy
		return 0;
	else
	{
		if (front == -1) // Queue rỗng
			front = 0;
		if (rear == MAX - 1) // Queue tràn
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}

int PopTT(int a[], int &rear, int& front, int& x)
{
	if (front == -1) // Hàng đợi rỗng
		return 0;
	else
	{
		x = a[front++];
		if (front > rear) // Sau khi lấy phần tử, hàng đợi rỗng
		{
			rear = -1;
			front = -1;
		}
		return 1;
	}
}

int PushV(int a[], int &rear, int& front, int x)
{
	if ((rear - front == MAX - 1) || (rear - front == -1)) // Hàng đợi đầy
		return 0;
	else
	{
		if (front == -1) // Hàng đợi rỗng
			front = 0;
		if (rear == MAX - 1) // Hàng đợi tràn
			rear = -1;
		a[++rear] = x;
	}
	return 1;
}

int PopV(int a[], int &rear, int& front, int& x)
{
	if (front == -1) // Hàng đợi rỗng
		return 0;
	else
	{
		x = a[front];
		if (front = rear) // Sau khi lấy ra, hàng đợi rỗng
		{
			rear = -1;
			front = -1;
		}
		else
		{
			front++;
			if (front > MAX - 1)
				front = 0;
		}
		return 1;
	}
}