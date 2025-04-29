//Latest Update 29/4/2025   5:57AM
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


void loadDatabase();
void saveDatabase();
void savePets(int petCount);
void loadPets();
void saveRequests(int requestCount);
void loadRequests();
void loadUsers();
void saveUsers(int userCount);

void MenuLevel2(int choice);

bool AdminLogin();
void AdminMenuLevel1();
void AdminMenuLevel2(int choiceLevel2);

void registerUser(int& userCount);
bool Userlogin(int userCount);
void UserMenuLevel1();
void UserMenuLevel2(int choiceLevel2);

void Add_Pet();
void Update_Pet();
void Display_Pets();
void Remove_Pet();
void Display_One_Pet(int index);
void Pet_Search(int petCount);
void New_Adoption_Request();
void Display_All_Requests(int& requestCount);
void Display_Pending_Requests(int& requestCount);
void Modify_Request_Status();
void Remove_Pet(int petid);
void Requests_Management_Menu();

const int MAX = 100;
int petCount = 0;
int userCount = 0;
int requestCount = 0;
int LoggedUserID = 0;

struct Pet
{
    int id;
    string name;
    int age;
    string breed;
    bool health_Status;
    string species;
    bool availability;
}pets[MAX];// array of pets we have

struct AdoptionRequest {
    int requestID;
    int userID;
    int petID;
    string status;
    string date;
    string experience;
}Requests[MAX];

struct User {
    string username;
    bool role; //1=adopter 0=caretaker
    string password;
    string email;
    long long phone;
    int ID;
} users[MAX];

//Hind begin
// Loads user data from file at startup
void loadUsers() {
    ifstream file("users.txt");
    if (!file) {
        cout << "No existing user data found. Starting fresh." << endl;
        return;
    }

    file >> userCount;
    while (file >> users[userCount].role >> users[userCount].username >> users[userCount].password) {

        userCount++;
        if (userCount >= MAX) break;
    }

    file.close();
}

// Saves all user data before exiting
void saveUsers(int userCount) {
    string username, password;
    ofstream file("users.txt", ios::app);
    if (!file) {
        cout << "Error saving user data!" << endl;
        return;
    }
    file << userCount << endl;
    for (int i = 0; i < userCount; i++) {
        file << users[userCount].role<< users[i].username << " " << users[i].password << endl;
    }

    file.close();
}


// Handles user registration
void registerUser(int& userCount) {
    if (userCount >= MAX) {
        cout << "User limit reached! Cannot register more users." << endl;
        return;
    }
    cout << "select your role (0 for caretaker || 1 for adopter): ";
    cin >> users[userCount].role;
    cout << "select a username: ";
    cin >> users[userCount].username;
    cout << "enter ID: ";
    cin >> users[userCount].ID;
    cout << "select a password: ";
    cin >> users[userCount].password;
    cout << "enter email: ";
    cin >> users[userCount].email;
    cout << "enter phone number: ";
    cin >> users[userCount].phone;
    cout << "User registered successfully! Now, you can login." << endl;
    userCount++;
}

//// Handles user login
bool Userlogin(int userCount) {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            LoggedUserID = users[i].ID;
            UserMenuLevel1();
         
            return true;
        }
    }

    cout << "Incorrect Information. Try Again." << endl;
    return false;
}

////Hind end

////John begin
//???????????????????????????????????????????????
////John end


