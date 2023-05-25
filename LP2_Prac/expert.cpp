#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Define the rules as functions
string rule1(const unordered_map<string, bool>& symptoms)
{
    if (symptoms.count("fever") && symptoms.count("cough"))
        return "You may have flu.";
    return "";
}

string rule2(const unordered_map<string, bool>& symptoms)
{
    if (symptoms.count("swelling") && symptoms.count("pain"))
        return "You may have a fracture.";
    return "";
}

string rule3(const unordered_map<string, bool>& symptoms)
{
    if (symptoms.count("breath problem") && symptoms.count("vomiting"))
        return "You may have cancer.";
    return "";
}

string rule4(const unordered_map<string, bool>& symptoms)
{
    if (symptoms.count("breath problem") && symptoms.count("chest problem"))
        return "You may have a heart attack.";
    return "";
}

// Define a function to perform the diagnosis
string performDiagnosis(const unordered_map<string, bool>& symptoms)
{
    vector<string> results;
    vector<string> ruleNames = {"rule1", "rule2", "rule3", "rule4"};
    vector<string> ruleDescriptions = {"flu", "fracture", "cancer", "heart attack"};

    // // Apply each rule to the symptoms and collect the results
    string res= "";
    res = rule1(symptoms);
    if(!res.empty()){
        results.push_back(res);
        res="";
    }
    res = rule2(symptoms);
    if(!res.empty()){
        results.push_back(res);
        res="";
    }
    res = rule3(symptoms);
    if(!res.empty()){
        results.push_back(res);
        res="";
    }
    res = rule4(symptoms);
    if(!res.empty()){
        results.push_back(res);
        res="";
    }

    if (results.empty())
        return "Sorry, we couldn't find your problem.";
    else if (results.size() == 1)
        return "You may have " + results[0] + ".";
    else {
        string result = "You may have multiple problems: ";
        for (const string& problem : results)
            result += problem + ", ";
        result = result.substr(0, result.length() - 2);  // Remove the trailing comma and space
        result += ".";
        return result;
    }
}

int main()
{
    unordered_map<string, bool> symptoms;

    // Display menu options
    cout << "Please select symptoms by entering the corresponding number:" << endl;
    cout << "1. Fever" << endl;
    cout << "2. Cough" << endl;
    cout << "3. Swelling" << endl;
    cout << "4. Pain" << endl;
    cout << "5. Breath problem" << endl;
    cout << "6. Vomiting" << endl;
    cout << "7. Chest problem" << endl;
    cout << "0. Finish selecting symptoms" << endl;

    // Prompt the user to select symptoms until they finish
    int choice;
    do {
        cout << "Enter your choice (0-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                symptoms["fever"] = true;
                break;
            case 2:
                symptoms["cough"] = true;
                break;
            case 3:
                symptoms["swelling"] = true;
                break;
            case 4:
                symptoms["pain"] = true;
                break;
            case 5:
                symptoms["breath problem"] = true;
                break;
            case 6:
                symptoms["vomiting"] = true;
                break;
            case 7:
                symptoms["chest problem"] = true;
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    // Perform the diagnosis and display the result
    string diagnosisResult = performDiagnosis(symptoms);
    cout << "Diagnosis: " << diagnosisResult << endl;

    return 0;
}
