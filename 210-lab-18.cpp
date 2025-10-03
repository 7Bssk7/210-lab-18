#include <iostream>
#include <string>
using namespace std;

void outputMenu();

int main(){
    int entry;
    
    outputMenu();
    cout << "Choice: ";
    cin >> entry;

    return 0;
}

void outputMenu(){
    cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
}