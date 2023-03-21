#include <conio.h>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include <iostream>

// Class of functions that handles the information of individual student
class Student {
private:
    std::string mName;
    std::string mBirthday;
    std::string mAddress;
    std::string mGender;
    int mStudent_ID;
    std::string mDegree_program;
    std::string mYear_level;

public:
    Student() {}
    Student(std::string name, std::string birthday, std::string address, std::string gender, int student_id, std::string degree_program, std::string year_level)
        : mName(name), mBirthday(birthday), mAddress(address), mGender(gender), mStudent_ID(student_id), mDegree_program(degree_program), mYear_level(year_level) {}
    Student(Student& student) {
        mName = student.getName();
        mBirthday = student.getBirthday();
        mAddress = student.getAddress();
        mGender = student.getGender();
        mStudent_ID = student.getStudentID();
        mDegree_program = student.getDegreeProgram();
        mYear_level = student.getYearLevel();
    }

    std::string getName() {
        return mName;
    }
    std::string getBirthday() {
        return mBirthday;
    }
    std::string getAddress() {
        return mAddress;
    }
    std::string getGender() {
        return mGender;
    }
    int getStudentID() {
        return mStudent_ID;
    }
    std::string getDegreeProgram() {
        return mDegree_program;
    }
    std::string getYearLevel() {
        return mYear_level;
    }

    void setName(std::string name) {
        mName = name;
    }
    void setBirthday(std::string birthday) {
        mBirthday = birthday;
    }
    void setAddress(std::string address) {
        mAddress = address;
    }
    void setGender(std::string gender) {
        mGender = gender;
    }
    void setStudentID(int student_id) {
        mStudent_ID = student_id;
    }
    void setDegreeProgram(std::string degree_program) {
        mDegree_program = degree_program;
    }
    void setYearLevel(std::string year_level) {
        mYear_level = year_level;
    }
};

//Class of functions that handles the information of the student; involving choices
class StudentChoiceHandler {
public:
    /*
     * @brief This function displays the gender choices.
     */
    void displayGenderChoices() {
        std::cout << "> Gender:" << std::endl;
        std::cout << "  [1] MALE" << std::endl;
        std::cout << "  [2] FEMALE" << std::endl;
    }
    /*
     * @brief This function displays the degree program choices.
     */
    void displayDegreeProgramChoices() {
        std::cout << "> Degree Program:" << std::endl;
        std::cout << "  [1] BSCS" << std::endl;
        std::cout << "  [2] BSIT" << std::endl;
        std::cout << "  [3] BMMA" << std::endl;
        std::cout << "  [4] BSCE" << std::endl;
        std::cout << "  [5] BSCPE" << std::endl;
        std::cout << "  [6] BSEE" << std::endl;
        std::cout << "  [7] BSECE" << std::endl;
        std::cout << "  [8] BSME" << std::endl;
    }
    /*
     * @brief This function displays the year level choices.
     */
    void displayYearLevelChoices() {
        std::cout << "> Year Level:" << std::endl;
        std::cout << "  [1] 1ST YEAR" << std::endl;
        std::cout << "  [2] 2ND YEAR" << std::endl;
        std::cout << "  [3] 3RD YEAR" << std::endl;
        std::cout << "  [4] 4TH YEAR" << std::endl;
    }
    /*
     * @brief This function gets the gender.
     * @return The gender of the student in uppercase, or "INVALID" if the choice is invalid.
     */
    std::string getGenderChoice() {
        int choice;
        std::cout << "  Please type your selection: ";
        std::cin >> choice;

        switch (choice) {
        case (1):
            return "MALE";
        case (2):
            return "FEMALE";
        default:
            return "INVALID";
        }
    }
    /*
     * @brief This function gets the degree program.
     * @return The degree program of the student in uppercase, or "INVALID" if the choice is invalid.
     */
    std::string getDegreeProgramChoice() {
        int choice;
        std::cout << "  Please type your selection: ";
        std::cin >> choice;

        switch (choice) {
        case (1):
            return "BSCS";
        case (2):
            return "BSIT";
        case (3):
            return "BMMA";
        case (4):
            return "BSCE";
        case (5):
            return "BSCPE";
        case (6):
            return "BSEE";
        case (7):
            return "BSECE";
        case(8):
            return "BSME";
        default:
            return "INVALID";
        }
    }
    /**
     *  @brief This function gets the year level.
     *  @return The year level of the student in uppercase, or "INVALID" if the choice is invalid.
     */
    std::string getYearLevelChoice() {
        int choice;
        std::cout << "  Please type your selection: ";
        std::cin >> choice;

        switch (choice) {
        case (1):
            return "1ST YEAR";
        case (2):
            return "2ND YEAR";
        case (3):
            return "3RD YEAR";
        case (4):
            return "4TH YEAR";
        default:
            return "INVALID";
        }
    }
};

