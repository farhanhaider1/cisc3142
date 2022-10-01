#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    vector<string> words;
   
    string inString, word = "";
    
    cout << "Enter some word and it will change "
            "each word to uppercase" << endl;

    //read a string or a line from an input stream
    getline(cin, inString);
   
    for(int i = 0; i <= inString.size(); i++){
        
        char character = inString[i];
        word += character;
        if(character == ' '){
            words.push_back(word);
            word = "";
        }
    }
   
    words.push_back(word);

    string lineToPrint = "";
    for(int i = 0; i <= words.size(); i++){
       
        for (auto & c: words[i]) c = toupper(c);
        lineToPrint += words[i];
       
    }
    cout << lineToPrint;

}
