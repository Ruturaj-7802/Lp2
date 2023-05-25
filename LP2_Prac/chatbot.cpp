#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

class Question {
public:
    string query;
    string answer;

    Question() {
        query = "";
        answer = "";
    }

    Question(const string& q, const string& a) {
        query = q;
        answer = a;
    }
};

class Chat {
public:
    list<Question> questionList;

    Chat() {
        loadQuestionsFromFile();
    }

    bool isQuestion(const string& input) {
        return (!input.empty() && input.back() == '?');
    }

    bool check(const string& input) {
        for (const auto& question : questionList) {
            if (input == question.query) {
                return true;
            }
        }
        return false;
    }

    void reply(const string& input) {
        for (const auto& question : questionList) {
            if (input == question.query) {
                cout << question.answer << endl;
                return;
            }
        }
    }

    void storeNewQuestion(const string& input) {
        string answer;
        cout << "Hmmm . . . that's a good question! Maybe you could help me?" << endl << input << endl;
        getline(cin, answer);
        Question newQuestion(input, answer);
        questionList.push_back(newQuestion);
        saveQuestionsToFile();
    }

    void loadQuestionsFromFile() {
        ifstream inputFile("QA.txt");
        string tempQ;
        string tempA;

        while (getline(inputFile, tempQ, ';') && getline(inputFile, tempA)) {
            Question question(tempQ, tempA);
            questionList.push_back(question);
        }
        inputFile.close();
    }

    void saveQuestionsToFile() {
        ofstream outputFile("QA.txt", ios::app);
        if (outputFile.is_open()) {
            const Question& newQuestion = questionList.back();
            outputFile << endl << newQuestion.query << ";" << newQuestion.answer;
        } else {
            cout << "Error: File couldn't be opened." << endl;
        }
        outputFile.close();
    }
};

int main() {
    Chat chat;
    string input;
    while (true) {
        cout << "Hello! You can ask me any question" << endl;
        getline(cin, input);
        for (auto& c : input) {
            c = tolower(c);
        }
        if (chat.isQuestion(input)) {
            if (chat.check(input)) {
                chat.reply(input);
            } else {
                chat.storeNewQuestion(input);
            }
        } else {
            cout << "Wrong question format! Please end your question with a question mark (?)" << endl;
        }
    }
    return 0;
}