//Class of functions that handles the information of the student; not involving choices
class StudentInfoHandler {
public:
    /**
     * @brief This function gets the name and converts it to uppercase.
     * @return The name of the student in uppercase.
     */
    std::string getName() {
        std::string name;

        std::cout << "> Name: ";
        std::getline(std::cin >> std::ws, name);

        // Convert to Uppercase
        for (int i = 0; i < name.length(); i++) {
            name[i] = toupper(name[i]);
        }

        return name;
    }
    /**
     * @brief This function gets the birthday.
     * @return The birthday of the student.
     */
    std::string getBirthday() {
        std::string birthday;
        std::cout << "> Birthday (MM/DD/YYYY): ";
        std::getline(std::cin >> std::ws, birthday);

        if (birthday.length() != 10) {
            return "INVALID";
        }
        else if (birthday[2] != '/' || birthday[5] != '/') {
            return "INVALID";
        }
        else {
            int month = std::stoi(birthday.substr(0, 2));
            int day = std::stoi(birthday.substr(3, 2));
            int year = std::stoi(birthday.substr(6, 4));

            if (month < 1 || month > 12) {
                return "INVALID";
            }
            else if (day < 1 || day > 31) {
                return "INVALID";
            }
            else if (month == 2) {
                if (year % 4 == 0) {
                    if (day > 29) {
                        return "INVALID";
                    }
                }
                else {
                    if (day > 28) {
                        return "INVALID";
                    }
                }
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (day > 30) {
                    return "INVALID";
                }
            }
        }

        return birthday;
    }
    /**
     * @brief This function gets the address and converts it to uppercase.
     * @return The address of the student in uppercase.
     */
    std::string getAddress() {
        std::string address;
        std::cout << "> Address: ";
        std::getline(std::cin >> std::ws, address);

        for (int i = 0; i < address.length(); i++) {
            address[i] = toupper(address[i]);
        }

        return address;
    }
    /**
     * @brief This function gets the student ID and checks if it is valid (9 digits).
     * @return The student ID of the student, or -1 if invalid.
     */
    int getStudentID() {
        int student_id;
        std::cout << "> Student ID (XXXXXXXXX): ";
        std::cin >> student_id;

        if (student_id < 100000000 || student_id > 999999999) {
            return -1;
        }

        return student_id;
    }
};

// Class of functions that handles the student information system
class StudentRecordManager {
private:
    Student* mStudent = nullptr;
    int mStudentSize = 0;

    std::string mTxtFile = "student_record.txt";

    StudentRecordManager* mHead = nullptr;
    StudentRecordManager* mTail = nullptr;
    StudentRecordManager* mCurr = nullptr;
    StudentRecordManager* mPrev = nullptr;
    StudentRecordManager* mNext = nullptr;

public:
    bool addRecord(Student student);
    Student* searchRecord(std::string name);
    Student* searchRecord(int student_ID);
    void displayAllRecords();
    void displayRecord(Student* student);
    bool deleteRecord(int student_ID);

    void storeAllStudentInfoToFile();
    void readAllStudentInfoFromFile();
    void unloadAllStudent();

};

