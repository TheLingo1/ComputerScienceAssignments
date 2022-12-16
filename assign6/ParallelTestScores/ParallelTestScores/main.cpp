/*
 Program Name: Parallel Test Scores
 Date Written: 11-16-2022
 Author: Gabrieal Jimmy
 Program Purpose: This program grades students tests using their answers entered in a file. This was used to learn about arrays and pointers and reading files.
 */

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
void handleFileOpenFailure
string filename - the file name of the that had the open failure

This function handles the error messaging for a file open failure for the 
the <filename> and displays a message with the following format:

File <filename> could not be opened !
Press the enter key to continue ...

This function pauses the screen so that the end user sees the error memssage.
The function then exits the program when the user responds.
*/

void handleFileOpenFailure(string filename) {
    cout << "File " << filename << " could not be opened !" << endl;
    cout << "Press the enter key once or twice to end..." << endl;
    cin.ignore(); cin.get();
    exit(1);
}

/*
ReadInStudentNamesTo
Parameters:
string   studentNames[]       - the array to be filled with the student names by this function used by calling main
string   studentNamesFilename - The file that the student names are read from
unsigned &noStudents          - The number of students read in from the file used by calling main()

This function uses handleFileOpenFailure(string filename) to handle file open failures.

This function uses streams to fill the names array and closes the file stream when done.
The function uses to handle file open errors.
*/

void ReadInStudentNamesTo(string studentNames[], string studentNamesFilename, unsigned &noStudents) {
    ifstream studentNamesFile;
    string Name;
    *&noStudents = 0;
    studentNamesFile.open(studentNamesFilename);
    if (studentNamesFile){
        while (getline(studentNamesFile, Name)){
            if (Name != ""){
                studentNames[*&noStudents] = Name;
                *&noStudents += 1;
            }
        }
        studentNamesFile.close();
    } else {
        handleFileOpenFailure(studentNamesFilename);
    }
}

/*
ReadInFileLinesTo
Parameter
char   dataArray[] - The data array to be filled at each element by a line entry in the file
string filenameStr - The file name used to get the information

This function uses handleFileOpenFailure(string filename) to handle file open failures.

This function reads in each line entry from the file into an element in the data array  
*/

void ReadInFileLinesTo(char dataArray[], string filenameStr){
    ifstream inFile;
    inFile.open(filenameStr);
    string c;
    int index = 0;
    if (inFile){
        while (getline(inFile, c)){
            dataArray[index] = c[0];
            index++;
        }
        inFile.close();
    } else {
        handleFileOpenFailure(filenameStr);
    }
}

/*
string ProcessCreateReportStringFor
unsigned studentNo          - the currect student no used to create the report string 
unsigned maximumNoQuestions - the number of questions in the test,
                              this is how many answers are accessed in the student answers array
unsigned studentQuestionNo  - the starting question number to use for accessing the student answers array
string   studentNames[]     - the current student name for the inputted student number
char     studentAnswers[]   - contains all the answers for all the students
                              contains the sets of size maximumNoQuestions to use for the current input student number
char correctAnswers[]       - contain s the correct answers for the test

This function uses handleFileOpenFailure(string filename) to handle file open failures.

This function builds a report string for the student number that is passed in by the calling function.
The report string is returned by function name to the calling programs.
*/
string ProcessCreateReportStringFor(unsigned studentNo, unsigned maximumNoQuestions, unsigned studentQuestionNo, string   studentNames[], char studentAnswers[], char correctAnswers[]) {
    
    string reportStr = "";
    uint correct = 0;
    string incorrectAnswers = "Incorrect Answers :";
    
    for (int i = 0; i < maximumNoQuestions; i++){
        if (studentAnswers[i + studentQuestionNo] == correctAnswers[i]){
            correct++;
        } else {
            incorrectAnswers += " " + to_string(i + 1) + " (" + studentAnswers[i + studentQuestionNo] + "/" + correctAnswers[i] + ")";
        }
    }
    if (correct == maximumNoQuestions){
        incorrectAnswers += " None";
    }
    int percent = ((float)correct/maximumNoQuestions) * 100;
    reportStr += "Student Number : " + to_string(studentNo + 1) + "\n";
    reportStr += "Student Name : " + studentNames[studentNo] + "\n";
    reportStr += "Amount Correct : " + to_string(correct) + "\n";
    reportStr += "Percent Score : " + to_string(percent) + "\n";
    reportStr += incorrectAnswers + "\n";
    if (percent >= 70){
        reportStr += "Student Passed.\n";
    } else {
        reportStr += "Student not passed.\n";
    }
    
    return (reportStr);
}

int main() {

  const string STUDENT_NAMES_FILENAME   = "StudentNames.txt";
  const string CORRECT_ANSWERS_FILENAME = "CorrectAnswers.txt";
  const string STUDENT_ANSWERS_FILENAME = "StudentAnswers.txt";
  const string STUDENT_REPORT_FILENAME  = "StudentReport.txt";

  const unsigned MAXIMUM_NUMBER_OF_STUDENTS = 10;
  string   studentNames[MAXIMUM_NUMBER_OF_STUDENTS];
  unsigned noStudents;

  const unsigned MAXIMUM_NUMBER_OF_QUESTIONS = 10;
  char     correctAnswers[MAXIMUM_NUMBER_OF_STUDENTS];
  char     studentAnswers[MAXIMUM_NUMBER_OF_STUDENTS * MAXIMUM_NUMBER_OF_QUESTIONS];
  ofstream reportFileStream(STUDENT_REPORT_FILENAME);
  if (reportFileStream.fail())
    handleFileOpenFailure(STUDENT_REPORT_FILENAME);
    
    ReadInStudentNamesTo(studentNames,   STUDENT_NAMES_FILENAME, noStudents);
    ReadInFileLinesTo(correctAnswers, CORRECT_ANSWERS_FILENAME);
    ReadInFileLinesTo(studentAnswers, STUDENT_ANSWERS_FILENAME);

  string studentReportStr;
  for (unsigned studentNo = 0, studentQuestionNo = 0;
    studentNo < noStudents;
    ++studentNo, studentQuestionNo= studentQuestionNo+MAXIMUM_NUMBER_OF_QUESTIONS) {
    studentReportStr = ProcessCreateReportStringFor(studentNo, MAXIMUM_NUMBER_OF_QUESTIONS, studentQuestionNo,
                                                    studentNames, studentAnswers, correctAnswers);
    cout             << studentReportStr << endl;
    reportFileStream << studentReportStr << endl;
  }
  reportFileStream.close();
}
