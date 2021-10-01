#include <iostream>
#include <conio.h>
using namespace std;
#define COUNT 10

struct Node
{
	int info;
	Node *left, *right;
};
Node* root; // root là nốt gốc của cây

void init(); // Khởi tạo cây rỗng
void duyetLNR(Node*p); // Duyệt theo Left - Node - Right
void duyetNLR(Node*p); // Duyệt theo Node - Left - Right
void duyetLRN(Node*p); // Duyệt theo Left - Right - Node
Node *Search(Node* p, int x); // Tìm kiếm
int insert(Node*&p, int x); // Thêm phần tử vào cây
void SearchStandFor(Node*&p, Node*&q); // Hàm hỗ trợ hàm Delete
int Delete(Node*&T, int x); // Xóa phần tử trong cây
void Process_Tree(Node *p, int space); // Xuất cây 
int countNode(Node *p); // Đếm số Node trong cây
int timMax(Node *p); // Tìm GTLN trong cây
void duyetLNR_No(Node *p);  // Duyệt Left - Node - Right không đệ quy

int main()
{
	int chon;
	bool input = false;
	do {
		system("cls");
		cout << "1. Khoi tao cay rong." << endl;
		cout << "2. Duyen cay theo Left - Node - Right." << endl;
		cout << "3. Duyet cay theo Node - Left - Right." << endl;
		cout << "4. Duyet cay theo Left - Right - Node." << endl;
		cout << "5. Tim kiem." << endl;
		cout << "6. Them phan tu vao cay." << endl;
		cout << "7. Xoa phan tu khoi cay." << endl;
		cout << "8. Xuat cay." << endl;
		cout << "9. Dem so Node trong cay." << endl;
		cout << "10. Tim gia tri lon nhat trong cay." << endl;
		cout << "11. Duyet khong de quy." << endl;
		cout << "12. Thoat." << endl;
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			init();
			cout << "Khoi tao cay rong thanh cong!!!" << endl;
			input = true;
			break;
		case 2:
			if (input)
			{
				cout << "Cay sau khi duyet theo Left - Node - Right: ";
				duyetLNR(root);
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 3:
			if (input)
			{
				cout << "Cay sau khi duyet theo Node - Left - Right: ";
				duyetNLR(root);
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 4:
			if (input)
			{
				cout << "Cay sau khi duyet theo Left - Right - Node: ";
				duyetLRN(root);
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 5:
			if (input)
			{
				int x;
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				if (Search(root, x) != NULL)
					cout << x << " co ton tai trong cay." << endl;
				else
					cout << x << " khong ton tai trong cay." << endl;
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 6:
			if (input)
			{
				int x;
				cout << "Nhap gia tri can them: ";
				cin >> x;
				if (insert(root, x))
					cout << "Da them " << x << " vao cay thanh cong." << endl;
				else
					cout << x << " da ton tai trong cay roi." << endl;
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 7:
			if (input)
			{
				int x;
				cout << "Nhap gia tri can xoa: ";
				cin >> x;
				if (Delete(root, x))
					cout << "Da xoa " << x << " thanh cong." << endl;
				else
					cout << x << " khong ton tai trong cay de xoa. " << endl;
			} 
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 8:
			if (input)
			{
				cout << "Cay nhi phan nhu sau: ";
				Process_Tree(root, 0);
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 9:
			if (input)
			{
				cout << "Cay nhi phan dang co " << countNode(root) << " Node." << endl;
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 10:
			if (input)
			{
				cout << "Gia tri lon nhat trong cay la: " << timMax(root) << endl;
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		case 11:
			if (input)
			{
				cout << "Duyet khong de quy: " << endl;
				duyetLNR_No(root);
			}
			else
				cout << "Vui long khoi tao cay rong truoc." << endl;
			break;
		default:
			cout << "Ban chon thoat. Bye bye ^^." << endl;
		}
		_getch();
	} while (chon >= 1 && chon <= 11);
	return 0;
}

void init() // Khởi tạo cây rỗng
{
	root = NULL;
}

void duyetLNR(Node*p) // Duyệt theo Left - Node - Right
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}

void duyetNLR(Node*p) // Duyệt theo Node - Left - Right
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetLNR(p->right);
	}
}

void duyetLRN(Node*p) // Duyệt theo Left - Right - Node
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}

Node *Search(Node*p, int x) // Tìm kiếm
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x < p->info)
				return Search(p->left, x);
			else
				return Search(p->right, x);
	}
	return NULL;
}

int insert(Node*&p, int x) // Thêm phần tử vào cây
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return 0;
		else
			if (x < p->info)
				return insert(p->left, x);
			else
				return insert(p->right, x);
	}
}

void SearchStandFor(Node*&p, Node*&q) // Hàm hỗ trợ hàm Delete
{
	if (q->left == NULL)
	{
		p->info == q->info;
		p = q;
		q = q->right;
	}
	else
		SearchStandFor(p, q->left);
}

int Delete(Node*&T, int x) // Xóa phần tử trong cây
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else
				SearchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x) 
		return Delete(T->right, x);
	if (T->info > x) 
		return Delete(T->left, x);
}

void Process_Tree(Node *p, int space) // Xuất cây
{
	if (p == NULL)
		return;
	space += COUNT;
	Process_Tree(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	Process_Tree(p->left, space);

}

int countNode(Node *p) // Đếm số Node trong cây
{
	if (p != NULL)
		if (p->left == NULL && p->right == NULL) // Là Node lá
			return 1; // Có 1 Node
		else
			return 1 + countNode(p->left) + countNode(p->right);
	return 0; // Không có Node nào
}

int timMax(Node *p) // Tìm GTLN trong cây
{
	if (p->right != NULL)
		return timMax(p->right);
	else
		return p->info;
}

// Duyệt không đệ quy
struct NodeS
{
	int info;
	NodeS *link;
};

NodeS *sp;

void init_No()
{
	sp == NULL;
}

int isEmpty_No()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void Push_No(int x)
{
	NodeS *p = new NodeS;
	p->info = x;
	p->link = sp;
	sp = p;
}

void Pop_No(int &x)
{
	if (sp != NULL)
	{
		NodeS *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
	}
}

void duyetLNR_No(Node *p) // Duyệt Left - Node - Right không đệ quy
{
	init_No();
	Node * current = p;
	while (current != NULL || isEmpty_No() == false)
	{
		while (current != NULL)
		{
			Push_No(current->info);
			current = current->left;
		}
		int x;
		Pop_No(x);
		current = Search(root, x);
		cout << x << " ";
		current = current->right;
	}
}
