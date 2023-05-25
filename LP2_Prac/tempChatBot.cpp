#include<bits/stdc++.h>
using namespace std;

class Question{
public:
    string query, answer;
    Question(){
        query = answer = "" ;
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
        if(!input.empty() && input.back() == '?') return true;
        return false;
    }
    bool check(string input){
        for(auto ques: questionList){
            if(input == ques.query) return true;
        } 
        return false;
    }
    void reply(string input){
        for(auto ques: questionList){
            if(input == ques.query){
                cout << ques.answer << endl;
                return;
            }
        } 
    }
    void addNewQuestions(string input){
        string ans;
        cout << "Help us answer that!" << endl << input << endl;
        getline(cin, ans);
        Question ques(input,ans);
        questionList.push_back(ques);
        saveQuestionToFile();
    }
    void loadQuestionsFromFile(){
        ifstream inputFile("QA.txt");
        string tempQ, tempA;
        while(getline(inputFile, tempQ, ';') && getline(inputFile, tempA)){
            Question tempQues(tempQ, tempA);
            questionList.push_back(tempQues);
        }
        inputFile.close();
    }
    void saveQuestionToFile(){
        ofstream outputFile("QA.txt", ios::app);
        if(outputFile.is_open()){
            Question tempQues = questionList.back();
            outputFile << tempQues.query << ';' << tempQues.answer<< endl;
        }       
        else{
            cout << "ERROR! File cannot be opened." << endl;
        }
        return;
    }

};
int main(){
    Chat chat;
    string input;
    while(true){
        cout << "How may I help you?" << endl;
        getline(cin, input);
        if(chat.isQuestion(input)){
            if(chat.check(input)){
                chat.reply(input);
            }
            else{
                chat.addNewQuestions(input);
            }
        }
        else{
            cout << "Invalid format! End question with '?'" << endl;
        }
    }
    return 0;
}

/*

void addNewQuestion(string input){
    string ans;
    cout << "Help us with that answer!" << endl << input << endl;
    getline(cin, ans);
    Question q(input, ans);
    questionList.push_back(q);
    saveQuestionToFile();
}

void saveQuestionToFile(){
    outstream outputFile("QA.txt", ios::app);
    Question q = questionList.back();
    if(outputFile.is_open()){
        outputFile << q.query << ";" << q.answer << endl;
    }
    else{
        cout << "ERROR! File cannot be opened." << endl;
    }
    return;

}

void loadQuestionsFromFile(){
    ifstream inputFile("QA.txt");
    string tempQ, tempA;
    
    while(getline(inputFile, tempQ, ';') && getline(inputFile, tempA)){
        Question tempQuestion(tempQ, tempA);
        questionList.push_back(tempQuestion);
    }
    inputFile.close();
}

*/