#define CATCH_CONFIG_RUNNER
// #include "catch.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "DSString.h"



int main(int argc, char *argv[]) {
    //Catch::Session().run();
    //opens
//    ifstream train("data/train_dataset_20k.csv");
    ifstream train(argv[1]);
    // check if it opens
    if(!train.is_open()) {
        cout << "train not open" << endl;
        return -1;
    }


    //buffer imput
    char *imput = new char [10000];
    // Source.getline(buffer, size, delinter)
    //removes first line
    train.getline(imput, 10000);
    //score
    int s;
    //tweet id
    char* id;
    //content of tweet
    char* twt;

    //map making
    map<char*,int> mapy;
    //loop thought all tweet
    while(!train.eof()){
        train.getline(imput, 10000, ',');
        s = atoi(imput);
        train.getline(imput, 10000, ',');
        //id = imput;
        //take out the useless content
        train.getline(imput, 10000, ',');
        train.getline(imput, 10000, ',');
        train.getline(imput, 10000, ',');
        //take the
        train.getline(imput, 10000, '\n');
        twt = imput;

        //Reference used to construct the following tempWord
        //https://www.cplusplus.com/reference/cstring/strtok/
        //https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c
        //https://linux.die.net/man/3/strtok_r
        // Spitting the tweet by each word
        char* tempWord;
        // Using strtok function from cstring to split the tweet by delimiters
        tempWord = strtok(twt,"1234567890()//^[].,;:-_?!@&#&*+=`~\"% "); 
        //iterating through the tweet
        while(tempWord != nullptr) {
            //take out neutral buffer words ex: a, as,
            if(strlen(tempWord) > 3) {
               //check if the tweet is positive or negative
                if(s == 0){
                    mapy[tempWord]-=1;
                }
                else {
                    mapy[tempWord]+=1;
                }
            }
            //moves the buffer to the next line and sets the delimiter
            tempWord = strtok(nullptr,"1234567890()//^[].,;:-_?!@&#&*+=`~\"% ");
        }
    }
    train.close();

    // opening testing data set
    //ifstream testset("data/test_dataset_10k.csv");
    ifstream testset(argv[2]);
    // check if it opens
    if(!testset.is_open()){
        cout << "testset not open" << endl;
        return -1;
    }

    //remove first line
    testset.getline(imput, 10000);

    //creating a map to store id and sentiment
    map<char*,int> testing; //<id,sentiment>
    //totalling up the sentiments of every word in tweet
    int total;

    //move through every tweet
    while(!testset.eof()) {
        total = 0;
        testset.getline(imput, 10000, ',');
        id = imput;
        //take out the useless content
        testset.getline(imput, 10000, ',');
        testset.getline(imput, 10000, ',');
        testset.getline(imput, 10000, ',');
        //take the tweet
        testset.getline(imput, 10000, '\n');
        twt = imput;

        //split tweet into words by delimiter
        char* bufferWord;
        bufferWord = strtok(twt,"1234567890()//^[].,;:-_?!@&#&*+=`~\"% ");
        while(bufferWord != nullptr) {
            if(strlen(bufferWord) > 3) {
                //take out neutural buffer words ex: a, as,
                if (mapy[bufferWord] >= 100)
                    total += mapy[bufferWord];
            }
            //moves the buffer to the next line and sets the delimiter
            bufferWord = strtok(nullptr,"1234567890()//^[].,;:-_?!@&#&*+=`~\"% ");
        }

        //determing the tweet is positive or negitive
        if(total > 0) {
            testing[id] = 4;
        }
        if(total <= 0) {
            testing[id] = 0;
        }
    }
    testset.close();

    //Check if I got the sentiment pridiction correct
    //ifstream testscore("data/test_dataset_sentiment_100.csv");
    ifstream testscore(argv[3]);
    // check if it opens
    if(!testscore.is_open()){
        cout << "testscore not open" << endl;
        return -1;
    }

    //vector made to temporerly store all the tweets I got wrong
    vector <DSString> sadvector;
    double count = -1;
    double size = -1;
    testscore.getline(imput, 10000);//remove first line
    while(!testscore.eof()) {
        size++;
        testscore.getline(imput, 10000, ',');
        s = atoi(imput);
        testscore.getline(imput, 10000, '\n');
        id = imput;

        if(s == testing[id]){
            count++;
        }
        else{
            sadvector.push_back(id);
        }
    }
    testscore.close();

    //calculate the accuracy
    double accuracy = count/size;
    ofstream output(argv[4]);
    //ofstream output(argv[4], ios::out);
    if(!output.is_open()){
        cout << "output not open" << endl;
        return -1;
    }
    output << accuracy << endl;
    for(int i = 0; i < sadvector.size(); i++){
        output << sadvector[i] << endl;
    }

    output.close();


    return 0;
}
