#include<iostream>



using namespace std;
const int n = 100;
struct node {
	int x;
	struct node *next;
	struct node *prev;

};
class Linked_list {
	struct node *head, *tail;
public:
	Linked_list() {
		head = tail = NULL;
	}
	void insert(int x) {
		struct node *temp = new node;
		temp->x = x;
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = head;
		}
		else {
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
	}
	void print() {
		struct node *temp = new node;
		temp = tail;
		if (head != NULL) {
			cout << "\nThe linked list is :\t";
			while (temp != NULL)
			{
				cout << temp->x << "\t";
				temp = temp->prev;
			}
			cout << endl;
		}
	}
	int search(int x) {
		struct node *temp = new node;
		temp = head;
		if (tail->x == x)
			return 1;
		while (temp != NULL)
		{
			if (temp->x == x)
				return 1;
			temp = temp->next;
		}
		return 0;
	}
	void insert_specfic(int x, int place) {
		struct node *temp = new node;
		struct node *sorter = new node;
		temp->x = x;
		temp->next = NULL;
		temp->prev = NULL;
		sorter = tail;
		int counter = 1;
		while (true) {
			if (place == 1)
			{
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
				return;
			}
			else if (sorter == head && counter == place)
			{
				this->insert(x);
				return;
			}
				
			else if (counter == place) {
				sorter->next->prev = temp;
				temp->next = sorter->next;
				sorter->next = temp;
				temp->prev = sorter;
				return;
			}
			if (sorter == head)
				return;
			counter++;
			sorter = sorter->prev;
		}
		cout << "Error in index" << endl;
	}
};
int main() {
	Linked_list My_Array[5];
	int x;
	int row;

	int type = 0;
	while (type != 5)
	{
			system("cls");
		//print
		for (int i = 0; i < 5; i++) {
			My_Array[i].print();
		}
		cout << "\n1-First Input.\n2-Add Multi Number To A Specific Row.\n3-Add Elements To A specific Place.\n4-\n5-Colse\n";
		cin >> type;
		switch (type)
		{
		case 1:
		{
			cout << "Enter the length of column" << endl;
			int column;
			cin >> column;

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < column; j++) {
					cout << "Row    " << i << "\t column  " << j << "\t";
					cin >> x;
					My_Array[i].insert(x);
				}
			}
			break;
		}
		case 2:
		{
			cout << "Add Multi Number to A Specefic Row\nRow\t";
			cin >> row;
			cout << "How many Number you want to add \t";
			int multi_num;
			cin >> multi_num;
			for (int i = 0; i < multi_num; i++)
			{
				cout << "The " << i + 1 << " value   ";
				cin >> x;
				My_Array[row - 1].insert(x);
			}
			break;
		}
		case 3:
		{
			int place = 0, edit = 0;
			cout << "How many Edit You want to Add\t";
			cin >> edit;
			for (int j = 0; j < edit; j++) {
				cout << "Select A Row To Add An Element to a Specific place\t";
				cin >> row;
				cout << "Enter the Element\t";
				cin >> x;
				cout << "Enter the place of it\t";
				cin >> place;
						My_Array[row - 1].insert_specfic(x,  place);
			}

			break;
		}
		case 4:

		case 5:
			//			exit(-1);
		default: {
			cout << "Error In Your Input...";
			//			system("pause");
			break;
		}
		}
	}





	My_Array[0].insert_specfic(4, 5);
	My_Array[0].insert_specfic(4, 6);
	My_Array[0].insert_specfic(4, 7);
	My_Array[0].insert_specfic(4, 8);
	My_Array[0].insert_specfic(6, 9);

	My_Array[0].insert_specfic(3, 0);
	My_Array[0].insert_specfic(3, 0);
	My_Array[0].insert_specfic(3, 0);

	My_Array[0].insert_specfic(7, 2);
	My_Array[0].insert_specfic(7, 2);
	My_Array[0].insert_specfic(7, 2);

	My_Array[0].insert_specfic(8, 5);
	My_Array[0].insert_specfic(9, 5);


	/*for (int i = 0; i < 5; i++) {
	cout << My_Array[i].search(120);
	}*/
	cout << endl;








	//	system("pause");
	return 0;
}
