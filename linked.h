//Classes included
#include "node.h"

//libraries used
#include <iostream> //Included for cin and cout
#include <sstream> //Included for convienece of parsing answers and verifying correct inputs
#include <stdlib.h> //Included for the exit function
using namespace std;

//Constants
#define MIN 1 //This is the smallest number for options on the main display
#define MAX 6 //This is the largest number allowed on the main display


//Global Variables
string input; 		//This variable is used with getline to allow me to get user input
bool first_time;	//Allows easy reset of everything as well as stops the user from doing things when there isn't nodes
node* root;			//This is a pointer that will point to the first node added that still exsits
node* current;		//points to the last node I'm on.
int totalNodeCount; //Used to see if you ever delete all nodes and need to reset first_time

