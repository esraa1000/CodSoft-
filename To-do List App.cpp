#include <iostream>
#include <string>

using namespace std;

const int maxTasks = 10;

struct task {
    string name;
    bool done = false;
};

struct list {
    task allTasks[maxTasks];
    int numTasks = 0;
};

//function to add task, function to display tasks with status, mark completed, remove task
void displayMenu();
void viewTasks(const list&);
void addTask(list&);
void removeTask(list&);
void markTask(list&);

int main()
{
    list mylist;
    int option;

    cout << "TO-DO LIST APP\n\n";
    while (true) {
        displayMenu();
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
        case 1:
            viewTasks(mylist);
            break;

        case 2:
            addTask(mylist);
            break;

        case 3:
            removeTask(mylist);
            break;

        case 4:
            markTask(mylist);
            break;
        default:
            cout << "Invalid option. Please try again. \n";

        }

    }
    return 0;
}

void displayMenu() {
    cout << "Menu: \n";
    cout << "(1) View Tasks\n";
    cout << "(2) Add a Task\n";
    cout << "(3) Remove a Task\n";
    cout << "(4) Mark Task as Completed\n";
}

void viewTasks(const list& mylist) {
    if (mylist.numTasks == 0) {
        cout << "No Taks Available\n";
    }
    else {
        for (int i = 0; i < mylist.numTasks; i++) {
            cout << i + 1 << "." << mylist.allTasks[i].name;
            if (mylist.allTasks[i].done)
                cout << "  - Completed" << endl;
            else
                cout << "  - Pending" << endl;
        }
    }
}

void addTask(list& mylist) {
    if (mylist.numTasks >= maxTasks) {
        cout << "Task list is full.\n";
        return;
    }
    cout << "Enter the task name: ";
    cin.ignore();
    getline(cin, mylist.allTasks[mylist.numTasks].name);
    mylist.numTasks++;
    cout << "Task added Successfully!\n";
}

void removeTask(list& mylist) {
    int index;

    if (mylist.numTasks == 0) {
        cout << "There is no tasks to remove.\n";
        return;
    }

    cout << "Enter The task number you want to remove: ";
    cin >> index;

    if (index < 1 || index > mylist.numTasks) {
        cout << "Invalid Task Number. Please Try Again.";
        return;
    }

    for (int i = index - 1; i < mylist.numTasks - 1; i++) {
        mylist.allTasks[i] = mylist.allTasks[i + 1];
    }

    mylist.numTasks--;
    cout << "The Task removed Successfully";
}

void markTask(list& mylist) {
    int index;

    if (mylist.numTasks == 0) {
        cout << "There are no tasks to mark.\n";
        return;
    }

    cout << "Enter The task number you want to remove: ";
    cin >> index;

    if (index < 1 || index > mylist.numTasks) {
        cout << "Invalid Task Number. Please Try Again.";
        return;
    }

    mylist.allTasks[index - 1].done = true;
    cout << "Task Marked Successfully!\n";
}