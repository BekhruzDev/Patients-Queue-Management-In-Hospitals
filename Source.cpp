/**
*  Section
*  Team Number:    03
* 
*  Team Members:   Abdullakhujaev Bekhruz  U2010010
*                  Abdukarimov Abdulvokhid U2010004
*                  Abdunasimov Alibek      U2010011
*                  Mirzaliyev Islom        U2010170
* 
*  Project Topic:  Patients' Queue Management At Hospitals And Clinics
   
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

//CREATING A NODE
struct Node
{
    int priority;
    int data;
    struct Node* next;
};

//PRIORITY QUEUE IMPLEMENTATION
class PriorityQueue
{
private:
    Node* front;
public:
    PriorityQueue()
    {
        front = NULL;
    }
     //Insert the new patient's id and its priority into Priority Queue
    void insert(int patientID, int patientPriority)
    {
        Node* temp, * queue;
        temp = new Node;
        temp->data = patientID;
        temp->priority = patientPriority;
        if (front == NULL || patientPriority < front->priority)
        {
            temp->next = front;
            front = temp;
        }
        else
        {
            queue = front;
            while (queue->next != NULL && queue->next->priority <= patientPriority)
                queue = queue->next;
            temp->next = queue->next;
            queue->next = temp;
        }
    }
    // REMOVING PATIENT FROM THE PRIORITY QUEUE
    void del()
    {
        //here if the queue is empty, we cannot remove element from it!
        Node* temp;
        if (front == NULL) // underflow occurs
            cout << "No patients left in the queue\n";
        else
        {
            //if the queue is not empty
            temp = front;
            cout << "Now it is the turn of the patient ID: " << temp->data << endl;
            front = front->next;
            free(temp);
        }
    }
     //DISPLAYING THE ENTIRE QUEUE
    void display()
    {
        Node* pointer;
        pointer = front;
        if (front == NULL)
            cout << "\nNo patients in the queue!\n";
        else
        {
            cout << "\nPatients' current queue is :\n";
            while (pointer != NULL)
            {
                cout <<"<"<< pointer->priority<<">" << " ----------- " << pointer->data << endl;
                pointer = pointer->next;
            }
        }
    }
};

//PROGRAM DRIVER
int main()
{
    int choice, patientID, patientPriority;
    PriorityQueue pq;
    cout << " \t *******************************************";
    cout << "\n\t   WELCOME TO PATIENT QUEUE MANAGEMENT APP" <<endl;
    cout << " \t *******************************************";

    do
    {
        cout << "\n\t\t\t======="<<endl;
        cout << "\t\t\tM E N U " << endl;
        cout << "\t\t\t=======" << endl << endl;

        cout << "\t\t[1] Add a new patient\n";
        cout << "\t\t[2] Doctor is calling the next patient \n";
        cout << "\t\t[3] Display all patients' queue\n";
        cout << "\t\t[0] Exit the program\n";
        cout << "\t\tEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\tAdd the new patient's ID : ";
            cin >> patientID;
            cout << "\tEnter the patient's priority : ";
            cin >> patientPriority;
            while (patientPriority < 1 || patientPriority > 7) {
                cout << "\t\tNOTE: PATIENTS PRIORITY IS BETWEEN 1 AND 7!" << endl;
                cout << "Enter another priority between 1 and 7: ";
                cin >> patientPriority;
                continue;
            }
            pq.insert(patientID, patientPriority);
            break;
        case 2:
            pq.del();
            break;
        case 3:
            pq.display();
            break;
        case 0:
            break;
        default:
            cout << "\tPlease, enter a valid choice number!\n";
        }
    }     while (choice != 0);
    return 0;
}