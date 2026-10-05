#include "textEditor.hpp"
textEditor* textEditor::canvas(){
    cout << "Canvas Function called of textEditor class "<<endl;
    return this;
}

textEditorCanvasObject * textEditorCanvasObject::canvas(){
    return this;
}
Node* head = nullptr;
void textEditorCanvasObject::insert(string data){
    Node * tmp = new Node();
    tmp->data = data;
    tmp->next = nullptr;
    if(head==NULL){
        head = tmp;
        top++;
    }
    else{
        Node * current = head;
        while(current->next!=nullptr){
            current = current->next;
        }
        current->next = tmp;
        top++;
    }
}
void textEditorCanvasObject::show()
{
    if(top==-1){
        cout << "canva is Empty"<<endl;
        return;
    }
    Node* tmp = head;
    cout << endl << "---------------------------------------"<<endl;
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl << "----------------------------------------"<<endl;
}
void textEditorCanvasObject::pop()
{

    if (head == nullptr)
    {
        cout << "Empty Canvas" << endl;
        return;
    }

    if (head->next == nullptr)
    {
        top--;
        delete head;
        head = nullptr;
        return;
    }

    Node* tmp = head;

    while (tmp->next->next != nullptr)
    {
        top--;
        tmp = tmp->next;
    }
    top--;
    delete tmp->next;
    tmp->next = nullptr;
}
void textEditorCanvasObject::writes(){
    while(1){
        char choice;
            cout << endl << "choice"<<endl;
        cin>>choice;

        switch(choice){
            case 'p':{
                string data;
                cin>>data;
                insert(data);
            }
            break;
            case 'd':{
                pop();
            }
            break;
            case 's':{
                show();
            }
            break;
            case 'e':
                exit(0);
            break;
            default:
                cout << "Invalid Choice" <<endl;
        }
    }
}

//g++ main.cpp src/textEditor.cpp -Iinclude -o build/text_editor
//g++ main.cpp src/textEditor.cpp -Iinclude -o build/text_editor



