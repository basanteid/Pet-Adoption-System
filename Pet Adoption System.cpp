//كله يحط شغله هنا واسمه جمب كل حاجة عاملها 
//محدش يعدل في شغل حد حتا لو في ايرورز انا هتصرف
//قللو global variables على اد ما تقدرو

#include <iostream>
#include <cstring>
using namespace std;
bool request_decision; // used to know if user wants to purchase or not
const int no_pets = 5;
const int no_requests = 5;

struct pet
{
    string name, id;
    int price;
} pets[no_pets]; // array of pets we have
struct dob
{
    int day, month, year; // nested struct
};
struct adoption_request
{
    string request_id, user_id, pet_id;
    string status;
    dob date;
} request_arr[no_requests];

bool user_request(int i,int j)
{
    cout << "Enter user ID:\t";
    cin >> request_arr[i].user_id;
    cout << "\nEnter pet ID:\t";
    cin >> request_arr[i].pet_id;
    cout << "\n Enter the date you want to receive your pet:\t";
    cin >> request_arr[i].date.day;
    cout << " ";
    cin >> request_arr[i].date.month;
    cout << " ";
    cin >> request_arr[i].date.year;

    cout << "your pet is : " << pets[j].name << endl; // user will search for a specific pet so i means the pet he wants
    cout << "pet price is : " << pets[j].price << endl;
    cout << "Do you want to purchase this pet?(yes or no) \t";
    cin >> request_decision;
    if (request_decision)
        cout << "\nyour request has been sent successfully..please wait for response soon";

    return user_request; // 1 if he wants to purchase 0 if not
}

//John end
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pet
 {
    int pet_Id;
    string name;
    int age;
    string breed;
    bool health_Status;
    string species;
    bool availability;

    Pet(int id, string n, int a, string b, bool h, string s, bool av) {
        petId = id;
        name = n;
        age = a;
        breed = b;
        health_Status = h;
        species = s;
        availability = av;
    }

    void displayPet() {
        cout << "Pet ID: " << petId << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Breed: " << breed << endl;
        if (health_status)
        cout << "Health Status: " <<  "Good" << endl;
        else
        cout << "Health Status: " <<  "Bad" << endl;
        cout << "Species: " << species << endl;
        if (availability)
        cout << "Availability: " <<  "Available" << endl;
        else
        cout << "Availability: " <<  "Not Available" << endl;

    }
};

vector<Pet> pets;

void addPet() {
    int id, age;
    string name, breed, species;
    bool availability , health_status;

    cout << "Enter Pet ID: ";
    cin >> id;
    cout << "Enter Pet Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Pet Age: ";
    cin >> age;
    cout << "Enter Pet Breed: ";
    cin.ignore();
    getline(cin, breed);
    cout << "Enter Pet Health stauts (1 for Good, 0 for Bad): ";
    int h;
    cin >> h;
    health_status = (h == 1);
    cout << "Enter Pet Species: ";
    getline(cin, species);
    cout << "Enter Pet Availability (1 for Available, 0 for Not Available): ";
    int av;
    cin >> av;
    availability = (av == 1);

    Pet newPet(id, name, age, breed, healthStatus, species, availability);
    pets.push_back(newPet);

    cout << "Pet added successfully!" << endl;
}

void updatePet() {
    int id;
    cout << "Enter Pet ID to update: ";
    cin >> id;

    for (auto& pet : pets) {
        if (pet.petId == id) {
            cout << "Enter new Pet Name: ";
            cin.ignore();
            getline(cin, pet.name);
            cout << "Enter new Pet Age: ";
            cin >> pet.age;
            cout << "Enter new Pet Breed: ";
            cin.ignore();
            getline(cin, pet.breed);
            cout << "Enter new Pet Health Status: (1 for Good , 0 for Bad): ";
            int h;
            cin >> h;
            health_status = (h == 1);
            cout << "Enter new Pet Species: ";
            getline(cin, pet.species);
            cout << "Enter new Pet Availability (1 for Available, 0 for Not Available): ";
            int av;
            cin >> av;
            pet.availability = (av == 1);

            cout << "Pet updated successfully!" << endl;
            return;
        }
    }

    cout << "Pet not found!" << endl;
}

void deletePet() {
    int id;
    cout << "Enter Pet ID to delete: ";
    cin >> id;

    for (auto i = pets.begin(); i != pets.end(); ++i) {
        if (i->petId == id) {
            pets.erase(i);
            cout << "Pet deleted successfully!" << endl;
            return;
        }
    }

    cout << "Pet not found!" << endl;
}

void displayPets() {
    for (const auto& pet : pets) {
        pet.displayPet();
        cout << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Pet" << endl;
        cout << "2. Update Pet" << endl;
        cout << "3. Delete Pet" << endl;
        cout << "4. Display Pets" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPet();
                break;
            case 2:
                updatePet();
                break;
            case 3:
                deletePet();
                break;
            case 4:
                displayPets();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}  //BASMALA end 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	//متحطوش حاجة هنا غير الفنكشن النهائية لكل جزء بس
}
