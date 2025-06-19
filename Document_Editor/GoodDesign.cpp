#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

class DocumentElement{
    public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement{
    private:
    string text;

    public:
    TextElement(string text){
        this->text = text;
    }
    string render() override{
        return text;
    }
};

class ImageElement : public DocumentElement{
private:
    string imagePath;

public:
    ImageElement(string imagePath) {
        this->imagePath = imagePath;
    }

    string render() override {
        return "[Image: " + imagePath + "]";
    }
};

class NewLineElement : public DocumentElement{
public:
    string render() override {
        return "\n";
    }
};

class TabSpaceElement: public DocumentElement{
public:
    string render() override {
        return "\t";
    }
};

class Document {
    private:
    vector<DocumentElement*> documentElements;

    public:
    void addElement(DocumentElement* element){
        documentElements.push_back(element);
    }

    string render(){
        string result;
        for(auto ele: documentElements){
            result += ele->render();
        }
    }
};

// Persistence abstraction
class Persistence {
public:
    virtual void save(string data) = 0;
};

// FileStorage implementation of Persistence
class FileStorage : public Persistence {
public:
    void save(string data) override {
        ofstream outFile("document.txt");
        if (outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

// Placeholder DBStorage implementation
class DBStorage : public Persistence {
public:
    void save(string data) override {
        // Save to DB
    }
};

// DocumentEditor class managing client interactions

class DocumentEditor{
    private:
    Document* document;
    Persistence* storage;
    string renderedDocument;

    public:
    DocumentEditor(Document* document, Persistence* storage){
        this->document = document;
        this->storage = storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

      void addImage(string imagePath) {
        document->addElement(new ImageElement(imagePath));
    }

    // Adds a new line to the document.
    void addNewLine() {
        document->addElement(new NewLineElement());
    }

    // Adds a tab space to the document.
    void addTabSpace() {
        document->addElement(new TabSpaceElement());
    }

    string renderDocument() {
        if(renderedDocument.empty()) {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

       void saveDocument() {
        storage->save(renderDocument());
    }


};

int main(){
    Document* document = new Document();
    Persistence* persistence = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document,persistence);

    editor->addText("Hellowww");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    cout << editor->renderDocument() << endl;
    editor->saveDocument();

    return 0;
};
