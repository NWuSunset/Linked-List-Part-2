#include <iostream>
#include "Student.h"
#include "Node.h"
#include <cstring>
#include <limits> //used just to clear invalid inputs


using namespace std;

void Add(Node* & head, Node* curr);
void addNodes(Node* & head, Node* curr, Node* node);
void Delete(Node* node, Node* & head);
void deleteNodes(Node* curr, int id, Node* & head);
void Print(Node* node);
void Average(Node* node, float& num, float& total);
template <typename T>
T validInput();

int main() {
    Node* head = nullptr; //create the first (header) node in the list
    bool quit = false;

    float num = 1;
    float total = 0;

    while (quit == false) {
        char input[8];
        cout << "Do you want to ADD, PRINT, DELETE, AVERAGE (Averages student gpas), or QUIT" << endl;;
        cin.getline(input, 8);
        if (cin.fail()) {
            //in case more than 8 is entered
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (strcasecmp(input, "ADD") == 0) {
            Add(head, head); //pass is head twice for current and head
        } else if (strcasecmp(input, "PRINT") == 0) {
            if (head != nullptr) {
                Print(head);
            } else {
                cout << "There are no students in the list" << endl;
            }
        } else if (strcasecmp(input, "DELETE") == 0) {
            Delete(head, head);
        } else if (strcasecmp(input, "AVERAGE") == 0) {
            if (head != nullptr) {
                Average(head, num, total);
            } else {
                cout << "There are no students in the list" << endl;
            }
        } else if (strcasecmp(input, "QUIT") == 0) {
            quit = true;
        }
    }
    return 0;
}

void Add(Node* & head, Node* curr) {
    //individual variables for clarity
    char firstName[20];
    char lastName[20];

    cout << "First Name: " << endl;
    cin.getline(firstName, 20);
    cout << "Last Name: " << endl;
    cin.getline(lastName, 20);
    cout << "id: " << endl;
    const int id = validInput<int>();
    cout << "gpa: " << endl;
    const float gpa = validInput<float>();
    cin.ignore();

    Student* student = new Student(firstName, lastName, id, gpa); //Create a new student with the information
    Node* node = new Node(student); //create a new node based on the student

    addNodes(head, curr, node); //Make sure the nodes will be sorted into the list correctly
}

//Sorts the list from lowest to highest student id.
void addNodes(Node* & head, Node* curr, Node* node) {
    //Used to sort the nodes
    //If there isn't a head node (no items in list) then add the first item and exit the function
    if (head == nullptr) {
        head = node;
        return;
    }

    //If there isn't a next item in the list then add the passed in node to the list and exit the function. (also checking in case this is the second item added to the list)
    if (curr->getNext() == nullptr) {
        if (node->getStudent()->getId() >= curr->getStudent()->getId()) {
            //If the passed in node would still make the list be in order
            curr->setNext(node);
            return; //exit because we don't have to sort the list
        }
        curr->setNext(node);
    }

    //If the passed in node is less than the head node. Swap their positions
    if (node->getStudent()->getId() < head->getStudent()->getId()) {
        //Swap the head and node positions in the list
        head->setNext(node->getNext()); //head now has node's next
        node->setNext(head); //and now head is node's next.
        head = node; //change the header pointer to node (making node the new head)
        return;
    }

    //If the next node is greater than the node passed in we want to swap their places in the list
    if (curr->getNext()->getStudent()->getId() > node->getStudent()->getId()) {
        node->setNext(curr->getNext()); //Then set the greater node (next node) after the passed in node
        curr->setNext(node); //Then the node after current will be set to the passed in node
        cout << "Checking if next node is greater than node passed in" << endl;
        Print(head);
        return; //we can then stop the recursion
    }

    //Go through function again if there is still more list to go through (to fully sort it)
    //This will occur for 3 or more nodes in the list
    addNodes(head, curr->getNext(), node);
}

void Delete(Node* node, Node* & head) {
    if (node == nullptr) {
        cout << "Empty List!" << endl;
        return;
    }
    cout << "Enter the student id you wish to delete: " << endl;
    const int id = validInput<int>();

    deleteNodes(node, id, head);
    cin.ignore();
}

void deleteNodes(Node* curr, int id, Node* & head) {
    if (curr == head) {
        //In the case that curr is the head
        if (curr->getStudent()->getId() == id) {
            Node* temp = curr->getNext(); //save node's next
            delete curr;
            if (temp != nullptr) {
                head = temp; //Set the head to the node's next
            } else {
                head = nullptr; //make sure head no longer points to the original position (since we deleted it)
            }
            return;
        }
    }

    if (curr->getNext() != nullptr) {
        //If we find the correct node to delete
        if (curr->getNext()->getStudent()->getId() == id) {
            const Node* temp = curr->getNext(); //save the location of the node to delete
            curr->setNext(curr->getNext()->getNext()); //set the next node to the one after the node we are removing

            //delete the node from the linked list
            delete temp;
        } else {
            //Try the next node in the list to see if it matches the id
            deleteNodes(curr->getNext(), id, head);
        }
    } else {
        cout << "The id doesn't exit in the list" << endl;
    }
}

//Go though all the nodes in the list using recursion
void Print(Node* node) {
    cout.setf(ios::showpoint); //show zeros in the decimal places
    cout.precision(3); //to 2 decimal places (for the gpa)

    //Print out things for the student
    cout << node->getStudent()->getFirstName() << ", "
        << node->getStudent()->getLastName() << ", "
        << node->getStudent()->getId() << ", "
        << node->getStudent()->getGpa() << endl;

    if (node->getNext() != nullptr) {
        Print(node->getNext());
    }
}

//Prints out the average gpa of all students
void Average(Node* node, float& num, float& total) {
    total += node->getStudent()->getGpa(); //add gpa to the average

    if (node->getNext() != nullptr) {
        num++; //number of things in the list increment
        Average(node->getNext(), num, total);
    } else {
        //if the end of the list is hit
        float average = 0;
        average = (total / num);
        cout << "GPA average: " << average << endl;

        //reset values
        total = 0;
        num = 1;
    }
}

//This is just for clearing invalid inputs so it doesn't break the program (I'm not using it for any logic :) (if templates aren't allowed) )
template <typename T>
T validInput() {
    //Template makes it able to take any data type (so I don't have to write code for different types...)
    T value;
    while (!(cin >> value)) {
        cout << "Invalid input. please enter a valid number" << endl;
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    }
    return value;
}