// Class of functions that handles the menus
class Menu {
public:
    /**
     * @brief This function displays the main menu of the program.
     * Sample:
     *  ==========================================================
     *  | WELCOME TO GROUP JOLLIBEE'S STUDENT INFORMATION SYSTEM |
     *  ==========================================================
     *  | What do you want to do?                                |
     *  |                                                        |
     *  | [1] Add New Record                                     |
     *  | [2] Display All Records                                |
     *  | [3] Display Specific Record                            |
     *  | [4] Delete Record                                      |
     *  | [5] Save & Exit                                        |
     *  ==========================================================
     */
    void displayMenu() {
        std::cout << "==========================================================" << std::endl;
        std::cout << "| WELCOME TO GROUP JOLLIBEE'S STUDENT INFORMATION SYSTEM |" << std::endl;
        std::cout << "==========================================================" << std::endl;
        std::cout << "| What do you want to do?                                |" << std::endl;
        std::cout << "|                                                        |" << std::endl;
        std::cout << "| [1] Add New Record                                     |" << std::endl;
        std::cout << "| [2] Display All Records                                |" << std::endl;
        std::cout << "| [3] Display Specific Record                            |" << std::endl;
        std::cout << "| [4] Delete Record                                      |" << std::endl;
        std::cout << "| [5] Save & Exit                                        |" << std::endl;
        std::cout << "==========================================================" << std::endl;
    }
    /**
     * @brief This function gets the choice of the user
     * @return The choice of the user
     */
    int getChoice() {
        int choice;
        std::cout << std::endl;
        std::cout << "Please type your selection: ";
        std::cin >> choice;
        return choice;
    }
    /**
     * @brief This function displays the exit message of the program and the creators of the program
     */
    void displayExit() {
        std::cout << "\nThank you for using our system!" << std::endl;
        std::cout << "\nGroup Members:" << std::endl;
        std::cout << "1. Jommel Rowin S. Sabater" << std::endl;
        std::cout << "2. Cloud Marshall Bruce Marcellana" << std::endl;
        std::cout << "3. Nadine C. Younes" << std::endl;
        std::cout << "4. Maria Teresa M. Castillo" << std::endl;
    }
    /**
     * @brief This function displays a loading animation
     */
    void displayLoading() {
        int numberOfDots = 3;
        double timeInterval;
        std::cout << std::endl << "Loading ";
        for (numberOfDots; numberOfDots >= 0; numberOfDots--) {
            {
                std::cout << ".";
                for (timeInterval = 0; timeInterval <= 100000000; timeInterval++);
            }
        }
    }

    /**
     * @brief This function pauses the program until the user presses any key
     */
    void pause() {
        std::cout << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        _getch();
    }
};

int main()
{
    StudentRecordManager studentRecordManager;
    studentRecordManager.readAllStudentInfoFromFile();

    Menu menu;
    int choice;
    do {
        system("CLS"); system("color 0B");

        menu.displayMenu(); //Display menu
        choice = menu.getChoice(); //Get user's choice

        menu.displayLoading();

        switch (choice) {
        case (1): {
            system("CLS"); system("color 0C");
            StudentInfoHandler studentInfoHandler;
            StudentChoiceHandler studentChoiceHandler;

            Student student;

            std::cout << "==================" << std::endl;
            std::cout << "| ADD NEW RECORD |" << std::endl;
            std::cout << "==================" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter the following information: " << std::endl;
            student.setName(studentInfoHandler.getName());
            student.setBirthday(studentInfoHandler.getBirthday());
            if (student.getBirthday() == "INVALID") { //If the birthday is invalid, it will not add the record
            	std::cout << "Invalid input. Try again!" << std::endl;
            	menu.pause();
            	menu.displayLoading();
            	break;
            }
            student.setAddress(studentInfoHandler.getAddress());
            studentChoiceHandler.displayGenderChoices();
            student.setGender(studentChoiceHandler.getGenderChoice());
            if (student.getGender() == "INVALID") { //If the gender is invalid, it will not add the record
                std::cout << "Invalid input. Try again!" << std::endl;

                menu.pause();
                menu.displayLoading();
                break;
            }
            student.setStudentID(studentInfoHandler.getStudentID());
            if (student.getStudentID() == -1) { //If the student ID is invalid, it will not add the record
                std::cout << "Invalid input. Try again!" << std::endl;

                menu.pause();
                menu.displayLoading();
                break;
            }
            studentChoiceHandler.displayDegreeProgramChoices();
            student.setDegreeProgram(studentChoiceHandler.getDegreeProgramChoice());
            if (student.getDegreeProgram() == "INVALID") { //If the degree program is invalid, it will not add the record
                std::cout << "Invalid input. Try again!" << std::endl;

                menu.pause();
                menu.displayLoading();
                break;
            }
            studentChoiceHandler.displayYearLevelChoices();
            student.setYearLevel(studentChoiceHandler.getYearLevelChoice());
            if (student.getYearLevel() == "INVALID") { //If the year level is invalid, it will not add the record
                std::cout << "Invalid input. Try again!" << std::endl;

                menu.pause();
                menu.displayLoading();
                break;
            }

            if (studentRecordManager.addRecord(student)) {
                menu.displayLoading();
                std::cout << "\n\nRecord added successfully!" << std::endl;
            }
            else {
                menu.displayLoading();
                std::cout << "\n\nRecord already exists!" << std::endl;
            }

            menu.pause();
            menu.displayLoading();
            break;
        }
        case (2): {
            system("CLS"); system("color 0D");
            StudentInfoHandler studentInfoHandler;

            Student student;

            std::cout << "=======================" << std::endl;
            std::cout << "| ALL STUDENT RECORDS |" << std::endl;
            std::cout << "=======================" << std::endl;
            std::cout << std::endl;

            studentRecordManager.displayAllRecords();

            menu.pause();
            menu.displayLoading();
            break;
        }
        case (3): {
            system("CLS"); system("color 0E");
            StudentInfoHandler studentInfoHandler;

            Student student;

            std::cout << "=============================" << std::endl;
            std::cout << "| DISPLAY SPECIFIC RECORD   |" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cout << "| [1] Search by Student ID  |" << std::endl;
            std::cout << "| [2] Search by Name        |" << std::endl;
            std::cout << "=============================" << std::endl;
            int choice = menu.getChoice();
            menu.displayLoading();
            std::cout << std::endl;

            switch (choice) {
            case (1):
                std::cout << std::endl;
                std::cout << "Enter the following details:" << std::endl;;
                student.setStudentID(studentInfoHandler.getStudentID());
                menu.displayLoading();
                studentRecordManager.displayRecord(studentRecordManager.searchRecord(student.getStudentID()));
                break;
            case (2):
                std::cout << std::endl;
                std::cout << "Enter the following details:" << std::endl;
                student.setName(studentInfoHandler.getName());
                menu.displayLoading();
                studentRecordManager.displayRecord(studentRecordManager.searchRecord(student.getName()));
                break;
            default:
                std::cout << "Invalid input. Try again!" << std::endl;
                break;

            }
            menu.pause();
            menu.displayLoading();
            break;
        }
        case (4): {
            system("CLS"); system("color 0F");
            StudentInfoHandler studentInfoHandler;

            Student student;

            std::cout << "=========================" << std::endl;
            std::cout << "| DELETE STUDENT RECORD |" << std::endl;
            std::cout << "=========================" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter the following information: " << std::endl;
            student.setStudentID(studentInfoHandler.getStudentID());
            if (studentRecordManager.deleteRecord(student.getStudentID())) {
                menu.displayLoading();
                std::cout << "\n\nRecord deleted successfully!" << std::endl;

                menu.pause();
                menu.displayLoading();
            }
            else {
                menu.displayLoading();
                std::cout << "\n\nRecord not found or invalid student ID!" << std::endl;

                menu.pause();
                menu.displayLoading();
            }
            break;
        }
        case (5): {
            system("CLS"); system("color 0A");
            studentRecordManager.storeAllStudentInfoToFile();
            studentRecordManager.unloadAllStudent();
            menu.displayExit();
            break;
        }
        }
    } while (choice != 5);
    return 0;
}


