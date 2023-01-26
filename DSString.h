// Improvment on the Cstring
// Created by Mark Fontenot on 6/2/2021.
//

#ifndef PA01_SENTIMENT_DSSTRING_H
#define PA01_SENTIMENT_DSSTRING_H
#include <iostream>
#include <cstring>

using namespace std;
class DSString{

private:
    /**
     *  You will need to add some private data members here.
     *  This is up to your discretion.  However, we **strongly**
     *  encourage you to implement your string class as a wrapper
     *  for typical null-terminated c-strings.  In doing this, you
     *  may use c-sting functions in the methods in this class such
     *  as:
     *    * strlen(...)
     *    * strcpy(...)
     *    * strcmp(...)
     *    * strncpy(...)
     *    * strcat(...)
     *    * strncat(...)
     *
     *    A quick google search will return plenty of references on
     *    the c-string functions.
     **/
    int size = 0;
    //int position = 0;
    char* str = nullptr;

public:

    /**
     * Constructors and destructor
     *
     * Make sure you do proper memory management.
     **/
    DSString();//base

    DSString(const char*);//constructor with char*


    DSString(const DSString&);//constructor with DSString&

    ~DSString(); //destructor

    /**
     * Overloaded Assignment Operators
     */
    DSString& operator= (const char*);

    DSString& operator= (const DSString&);

    /**
     * Overloaded non-modifying string concat
     * @return
     */
    DSString operator+ (const DSString&);

    /**
     * Standard relational operators.  Feel free to add additional.
     *
     * Note that for each operator, there are two overloaded versions:
     *    one that takes a DSString object
     *    one that takes a null-terminated c-string
     *
     **/
    //compare the word
    bool operator== (const char*);//if the word are the same (char*)

    bool operator== (const DSString&);//if the word are the same (DSString&)

    bool operator> (const DSString&);//if the word is greater in asci value (DSString&)

    bool operator> (const char*);//if the word is greater in asci value (char*)

    /**
     * Subscript operator to access a particular character of a DSString object
     * @return the character requested by reference
     */
    char& operator[] (int);

    /**
     * getLength() returns the number (count) of characters in the string.
     **/
    int getLength() const;


    /**
     * The substring method returns a string object that contains a
     * sequence of characters from this string object.
     *
     * param start - the index of where to start
     * param numChars - the number (count) of characters to copy into
     *    the substring
     * @return a DSString object containing the requested substring
     **/
    DSString substring(int start, int numChars);//used to segment out portion of words

    /**
     * the c_str function returns a null-terminated c-string holding the
     * contents of this object.
     **/
    char* c_str();

    /**
     * Overloaded stream insertion operator to print the contents of this
     * string to the output stream in the first argument.
     **/
     //friend is able to acc private
    friend std::ostream& operator<< (std::ostream&, const DSString&);

    //You are free to add more functionality to the class.  For example,
    //you may want to add a find(...) function that will search for a
    //string within a string.  (just an example)
    //
    //Further - you will be able to update and modify this class as the
    //semester progresses.

//    DSString lowercase(imput);

//Lowercase maker
//    void lowerC(char *imput) const;



};



#endif //PA01_SENTIMENT_DSSTRING_H
