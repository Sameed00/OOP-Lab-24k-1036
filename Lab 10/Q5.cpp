#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream f("data.txt", ios::out);
    f << "AI is the future. AI will transform the world. Embrace AI now.";
    f.close();

    string searchWord, replacementWord;
    cout << "Enter word to search: ";
    cin >> searchWord;
    cout << "Enter replacement word: ";
    cin >> replacementWord;

    if(replacementWord.length() > searchWord.length()){
        cout << "Replacement word is too long.\n";
        return 1;
    }

    fstream file("data.txt", ios::in | ios::out);
    string buf = "";
    char ch;
    streampos pos;

    while(file.get(ch)){
        buf += ch;
        if(buf.length() > searchWord.length())
            buf.erase(0,1);
        if(buf == searchWord){
            pos = file.tellg();
            file.seekp(pos - (streamoff)searchWord.length());
            file << replacementWord;
            for(int i = replacementWord.length(); i < searchWord.length(); i++)
                file << ' ';
            file.seekg(pos);
            buf = "";
        }
    }
    file.close();

    ifstream r("data.txt");
    string line;
    while(getline(r, line)){
        cout << line << endl;
    }
    r.close();
}

