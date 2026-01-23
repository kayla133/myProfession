// note, to set up any code in C++ the follow must be included:
// #include <iostream>
// 
// using namespace std; will print statements without having to use it as a prefix every time.
// 
// int main() {content}

#include <iostream>
#include <list>
#include <string>
#include <cstdlib>

using namespace std;

list<string> toDo = {};

// this function allows the user to add a task
void addTask() {
	string task;
	// user adds task
	cout << "Please enter the tasks for your To-Do list using enter to sperate each task. When you are finished enter q." << endl;

	// this will clear any choices from the menu selection to allow it to run properly
	cin.ignore();

	// get the user input and add it to the toDo list
	while (getline(cin, task) && task != "q") {
		if (!task.empty()) {
			toDo.push_front("[ ] " + task);
		}
		
	}
	system("cls");
}

// this function prints the list
void printList() {
	for (string tasks : toDo) {
		cout << tasks << "\n";
	}
}

// this function allows the user to check off an item from the lsit
void complete() {
	printList();

	if (toDo.empty()) {
		cout << "The list is empty, nothing can be marked as complete. \n";
		return;
	}

	int index;
	// ask the user for the index that they would like to delete
	cout << "What is the index of the item you would like to check off? \n";
	cin >> index;

	// create error message if user chooses the incorect index
	if (index < 0 || index >= toDo.size()) {
		cout << "Error: Index " << index << " is out of range. "
			<< "Please choose between 0 and " << toDo.size() - 1 << ". \n";
	}
	else {
		// this allows a starting point
		auto it = toDo.begin();

		// add that amount to the index marker that you choose. If you said 2, then it would append index 2
		advance(it, index);

		// this appends the content of the index marker
		*it = "[X] Complete!";
	}

}









int main() {
	int choice = 0;
	
	cout << "Welocome to the To-Do list application! \n";
	
	// this line reads what the user types.

	while (choice != 6) {
		cout << "1. Add Task \n";
		cout << "2. Mark Task as Complete \n";
		cout << "3. List Task \n";
		cout << "4. Save to File \n";
		cout << "5. Load File \n";
		cout << "6. Quit Program \n";
		cin >> choice;
		system("cls");

		if (choice == 1) {
			// add item to list
			addTask();
		}
		
		if (choice == 2) {
			// check off item
			complete();
		}

		if (choice == 3) {
			// print list
			printList();
		}

		if (choice == 4) {
			// save list
		}

		if (choice == 5) {
			// load lsit
		}

		if (choice == 6) {
			// quit
			cout << "See ya later!";
		}
	}
	
	return 0;
}


