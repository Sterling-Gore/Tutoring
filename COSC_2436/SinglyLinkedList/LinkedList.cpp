#include <iostream>
#include <string>

struct node
{
    char data;
    node* next;
};

class LinkedList
{
private:
    node* head;
    node* tail;
public:
    //constructor
    LinkedList(){ head = tail = NULL;}

    //destructor
    ~LinkedList()
    {
        node* next = head;
        while( next != NULL)
        {
            node* curr = next;
            next = next->next;
            delete curr;
        }
    }

    void create_new(char val)  
    {
        node* n = new node();
        n->data = val;
        n->next = NULL;
        head = tail = n;
    }

    void add_to_front(char val)
    {
        if(head == NULL)
        {
            create_new(val);
        }
        else
        {
            node* n = new node();
            n->data = val;
            n->next = head;
            head = n;
        }  
    }

    void add_to_back(char val)
    {
        if(head == NULL)
        {
            create_new(val);
        }
        else  
        {
            node* n = new node();
            n->data = val;
            n->next = NULL;
            tail->next = n;
            tail = n;
        }
    }

    void print()
    {
        node* curr = head;
        while(curr != NULL)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};


int main(){

    LinkedList forward;
    LinkedList backward;
    std::string word;
    std::cin >> word;
    for(int i = 0; i < word.length(); i++)
    {
        forward.add_to_back(word[i]);
        backward.add_to_front(word[i]);
    }

    std::cout << "This is the word forwards" << std::endl;
    forward.print();

    std::cout << "This is the word backwards" << std::endl;
    backward.print();

    

    return 0;
}
