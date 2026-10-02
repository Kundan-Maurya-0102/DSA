#ifndef TEXT_EDITOR_HPP
#define TEXT_EDITOR_HPP
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct Node{
    string data;
    Node * next;
};

// extern Node* head;
class textEditorCanvasObject{
    private:
        int top=-1;
    public:
        virtual textEditorCanvasObject* canvas();
        virtual void writes();
        void insert(string data);
        void show();
        void pop();
};

class textEditor: public textEditorCanvasObject {
    public:
        textEditor* canvas() override;
};
#endif