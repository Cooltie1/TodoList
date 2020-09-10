//
// Created by scott on 9/8/2020.
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include "TodoListInterface.h"
#include <fstream>
#include <string>
#include <vector>

class TodoList : public TodoListInterface {
private:
	vector<string> tasks;
public:
    TodoList () {
        cout << "In Constructor" << endl;
        string line;
  		ifstream infile ("example.txt");
  		if (infile.is_open()) {
    		while ( getline (infile,line) ) {
      			cout << line << '\n';
				tasks.push_back(line);
    		}
    		infile.close();
  		}

  		else cout << "Unable to open file";
    };
    virtual ~TodoList() {
        cout << "In Desctructor" << endl;
        ofstream outfile;
		outfile.open("example.txt", ofstream::out | ofstream::trunc);
		for(int i = 0; i <tasks.size(); i++) {
			outfile << tasks.at(i);
			if (i + 1 < tasks.size()) {
				outfile << endl;
			}
		}
		outfile.close();
    };

    void add(string _duedate, string _task) {
        cout << "In add" << endl;
		tasks.push_back(_duedate + " " + _task);
    }
    int remove(string _task) {

        cout << "In remove" << endl;
		// START WORK HERE! USE CIN.IGNORE OR SOMEHOW DELETE FIRST WORD OF EACH STRING IN VECTOR AND THEN CHECK

    };
    void printTodoList() {

        cout << "In list" << endl;
    }
    void printDaysTasks(string _date) {

        cout << "In daysTask" << endl;
    }

};


#endif //TODOLIST_TODOLIST_H