////Basmala begin
void Add_Pet()
{
    if (petCount < MAX - 1)
    {
        cout << "Enter Pet ID: " << "\n";
        cin >> pets[petCount].id;
        if (cin.fail())
            cout << "INVALID CHOICE!!";
        cout << "Enter Pet Name: " << "\n";
        cin >> pets[petCount].name;
        cout << "Enter Pet Age: " << "\n";
        cin >> pets[petCount].age;
        if (cin.fail())
            cout << "INVALID CHOICE!!";
        cout << "Enter Pet Breed: " << "\n";
        cin >> pets[petCount].breed;
        if (cin.fail())
            cout << "INVALID CHOICE!!";
        cout << "Enter Pet Health status (1 for Good , 0 for Bad ) : " << "\n";
        int h;
        cin >> h;
        if (cin.fail())
            cout << "INVALID CHOICE!!";
        pets[petCount].health_Status = (h == 1);
        cout << "Enter Pet Species : " << "\n";
        cin >> pets[petCount].species;
        cout << "Enter Pet Availability (1 for Available , 0 for Not Available ) : " << "\n";
        int av;
        cin >> av;
        if (cin.fail())
            cout << "INVALID CHOICE!!";
        pets[petCount].availability = (av == 1);
        petCount++;
        cout << "Pet Added successfully!" << "\n";
    }
    else
    {
        cout << "The stock is full!" << "\n";
    }

}
void Update_Pet()
{
    int id;
    cout << "Enter Pet ID to update: " << "\n";

    cin >> id;
    for (int i = 0; i < petCount; i++)
    {
        if (pets[i].id == id)
        {
            int choiceUpdate;
            cout << "What do you want to update?\n";
            cout << "1) Name\n";
            cout << "2) Age\n";
            cout << "3) Breed\n";
            cout << "4) Health Status\n";
            cout << "5) Availability\n";

            cin >> choiceUpdate;
            if (cin.fail())
                cout << "Invalid Choice";
            switch (choiceUpdate)
            {
            case 1:
                cout << "Enter new Pet Name: ";
                cin >> pets[i].name;
                break;
            case 2:
                cout << "Enter new Pet Age: ";
                cin >> pets[i].age;
                if (cin.fail())
                    cout << "Invalid Age!";
                break;
            case 3:
                cout << "Enter new Pet Breed: ";
                cin >> pets[i].breed;
                break;
            case 4:
                cout << "Enter new Pet Health status (1 for Healthy , 0 for Unhealthy): ";
                int h;
                cin >> h;
                if (cin.fail())
                    cout << "INVALID CHOICE!!";
                pets[i].health_Status = (h == 1);
                break;
            case 5:
                cout << "Enter new Pet Availability (1 for Available , 0 for Not Available): " ;
                int av;
                cin >> av;
                if (cin.fail())
                    cout << "INVALID CHOICE!!";
                pets[i].availability = (av == 1);
                break;
            default:
                cout << "INVALID CHOICE!!";
            }
            cout << "Pet updated successfully!" << "\n";
        }
        else
        {
            cout << "Pet Not Found!" << "\n";
        }
    }
    return;
}
void Display_Pets()
{
    for (int i = 0; i < petCount; i++)
    {
        if (pets[i].id != 0)
        {
            cout << "--Pet " << i + 1 << "--";
            cout << " ID: " << pets[i].id << "\n";
            cout << " Name: " << pets[i].name << "\n";
            cout << " Age: " << pets[i].age << "\n";
            cout << " Breed: " << pets[i].breed << "\n";
            cout << "Pet Health Status: " << (pets[i].health_Status ? "Healthy" : "Unhealthy") << endl;
            cout << "Pet " << i + 1 << " Species: " << "\t" << pets[i].species << "\n";
            cout << (pets[i].availability ? "Pet Available" : "Pet Not Available") << endl;
        }
    }
}
void Remove_Pet()
{
    int id;
    cout << "Enter Pet ID to remove: " << "\n";

    cin >> id;
    if (cin.fail())
        cout << "Invalid ID.";

    for (int i = 0; i < petCount; i++)
    {
        if (pets[i].id == id)
        {
            pets[i].id = 0;
            petCount--;
            cout << "Pet Removed Successfuly!" << "\n";
            break;
        }
    }
    cout << "Incorrect ID!" << "\n";
    return;
}

