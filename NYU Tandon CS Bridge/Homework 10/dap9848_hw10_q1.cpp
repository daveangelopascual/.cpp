#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
void printArray(string arr[], int arrSize);
void countWord(string string, int& wordCount);


int main(){
string input = "You are doing very good ";

//cout << "Please enter a sentence with no delimiters beside a space between the words:\n";
//getline(cin, input);

int wordsInSentence = 0;
string* sentenceInArr = createWordsArray(input, wordsInSentence);
printArray(sentenceInArr, wordsInSentence);
delete [] sentenceInArr;

}

string* createWordsArray(string sentence, int& outWordsArrSize){
    int start = 0, finish, words = 0;
    countWord(sentence, words);
    string *sentenceArr = new string[words];

    while (start < sentence.length()){
        if (sentence.find(" ", start) == string::npos){
            finish = sentence.length();
        }
        else{
            finish = sentence.find(" ", start);
        }

        string word = "";
        for (start = start; start < finish; start++)
            word += sentence[start];
        
        *(sentenceArr + outWordsArrSize) = word;
        outWordsArrSize++;

        start = finish + 1;
    }
    return sentenceArr;
}

void printArray(string arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countWord(string string, int& wordCount){
    int i = 0;
    while (i < string.length()){
        if (string.find(" ", i) == string::npos)
            wordCount++;
        else{
            wordCount++;
            i = string.find(" ", i);
        }
        i++;
    }
}   