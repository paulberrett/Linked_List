/* 
	Paul Berrett Linked List Program
	6/5/2015
*/

#include "linked.h"

//This funciton adds a new node and does the nessisary conections for a double linked list.
void insertNode(){
	cout << "Enter the value of the node you wish to insert and hit enter:\n";
	getline(cin, input);			//obtain the input from the terminal
	if(first_time){					//Run this on the first time they try to add a node
		root = new node;			//provides the first node which root points at
		root->setValue(input);		//give the root its initial value
		first_time = false;			//Indicates that it is no longer the first time
		current = root;				//Sets the value of the head to the root node
		totalNodeCount++;			//Keeps track of how many nodes there are
	}else {
		bool duplicate=false;		//I added this in order to make things easier for me, duplicates make the other functions more difficult
		node* find = root;			//start search at the root
		while(find){
			if(find->getValue()==input)	//This checks to see if you tried to add a duplicate and sets a boolean to see what to do next
				duplicate = true;
			find = find->getTail();
		}
		if(!duplicate){
			node* temp;
			temp = new node;			//The pointer temp points to a new node
			temp->setValue(input);		//Give this node a value from the input provided
			temp->setHead(current);		//Have the head of the new node point at the previous node
			current->setTail(temp);		//Have the tail of the previous node point to the new node
			current = temp;				//Update the current node I'm working on to the new node added
			totalNodeCount++;			//Keeps track of how many nodes there are
			cout << "You inserted \"" << input << "\" to the node list\n";
		}else{
			cout << "you alread have a node with the value \"" << input << "\"\n";
		}
	}
}

void deleteNode(){
	if(first_time){	//If you haven't entered anything I don't let you try to delete
		cout << "\nYou must first enter a node to be able to delete it\n";
	}else {
		cout << "Enter the value of the node you wish to delete:\n";
		getline(cin, input); 				//This gets the input from the terminal
		node* temp = root; 					//Search from the first node
		bool deleted=false;
		while(temp){
			if(temp->getValue() == input){	//This is used to indicate that you found a match to delete
				totalNodeCount--;
				cout << "You deleted \"" << input << "\" from the node list\n";
				if(temp->getHead()){		//This is if you don't delete the root
					temp->getHead()->setTail(temp->getTail());
				}else {						//if you do delete the root I need to reassign it to the next node
					root = temp->getTail();
				}
				if(temp->getTail()){		//this is if you don't delete the last node added
					temp->getTail()->setHead(temp->getHead());
				}else {						//if you do delete the last node added I need to go back a node with current
					current = temp->getHead();
				}
				if(!totalNodeCount)
					first_time = true;
				deleted = true;
				break;
			}
			temp = temp->getTail();			//this assignes temp to the next node in the list
			
		}
		if(!deleted)
			cout << "A node with the value \"" << input << "\" could not be found\n";
	}
}

void printList(){
	if(first_time){
		cout << "You have to enter at least one node to print something\n";
	}else {
		cout << "The nodes in the list are: \n";
		node* temp = root;
		while(temp){//The point of this code is to iterate through all the nodes and print their values
			cout << "\"" << temp->getValue() <<"\"\n";
			temp = temp->getTail();
		}
	}
	return;
}

void findNode(){
	if(first_time){
		cout << "You can't search for what isn't there, try inserting a node\n";
	}else {
		cout << "Enter the value of the node you wish to find:\n";
		getline(cin, input);
		node* temp = root;
		bool found = false;
		while(temp){ //Just like the print I search through this function and see if the value inputed is there
			if(input == temp->getValue()){
				cout << "There is a node with the value \"" << input << "\"\n";
				found = true;
				break;
			}
			temp = temp->getTail();
		}
		if(!found)
			cout << "There isn't a node with the value \"" << input << "\"\n";
	}
}

void deleteList(){
	if(first_time){
		cout << "You have nothing to delete, try inserting a node\n";
	}else{
		cout << "Are you certain you wish to delete your list (y/n):\n";
		while(true){
			getline(cin, input);
			if(input == "y"){
				first_time = true; //By setting this I esentally start over.
				break;
			}else if(input =="n"){
				break;
			}else{
				cout << "please select only the character 'y' or 'n'\n";
			}
		}
	}
}

void mainMenu(){
	while(true){
		int myNumber = 0;
		cout << "\nWhat do you want to do?\n";
		cout << "1) Insert Node\n";
		cout << "2) Delete Node\n";
		cout << "3) Print all Nodes in linked list\n";
		cout << "4) Find a Node\n";
		cout << "5) Delete the whole list\n";
		cout << "6) Quit\n";

		while (true) {
			cout << "Please enter a valid number between "<< MIN << " and " << MAX <<": ";
			getline(cin, input);

			// This code converts from string to number safely.
			stringstream myStream(input);
			if (myStream >> myNumber && myNumber>=MIN && myNumber<=MAX) // I used constants to allow me to change the range easily
				break;

			cout << "Invalid number, please try again\n";
		}
		switch (myNumber){
			case 1:
				insertNode();
				break;
			case 2:
				deleteNode();
				break;
			case 3:
				printList();
				break;
			case 4:
				findNode();
				break;
			case 5:
				deleteList();
				break;
			case 6:
				exit (0);
				break;
		}
	}
}

int main() {
	cout << endl << endl;
	cout << "Welcome to my linked list program!!!\n\n";
	//this intiates some of my global values
	input = "";
	first_time = true;
	totalNodeCount = 0;
	mainMenu();

return 0;
}