/*
GROUP MEMBERS
Liben Atnafu (UGR/34815/16)
Maramawit Esualegn (Ugr/34857/16)
Mekdelawit Kornisa  (Ugr/34892/16)
Mikiyas Achamyelew (Ugr/34986/16)
Naol Asfaw (Ugr/35079/16)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
//#include <fstream>
#include <algorithm> // For std::remove_if

class Patient {
public:
    int id;
    std::string name;
    std::string diagnosis;
    std::string treatment;

    Patient(int id, std::string name, std::string diagnosis, std::string treatment)
        : id(id), name(name), diagnosis(diagnosis), treatment(treatment) {}
};

class Astu_ClinicalManagementSystem {
private:
    std::vector<Patient> patients;

    void addPatient() {
        int id;
        std::string name, diagnosis, treatment;

        std::cout << "Enter Patient ID: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Enter Patient Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Patient Diagnosis: ";
        std::getline(std::cin, diagnosis);
        std::cout << "Enter Patient Treatment: ";
        std::getline(std::cin, treatment);

        patients.emplace_back(id, name, diagnosis, treatment);
        std::cout << "Patient added successfully.\n";
    }

    void viewPatients() {
        std::cout << std::setw(5) << "ID" << std::setw(15) << "Name" << std::setw(20) << "Diagnosis" << std::setw(20) << "Treatment" << "\n";
        for (const auto& patient : patients) {
            std::cout << std::setw(5) << patient.id << std::setw(15) << patient.name << std::setw(20) << patient.diagnosis << std::setw(20) << patient.treatment << "\n";
        }
    }

    void deletePatient() {
        int id;
        std::cout << "Enter Patient ID to delete: ";
        std::cin >> id;

        auto it = std::remove_if(patients.begin(), patients.end(), [id](const Patient& patient) { return patient.id == id; });
        if (it != patients.end()) {
            patients.erase(it, patients.end());
            std::cout << "Patient deleted successfully.\n";
        } else {
            std::cout << "Patient not found.\n";
        }
    }

    void updatePatient() {
        int id;
        std::cout << "Enter Patient ID to update: ";
        std::cin >> id;
        std::cin.ignore();
	

        for (auto& patient : patients) {
            if (patient.id == id) {
                std::cout << "Enter new Patient Name: ";
                std::getline(std::cin, patient.name);
                std::cout << "Enter new Patient Diagnosis: ";
                std::getline(std::cin, patient.diagnosis);
                std::cout << "Enter new Patient Treatment: ";
                std::getline(std::cin, patient.treatment);
                std::cout << "Patient updated successfully.\n";
                return;
            }
        }
        std::cout << "Patient not found.\n";
    }
	void searchPatient(){
		std::string name;
		std::cout<< "Enter the patient Name to search:";
		std::cin>> name;
		std::cin.ignore();
		std::getline(std::cin,name);
		auto it = std::find_if(patients.begin(), patients.end(), [name](const Patient& patient) { return patient.name == name; });
        if (it != patients.end()){
			
			std::cout<< "The patient you searched for is:\n";
			std::cout<< "ID:"<< it->id<<"\n";
			std::cout<< "Name:"<< it->name<< "\n";
			std::cout<< "Diagnosis:"<< it->diagnosis<< "\n";
			std::cout<< "Treatment:"<< it->treatment<< "\n";
			
		}
	  
         else {
            std::cout << "Patient not found.\n";
        }
		
	}

public:
    void menu() {
        int choice;
        do {
            std::cout << "\nAstu_Clinical Management System\n";
            std::cout << "1. Add Patient\n";
            std::cout << "2. View Patients\n";
            std::cout << "3. Delete Patient\n";
            std::cout << "4. Update Patient\n";
			std::cout << "5. Search Patient\n";
            std::cout << "6. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: addPatient(); break;
                case 2: viewPatients(); break;
                case 3: deletePatient(); break;
                case 4: updatePatient(); break;
				case 5: searchPatient(); break;
                case 6: std::cout << "Exiting...\n"; break;
                default: std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    Astu_ClinicalManagementSystem a_cms;
   a_cms.menu();
    return 0;
}