////Basmala end
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////Alaa begin 
void Display_One_Pet( int index)
{
    cout << "Pet ID: " << pets[index].id << endl;
    cout << "Pet Name:" << pets[index].name << endl;
    cout << "Pet Species:" << pets[index].species << endl;
    cout << "Pet Breed:" << pets[index].breed << endl;
    cout << "Pet Health Status: " << (pets[index].health_Status ? "Healthy" : "Unhealthy") << endl;
    cout << (pets[index].availability ? "Pet Available" : "Pet Not Available") << endl;

}

void Pet_Search(int petCount)
{
    string Dspecies, Dbreed;
    int maxage;
    bool found = false;
    cout << "Please Enter The Desired Species (Dog, Cat, Bird,...):\n ";//taking pet info
    cin >> Dspecies;
    cout << "Please Enter The Desired Breed (Husky, Siamese,...):\n ";
    cin >> Dbreed;
    cout << "Please Enter The Max Age (as you will be given a pet with that age or less than it):\n ";
    cin >> maxage;
    if (cin.fail())
        cout << "Invalid age\n";
    for (int i = 0; i < petCount; i++) //searching for pet
    {
        if (pets[i].availability && pets[i].species == Dspecies &&
            pets[i].breed == Dbreed && pets[i].age <= maxage)
        {
            cout << "Your Desired Pet Is Found \n";
            Display_One_Pet(i); //displaying the found pet info
            found = true;
            break;
        }
    }
    if (!found)
        cout << "No Pets Match Your Search\n";
}
//Alaa end
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////Hazem begin
//
 void Display_Request_byUserID()
{
    bool found = false;
    for (int i = 0; i < requestCount; i++)
    {
        if (Requests[i].userID == LoggedUserID)
        {
            found = true;
            cout << "Request ID: " << Requests[i].requestID << endl;
            cout << "Pet ID: " << Requests[i].petID << endl;
            cout << "Request Date: " << Requests[i].date << endl;
            cout << "Request Status: " << Requests[i].status << endl;
        }
    }
    if (!found)
        cout << "No adoption requests yet!";
}
 //Hazem end
 
////Ahmed begin
//?????????????????????????????????????
////Ahmed end

void New_Adoption_Request()
{
    if (requestCount>=MAX) {
        cout << "Max request limit reached!\n";
        return;
    }
    int petIDsearch;
    bool confirm = false;
    bool found = false;
    cout << "Enter ID for the pet you want to adopt: ";
    cin >> petIDsearch;
    for (int i = 0; i < petCount; i++)
    {
        if (petIDsearch == pets[i].id && pets[i].availability)
        {
            found = true;
            cout << "Pet Found. \nDo you want to confirm your Adoption Request?(1 to confirm || 0 to cancel)";
            cin >> confirm;
            if (confirm)
            {
                cout << "Enter Request Date: ";
                cin >> Requests[requestCount].date;
                Requests[requestCount].userID = LoggedUserID;
                Requests[requestCount].petID = pets[i].id;
                Requests[requestCount].requestID = requestCount;
                Requests[requestCount].status = "Pending";
                cout << "Congrats! Your Adoption Request has been submitted.\n";
                cout << "Your Request Info:\n";
                cout << "Request Id:" << Requests[requestCount].requestID << endl;
                cout << "Request Date: " << Requests[requestCount].date << endl;
                cout << "Requested Pet ID:" << Requests[requestCount].petID << endl;
                cout << "Request Status: " << Requests[requestCount].status << endl;
                cout << "Check Requests History to keep updated about your request status\n";
                cout << "Finally, Tell Us About Your Experience: ";
                cin >> Requests[requestCount].experience;
                cout << "Thank You!";
                requestCount++;
                break;
            }

        }
    }
    if (!found)
        cout << "Sorry! Pet Not Found.\n";
}

