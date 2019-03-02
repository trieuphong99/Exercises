#include<iostream>

using namespace std;

struct Node {
	
	int data;
	Node* next;

	// Constructor
	Node(int data = 0, Node* next = NULL) {
		this->data = data;
		this->next = next;
	}
};

class LinkedList{
	Node* head;
	
public:	
	int size;
	
	// Constructor
	LinkedList() {
		head = NULL;
		size = 0;
	}
	
	void addNode(int data){
		Node* newNode = new Node(data);
		if (head == NULL) 
			head = newNode;
		else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = new Node(data);
		}
	}
	
	void deleteNode(int pos) {
		if (pos > size - 1 || pos < 0) {
			cout << "Invalid position" << endl;
			return;
		}
		else if (pos == 0) {
			Node* temp = head;
			head = head->next;
			
			delete temp;
		} else {
			int i = 1;
			Node* p = head;
			while (i < pos && p->next != NULL) {
				p = p->next;
				i++;
			}
			Node* temp = p->next;
			p->next = temp->next;
			
			delete temp;
		}
	}
	
	void changeNodePos(int pos){
		
	}
};

int main(){
    int num_input;
    cin >> num_input;
    string input_operation;
    LinkedList list;
    int p,x;
    for(int i=0;i<num_input;i++){
        cin >> input_operation;
        if(input_operation=="insert"){
        	cin >> p >> x;
            list.addNode(x);
        }
        else{
        	cin >> p;
        	list.deleteNode(p);
        	list.changeNodePos(p);
        }
	}
}