/**
* @brief This function is used to add a student to the record manager.
* @param student - Student to add to record manager.
* @return True if successful false otherwise. This function is used to add a student to the record manager
*/
bool StudentRecordManager::addRecord(Student student) {
    // If student ID is already in the record
    for (mCurr = mHead; mCurr != nullptr; mCurr = mCurr->mNext) {
        if (mCurr->mStudent->getStudentID() == student.getStudentID()) {
            return false;
        }
    }

    // If the the student record is empty
    if (mHead == nullptr) {
        mHead = new StudentRecordManager();
        mHead->mStudent = new Student(student);
        mStudentSize++;
        return true;
    }

    // If the student record is not empty
    for (mCurr = mHead; mCurr->mNext != nullptr; mCurr = mCurr->mNext) {}

    mTail = new StudentRecordManager();
    mTail->mPrev = mCurr;
    mCurr->mNext = mTail;
    mTail->mStudent = new Student(student);
    mStudentSize++;

    return true;
}

/**
* @brief This function is used to search for a student record by name.
* @param name - Name of student to search for.
* @return The pointer to the student if found, nullptr otherwise.
*/
Student* StudentRecordManager::searchRecord(std::string name) {
    mCurr = mHead;
    while (mCurr != nullptr) {

        if (mCurr->mStudent->getName() == name) {
            return mCurr->mStudent;
        }
        mCurr = mCurr->mNext;
    }
    return nullptr;
}


/**
* @brief This function is used to search for a student record by student ID.
* @param student_ID - The Student ID to search for.
* @return The pointer to the student if found, nullptr otherwise.
*/
Student* StudentRecordManager::searchRecord(int student_ID) {
    mCurr = mHead;
    while (mCurr != nullptr) {

        if (mCurr->mStudent->getStudentID() == student_ID) {
            return mCurr->mStudent;
        }
        mCurr = mCurr->mNext;
    }
    return nullptr;
}

/**
 * @brief This function is used to display all student records.
 * Sample:
 *     > If there is a record with student ID 201900001 and name John Doe, it will display:
 *          [1]   201900001 : John Doe
 *          [2]   201900002 : Jane Doe...
 *     > If there is no record, it will display:
 *          No records found!
 */
