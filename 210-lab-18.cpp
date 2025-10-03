#include <iostream>
#include <string>
using namespace std;

class Movie{
    public:
        string getComment() const { return comment; }
        void setComment( string c) { this->comment = c; }
        double getRating() const { return rating; }
        void setRating( double r ) { this->rating = r; }

    private:
        string comment;
        double rating;

};

struct Node{
    Movie choice;
    Node *next;
};

void outputMenu();
void outputList( Node *);
void addHead( Node *&);
void addTail ( Node *&);

int main(){
    Node *head = nullptr;
    int entry;
    
    outputMenu();
    cout << "Choice: ";
    cin >> entry;
    while((entry > 2) || (entry < 1)){
        cout << "Invalid choice, please enter your choice again(1 - 2): ";
        cin >> entry;
    }
    if(entry == 2){
        addTail(head);
    }
    else if(entry == 1){
        addHead(head);
    }

    return 0;
}

void outputMenu(){
    cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
}

void addHead( Node *&hd){

}

void addTail ( Node *&hd){
    
}