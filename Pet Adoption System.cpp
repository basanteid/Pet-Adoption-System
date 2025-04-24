//كله يحط شغله هنا واسمه جمب كل حاجة عاملها 
//محدش يعدل في شغل حد حتا لو في ايرورز انا هتصرف
//قللو global variables على اد ما تقدرو

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//Hind begin
struct User {
    string username;
    string password;
};

const int MAX_USERS = 10;
User users[MAX_USERS];
int userCount = 0;

void loadUsers();
void saveUsers();
void registerUser();
bool loggingin();
void menu();

// Loads user data from file at startup
void loadUsers() {
    ifstream file("users.txt");
    if (!file) {
        cout << "No existing user data found. Starting fresh." << endl;
        return;
    }

    userCount = 0;
    while (file >> users[userCount].username >> users[userCount].password) {
        userCount++;
        if (userCount >= MAX_USERS) break;
    }

    file.close();
}

// Saves all user data before exiting
void saveUsers() {
    string username, password;
    ofstream file("users.txt", ios::app);
    if (!file) {
        cout << "Error saving user data!" << endl;
        return;
    }

    for (int i = 0; i < userCount; i++) {
        file << users[i].username << " " << users[i].password << endl;
    }

    file.close();
}


// Handles user registration
void registerUser() {
    if (userCount >= MAX_USERS) {
        cout << "User limit reached! Cannot register more users." << endl;
        return;
    }

    cout << "Select a username: ";
    cin >> users[userCount].username;

    cout << "Select a password: ";
    cin >> users[userCount].password;

    userCount++;
    cout << "User registered successfully!" << endl;
}

// Handles user login
bool loggingin() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            return true;
        }
    }

    cout << "Incorrect Information. Try Again." << endl;
    return false;
}

// Displays menu and processes user choices
void menu() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\nSelect a choice:\n1: Register\n2: Login\n3: Exit\nYour choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            if (loggingin()) {
                cout << "Login successful!" << endl;
            }
        }
        else if (choice == 3) {
            saveUsers();
            cout << "Goodbye!" << endl;
            running = false;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
} //Hind end


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//John begin
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

//Basmala begin
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
} //Basmala end

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Alaa begin 
pet pets[100];
void display_pet_info(pet pets[], int index)
{
	cout << "Pet ID :\t" << pets[index].id << endl;
	cout << "Pet Name :\t" << pets[index].name << endl;
	cout << "Pet Species :\t" << pets[index].species << endl;
	cout << "Pet Breed :\t" << pets[index].breed << endl;
	cout << "Pet Status :\t" << pets[index].status << endl;

}

void pet_search(pet pets[], int petcount)
{
	string Dspecies, Dbreed;
	int maxage;
	bool found = false;
	cout << "Search For a Pet 🔍🔍\n";
	cout << "Please Enter The Desired Species (dog,cat,bird,...):\n ";//taking pet info
	cin >> Dspecies;
	cout << "Please Enter The Desired Breed (husky,siamese,...):\n ";
	cin >> Dbreed;
	cout << "Please Enter The Max Age (as you will be given a pet with that age or less than it):\n ";
	cin >> maxage;
	cout << "Searching For Your Pet 🐶\n";
	for (int i = 0; i < petcount; i++) //searching for pet
	{
		if (pets[i].availability && pets[i].species == Dspecies &&
			pets[i].breed == Dbreed && pets[i].age <= maxage)
		{
			cout << "Your Desired Pet Is Found \n";
			display_pet_info(pets, i); //displaying the found pet info
			found = true;
			break;
		}

	}
	if (!found)
		cout << "No Pets Match Your Search\n";

}//Alaa end

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Hazem begin
struct AdoptionRequest { 
    int requestID;
    int userID;
    int petID;
    string status;
    string date;
};

// Function to display all requests
void displayRequests(AdoptionRequest requests[], int count) {
    if (count == 0) {
        cout << "No adoption requests yet.\n";
        return;
    }

    cout << "\n--- Adoption Request History ---\n";
    for (int i = 0; i < count; ++i) {
        cout << "Request ID: " << requests[i].requestID << endl;
        cout << "User ID: " << requests[i].userID << endl;
        cout << "Pet ID: " << requests[i].petID << endl;
        cout << "Status: " << requests[i].status << endl;
        cout << "Date: " << requests[i].date << endl;
        cout << "-----------------------------\n";
    }
}

// Function to add a new adoption request
void addRequest(AdoptionRequest requests[], int& count, int maxRequests) {
    if (count >= maxRequests) {
        cout << "Max request limit reached!\n";
        return;
    }

    AdoptionRequest newRequest;
    cout << "Enter Request ID: ";
    cin >> newRequest.requestID;
    cout << "Enter User ID: ";
    cin >> newRequest.userID;
    cout << "Enter Pet ID: ";
    cin >> newRequest.petID;
    cout << "Enter Date (e.g. 2025-04-23): ";
    cin >> newRequest.date;
    newRequest.status = "Pending";

    requests[count++] = newRequest;
}

// Function to handle user interaction
void handleUserInteraction() {
    const int MAX_REQUESTS = 100;
    AdoptionRequest requests[MAX_REQUESTS];
    int count = 0;
    char choice;

    do {
        addRequest(requests, count, MAX_REQUESTS);
        displayRequests(requests, count);
        cout << "Do you want to add another request? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you! Exiting...\n";
} //Hazem end

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main()
{
    int choice;
    while (true) {
	cout << "1. Register" << "\n";
	cout << "2. Login" << "\n";
        cout << "3. Add Pet" << endl;
        cout << "4. Update Pet" << endl;
        cout << "5. Delete Pet" << endl;
        cout << "6. Display Pets" << endl;
	cout << "7. View Request History" << "\n";
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
	    case 1:
         	registerUser();
         	break;
	    case 2:
         	if (loggingin()) {
    			cout << "Login successful!" << endl;
			}
        	break;
            case 3:
                addPet();
                break;
            case 4:
                updatePet();
                break;
            case 5:
                deletePet();
                break;
            case 6:
                displayPets();
                break;
            case 7:
	 	handleUserInteraction();
		break;
	    case 8: 
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    system ("pause");
}  //Basmala,Basant

