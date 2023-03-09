#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include <iostream>

class Student { //Class of the student's information
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

class StudentChoiceHandler { //Class of functions that handles the information of the student; involving choices
public:
    void displayGenderChoices() {
    std::cout << "\t1. MALE" << std::endl;
    std::cout << "\t2. FEMALE" << std::endl;
    }
    void displayDegreeProgramChoices() {
        std::cout << "\t1. BSCS" << std::endl;
        std::cout << "\t2. BSIT" << std::endl;
        std::cout << "\t3. BMMA" << std::endl;
        std::cout << "\t4. BSCE" << std::endl;
        std::cout << "\t5. BSCPE" << std::endl;
        std::cout << "\t6. BSEE" << std::endl;
        std::cout << "\t7. BSECE" << std::endl;
        std::cout << "\t8. BSME" << std::endl;
    }
    void displayYearLevelChoices() {
        std::cout << "\t1. 1ST YEAR" << std::endl;
        std::cout << "\t2. 2ND YEAR" << std::endl;
        std::cout << "\t3. 3RD YEAR" << std::endl;
        std::cout << "\t4. 4TH YEAR" << std::endl;
    }

    std::string getGenderChoice() {
        int choice;
        std::cout << "\tPlease type your selection: ";
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
    std::string getDegreeProgramChoice() {
        int choice;
        std::cout << "\tPlease type your selection: ";
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
    std::string getYearLevelChoice() {
        int choice;
        std::cout << "\tPlease type your selection: ";
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

class StudentInfoHandler { //Class of functions that handles the information of the student; not involving choices
public:
    std::string getName() {
        std::string name;

        std::cout << "Name: ";
        std::getline(std::cin >> std::ws, name);

        // Convert to Uppercase
        for (int i = 0; i < name.length(); i++) {
			name[i] = toupper(name[i]);
		}

        return name;
    }
    std::string getBirthday() {
        std::string birthday;
        std::cout << "Birthday (MM/DD/YYYY): ";
        std::getline(std::cin >> std::ws, birthday);

        return birthday;
    }
    std::string getAddress() {
        std::string address;
        std::cout << "Address: ";
        std::getline(std::cin >> std::ws, address);

        // Convert to Uppercase
        for (int i = 0; i < address.length(); i++) {
            address[i] = toupper(address[i]);
        }

        return address;
    }
    int getStudentID() {
        int student_id;
        std::cout << "Student ID: ";
        std::cin >> student_id;

        if (student_id < 100000000 || student_id > 999999999) { //Checks if the student ID is valid; 9 digits
            std::cout << "Invalid Student ID" << std::endl;
            return -1;
        }

        return student_id;
    }
};

class StudentRecordManager {
private:
    Student* mStudent = nullptr;

    std::string mFileName;
    int mStudentSize;

    StudentRecordManager* mHead = nullptr;
    StudentRecordManager* mTail = nullptr;
    StudentRecordManager* mCurr = nullptr;
    StudentRecordManager* mPrev = nullptr;
    StudentRecordManager* mNext = nullptr;

public:
    bool addRecord(Student student);
    Student* searchRecord();
    void displayAllRecords();
    Student* displaySpecificRecord();
    bool deleteRecord(int temp_student_ID);
};

class Menu {
public:
    void displayMenu() {
        std::cout << "Welcome to Group Jollibee's Student Information System" << std::endl;
        
        std::cout << "\nWhat do you want to do?" << std::endl;
        std::cout << "1. Add New Record" << std::endl;
        std::cout << "2. Search Record" << std::endl;
        std::cout << "3. Display All Records" << std::endl;
        std::cout << "4. Display Specific Record" << std::endl;
        std::cout << "5. Delete Record" << std::endl;
        std::cout << "6. Exit" << std::endl;
    }

    int getChoice() {
		int choice;
		std::cout << "\nPlease type your selection: ";
        std::cin >> choice;
        return choice;
	}

    void displayExit() {
        std::cout << "\nThank you for using our system!" << std::endl;
        std::cout << "\nGroup Members:" << std::endl;
        std::cout << "1. Jommel Rowin S. Sabater" << std::endl;
        std::cout << "2. Cloud Marshall Bruce Marcellana" << std::endl;
        std::cout << "3. Nadine C. Younes" << std::endl;
        std::cout << "4. Maria Teresa M. Castillo" << std::endl;
    }

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
};

int main()
{
    StudentRecordManager studentRecordManager;

    Menu menu;
    int choice;
    do {
        system("CLS");

        menu.displayMenu(); //Display menu
        choice = menu.getChoice(); //Get user's choice

        menu.displayLoading();

        switch (choice) {
        case (1): {
            system("CLS");
            StudentInfoHandler studentInfoHandler;
            StudentChoiceHandler studentChoiceHandler;

            Student student;
            std::cout << "ADD NEW RECORD" << std::endl;

            std::cout << "\nEnter the following information: " << std::endl;
            student.setName(studentInfoHandler.getName());
            student.setBirthday(studentInfoHandler.getBirthday());
            student.setAddress(studentInfoHandler.getAddress());
            std::cout << "Gender:" << std::endl;
            studentChoiceHandler.displayGenderChoices();
            student.setGender(studentChoiceHandler.getGenderChoice());
            if (student.getGender() == "INVALID") { //If the gender is invalid, it will not add the record
                std::cout << "Invalid input. Try again!" << std::endl;

                menu.displayLoading();
                break;
            }
            student.setStudentID(studentInfoHandler.getStudentID());
            if (student.getStudentID() == -1) { //If the student ID is invalid, it will not add the record
                std::cout << "Invalid input. Try again!" << std::endl;

                menu.displayLoading();
                break;
            }
            std::cout << "Degree Program:" << std::endl;
            studentChoiceHandler.displayDegreeProgramChoices();
            student.setDegreeProgram(studentChoiceHandler.getDegreeProgramChoice());
            if (student.getDegreeProgram() == "INVALID") { //If the degree program is invalid, it will not add the record
                std::cout << "Invalid input. Try again!" << std::endl;

                menu.displayLoading();
                break;
            }
            std::cout << "Year Level:" << std::endl;
            studentChoiceHandler.displayYearLevelChoices();
            student.setYearLevel(studentChoiceHandler.getYearLevelChoice());
            if (student.getYearLevel() == "INVALID") { //If the year level is invalid, it will not add the record
                std::cout << "Invalid input. Try again!" << std::endl;

                menu.displayLoading();
                break;
            }

            if (studentRecordManager.addRecord(student)) {
                std::cout << "\n\nRecord added successfully!" << std::endl;
            }
            else {
                std::cout << "\n\nRecord already exists!" << std::endl;
            }

            menu.displayLoading();
            break;
        }
        case (2): {
            studentRecordManager.searchRecord();
            break;
        }
        case (3): {
			studentRecordManager.displayAllRecords();
			break;
        }
        case (4): {
			studentRecordManager.displaySpecificRecord();
			break;
        }
        case (5): {
            system("CLS");
            StudentInfoHandler studentInfoHandler;

            Student student;

            std::cout << "DELETE STUDENT RECORD" << std::endl;
            student.setStudentID(studentInfoHandler.getStudentID());
            if (studentRecordManager.deleteRecord(student.getStudentID())) {
                std::cout << "\n\nRecord deleted successfully!" << std::endl;
                menu.displayLoading();
            }
            else {
                std::cout << "\n\nRecord not found!" << std::endl;
                menu.displayLoading();
            }
            break;
        }
        case (6): {
			menu.displayExit();
			break;
        }
        }
    } while (choice != 6);

    return 0;
}

bool StudentRecordManager::addRecord(Student student) {
    system("CLS");
    
    //Check if student ID is already in the list
    mCurr = mHead;
    while (mCurr != nullptr) {
        if (mCurr->mStudent->getStudentID() == student.getStudentID()) {
            return false;
        }
        mCurr = mCurr->mNext;
    }

    //If the list is empty
    if (mHead == nullptr) {
        mHead = new StudentRecordManager();
        mHead->mStudent = new Student(student);
        mStudentSize++;
        return true;
    }

    //If the list is not empty
    mCurr = mHead;
    while (mCurr->mNext != nullptr) {
		mCurr = mCurr->mNext;
	}

    mTail = mCurr->mNext;
    mTail = new StudentRecordManager();
    mTail->mPrev = mCurr;
    mTail->mStudent = new Student(student);
    mStudentSize++;

    return true;
}

Student* StudentRecordManager::searchRecord() { // The same with displaySpecificRecord(); To clarify
    /*
     * ToDo: Add search student record by name
     * If Student record is not found return nullptr
     */
    int choice;

    do {
        system("CLS");

        std::cout << "SEARCH STUDENT RECORD" << std::endl;
        std::cout << "\nHow do you want to search?" << std::endl;
        std::cout << "1. Search by name" << std::endl;
        std::cout << "2. Search by student ID" << std::endl;
        std::cout << "3. Go Back" << std::endl;
        std::cout << "\nPlease type your selection: ";

        std::cin >> choice;

        switch (choice) {
        case 1: {// Search by name
            std::string temp_name;
            std::cout << "\nEnter Student's name: ";
            std::cin >> temp_name;

            mCurr = mHead;
            while (mCurr != nullptr) {
                if (mCurr->mStudent->getName() == temp_name) {
                    return mCurr->mStudent;
                }
                mCurr = mCurr->mNext;
            }
            std::cout << "\nStudent not found!" << std::endl;
            break;
        }
        case 2: { // Search by student ID
            int temp_student_ID;
            std::cout << "\nEnter the Student ID: ";
            std::cin >> temp_student_ID;

            mCurr = mHead;
            while (mCurr != nullptr) {
                if (mCurr->mStudent->getStudentID() == temp_student_ID) {
                    return mCurr->mStudent;
                }
                mCurr = mCurr->mNext;
            }
            std::cout << "\nStudent not found!" << std::endl;
            break;
        }
        case 3: { // Go Back
            std::cout << "Going Back...";
            break;
        }
        default:
            // Invalid input
            break;
        }
    } while (!(choice == 1 || choice == 2 || choice == 3));

    return nullptr;
}

void StudentRecordManager::displayAllRecords() {
    system("CLS");

    std::cout << "DISPLAY STUDENT RECORD\n" << std::endl;

    mCurr = mHead;
    if (mCurr == nullptr) {
        std::cout << "No records found!" << std::endl;;
    }

    int count = 1;
    while (mCurr != nullptr) {
        // Display record in "student number : name" format
        std::cout << count++ << "\t" << mCurr->mStudent->getStudentID() << " : " << mCurr->mStudent->getName() << std::endl;
        mCurr = mCurr->mNext;
    }
    return;
}

Student* StudentRecordManager::displaySpecificRecord() { // The same with searchRecord(); To clarify
    /*
     *ToDo: Add search student record by name
     * If Student record is not found return nullptr
     */
    int choice;

    do {
        system("CLS");

        std::cout << "SEARCH STUDENT RECORD" << std::endl;
        std::cout << "\nHow do you want to search?" << std::endl;
        std::cout << "1. Search by name" << std::endl;
        std::cout << "2. Search by student ID" << std::endl;
        std::cout << "3. Go Back" << std::endl;
        std::cout << "\nPlease type your selection: ";

        std::cin >> choice;

        switch (choice) {
        case 1: {// Search by name
            std::string temp_name;
            std::cout << "\nEnter Student's name: ";
            std::cin >> temp_name;

            mCurr = mHead;
            while (mCurr != nullptr) {
                if (mCurr->mStudent->getName() == temp_name) {
                    std::cout << "\nStudent Name: " << mCurr->mStudent->getName() << std::endl;
                    std::cout << "> Birthday: " << mCurr->mStudent->getBirthday() << std::endl;
                    std::cout << "> Address: " << mCurr->mStudent->getAddress() << std::endl;
                    std::cout << "> Gender: " << mCurr->mStudent->getGender() << std::endl;
                    std::cout << "> Student ID: " << mCurr->mStudent->getStudentID() << std::endl;
                    std::cout << "> Degree Program: " << mCurr->mStudent->getDegreeProgram() << std::endl;
                    std::cout << "> Year Level: " << mCurr->mStudent->getYearLevel() << std::endl;
                    return mCurr->mStudent;
                }
                mCurr = mCurr->mNext;
            }
            std::cout << "\nStudent not found!" << std::endl;
            break;
        }
        case 2: { // Search by student ID
            int temp_student_ID;
            std::cout << "\nEnter the Student ID: ";
            std::cin >> temp_student_ID;

            mCurr = mHead;
            while (mCurr != nullptr) {
                if (mCurr->mStudent->getStudentID() == temp_student_ID) {
                    std::cout << "\nStudent ID: " << mCurr->mStudent->getStudentID() << std::endl;
                    std::cout << "> Name: " << mCurr->mStudent->getName() << std::endl;
                    std::cout << "> Birthday: " << mCurr->mStudent->getBirthday() << std::endl;
                    std::cout << "> Address: " << mCurr->mStudent->getAddress() << std::endl;
                    std::cout << "> Gender: " << mCurr->mStudent->getGender() << std::endl;
                    std::cout << "> Degree Program: " << mCurr->mStudent->getDegreeProgram() << std::endl;
                    std::cout << "> Year Level: " << mCurr->mStudent->getYearLevel() << std::endl;
                    return mCurr->mStudent;
                }
                mCurr = mCurr->mNext;
            }
            std::cout << "\nStudent not found!" << std::endl;
            break;
        }
        case 3: { // Go Back
            std::cout << "Going Back...";
            break;
        }
        default:
            // Invalid input
            break;
        }
    } while (!(choice == 1 || choice == 2 || choice == 3));

    return nullptr;
}

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

