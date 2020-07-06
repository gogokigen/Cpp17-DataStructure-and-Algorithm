//https://stackoverflow.com/questions/11876290/c-fastest-way-to-read-only-last-line-of-text-file
//gcc -g read_last_line_of_file.cpp -lstdc++ -o read_last_line_of_file
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    string filename = "testlog";
    ifstream fin;
    fin.open(filename);
    if(fin.is_open()) {
        fin.seekg(0,ios_base::end);             //Start at end of file

        char ch = ' ';                         //Init ch not equal to '\n'
        while(ch != '\n'){
            fin.seekg(-2,std::ios_base::cur); //Two bytes back, this means we
                                              //will NOT check the last character
            //cout << "sp: " << (int)fin.tellg() << endl;
            if((int)fin.tellg() <= 0){        //If passed the start of the file,
                fin.seekg(0);                 //this is the start of the line
                break;
            }
            fin.get(ch);                      //Check the next character
        }


        string lastLine;            
        getline(fin,lastLine);                      // Read the current line
        fin.close();

        cout << "final line length: " << lastLine.size() << endl;
        cout << "final line character codes: ";
        for(size_t i =0; i < lastLine.size(); i++){
            cout << hex << (int)lastLine[i] << " ";
        }
        cout << endl;
        cout << "Result: " << lastLine << '\n';     // Display it
    }  else {
        cout << "Could not find end line character" << endl;
    }

    return 0;
}
