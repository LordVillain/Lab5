
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile;
    ofstream outputFile;

    char c;
    cout << "otrkryt input?(y/n)\n";
    cin >> c;
    if (c == 'y')
        inputFile.open("input.txt");

    cout << "otrkryt output?(y/n)\n";
    cin >> c;
    if (c == 'y')
        outputFile.open("output.txt");

    if (!inputFile.is_open()) {
        cout << "oshibka pri otkritii inhodnogo faila" << endl;
        return 0;
    }

    if (!outputFile.is_open()) {
        cout << "oshibka pri open outhodnogo faila" << endl;
        return 0;
    }

    string line;

    int startline = 0;
    int counter = 0;
    string text = "#";
    int i = 0;
    while (true) {
        getline(inputFile, line);
        if (line.empty()) {
            //if (counter > 1)
            outputFile << "nomer stroki:\n" << startline << "\nkol-vo:\n" << counter << "\ntext:\n" << text << "\n\n\n";
            break;
        }
        if (line == text || text == "#") {
            counter++;
            text = line;
        }
        else {
            //if (counter > 1)
            outputFile << "nomer stroki:\n" << startline << "\nkol-vo:\n" << counter << "\ntext:\n" << text << "\n\n\n";
            counter = 1;
            startline = i;
            text = line;
        }
        i++;
    }

    inputFile.close();
    outputFile.close();

    ifstream inputFile2;
    ifstream outputFile2;
    inputFile2.open("input.txt");
    outputFile2.open("output.txt");

    cout << "faily obrabotany.\nposmotret input?(y/n)";
    cin >> c;
    if (c == 'y'){
        while (true) {
            getline(inputFile2, line);
            if (line.empty()) {
                break;
            }
            cout << line << "\n";
        }
    }

    cout << "\nposmotret output?(y/n)";
    cin >> c;
    if (c == 'y'){
        while (!outputFile2.eof()) {
            getline(outputFile2, line);
            cout << line << "\n";
        }
    }
    inputFile2.close();
    outputFile2.close();
}
