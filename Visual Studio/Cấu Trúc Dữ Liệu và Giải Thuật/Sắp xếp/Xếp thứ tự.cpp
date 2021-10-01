#include <iostream>
#include <conio.h>
#define MAX 100
using namespace std;

void Input(int a[], int n); // Hàm nhập mảng
void Output(int a[], int n); // Hàm xuất mảng
void Swap(int &a, int &b); // Hảng hoán đổi
void Sort_Swap_Tang(int a[], int n); // Hàm sắp xếp theo thứ tự tăng dần bằng SELECTION SORT - Độ phức tạp: O(n2)
void Sort_Swap_Giam(int a[], int n); // Hàm sắp xếp theo thứ tự giảm dần bằng SELECTION SORT - Độ phức tạp: O(n2)
void Sort_Insertion_Tang(int a[], int n); // Hàm sắp xếp theo thứ tự tăng dần bằng INSERTION - Độ phức tạp: O(n2)
void Sort_Insertion_Giam(int a[], int n); // Hàm sắp xếp theo thứ tự giảm dần bằng INSERTION - Độ phức tạp: O(n2)
void Sort_Bubble_Tang(int a[], int n); // Hàm sắp xếp theo thứ tự tăng dần bằng BUBBLE - Độ phức tạp: O(n2)
void Sort_Bubble_Giam(int a[], int n); // Hàm sắp xếp theo thứ tự giảm dần bằng BUBBLE - Độ phức tạp: O(n2)
void Sort_Interchange_Tang(int a[], int n); // Hàm sắp xếp theo thứ tự tăng dần bằng INTERCHANGE - Độ phức tạp: O(n2)
void Sort_Interchange_Giam(int a[], int n); // Hàm sắp xếp theo thứ tự giảm dần bằng INTERCHANGE - Độ phức tạp: O(n2)
void Merge_Sort(int a[], int left, int right); 
void Merge(int a, int left, int right, int middle); 
void Quick_Sort(int a[], int left, int right); // Sắp xếp theo bằng Quick Sort - Độ phức tạp: O(nlog(n))
void Heap_Sort(int a[], int); // Sắp xếp theo bằng Heap Sort - Độ phức tạp: O(nlog(n))
void Shift(int a[], int i, int n); // Hỗ trợ hàm Heap Sort
int Search(int a[], int n, int x); // Tìm kiếm tuần tự
int Binary_Search(int a[], int n, int x); // TÌm kiếm nhị phân - Độ phức tạp: O(log(n))

