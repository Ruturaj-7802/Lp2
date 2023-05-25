#include<bits/stdc++.h>
using namespace std;

class Question{
public:
    string query, answer;
    Question(){
        query = answer = "";
    }
    Question(string q, string a){
        query = q;
        answer = a;
    }
};

class Chat{
public:
    vector<Question> questionList;
    Chat(){
        loadQuestionsFromFile();
    }
    bool isQuestion(string input){
        if(!input.empty() && input.back()=='?') return true;
        return false;
    }

    bool check(string input){
        for(auto question : questionList){
            if(question.query == input) return true;
        }
        return false;
    }
    
    void reply(string input){
        for(auto question: questionList){
            if(input == question.query){
                cout << question.answer << endl;
                break;
            }
        }
        return;
    }

    void storeNewQuestions(string input){
        string answer;
        cout << "Help us with answer to that!" << endl << input << endl;
        getline(cin, answer);

        Question newQues(input, answer);
        questionList.push_back(newQues);
        saveQuestionsToFile();
    }

    void loadQuestionsFromFile(){
        ifstream inputFile("QA.txt");
        string tempQ, tempA;

        while(getline(inputFile, tempQ, ';') && getline(inputFile, tempA)){
            Question questionLoad(tempQ, tempA);
            questionList.push_back(questionLoad);
        }
        inputFile.close();
    }
    
    void saveQuestionsToFile(){
        ofstream outputFile("QA.txt", ios::app);
        if(outputFile.is_open()){
            Question question = questionList.back();
            outputFile << endl << question.query << ';' << question.answer;
        }
        else{
            cout << "ERROR! File cannot be opened." << endl;
        }
        outputFile.close();
    }
};

int main(){
    Chat chat;
    string input;
    while(true){
        cout << "How may I help you?" << endl;
        getline(cin, input);
        for(auto c: input) c = tolower(c);
        if(chat.isQuestion(input)){
            if(chat.check(input)){
                chat.reply(input);
            }
            else{
                chat.storeNewQuestions(input);
            }
        }
        else{
            cout << "invalid Format! End question with '?'" << endl;
        }
    }
    return 0;
}