#include<iostream>



using namespace std;
struct node {
	int x;
	int i = 0;
	struct node *next;
	struct node *prev;

};
class Linked_list {
	struct node *head, *tail;
public:
	Linked_list() {
		head = tail = NULL;
		/*head->next->prev = NULL;
		tail->prev->next = NULL;*/
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
			head->i = tail->i = 0;
		}
		else {
			if (head->next == NULL)
			{
				if (tail->prev == NULL) {
					head->prev = temp;
					head = temp;
					head->i = 1;
				}

				else {
					temp->next = head;
					head = temp;
					head->i = 2;
				}
			}
			else {
				temp->next = head;
				(head->next)->prev = head;
				temp->i = temp->next->i;
				temp->i++;
				head = temp;
			//	int y = head->next->i;
			//	head->i = y+1;
			}
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
				//cout << temp->i << "\t";
				temp = temp->prev;
			}
			cout << head->x;
			//cout << head->i;
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
		temp->x = x;
		temp->next = NULL;
		temp->prev = NULL;

		if (place == head->i) {
			this->insert(x);
		}
		else if (place == 0) {
			(tail->prev)->next = tail;
			temp->prev = tail;
			tail = temp;
			struct node *counter = new node;
			counter = tail->prev;
			while (counter != NULL)
			{
				counter->i++;
				counter = counter->prev;
			}
			head->i++;
		}
		else if ((head->i) - 1 == place) {
			head->next->prev = temp;
			temp->i = head->i;
			head->i++;
			temp->next = head ->next;
			head->next = temp;
		}
		else if (place == 1) {
			tail->prev->next = temp;
			temp->prev = tail->prev;
			tail->prev = temp;
			temp->i = 1;
			struct node *counter = new node;
			counter = temp->prev;
			while (counter != NULL)
			{
				counter->i++;
				counter = counter->prev;
			}
			head->i++;

		}

		else {
			struct node *curr = new node;
			curr = head->next;
			while (curr != NULL)
			{
				if (curr->i == place)
				{
					temp->i = curr->i;
					(curr->next)->prev = temp;
					temp->next = curr->next;
					curr->next = temp;
					temp->prev = curr;
					

					while (curr != NULL)
					{
						curr->i++;
						curr = curr->prev;
					}
					head->i++;
					break;
				}
				curr = curr->next;
			}
		}




	};
	

	void delete_row() {
		struct node *temp = new node;
		struct node *sort = new node;
		temp = tail;
		if (head != NULL) {
			free(head);
			while (temp != NULL)
			{
				sort = temp->prev;
				free(temp);
				temp = sort;
			}
			free(head);
		}
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
			My_Array[row - 1].insert_specfic(x, place - 1);
		}

			break;
		}
		case 4:

		case 5:
			exit(-1);
		default: {
			cout << "Error In Your Input...";
			system("pause");
			break;
		}
		}
	}







	
		/*for (int i = 0; i < 5; i++) {
		cout << My_Array[i].search(120);
	}*/
	cout << endl;


	
	
	//My_Array[0].insert_specfic(4,5-1);
	//My_Array[0].insert_specfic(4, 6 - 1);
	//My_Array[0].insert_specfic(4, 7 - 1);
	//My_Array[0].insert_specfic(4, 8 - 1);
	//My_Array[0].insert_specfic(6, 9 -2);

	//My_Array[0].insert_specfic(3, 0);
	//My_Array[0].insert_specfic(3, 0);
	//My_Array[0].insert_specfic(3, 0);

 //	My_Array[0].insert_specfic(7, 2-1);
	//My_Array[0].insert_specfic(7, 2 - 1);
	//My_Array[0].insert_specfic(7, 2 - 1);

	//My_Array[0].insert_specfic(8, 5);
	//My_Array[0].insert_specfic(9, 5);

	

	system("pause");
	return 0;
}