// Function to display all requests
void Display_All_Requests(int& requestCount) 
{
    if (requestCount == 0) {
        cout << "No adoption requests yet.\n";
        return;
    }

    cout << "--ALL Requests--\n";
    for (int i = 0; i < requestCount; i++) {
        cout << "Request no." << i << endl;
        cout << "User ID: " << Requests[i].userID << endl;
        cout << "Request ID: " << Requests[i].requestID << endl;
        cout << "Pet ID: " << Requests[i].petID << endl;
        cout << "Status: " << Requests[i].status << endl;
        cout << "Date: " << Requests[i].date << endl;
        cout << "User Experience: " << Requests[i].experience << endl;
    }
}

void Display_Pending_Requests(int& requestCount)
{
    bool found = false;
    if (requestCount == 0) {
        cout << "No adoption requests yet.\n";
        return;
    }

    for (int i = 0; i < requestCount; i++) {
        if (Requests[i].status == "Pending")
        {
            found = true;
            cout << "Request no." << i << endl;
            cout << "User ID: " << Requests[i].userID << endl;
            cout << "Request ID: " << Requests[i].requestID << endl;
            cout << "Pet ID: " << Requests[i].petID << endl;
            cout << "Status: " << Requests[i].status << endl;
            cout << "Date: " << Requests[i].date << endl;
            cout << "User Experience: " << Requests[i].experience << endl;
        }
        if (!found)
            cout << "No Pending Requests\n";
    }
}
void Remove_Pet(int petid)
{
    for (int i = 0; i < petCount; i++)
    {
        if (pets[i].id == petid)
        {
            pets[i].id = 0;
            petCount--;
            break;
        }
    }
}
void Modify_Request_Status() 
{
    int requestid;
    bool found = false;
    cout << "Enter Id of the Request you want to Modify: ";
    cin >> requestid;
    for (int i = 0; i < requestCount; i++)
    {
        if (requestid == Requests[i].requestID)
        {
            found = true;
            cout << "Request no." << i << " info\n";
            cout << "User ID: " << Requests[i].userID << endl;
            cout << "Request ID: " << Requests[i].requestID << endl;
            cout << "Pet ID: " << Requests[i].petID << endl;
            cout << "Status: " << Requests[i].status << endl;
            cout << "Date: " << Requests[i].date << endl;

            cout << "Do you want to Accept or Reject? ";
            cin >> Requests[i].status;
            if (Requests[i].status == "Accept")
            {
                Requests[i].status = "Accepted";
                Remove_Pet(Requests[i].petID);
                cout << "Request " << Requests[i].status << " Successfully!\n";

            }
            else if (Requests[i].status == "Reject")
                Requests[i].status = "Rejected";
            else
                "Invalid Modification!\n";

            return;
        }
    }
    if (!found)
        cout << "Request Id Not Found";
}
void Requests_Management_Menu() 
{
    int choice;
    do {

        cout << "Welcome Admin\n";
        cout << "Select Your Action\n";
        cout << "1) View All Requests\n";
        cout << "2) View Pending Requests ONLY\n";
        cout << "3) Modify Request Status\n";
        cout << "Any number to Exit\n";
        cin >> choice;
        if (cin.fail())
            cout << "INVALID CHOICE!!";
        switch (choice)
        {
        case 1: 
            Display_All_Requests(requestCount);
            break;
        case 2: 
            Display_Pending_Requests(requestCount);
            break;
        case 3: 
            Modify_Request_Status();
            break;
        }
    } while (choice == 1 || choice == 2 || choice == 3);
}

void AdminMenuLevel1()
{
    int choiceLevel2;
    do {

        cout << "Welcome Admin\n";
        cout << "Select Your Action\n";
        cout << "1) Pet Stock Management\n";
        cout << "2) Requests Management\n";
        cout << "3) Notify Applicants\n";
        cout << "Any number to Exit\n";
        cin >> choiceLevel2;
        if (cin.fail())
            cout << "INVALID CHOICE!!\n";
        AdminMenuLevel2(choiceLevel2);
    } while (choiceLevel2 == 1 || choiceLevel2 == 2 || choiceLevel2 == 3);

}

