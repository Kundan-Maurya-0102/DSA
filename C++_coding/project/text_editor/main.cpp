#include<iostream>
#include "include/textEditor.hpp"
using namespace std;

int main(){
    textEditor KundanTextEditor;
    textEditorCanvasObject *obj = KundanTextEditor.canvas();
    obj->writes();
    return 0;
}