void StudentRecordManager::displayAllRecords() {
    mCurr = mHead;
    if (mCurr == nullptr) {
        std::cout << "No records found!" << std::endl;;
    }

    int count = 1;
    while (mCurr != nullptr) {
        std::cout << "[" << count++ << "]   " << mCurr->mStudent->getStudentID() << " : " << mCurr->mStudent->getName() << std::endl;

        mCurr = mCurr->mNext;
        count++;
    }
}

void StudentRecordManager::displayRecord(Student* student) {
    system("CLS"); system("color 09");
    std::cout << "==========================" << std::endl;
    std::cout << "| DISPLAY STUDENT RECORD |" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << std::endl;

    if (student == nullptr) {
        std::cout << "No records found!" << std::endl;
        return;
    }

    std::cout << "Student ID: " << student->getStudentID() << std::endl;
    std::cout << "Name: " << student->getName() << std::endl;
    std::cout << "Gender: " << student->getGender() << std::endl;
    std::cout << "Birthday: " << student->getBirthday() << std::endl;
    std::cout << "Address: " << student->getAddress() << std::endl;
    std::cout << "Degree Program: " << student->getDegreeProgram() << std::endl;
    std::cout << "Year Level: : " << student->getYearLevel() << std::endl;
}

/**
 * @brief This function is used to delete a student record by student ID.
 * @param student_ID - The student ID of the student record to be deleted.
 * @return true if the record is deleted successfully; else, false.
 */
bool StudentRecordManager::deleteRecord(int student_ID) {
    mCurr = mHead;
    while (mCurr != nullptr) {
        if (mCurr->mStudent->getStudentID() == student_ID) {
            if (mCurr == mHead) {
                mHead = mCurr->mNext;
                if (mHead != nullptr) {
                    mHead->mPrev = nullptr;
                }

                delete mCurr->mStudent;
                delete mCurr;

                mStudentSize--;

                return true;
            }
            else if (mCurr == mTail) {
                mTail = mCurr->mPrev;
                if (mTail != nullptr) {
                    mTail->mNext = nullptr;
                }

                delete mCurr->mStudent;
                delete mCurr;

                mStudentSize--;

                return true;
            }
            else {
                mCurr->mPrev->mNext = mCurr->mNext;
                mCurr->mNext->mPrev = mCurr->mPrev;

                delete mCurr->mStudent;
                delete mCurr;

                mStudentSize--;

                return true;
            }

        }
        mCurr = mCurr->mNext;
    }
    return false;
}

/**
 * @brief This function is used to read all student information from a text file.
 */
void StudentRecordManager::readAllStudentInfoFromFile() {
    std::ifstream file(mTxtFile);

    file.is_open();
    std::string line;
    int counter = 0;

    Student student;
    while (std::getline(file, line)) {
        if (counter == 0) {
            student.setName(line);
        }
        else if (counter == 1) {
            student.setStudentID(std::stoi(line));
        }
        else if (counter == 2) {
            student.setGender(line);
        }
        else if (counter == 3) {
            student.setBirthday(line);
        }
        else if (counter == 4) {
            student.setAddress(line);
        }
        else if (counter == 5) {
            student.setDegreeProgram(line);
        }
        else if (counter == 6) {
            student.setYearLevel(line);
            addRecord(student);
            counter = -1;
        }
        counter++;
    }

    file.close();
}

/**
 * @brief This function is used to store all student information to a text file.
 */
void StudentRecordManager::storeAllStudentInfoToFile() {
    std::ofstream file(mTxtFile);

    if (mHead == nullptr) {
        return;
    }

    for (mCurr = mHead; mCurr != nullptr; mCurr = mCurr->mNext) {
        file << mCurr->mStudent->getName() << std::endl;
        file << mCurr->mStudent->getStudentID() << std::endl;
        file << mCurr->mStudent->getGender() << std::endl;
        file << mCurr->mStudent->getBirthday() << std::endl;
        file << mCurr->mStudent->getAddress() << std::endl;
        file << mCurr->mStudent->getDegreeProgram() << std::endl;
        file << mCurr->mStudent->getYearLevel() << std::endl;
    }

    file.close();
}

/**
 * @brief This function is used to unload all student records.
 */
void StudentRecordManager::unloadAllStudent() {
    while (mHead != nullptr) {
        mCurr = mHead;
		mHead = mHead->mNext;
		delete mCurr->mStudent;
		delete mCurr;
    }
}
