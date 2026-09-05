#include<bits/stdc++.h>
using namespace std;

class MCQ {
public:
    int id = 0;;
    string question;
    string options[4];
    int correctOption=0;
    string explanation;
    string subject;
};
class Attempt {
public:
    string subject;
    int score = 0;
    int total = 0;
    string date;
};

class invalid_value_exception {
    private:
    string message;
    public:
    invalid_value_exception(const string& msg) {this->message = msg;}
    string getMessage() const {return message;}
};

class ManageMcq {
    const vector<string> subjects{
        "Aptitude", "C Programming", "C++", "Java", "Python",
        "Database", "Data Structures", "Operating Systems",
        "Computer Networks", "Web Technologies"
    };
    const string historyFile = "quiz_history.txt";
    mt19937 randomGenerator;

public:
    ManageMcq() {
        randomGenerator.seed(time(0));
        for (const string& subject : subjects) {
            ofstream subjectFile(fileSafeSubject(subject), ios::app);
        }
    }

private:
    void randomizeQuestions(vector<MCQ>& questions) {
        shuffle(questions.begin(), questions.end(), randomGenerator);
    }

    static string cleanPipeFromText(string value) {
        for(auto& ch: value) {
            if(ch == '|') ch = '/';
        }
        return value;
    }

    static string fileSafeSubject(const string& subject) {
        string name = subject;
        for (char& character : name) {
            if (character == ' ') character = '_';
            else if (character == '+') character = 'p';
        }
        return "mcq_" + name + ".txt";
    }

