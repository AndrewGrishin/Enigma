#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Enigma{

private:
    
    string key;
    int *startPositions;
    char *dictionary;
    
    void creatDictionary(){
        dictionary = new char[95];
        dictionary[0] = 't';
        dictionary[1] = 'u';
        dictionary[2] = '$';
        dictionary[3] = '%';
        dictionary[4] = '|';
        dictionary[5] = ';';
        dictionary[6] = '+';
        dictionary[7] = '2';
        dictionary[8] = ' ';
        dictionary[9] = '#';
        dictionary[10] = '&';
        dictionary[11] = '\'';
        dictionary[12] = '(';
        dictionary[13] = ')';
        dictionary[14] = '*';
        dictionary[15] = '5';
        dictionary[16] = '}';
        dictionary[17] = '~';
        dictionary[18] = 'K';
        dictionary[19] = '8';
        dictionary[20] = '4';
        dictionary[21] = '<';
        dictionary[22] = '=';
        dictionary[23] = '>';
        dictionary[24] = ',';
        dictionary[25] = '!';
        dictionary[26] = '"';
        dictionary[27] = '-';
        dictionary[28] = '?';
        dictionary[29] = 'B';
        dictionary[30] = 'C';
        dictionary[31] = 'I';
        dictionary[32] = 'Q';
        dictionary[33] = '@';
        dictionary[34] = 'H';
        dictionary[35] = 'S';
        dictionary[36] = 'T';
        dictionary[37] = 'Y';
        dictionary[37] = 'Z';
        dictionary[39] = '[';
        dictionary[40] = '\\';
        dictionary[41] = 's';
        dictionary[42] = 'e';
        dictionary[43] = '3';
        dictionary[44] = 'v';
        dictionary[45] = '9';
        dictionary[46] = ':';
        dictionary[47] = '6';
        dictionary[48] = '{';
        dictionary[49] = 'J';
        dictionary[50] = 'W';
        dictionary[51] = 'X';
        dictionary[52] = '.';
        dictionary[53] = '7';
        dictionary[54] = 'A';
        dictionary[55] = 'F';
        dictionary[56] = ']';
        dictionary[57] = '^';
        dictionary[58] = '_';
        dictionary[59] = 'L';
        dictionary[60] = 'D';
        dictionary[61] = 'E';
        dictionary[62] = 'j';
        dictionary[63] = 'M';
        dictionary[64] = 'U';
        dictionary[65] = 'N';
        dictionary[66] = 'q';
        dictionary[67] = 'c';
        dictionary[68] = 'd';
        dictionary[69] = 'g';
        dictionary[70] = 'h';
        dictionary[71] = 'i';
        dictionary[72] = 'z';
        dictionary[73] = 'r';
        dictionary[74] = '/';
        dictionary[75] = '0';
        dictionary[76] = '1';
        dictionary[77] = 'R';
        dictionary[78] = 'k';
        dictionary[79] = 'l';
        dictionary[80] = 'm';
        dictionary[81] = 'n';
        dictionary[82] = 'o';
        dictionary[83] = 'p';
        dictionary[84] = 'G';
        dictionary[85] = 'O';
        dictionary[86] = 'a';
        dictionary[87] = 'b';
        dictionary[88] = 'w';
        dictionary[89] = 'x';
        dictionary[90] = 'y';
        dictionary[91] = 'P';
        dictionary[92] = 'V';
        dictionary[93] = '`';
        dictionary[94] = 'f';
    }
    
    void matchStartPosition(){
        int k(0);
        for (int i = 0; i < key.length(); i++){
            for (int j = 0; j < 95; j++){
                if (key[i] == dictionary[j]){
                    startPositions[k++] = j;
                }
            }
        }
    }
    
    long sum(){
        long k = 0;
        for (int i = 0; i < key.length(); i++){
            k += (int)dictionary[startPositions[i]];
        }
        return k;
    }
    
    char cryptLetter(char a){
        return (char)dictionary[(sum()*key.length() + (int)a) % 95];
    }
    
    char decryptLetter(char a){
        int k(0);
        while ((char)dictionary[(sum()*key.length() + dictionary[k]) % 95] != a && k <= 94) k++;
        return dictionary[k];
    }

    void rotateRotors(){
        
        unsigned long i(key.length() - 1);
        startPositions[i]++;
        
        while (startPositions[i] > 94 && i >= 0){
            startPositions[i] = 0;
            startPositions[--i]++;
        }
    }
    
public:
    
    Enigma(string Vkey = "someKey"){
        startPositions = new int[Vkey.length()];
        key = Vkey;
        creatDictionary();
        matchStartPosition();
    }
    
    void encrypt(bool encrypt = true){
        
        matchStartPosition();
        
        string input("");
        string crypted("");
        
        while (true){
            cout << "Input the text:" << endl;
            cout << "Answer: ";
            getline(cin, input);
            
            if (input == "qUIt") break;
            
            for (int i = 0; i < input.length(); i++){
                if (encrypt)
                    crypted += cryptLetter(input[i]);
                else
                    crypted += decryptLetter(input[i]);
                rotateRotors();
            }
            cout << endl << crypted << endl << endl;;
            crypted = "";
        }
    }
    
    void decrypt(){
        encrypt(false);
    }
    
};

int main(int argc, char* argv[]) {
    
    if (argc == 1){
        cout << "No parameter entered. Please, launch this programme again with \"encrypt\" or \"decrypt\" specification.\n";
        return 1;
    }
    
    Enigma na = Enigma();
    
    
    if (strcmp(argv[1],"encrypt"))
        na.encrypt();
    else
        na.decrypt();
    return 0;
}

// loop
// key injector
// mixing classes
// phone edition