int main()
{
	int chon, n, a[MAX];
	bool input = false;
	do {
		system("cls");
		cout << "MENU" << endl;
		cout << "1.  Nhap mang." << endl;
		cout << "2.  Xuat mang." << endl;
		cout << "3.  Sap xep tang dan bang SELECTION SORT." << endl;
		cout << "4.  Sap xep giam dan bang SELECTION SORT." << endl;
		cout << "5.  Sap xep tang dan bang INTERCHANGE SORT." << endl;
		cout << "6.  Sap xep giam dan bang INTERCHANGE SORT." << endl;
		cout << "7.  Sap xep tang dan bang BUBBLE SORT." << endl;
		cout << "8.  Sap xep giam dan bang BUBBLE SORT." << endl;
		cout << "9.  Sap xep tang dan bang INTERCHANGE SORT." << endl;
		cout << "10. Sap xep giam dan bang INTERCHANGE SORT." << endl;
		cout << "11. Sap xep tang dan bang MERGE SORT. " << endl;
		cout << "12. Sap xep bang QUICK SORT." << endl;
		cout << "13. Sap xep bang HEAP SORT." << endl;
		cout << "14. Tim kiem tuan tu." << endl;
		cout << "15. Tim kiem bang cay nhi phan. " << endl;
		cout << "16. Thoat." << endl;
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "Nhap so luong phan tu: ";
			cin >> n;
			Input(a, n);
			input = true;
			break;
		case 2:
			if (input)
			{
				cout << "Mang dang luu tru cac phan tu: " << endl;
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 3:
			if (input)
			{
				cout << "Mang sap xep tang dan bang HOAN DOI: " << endl;
				Sort_Swap_Tang(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 4:
			if (input)
			{
				cout << "Mang sap xep giam dan bang HOAN DOI: " << endl;
				Sort_Swap_Giam(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 5:
			if (input)
			{
				cout << "Mang sap xep tang dan bang CHEN TRUC TIEP: " << endl;
				Sort_Insertion_Tang(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 6:
			if (input)
			{
				cout << "Mang sap xep giam dan bang CHEN TRUC TIEP: " << endl;
				Sort_Insertion_Giam(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 7:
			if (input)
			{
				cout << "Mang sap xep tang dan bang NOI BOT: " << endl;
				Sort_Bubble_Tang(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 8:
			if (input)
			{
				cout << "Mang sap xep giam dan bang NOI BOT: " << endl;
				Sort_Bubble_Giam(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 9:
			if (input)
			{
				cout << "Mang sap xep tang dan bang DOI CHO TRUC TIEP: " << endl;
				Sort_Interchange_Tang(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 10:
			if (input)
			{
				cout << "Mang sap xep giam dan bang DOI CHO TRUC TIEP: " << endl;
				Sort_Interchange_Giam(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		/* case 11:
			if (input)
			{
				cout << "Mang sap xep tang dan bang MERGE SORT: " << endl;
				Merge_Sort(a, 0, n - 1);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break; */
		case 12:
			if (input)
			{
				cout << "Mang sap xep tang dan bang QUICK SORT: " << endl;
				Quick_Sort(a, 0, n - 1);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 13:
			if (input)
			{
				cout << "Mang sap xep tang dan bang HEAP SORT: " << endl;
				Heap_Sort(a, n);
				Output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 14:
			if (input)
			{
				int x;
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				if (Search(a, n, x) == -1)
					cout << x << " khong ton tai trong mang." << endl;
				else
					cout << x << " co ton tai trong mang." << endl;
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		case 15:
			if (input)
			{
				int x;
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				if (Binary_Search(a, n, x) == -1)
					cout << x << " khong ton tai trong mang." << endl;
				else
					cout << x << " co ton tai trong mang." << endl;
			}
			else
				cout << "Vui long nhap mang truoc." << endl;
			break;
		default:
			cout << "Ban chon thoat. Bye bye ^^." << endl;
		}
		_getch();
	} while (chon >= 1 && chon <= 15);
	return 0;
}


void Input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "a[" << i << "]: " << a[i] << endl;
}

void Swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void Sort_Swap_Tang(int a[], int n)
{
	int min, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
}

void Sort_Swap_Giam(int a[], int n)
{
	int max, i, j;
	for (i = 0; i < n - 1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
			if (a[max] < a[j])
				max = j;
		swap(a[max], a[i]);
	}
}

void Sort_Insertion_Tang(int a[], int n)
{
	int x, i, j;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j >= 0 && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

void Sort_Insertion_Giam(int a[], int n)
{
	int x, i, j;
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		x = a[i];
		while (j >= 0 && x > a[j])
		{
			j--;
			a[j + 1] = a[j];
		}
		a[j + 1] = x;

	}
}

void Sort_Bubble_Tang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

void Sort_Bubble_Giam(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] > a[j - 1])
				swap(a[j - 1], a[j]);
}

void Sort_Interchange_Tang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}

void Sort_Interchange_Giam(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[i])
				swap(a[i], a[j]);
}

/* void Merge_Sort(int a[], int left, int right)
{
	if(left < right)
	{
		int middle = left + (right - left) / 2;
		Merge_Sort(a, left, middle);
		Merge_Sort(a, middle + 1, right);
		Merge(a, left, middle, right);
	}
}

void Merge(int a, int left, int right, int middle) 
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int L[n1];
	int R[n2];
	for (i = 0; i < n1; i++)
		L[i] = a[left + i];
	for (j = 0; j < n2; j++)
		R[j] = a[middle + 1 + j];
	i = 0;
	j = 0;
	k = left;
	while(i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++ ;
		k++;
	}
} */

int Search(int a[], int n, int x) // Tìm kiếm tuần tự
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i; 
	return -1; 
	
}

int Binary_Search(int a[], int n, int x) // Tìm kiếm nhị phân
{
	int left = 0, right = n - 1, middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (a[middle] == x)
			return middle;
		if (x > a[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1; // Không tìm thấy x
}

void Quick_Sort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		Quick_Sort(a, left, j);
	if (i < right)
		Quick_Sort(a, i, right);
}

void Heap_Sort(int a[], int n) // Sắp xếp theo bằng Heap Sort 
// Tính chất Heap Sort: Phần tử đang xét a[i] phải là max của a[2*i+1] và a[2*i+2] 
{
	int i = n / 2;
	while (i >= 0) // Tạo Heap ban đầu
	{
		Shift(a, i, n - 1);
		i--;
	}
	int right = n - 1; // right là vị trí cuối cùng Heap xét
	while (right > 0)
	{
		if (a[0] > a[right])
		{
			swap(a[0], a[right]); // Hoán đổi a[0] với phần tử Heap đang xét
			right--; // Giới hạn lại phần tử đang xét
		}
		if (right > 0) // Kiểm tra dãy đang xét có nhiều hơn 1 phần tử
			Shift(a, 0, right); // Tạo Heap lại tại vị trí 0
	}
}

void Shift(int a[], int i, int n) // Hỗ trợ hàm Heap Sort
{
	int j = 2 * i + 1;
	if (j >= n) // Nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình
		return;
	if (j + 1 < n) // Nếu tồn tại vị trí j + 1 trong danh sách đang xét thoát khỏi chương trình
		if (a[j] < a[j + 1]) // Nếu vị trí không tồn tại phần tử a[j] < a[j+1]
			j++;
	if (a[i] >= a[j])
		return;
	else // *Xét lại tính lan truyền của vị trí a[1]
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		Shift(a, j, n);
	}
}