// DSString cpp for the DSString h file
// Created by mark on 6/2/2021.
//

#include "DSString.h"
#include <iostream>

using namespace std;

//Base/Default
DSString::DSString()
{
    //cout <<"Default Constructor called"<< endl;
    char* str  = new char[1];
    size = 0;
    str [0] = '\0';
}
//constructor with char*
DSString::DSString(const char *imput)
{
    //cout <<"Parameterized Constructor called"<< endl;
    size = strlen(imput);
    if(imput == nullptr){
        str = new char[1];
        str[0]= '\0';
    }
    else{
        str = new char[size+1];
        strcpy(str,imput);
    }
}
//constructor with DSString&
DSString::DSString(const DSString &imput)
{
    //cout <<"Parameterized Constructor called"<< endl;
    size = imput.size;
    if(imput.str == nullptr){
        str = new char[1];
        str[0]= '\0';
    }
    else{
        str = new char[size+1];
        strcpy(str,imput.str);
    }
}
//destructor
DSString::~DSString(){
    //cout <<"Destructor called"<< endl;
    delete[]str;
}
//Overloaded Assignment Operators for char *
DSString &DSString::operator=(const char *imput){
    //Check if there are the same, so not to overwrite what is already the same.
    if(imput == str){
        return *this;
    }
    else{
        size = strlen(imput);
        delete []str;
        str = new char[size+1];
        strcpy(str,imput);
        return *this;
    }
}

//Overloaded Assignment Operators for DSString&
DSString &DSString::operator=(const DSString &imput) {
    //Check if there are the same, so not to overwrite what is already the same.
    if(&imput == this){
        return *this;
    }
    else{
        size = imput.size;
        delete []str;
        str = new char[size+1];
        strcpy(str,imput.str);
        return *this;
    }
}

//Overloaded non-modifying string concat
DSString DSString::operator+(const DSString &imput) {
    //changes size to include the length of imput and str
    size += imput.size;
    //creates a temp buffer that allocates a new char*
    char *buffer = new char[size+1];
    //fill in the original str
    strcpy(buffer,str);
    //adds the imput at the end
    strcat(buffer, imput.str);
    str = buffer;
    return *this;
}

//relational operators.
//compare char*
bool DSString::operator==(const char *imput) {
    return strcmp(str,imput) == 0;
}

//compare DSString&
bool DSString::operator==(const DSString &imput) {
    return strcmp(str, imput.str) == 0;
}

//Alphabetical order DSString&
bool DSString::operator>(const DSString &imput) {
    return strcmp(str,imput.str) > 0;
}

//Alphabetical order char*
bool DSString::operator>(const char *imput) {
    return strcmp(str, imput) > 0;
}

//Subscript operator
char &DSString::operator[](const int index) {
    return str[index];
}


int DSString::getLength() const {
    return size;
}

//substring
DSString DSString::substring(int start, int numChars) {
    //allocate a buffer with size substring
    char *buffer = new char[numChars+1];
    //fills the buffer with substring
    for(int i = 0; i < numChars; i++) {
        buffer[i] = str[start + i];
    }
    //add nullptr at the end
    buffer[numChars]= '\0';
    //creating a temporary object for the function that doesn't change the og string object
    DSString temp(buffer);
    return temp;
}



std::ostream &operator<<(ostream & output, const DSString &imput) {
    output << imput.str;
    return output;
}

char *DSString::c_str() {
    return nullptr;
}
//lowercase maker
//void DSString::lowerC(char *imput) const {
//    // char *buffer = new char[size+1];
//    for(int i = 0; i < size; i++) {
//        char temp = imput[i];
//        if((int)temp >= 64 && (int)temp <= 90){
//            int num = (int)temp + 32;
//            imput[i] = (char)num;
//        }else{
//            continue;
//        }
//    }
//    //add nullptr at the end
//    imput[size]= '\0';
//    //creating a temporary object for the function that doesn't change the og string object
//    //DSString temp(buffer);
//
//}














