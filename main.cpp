#include <iostream>
#include "TodoList.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    TodoList mylist;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }
    string firstArg = argv[1];
    if (firstArg.compare("add") == 0) {
        cout << "Doing an add" << endl;
        string date = argv[2];
        string task = argv[3];
        mylist.add(date, task);
        cout << "date " << date << " task " << task << endl;
    }
	if (firstArg.compare("remove") == 0) {
        cout << "Doing a remove" << endl;
        string task = argv[2];
        if(mylist.remove(task) == 1) {
        	cout << "removed task: " << task << endl;
		}
		else {
			cout << "No task was removed" << endl;
		}
    }
	if (firstArg.compare("printList") == 0) {
        cout << "Doing a print" << endl;
        mylist.printTodoList();
		cout << "List Printed" << endl;
    }
	if (firstArg.compare("printDay") == 0) {
        cout << "Doing a printDay" << endl;
        string date = argv[2];
		mylist.printDaysTasks(date);
		cout << "Printed tasks on day: " << date << endl;
    }
    return 0;
}
