#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>

class DocumentEditor {
private:
    vector<string> documentElements;
    string renderedDocument;

public:
    void addText(string text){
        documentElements.push_back(text);
    }

    void addImage(string ImagePath){
        documentElements.push_back(ImagePath);
    }

     // Renders the document by checking the type of each element at runtime
    string renderDocument() {
        if(renderedDocument.empty()) {
            string result;
            for (auto element : documentElements) {
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" ||
                 element.substr(element.size() - 4) == ".png")) {
                    result += "[Image: " + element + "]" + "\n";
                } else {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }

    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout << "Document saved to document.txt" <<endl;
        }
        else{
            cout << "Error:Unable to open file for writing" << endl;
        }
    }
};

int main(){
    DocumentEditor* editor = new DocumentEditor();
    editor->addText("hello");
    editor->addText("pic.jpg");
    editor->addText("This is a doc editor");

    cout << editor->renderDocument() <<endl;
    editor->saveToFile();
    return 0;
}