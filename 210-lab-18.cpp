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
    outputList(head);

    return 0;
}

void outputMenu(){
    cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
}

void outputList( Node *hd){
    int count = 1;
    Node *current = hd;
    cout << "Output all reviews" << endl;
    if(!hd){
        cout << "Empty list" << endl;
    }
    else{
        while(current){
            cout << "     > Review #" << count << ": "  << current->choice.getRating() << ": " << current->choice.getComment() << endl;
            count++;
            current = current->next;
        } 
    }
}

void addHead( Node *&hd){
    double tempR;
    string tempC; 
    char q;
    bool review = 1;

    while( review != 0){
        Node *newNode = new Node;

        cout << "Enter review rating 0-5: ";
        cin >> tempR;
        cout << "Enter review comment: "; 
        cin.ignore();
        getline(cin, tempC);
        newNode->choice.setRating(tempR);
        newNode->choice.setComment(tempC);

        if(!hd){
            hd = newNode;
            newNode->next = nullptr;
        }
        else{
            newNode->next = hd;
            hd = newNode;
        }
        
        cout << "Enter another review? Y/N: ";
        cin >> q;
        if(tolower(q)== 'n'){
            review = 0;
        }
    }



}

void addTail ( Node *&hd){
    double tempR;
    string tempC;
    char q;
    bool review = 1;

    while(review == 1){
        Node *newNode = new Node;

        cout << "Enter review rating 0-5: ";
        cin >> tempR;
        cout << "Enter review comment: "; 
        cin.ignore();
        getline(cin, tempC);
        newNode->choice.setRating(tempR);
        newNode->choice.setComment(tempC);

        if(!hd){
            hd = newNode;
            newNode->next = nullptr;
        }
        else{
            Node *current = hd;
            while(current->next){
                current = current->next;
            }
            current->next = newNode;
            newNode->next = nullptr;
        }

        cout << "Enter another review? Y/N: ";
        cin >> q;
        if(tolower(q) == 'n'){
            review = 0;
        }
    }

}