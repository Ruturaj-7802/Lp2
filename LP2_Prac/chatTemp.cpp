#include<bits/stdc++.h>
using namespace std;

class Question{
public:
    string query, answer;
    Question(){
        query = "";
        answer = "";
    }
    Question(string q, string a){
        query = q;
        answer = a;
    }
};

class Chat{
public: 
    vector<Question> quesList;
    Chat(){
        loadQuestionsFromFile();
    }

    bool isQuestion(string input){
        return (!input.empty() && input.back() == '?');
    }

    bool check(string input){
        for(auto ques : quesList){
            if(input == ques.query) return true;
        }
        return false;
    }

    void reply(string input){
        for(auto ques: quesList){
            if(input == ques.query){
                cout << ques.answer << endl;
                return;
            }
        }   
    }

    void storeNewQuestion(string input){
        string answer;
        cout << "Hmmm....nice question! Maybe you could help with this answer." << endl << input << endl;
        getline(cin, answer);
        Question newQuestion(input, answer);
        quesList.push_back(newQuestion);
        saveQuestionsToFile();
    }

    void loadQuestionsFromFile(){
        ifstream inputFile("QA.txt");
        string tempQ, tempA;

        while(getline(inputFile, tempQ, ';') && getline(inputFile, tempA)){
            Question question(tempQ, tempA);
            quesList.push_back(question);
        }
        inputFile.close();
    }

    void saveQuestionsToFile(){
        ofstream outputFile("QA.txt", ios::app);
        if(outputFile.is_open()){
            Question newQues = quesList.back();
            outputFile << endl << newQues.query << ";" << newQues.answer;
        }
        else{
            cout << "Error: File cannot be opened." << endl;
        }
        outputFile.close();
    }
};

int main(){
    Chat chat;
    string input;
    while(true){
        cout << "Hello! You can ask me anything.\n\n" << endl;
        getline(cin, input);
        for(auto c: input){
            c = tolower(c);
        }
        if(chat.isQuestion(input)){
            if(chat.check(input)){
                chat.reply(input);
            }
            else{
                chat.storeNewQuestion(input);
            }
        }
        else{
            cout << "Wrong question format! End your question with '?'" << endl;
        }
    }
    return 0;
}