void AdminMenuLevel2(int choiceLevel2)
{
    int choicePetManagement;
    switch (choiceLevel2)
    {
    case 1:
        do
        {
            cout << "Enter Your Action\n";
            cout << "1) Display Pets\n";
            cout << "2) Add Pets\n";
            cout << "3) Update Pet\n";
            cout << "4) Remove Pets\n";

            cout << "Any number to Exit\n";
            cin >> choicePetManagement;
            if (cin.fail())
                cout << "Invalid Choice!!\n";
            if (choicePetManagement == 1)
            {
                Display_Pets();
            }
            if (choicePetManagement == 2)
            {

                Add_Pet();
            }
            if (choicePetManagement == 3)
            {
                Update_Pet();
            }
            if (choicePetManagement == 4)
            {
                Remove_Pet();
            }

        } while (choicePetManagement == 1 || choicePetManagement == 2 || choicePetManagement == 3 || choicePetManagement == 4);
        break;
    case 2:
        Requests_Management_Menu();
        break;
    case 3:
        break;
    }
}

bool AdminLogin()
{
    string AdminUsername = "Admin";
    string AdminPassword = "P@ssw0rd";
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;
    if (AdminUsername == username && AdminPassword == password)
    {
        AdminMenuLevel1();
        return true;
    }

    cout << "Incorrect Information. Try Again." << endl;
    return false;
}

void UserMenuLevel1()
{
    int choiceLevel2;
    do {

        cout << "Welcome User\n";
        cout << "Select Your Action\n";
        cout << "1) Display All Pets\n";
        cout << "2) Search for Pet\n";
        cout << "3) Submit Adoption Request\n";
        cout << "4) View All Requests\n";
        cout << "Any number to Exit\n";
        cin >> choiceLevel2;
        if (cin.fail())
            cout << "INVALID CHOICE!!\n";
        UserMenuLevel2(choiceLevel2);
    } while (choiceLevel2 == 1 || choiceLevel2 == 2 || choiceLevel2 == 3 || choiceLevel2 == 4);
}
void UserMenuLevel2(int choiceLevel2)
{
    switch (choiceLevel2)
    {
    case 1:
        Display_Pets();
        break;
    case 2: 
        Pet_Search(petCount);
        break;
    case 3: 
        New_Adoption_Request();
        break;
    case 4:  
        Display_Request_byUserID();
        break;
    }
}

void MenuLevel2(int choice)
{
    //int userCount = 0; // Declare userCount variable here
    switch (choice)
    {
    case 1:
    {
        AdminLogin();
        break;
    }
    case 2:
        registerUser(userCount); // Pass userCount as an argument without redeclaring its type
        Userlogin(userCount);
        break;
    case 3:
        Userlogin(userCount); // Pass userCount as an argument without redeclaring its type
        break;
    default:
        break;
    }
}

void savePets(int petCount)
{

}
void loadPets()
{

}
void saveRequests(int requestCount)
{

}
void loadRequests()
{

}
void loadDatabase()
{
    loadUsers();
    loadPets();
    loadRequests();
}
void saveDatabase()
{
    saveUsers(userCount);
    savePets(petCount);
    saveRequests(requestCount);
}

void main()
{
    loadDatabase();
    int level1choice;
    do
    {
        cout << "Choose what you want to do with the system: \n";
        cout << "1) Admin Login \n";
        cout << "2) User Registration \n";
        cout << "3) User Login \n";
        cout << "Any number for Exit \n";
        cin >> level1choice;
        if (cin.fail())
            cout << "INCORRECT CHOICE!!\n";
        switch (level1choice)
        {
        case 1:

            cout << "Welcome Administrator\n";
            MenuLevel2(1);
            break;

        case 2:

            cout << "Welcome to User Registration\n";
            MenuLevel2(2);
            break;

        case 3:

            cout << "Welcome to User Login\n";
            MenuLevel2(3);

            break;
        }

    } while (level1choice == 1 || level1choice == 2 || level1choice == 3);
    saveDatabase();
}