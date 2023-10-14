#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream inputFile;
    inputFile.open("input.txt");

    if (!inputFile.is_open()) {
        cout << "oshibka pri otkritii inhodnogo faila" << endl;
        return 1;
    }
    cout << "vvedite stroki (dla zavershenia vvedite pystyu stroky) :\n ";
    string line;

    while (true) {
        getline(cin, line);
        if (line.empty()) {
            break;
        }
        inputFile << line << endl;
    }
    inputFile.close();



    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cout << "oshibka pri open outhodnogo faila" << endl;
        return 1;
    }

    ifstream inputFileForReading("input.txt");
    if (!inputFileForReading.is_open()) {
        cout << "oshibka pri open inhodnogo faila" << endl;
        return 1;
    }



    string LineNow;
    string preLine = "";
    int lineCount = 0;
    vector<string> groupLines;
    // Перебор строк во входном файле
    while (getline(inputFileForReading, LineNow)) {
        lineCount++;

        // Если текущая строка совпадает с предыдущей, добавляем ее в группу
        if (LineNow == preLine) {
            groupLines.push_back(LineNow);
        }
        else {
            // Новая группа строк начинается, выводим информацию о предыдущей группе (если есть)
            if (!groupLines.empty()) {
                outputFile << "gruppa strok, nachinaya s nomera " << (lineCount - groupLines.size()) << ":\n";
                for (const string& groupLine : groupLines) {
                    outputFile << groupLine << endl;
                }
                if (groupLines.size() != 1) {
                    outputFile << "kolichestvo povtorenii: " << groupLines.size() << "\n\n";
                }
            }
            groupLines.clear();
            groupLines.push_back(LineNow);
        }
        preLine = LineNow;
    }

    // Проверка, возможно последняя группа строк не была выведена
    if (!groupLines.empty()) {
        outputFile << "gruppa strok, nachinaya s nomera " << (lineCount - groupLines.size()) << ":\n";
        for (const string& groupLine : groupLines) {
            outputFile << groupLine << endl;
        }
        outputFile << "kolichestvo povtorenii: " << groupLines.size() << "\n\n";
    }

    inputFileForReading.close();  
    outputFile.close();         

    ifstream outputFileForReading("output.txt");
    string str;
    while (getline(outputFileForReading, str)) {
        cout << str << endl;
    }
        outputFile.close();
    }
