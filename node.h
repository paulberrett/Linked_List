#include <string>
using namespace std; //Checks to see if anything that doesn't state the class comes from a namespace std

class node{
private:
	string value;
	node* last;
	node* next;

public:
	node (); 				//This constructor allows me to initiate values so I can easily do while loops
	void setValue(string);	//This allows me to set the value of the node
	string getValue();		//This allows me to return the value to my main program
	void setHead(node*);	//This allows me to point the node back
	node* getHead();		//This returns a pointer of the node before this node
	void setTail(node*);	//This allows me to point the node forward
	node* getTail();		//This returns a pointer of the noce after this node

};

node::node() {
	last = 0;
	next = 0;
	value = "";
}

void node::setValue(string current_value){
	value = current_value;
	return;
}

string node::getValue(){
	return value;
}

void node::setHead(node* last_node){
	last = last_node;
	return;
}

node* node::getHead(){
	return last;
}

void node::setTail(node* next_node){
	next = next_node;
	return;
}

node* node::getTail(){
	return next;
}