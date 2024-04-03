#include <iostream>
using namespace std;
struct node {
    int value = 0;
    node* next_node = nullptr;
};
struct stack {
    node* head = nullptr;
    node* tail = nullptr;
    int counter = 0;
    void queue(int value) {
        node* new_node = new node();
        new_node->value = value;
        if (counter == 0) {
            head = new_node;
            tail = new_node;
        }
        else {
            tail->next_node = new_node;
            tail = new_node;
        }
        counter++;
    }
    int unqueue() {
        if (counter > 0) {
            node* new_head = head->next_node;
            int value = head->value;
            delete head;
            head = new_head;
            counter--;
            return value;
        }
        else { return 0; }
    }
    int count() {
        return counter;
    }
    void insertBeforeNegative(){
        node* current_node = head;
        if (counter > 0) {
            while (current_node->next_node != nullptr) {
                if (current_node->next_node->value < 0) {
                    node* new_node = new node();
                    new_node->value = 1;
                    new_node->next_node = current_node->next_node;
                    current_node->next_node = new_node;
                    current_node = current_node->next_node;
                    counter++;
                }
                current_node = current_node->next_node;
            }
            if (head->value < 0) {
                node* new_node = new node();
                new_node->value = 1;
                new_node->next_node = head;
                head = new_node;
                counter++;
            }
        }
    }
    void removeNegative(){
        if (counter > 0) {
            node* current_node = head;
            node* ptr = nullptr;
            while (current_node->next_node != nullptr) {
                if (current_node->next_node->value < 0) {
                    ptr = current_node->next_node->next_node;
                    delete current_node->next_node;
                    current_node->next_node = ptr;
                    counter--;
                }
                else {
                    current_node = current_node->next_node;
                }
            }
            if (head->value < 0) {
                current_node = head;
                head = head->next_node;
                delete current_node;
                counter--;
            }
        }
    }
    int count(int value) {
        int count_value = 0;
        node* current_node = head;
        while (current_node != nullptr) {
            if (current_node->value == value) {
                count_value++;
            }
            current_node = current_node->next_node;
        }
        return count_value;
    }
    void clear(){
        int cize = count();
        for (int i = 0; i < cize; i++) {
            unqueue();
        }
    }
    void menu() {
        cout << "(0) shutdown program" << endl;
        cout << "(1) queue(int value)" << endl;
        cout << "(2) unqueue()" << endl;
        cout << "(3) count()" << endl;
        cout << "(4) insertBeforeNegative()" << endl;
        cout << "(5) removeNegative()" << endl;
        cout << "(6) count(int value)" << endl;
        cout << "(7) clear()" << endl;
    }
};
void main(int argc, char* argv[]) {
    bool interface = true;
    string argument;
    if (argc > 1) { argument = argv[1]; }
    if (argument == "false" || argument == "0") { interface = false; }
    stack list;
    int value;
    int count_what = 0;
    if (interface) {
        int switch_on = 1;
        while (switch_on) {
            system("cls");
            list.menu();
            cin >> switch_on;
            switch (switch_on) {
            case (0): {
                break;
                }      
            case (1): {
                cin >> value;
                list.queue(value);
                break;
                }
            case (2): {
                if (list.count() > 0) {
                    cout << list.unqueue() << endl;
                }
                break;
                }     
            case (3): {
                cout << list.count() << endl;
                break;
                }    
            case (4): {
                list.insertBeforeNegative();
                break;
                }  
            case (5): {
                list.removeNegative();
                break;
                }  
            case (6): {
                cin >> count_what;
                cout << list.count(count_what) << endl;
                break;
                }   
            case (7): {
                list.clear();
                break;
                }  
            default: {
                cout << "unknown command, try again" << endl;
                break;
                }
            }
            system("pause");
        }
    }
    else {
        while (true) {
            cin >> value;
            if (value != 0) {
                list.queue(value);
            }
            else {
                break;
            }
        }
        list.insertBeforeNegative();
        list.removeNegative();
        cin >> count_what;
        cout << list.count(count_what) << endl;
        list.clear();
    }
}