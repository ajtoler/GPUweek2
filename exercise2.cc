#include <iostream>
using namespace std;

struct StudentInfo{
    string name;
    string email;
    string username;
    string experiment;
};

void printStudentInfo(const StudentInfo& student){
    cout << "Name: " << student.name << endl;
    cout << "Email: " << student.email << endl;
    cout << "Username: " << student.username << endl;
    cout << "Experiment: " << student.experiment << endl;
}

int main() {
    StudentInfo Andrew = {"Andrew Toler", "atoler@umass.edu", "atoler", "ATLAS"};
    StudentInfo Miranda = {"Miranda Gorsuch", "mrgorsuch@wisc.edu", "mgorsuch", "LSST DESC"};
    StudentInfo Michael = {"Michael Martinez", "mnmartinez@wisc.edu", "mmartinez", "NGVLA"};
    StudentInfo Frank = {"Frank Strug", "fstrug2@uic.edu", "fstrug", "CMS"};
    StudentInfo Elliott = {"Elliott Kauffman", "ek8842@princeton.edu", "ekauffman", "CMS"};
    StudentInfo Ameya = {"Ameya Thete", "thete@wisc.edu", "athete", "CMS"};
    StudentInfo Lael = {"Lael Verace", "lverace@wisc.edu", "lverace", "CMS"};
    StudentInfo Hayden = {"Hayden Shaddix", "hshaddix@niu.edu", "hshaddix", "ATLAS"};
    StudentInfo Fatima = {"Fatima Rodriguez", "fatima@niu.edu", "frodriguez", "ATLAS"};
    StudentInfo Ashling = {"Ashling Quinn", "aq3942@princeton.edu", "aquinn", "CMS"};
    StudentInfo Rupesh = {"Rupesh Kannan", "rupesh.kannan@wisc.edu", "rkannan", "Superconducting Quantum Computing"};
    StudentInfo Charis = {"Charis-Kleio Koraka", "charis.kleio.koraka@cern.ch", "ckoraka", "CMS"};

    printStudentInfo(Andrew);
    // printStudentInfo(Miranda);
    // printStudentInfo(Michael);
    // printStudentInfo(Frank);
    // printStudentInfo(Elliott);
    // printStudentInfo(Ameya);
    // printStudentInfo(Lael);
    // printStudentInfo(Hayden);
    // printStudentInfo(Fatima);
    // printStudentInfo(Ashling);
    // printStudentInfo(Rupesh);
    printStudentInfo(Charis);

    return 0;
}