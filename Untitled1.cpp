#include<iostream>

using namespace std;

struct Node {
	
	int data;
        int position;
	Node* next;

	// Constructor
	Node(int data, int position, Node* next = NULL) {
		this->data = data;
		this->position = position;
		this->next = next;
	}
};

class LinkedList{
	
public:
	int size;
	
	// Constructor
	LinkedList() {
		size = 0;
	}
	
	void addNode(struct Node* prev_node, int data, int position){
		    Node* new_node = new Node(data,position);
  
    		new_node->next = prev_node->next;  
		
    		prev_node->next = new_node; 
	}
	
	void deleteNode(struct Node* head, int pos, int max_pos) {
		if (pos > max_pos || pos < 0) {
			cout << "Invalid position" << endl;
			return;
		}
		else if (pos == 0) {
			Node* temp = head;
			head = head->next;
			
			delete temp;
		} else {
			Node* p = head;
			while (p->next->next->position!=pos+1 && p->next != NULL) {
				p = p->next;
			}
			Node* temp = p->next;
			p->next = temp->next;
			
			delete temp;
		}
	}
	
	//void changeNodePos(int pos){
		
	//}
	
	void print(struct Node* node){
		while(node!=NULL){
			cout << node->data << " ";
			node = node->next;
		}
	}
};

int main(){
    int num_input;
    cin >> num_input;
    string input_operation;
    LinkedList list;
    struct Node* head = NULL;
    struct Node* node;
    int x,p,max_pos = 0;
    for(int i=0;i<num_input;i++){
        cin >> input_operation;
        if(input_operation=="insert"){
        	cin >> p >> x;
        	if(max_pos<p){
        		max_pos = p;
        	}
			if(head==NULL){
				head = new Node(x,p);
				node = head;
			}
        	else{
				list.addNode(node,x,p);
				node = node->next;
			}
        }
        else{
        	cin >> p;
        	list.deleteNode(head,p,max_pos);
        	//list.changeNodePos(p);
        }
    }
    list.print(head);
}