    static vector<string> split(const string& line) {
        vector<string> fields;
        string s = "";
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '|') {
                fields.push_back(s);
                s = "";
            } else {
                s += line[i];
            }
        }
        fields.push_back(s);
        return fields;
    }

    vector<MCQ> loadQuestions(const string& subject) const {
        vector<MCQ> questions;
        ifstream input(fileSafeSubject(subject)); // input("./mcq_Cpp.txt");|| subject = C++
        string line;
        while (getline(input, line)) {
            vector<string> fields = split(line);
            if (fields.size() != 9) continue;
            try {
                MCQ question;
                question.id = stoi(fields[0]);
                question.question = fields[1];
                for (int index = 0; index < 4; ++index) question.options[index] = fields[index + 2];
                question.correctOption = stoi(fields[6]);
                question.explanation = fields[7];
                question.subject = fields[8];
                questions.push_back(question);
            } catch (...) {
                // TODO: handle exception if input is not in corect frmt
            }
        }
        return questions;
    }

    bool saveQuestions(const string& subject, vector<MCQ>& questions) const {
        ofstream output(fileSafeSubject(subject));
        if (!output) return false;
        for (MCQ& question : questions) {
            output << question.id << '|' << cleanPipeFromText(question.question);
            for (const string& option : question.options) {output << '|' << cleanPipeFromText(option);}
            output << '|' << question.correctOption << '|' << cleanPipeFromText(question.explanation) << '|' << question.subject << '\n';
        }
        return true;
    }

    static int readInteger(const string& prompt, int minimum=0, int maximum=0) {
        int value;
        cout << prompt;
        cin >> value;
        return value;
    }

    static string readText(const string& prompt) {
        cin.ignore();
        string value;
        cout << prompt;
        getline(cin, value);
        return cleanPipeFromText(value);
    }

    int chooseSubject() const {
        cout << "\nAvailable subjects\n";
        for (int index = 0; index < subjects.size(); ++index)
            cout << index + 1 << ". " << subjects[index] << '\n';
        int subjectIdx = readInteger("Choose subject: ") - 1;
        if(subjectIdx <= 0 || subjectIdx>subjects.size()) {
            throw invalid_value_exception("Enter valid subject number.\n");
        }
        return subjectIdx;
    }

    static void printQuestion(const MCQ& question, int number) {
        cout << "\nQuestion " << number << ": " << question.question << '\n';
        for (int index = 0; index < 4; ++index) {
            cout << "  " << char('A' + index) << ". " << question.options[index] << '\n';
        }
    }

    void addQuestion() {
        int subjectIndex = chooseSubject();
        vector<MCQ> questions = loadQuestions(subjects[subjectIndex]);
        MCQ question;
        question.id = questions.empty() ? 1 : questions.back().id + 1;
        question.subject = subjects[subjectIndex];
        question.question = readText("Question: ");
        for (int index = 0; index < 4; ++index) {
            string prompt = "Option ";
            prompt += char('A' + index);
            prompt += ": ";
            question.options[index] = readText(prompt); // Option A: 
        }
        question.correctOption = readInteger("Correct option (1-4): ");
        question.explanation = readText("Short explanation: ");
        questions.push_back(question);
        cout << (saveQuestions(question.subject, questions) ? "Question added.\n" : "Could not save question.\n");
    }

    void listQuestions() const {
        int subjectIndex = chooseSubject();
        vector<MCQ> questions = loadQuestions(subjects[subjectIndex]);
        if (questions.empty()) {
            cout << "No questions found for this subject.\n";
            return;
        }
        for (const MCQ& question : questions) {
            printQuestion(question, question.id);
            cout << "Correct answer: " << char('A' + question.correctOption - 1)
                 << "\nExplanation: " << question.explanation << "\n";
        }
    }

    void updateQuestion() {
        int subjectIndex = chooseSubject();
        vector<MCQ> questions = loadQuestions(subjects[subjectIndex]);
        if (questions.empty()) { cout << "No questions found for this subject.\n"; return; }
        int id = readInteger("Enter question ID to update: ");
        auto found = questions.end();
        for (auto it = questions.begin(); it != questions.end(); ++it) {
            if (it->id == id) {
                found = it;
                break;
            }
        }
        if (found == questions.end()) { cout << "Question ID not found.\n"; return; }
        found->question = readText("New question: ");
        for (int index = 0; index < 4; ++index) {
            string prompt = "New option ";
            prompt += char('A' + index);
            prompt += ": ";
            found->options[index] = readText(prompt);
        }
        found->correctOption = readInteger("New correct option (1-4): ");
        found->explanation = readText("New short explanation: ");
        cout << (saveQuestions(found->subject, questions) ? "Question updated.\n" : "Could not save question.\n");
    }

    void deleteQuestion() {
        int subjectIndex = chooseSubject();
        vector<MCQ> questions = loadQuestions(subjects[subjectIndex]);
        int id = readInteger("Enter question ID to delete: ");
        bool found = false;
        for (int i = 0; i < questions.size(); i++) {
            if (questions[i].id == id) {
                questions.erase(questions.begin() + i);
                found = true;
                break;
            }
        }
        if (!found) { cout << "Question ID not found.\n"; return; }
        cout << (saveQuestions(subjects[subjectIndex], questions) ? "Question deleted.\n" : "Could not save question bank.\n");
    }

    void viewAllQuestions() const {
        bool foundAnyQuestion = false;
        for (const string& subject : subjects) {
            vector<MCQ> questions = loadQuestions(subject);
            for (const MCQ& question : questions) {
                if (!foundAnyQuestion) cout << "\n===== MCQ LIST =====\n";
                foundAnyQuestion = true;
                cout << "\nID: " << question.id << " | Subject: " << question.subject << '\n';
                printQuestion(question, question.id);
                cout << "Correct answer: " << char('A' + question.correctOption - 1) << '\n';
            }
        }
        if (!foundAnyQuestion) cout << "No MCQs found.\n";
    }

    void viewSubjectQuestions() const {
        int subjectIndex;
        subjectIndex = chooseSubject();
       
        vector<MCQ> questions = loadQuestions(subjects[subjectIndex]);
        if (questions.empty()) {
            cout << "No questions found for this subject.\n";
            return;
        }
        cout << "\n===== " << subjects[subjectIndex] << " MCQs =====\n";
        for (const MCQ& question : questions) {
            printQuestion(question, question.id);
            cout << "Correct answer: " << char('A' + question.correctOption - 1) << "\nExplanation: " << question.explanation << "\n";
        }
    }

    void manageQuestions() {
        while (true) {
            try {
                cout << "\n================ MCQ MANAGEMENT ================\n"
                << "1. Add MCQ\n2. View All MCQs\n3. Edit MCQ\n"
                << "4. Delete MCQ\n5. View MCQs of Given Subject\n6. Back\n";
                int choice = readInteger("Enter choice: ", 1, 6);
                switch (choice) {
                    case 1: addQuestion(); break;
                    case 2: viewAllQuestions(); break;
                    case 3: updateQuestion(); break;
                    case 4: deleteQuestion(); break;
                    case 5: viewSubjectQuestions(); break;
                    case 6: return;
                }
            } catch (const invalid_value_exception& e) {
                cout << "Exception occured: " << e.getMessage(); 
            }
        }
    }

    void saveAttempt(const Attempt& attempt) const {
        ofstream output(historyFile, ios::app);
        output << attempt.subject << '|' << attempt.score << '|' << attempt.total << '|' << attempt.date << '\n';
    }

    vector<Attempt> loadAttempts() const {
        vector<Attempt> attempts;
        ifstream input(historyFile);
        string line;
        while (getline(input, line)) {
            vector<string> fields = split(line);
            if (fields.size() != 4) continue;
            try { attempts.push_back({fields[0], stoi(fields[1]), stoi(fields[2]), fields[3]}); }
            catch (...) {}
        }
        return attempts;
    }

    void startQuiz() {
        int subjectIndex = chooseSubject();
        vector<MCQ> questions = loadQuestions(subjects[subjectIndex]);
        if (questions.empty()) { cout << "No questions available for this subject.\n"; return; }
        int count = readInteger("Number of questions (1-" + to_string(questions.size()) + "): ");
        randomizeQuestions(questions);
        questions.resize(count);
        int score = 0;
        vector<int> answers;
        for (int index = 0; index < count; ++index) {
            printQuestion(questions[index], index + 1);
            int answer = readInteger("Your answer (1-4): ");
            answers.push_back(answer);
            if (answer == questions[index].correctOption) ++score;
        }
        cout << "\n===== RESULT =====\nScore: " << score << "/" << count << "\n";
        for (int index = 0; index < count; ++index) {
            cout << "\n" << index + 1 << ". " << questions[index].question
                 << "\nYour answer: " << char('A' + answers[index] - 1)
                 << "\nCorrect answer: " << char('A' + questions[index].correctOption - 1)
                 << " (" << questions[index].options[questions[index].correctOption - 1] << ")"
                 << "\nExplanation: " << questions[index].explanation << '\n';
        }
        saveAttempt({subjects[subjectIndex], score, count, "12:52:10"});
        cout << "Attempt saved to quiz_history.txt.\n";
    }

    void viewHistory() const {
        vector<Attempt> attempts = loadAttempts();
        if (attempts.empty()) {
            cout << "No quiz attempts found.\n";
            return;
        }
        cout << "\n===== QUIZ SCORE HISTORY =====\n";
        for (size_t index = 0; index < attempts.size(); ++index) {
            cout << index + 1 << ". Subject: " << attempts[index].subject
                 << " | Score: " << attempts[index].score << '/' << attempts[index].total
                 << " | Date: " << "31/09/30" << '\n';
        }
    }

    void showAnalysis() const {
        vector<Attempt> attempts = loadAttempts();
        if (attempts.empty()) {
            cout << "No quiz history available.\n";
            return;
        }

        cout << "\n===== SUBJECT-WISE ANALYSIS =====\n";

        for (const string& subject : subjects) {
            vector<Attempt> subjectAttempts;

            for (const Attempt& attempt : attempts) {
                if (attempt.subject == subject) {
                    subjectAttempts.push_back(attempt);
                }
            }

            if (subjectAttempts.empty()) continue;

            double average = 0;
            int best = 0;

            for (const Attempt& attempt : subjectAttempts) {
                average += 100.0 * attempt.score / attempt.total;

                int percent = attempt.score * 100 / attempt.total;
                if (percent > best) {
                    best = percent;
                }
            }

            cout << subject << ": " << subjectAttempts.size()
                 << " attempt(s), Best " << best << "%, Average "
                 << fixed << setprecision(1)
                 << average / subjectAttempts.size() << "%\n";
        }
    }

public:
    void run() {
        while (true) {
            cout << "\n====================================================\n"
                 << "        MCQ EXAM PREPARATION ASSISTANT\n"
                 << "====================================================\n"
                 << "1. Manage MCQs\n2. Start Random Quiz\n"
                 << "3. View Quiz Score History\n4. Subject-wise Score Analysis\n"
                 << "5. Exit\n";
            int choice = readInteger("Enter choice: ", 1, 5);
            switch (choice) {
                case 1: manageQuestions(); break;
                case 2: startQuiz(); break;
                case 3: viewHistory(); break;
                case 4: showAnalysis(); break;
                case 5: cout << "Goodbye.\n"; return;
            }
        }
    }
};

int main() {
    try {
        ManageMcq application;
        application.run();
    } catch (...) {
        cout << "\nInput closed. Application ended.\n"<<"\n";
    }
    return 0;
}