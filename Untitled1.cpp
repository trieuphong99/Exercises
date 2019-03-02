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
	
	void addNode(struct Node* prev_node, int data){
		Node* new_node = new Node(data);
  
    		new_node->data  = new_data; 
  
    		new_node->next = prev_node->next;  
		
    		prev_node->next = new_node; 
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
	struct Node* node;
    for(int i=0;i<num_input;i++){
        cin >> input_operation;
        if(input_operation=="insert"){
        	cin >> p >> x;
		if(list.head==NULL){
			list.head = Node(x);
			node = list.head;
		}
            	else{
			list.addNode(node,x);
			node = node->next;
		}
        }
        else{
        	cin >> p;
        	list.deleteNode(p);
        	list.changeNodePos(p);
        }
	}
}
