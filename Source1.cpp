//Latest Update 2/5/2025  5:00AM
#include <iostream>
#include <cstring>
#include <string>
using namespace std; 

void GetLineforStrings(string& s);
void HandleIntErrors(int& i);
void HandleIntErrors(long long& i);
void HandleBoolErrors(bool& i);

void MenuLevel2(int choice);

bool AdminLogin();
void AdminMenuLevel1();
void AdminMenuLevel2(int choiceLevel2);

bool registerUser(int& userCount);
bool Userlogin(int userCount);
void UserMenuLevel1();
void UserMenuLevel2(int choiceLevel2);
void UserMenuLevel1caretaker();

void InitializePets();
void Add_Pet();
void Update_Pet();
void Display_Pets();
void Remove_Pet();
void Display_One_Pet(int index);
void Pet_Search(int petCount);
void New_Adoption_Request();
void Display_All_Requests(int requestCount);
void Display_Pending_Requests(int requestCount);
void Modify_Request_Status();
void ShiftPets(int index);
void Remove_Pet(int petid);
void Requests_Management_Menu();

const int MAX = 100;
int petCount = 5;
int userCount = 0;
int requestCount = 0;
int LoggedUserID = 0;
bool LoggedUserRole = 0;

struct Pet
{
    int id;
    string name;
    int age;
    string breed;
    bool health_Status; //1=healthy  0=unhealthy
    string species;
    bool availability; //1=available  0= unavailable
}pets[MAX];

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
    int ID;
    bool role; //1=adopter 0=caretaker
    string password;
    string email;
    long long phone;
} users[MAX];


void GetLineforStrings(string &s) //!!!!!! fiha moshkla sa3at it ignores 1st character of the input ||| used it once fel user experience
{
    cin.ignore(); //da ashan n-clear everything for the getline to work properly
    getline(cin, s); // we used getline ashan lw eluser used spaces elsystem my3mlsh ignore lel part after space
}

void HandleIntErrors(int& i)
{
    while (true)
    {
        cin >> i;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "INVALID!! Please enter an Integer: ";

        }
        else
            break;
    }
}
void HandleIntErrors(long long& i)
{
    while (true)
    {
        cin >> i;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "INVALID!! Please enter an Integer: ";

        }
        else
            break;
    }
}
void HandleBoolErrors(bool& i)
{
    while (true)
    {
        cin >> i;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "INVALID!! Please enter 0 or 1: ";

        }
        else
            break;
    }
}

void InitializePets()
{
    //Pet 1
    pets[0].id = 111;
    pets[0].name = "MAX";
    pets[0].species = "dog";
    pets[0].breed = "husky";
    pets[0].age = 2;
    pets[0].health_Status = 1;
    pets[0].availability = 1;

    //Pet 2
    pets[1].id = 222;
    pets[1].name = "REX";
    pets[1].species = "dog";
    pets[1].breed = "bulldog";
    pets[1].age = 5;
    pets[1].health_Status = 0;
    pets[1].availability = 1;

    //Pet 3
    pets[2].id = 333;
    pets[2].name = "LUNA";
    pets[2].species = "cat";
    pets[2].breed = "siamese";
    pets[2].age = 3;
    pets[2].health_Status = 1;
    pets[2].availability = 0;

    //Pet 4
    pets[3].id = 444;
    pets[3].name = "KITTY";
    pets[3].species = "cat";
    pets[3].breed = "ragdoll";
    pets[3].age = 1;
    pets[3].health_Status = 0;
    pets[3].availability = 1;

    //Pet 5
    pets[4].id = 555;
    pets[4].name = "DORIS";
    pets[4].species = "turtle";
    pets[4].breed = "musk";
    pets[4].age = 6;
    pets[4].health_Status = 1;
    pets[4].availability = 0;
}

//Hind begin

// Handles user registration
bool registerUser(int& userCount) {
    if (userCount >= MAX) {
        cout << "User limit reached! Cannot register more users." << endl;
        return false;
    }
    cout << "select your role (0 for caretaker || 1 for adopter): ";
    HandleBoolErrors(users[userCount].role);
    cout << "select a username: ";
    cin >> users[userCount].username;
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].username == users[userCount].username)
        {
            cout << "Username Already Taken! Try Registering again with different Username\n";
            return false;
        }
    }
    cout << "enter ID: ";
    HandleIntErrors(users[userCount].ID);

    for (int i = 0; i < userCount ; i++)
    {
        if (users[i].ID == users[userCount].ID)
        {
            cout << "ID Already Taken! Try Registering again with different ID\n";
            return false;
        }
    }
    cout << "select a password: ";
    cin>>users[userCount].password;
    cout << "enter email: ";
    cin>>users[userCount].email;
    cout << "enter phone number: ";
    HandleIntErrors(users[userCount].phone);
    cout << "User registered successfully!" << endl;
    cout << "==================================================================\n\n"; 
    cout<<"Now, you can login." << endl;
    userCount++;
    return true;
}

//// Handles user login
bool Userlogin(int userCount) {
    string username, password;

    cout << "Enter username: ";
    cin>>username;

    cout << "Enter password: ";
    cin>>password;

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            LoggedUserID = users[i].ID;
            LoggedUserRole = users[i].role;
            cout << "==================================================================\n\n";
            if (LoggedUserRole) //1=adopter 0=caretaker
                UserMenuLevel1(); //adopter level1 menu
            else
                UserMenuLevel1caretaker();      
            return true;
        }
    }

    cout << "Your Email or Password is Wrong!!! Try Again." << endl;
    cout << "==================================================================\n\n";
    return false;
}

////Hind end

////John begin
//???????????????????????????????????????????????
////John end


////Basmala begin
void Add_Pet()
{
    if (petCount < MAX )
    {
        cout << "Enter Pet ID: " << "\n";
        HandleIntErrors( pets[petCount].id);
        for (int i = 0; i < petCount; i++)
        {
            if (pets[i].id == pets[petCount].id)
            {
                cout << "ID Already Taken! Try adding a pet again with different ID\n";
                return;
            }
        }
        cout << "Enter Pet Name: " << "\n";
        cin>>pets[petCount].name;
        cout << "Enter Pet Age: " << "\n";
        HandleIntErrors(pets[petCount].age);
        cout << "Enter Pet Breed: " << "\n";
        cin>>pets[petCount].breed;
        cout << "Enter Pet Health status (1 for Healthy , 0 for Unhealthy) : " << "\n";
        HandleBoolErrors( pets[petCount].health_Status);
        cout << "Enter Pet Species : " << "\n";
        cin >> pets[petCount].species;
        cout << "Enter Pet Availability (1 for Available , 0 for Not Available ) : " << "\n";
        HandleBoolErrors(pets[petCount].availability);
        petCount++;
        cout << "Pet Added successfully!" << "\n";
        cout << "==================================================================\n\n";
    }
    else
    {
        cout << "The stock is full!" << "\n";
        cout << "==================================================================\n\n";
    }

}
void Update_Pet()
{
    if (petCount == 0) 
    {
        cout << "No pets available yet.\n";
        return;
    }
    int id;
    cout << "Enter Pet ID to update: " << "\n";
    HandleIntErrors(id);

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

            HandleIntErrors(choiceUpdate);
            switch (choiceUpdate)
            {
            case 1:
                cout << "Enter new Pet Name: ";
                cin >> pets[i].name;
                break;
            case 2:
                cout << "Enter new Pet Age: ";
                HandleIntErrors(pets[i].age);
                break;
            case 3:
                cout << "Enter new Pet Breed: ";
                cin >> pets[i].breed;
                break;
            case 4:
                cout << "Enter new Pet Health status (1 for Healthy , 0 for Unhealthy): ";
                HandleBoolErrors(pets[i].health_Status);
                break;
            case 5:
                cout << "Enter new Pet Availability (1 for Available , 0 for Not Available): ";
                HandleBoolErrors(pets[i].availability);
                break;
            default:
                cout << "INVALID CHOICE!!";
                break;
            }
            cout << "Pet updated successfully!" << "\n";
            cout << "==================================================================\n\n";
            return;
        }
    }
    cout << "Pet Not Found!" << "\n";
    cout << "==================================================================\n\n";

}
void Display_Pets()
{
    if (petCount == 0) {
        cout << "No pets available yet.\n";
        cout << "==================================================================\n\n";
        return;
    }
    for (int i = 0; i < petCount; i++)
    {
        if (pets[i].id != 0)
        {
            cout << "--Pet " << i + 1 << "--\n";
            cout << "ID: " << pets[i].id << "\n";
            cout << "Name: " << pets[i].name << "\n";
            cout << "Age: " << pets[i].age << "\n";
            cout << "Breed: " << pets[i].breed << "\n";
            cout << "Health Status: " << (pets[i].health_Status ? "Healthy" : "Unhealthy") << endl;
            cout << "Species: " << pets[i].species << "\n";
            cout << (pets[i].availability ? "Pet Available" : "Pet Not Available") << endl;
            cout << "===================================\n";
        }
    }
}
void ShiftPets(int index)
{
    for (int i = index; i < petCount; i++)
    {
        pets[i].id = pets[1 + i].id;
        pets[i].name = pets[1 + i].name;
        pets[i].species = pets[1 + i].species;
        pets[i].breed = pets[1 + i].breed;
        pets[i].age = pets[1 + i].age;
        pets[i].health_Status = pets[1 + i].health_Status;
        pets[i].availability = pets[1 + i].availability;
    }
}
void Remove_Pet()
{
    if (petCount == 0) {
        cout << "No pets available yet.\n";
        cout << "==================================================================\n\n";
        return;
    }
    int id;
    cout << "Enter Pet ID to remove: " << "\n";

    HandleIntErrors(id);

    for (int i = 0; i < petCount; i++)
    {
        if (pets[i].id == id)
        {
            pets[i].id = 0;
            ShiftPets(i);
            petCount--;
            cout << "Pet Removed Successfuly!" << "\n";
            cout << "==================================================================\n\n";
            return;
        }
    }

    cout << "Incorrect ID!" << "\n";
    cout << "==================================================================\n\n";
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
    cout << "==================================================================\n\n";

}

void Pet_Search(int petCount)
{
    string Dspecies, Dbreed;
    int maxage;
    cout << "Please Enter The Desired Species (Dog, Cat, Bird,...):\n ";//taking pet info
    cin >> Dspecies;
    cout << "Please Enter The Desired Breed (Husky, Siamese,...):\n ";
    cin >> Dbreed;
    cout << "Please Enter The Max Age (as you will be given a pet with that age or less than it):\n ";
    HandleIntErrors(maxage);
    for (int i = 0; i < petCount; i++) //searching for pet
    {
        if (pets[i].availability && pets[i].species == Dspecies &&
            pets[i].breed == Dbreed && pets[i].age <= maxage)
        {
            cout << "Your Desired Pet Is Found ????\n";
            Display_One_Pet(i); //displaying the found pet info
            return;
        }
    }
    cout << "No Pets Match Your Search\n";
    cout << "==================================================================\n\n";
    return;

}
//Alaa end
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////Hazem begin
//
void Display_Request_byUserID()
{
    if (requestCount == 0) {
        cout << "No adoption requests yet.\n";
        return;
    }

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
            cout << "==================================================================\n\n";
        }
    }
    if (!found)
    {
        cout << "No adoption requests yet!\n";
        cout << "==================================================================\n\n";
    }
}
 //Hazem end
 
////Ahmed begin
//?????????????????????????????????????
////Ahmed end

void New_Adoption_Request()
{
    if (requestCount>=MAX) {
        cout << "Max request limit reached!\n";
        cout << "==================================================================\n\n";
        return;
    }
    int petIDsearch;
    bool confirm = false;
    bool found = false;
    cout << "Enter ID for the pet you want to adopt: ";
    HandleIntErrors(petIDsearch);
    for (int i = 0; i < petCount; i++)
    {
        if (petIDsearch == pets[i].id && pets[i].availability)
        {
            found = true;
            cout << "Pet Found. \nDo you want to confirm your Adoption Request?(1 to confirm || 0 to cancel)";
            HandleBoolErrors(confirm);
            if (confirm)
            {
                cout << "Enter Request Date: ";
                cin >> Requests[requestCount].date;
                Requests[requestCount].userID = LoggedUserID;
                Requests[requestCount].petID = pets[i].id;
                Requests[requestCount].requestID = requestCount;
                Requests[requestCount].status = "Pending";
                cout << "Congrats! Your Adoption Request has been submitted.\n\n";
                cout << "Your Request Info:\n";
                cout << "Request Id:" << Requests[requestCount].requestID << endl;
                cout << "Request Date: " << Requests[requestCount].date << endl;
                cout << "Requested Pet ID:" << Requests[requestCount].petID << endl;
                cout << "Request Status: " << Requests[requestCount].status << endl;
                cout << "Check Requests History to keep updated about your request status\n";
                cout << "Finally, Tell Us About Your Experience: ";
                GetLineforStrings(Requests[requestCount].experience);
                cout << "Thank You!\n";
                cout << "==================================================================\n\n";
                requestCount++;
                break;
            }

        }
    }
    if (!found)
    {
        cout << "Sorry! Pet Not Found.\n";
        cout << "==================================================================\n\n";
    }
}

// Function to display all requests
void Display_All_Requests(int requestCount) 
{
    if (requestCount == 0) {
        cout << "No adoption requests yet.\n";
        cout << "==================================================================\n\n";
        return;
    }

    cout << "--ALL Requests--\n";
    for (int i = 0; i < requestCount; i++) 
    {
        cout << "Request no." << i << endl;
        cout << "User ID: " << Requests[i].userID << endl;
        cout << "Request ID: " << Requests[i].requestID << endl;
        cout << "Pet ID: " << Requests[i].petID << endl;
        cout << "Status: " << Requests[i].status << endl;
        cout << "Date: " << Requests[i].date << endl;
        cout << "User Experience: " << Requests[i].experience << endl;
        cout << "==================================================================\n";
    }
}

void Display_Pending_Requests(int requestCount)
{
    bool found = false;
    if (requestCount == 0) {
        cout << "No adoption requests yet.\n";
        cout << "==================================================================\n\n";
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
            cout << "==================================================================\n";
        }
    }
    if (!found)
    {
        cout << "No Pending Requests\n";
        cout << "==================================================================\n\n";
    }
}
void Remove_Pet(int petid)
{
    bool found = false;
    for (int i = 0; i < petCount; i++)
    {
        if (pets[i].id == petid)
        {
            found = true;
            pets[i].id = 0;
            petCount--;
            cout << "Pet Removed Successfully!\n";
            cout << "==================================================================\n\n";
            break;
        }
    }
    if (!found)
    {
        cout << "Pet Not Found\n";
        cout << "==================================================================\n\n";
    }
}
void Modify_Request_Status() 
{
    int requestid;
    bool found = false;
    cout << "Enter Id of the Request you want to Modify: ";
    HandleIntErrors(requestid);
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
            if (Requests[i].status == "Accept"|| Requests[i].status == "accept")
            {
                Requests[i].status = "Accepted";
                Remove_Pet(Requests[i].petID);
                cout << "Request " << Requests[i].status << " Successfully!\n";

            }
            else if (Requests[i].status == "Reject"|| Requests[i].status == "reject")
                Requests[i].status = "Rejected";
            else
                "Invalid Modification!\n";

            cout << "==================================================================\n\n";
            return;
        }
    }
    if (!found)
    {
        cout << "Request Id Not Found";
        cout << "==================================================================\n\n";
    }
}
void Requests_Management_Menu() 
{
    cout << "==================================================================\n\n";
    int choice;
    do {

        cout << "Select Your Action\n";
        cout << "1) View All Requests\n";
        cout << "2) View Pending Requests ONLY\n";
        cout << "3) Modify Request Status\n";
        cout << "Any number to Exit\n";
        HandleIntErrors(choice); 
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
    cout << "==================================================================\n\n";
    cout << "Welcome Admin\n";
    int choiceLevel2;
    do {

        cout << "Select Your Action\n";
        cout << "1) Pet Stock Management\n";
        cout << "2) Requests Management\n";
        cout << "3) Notify Applicants\n";
        cout << "Any number to Exit\n";
        HandleIntErrors(choiceLevel2);
        AdminMenuLevel2(choiceLevel2);
    } while (choiceLevel2 == 1 || choiceLevel2 == 2 || choiceLevel2 == 3);

}

void AdminMenuLevel2(int choiceLevel2)
{
    cout << "==================================================================\n\n";
    int choicePetManagement = 0;
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
            HandleIntErrors(choicePetManagement);
            if (choicePetManagement == 1)
            {
                Display_Pets();
            }
            else if (choicePetManagement == 2)
            {

                Add_Pet();
            }
            else if (choicePetManagement == 3)
            {
                Update_Pet();
            }
            else if (choicePetManagement == 4)
            {
                Remove_Pet();
            }
            else
                break;

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

void UserMenuLevel1()//adopter
{
    cout << "==================================================================\n\n";
    cout << "Welcome Adopter\n";
    int choiceLevel2;
    do {

        cout << "Select Your Action\n";
        cout << "1) Display All Pets\n";
        cout << "2) Search for Pet ????\n";
        cout << "3) Submit Adoption Request\n";
        cout << "4) View All Requests\n";
        cout << "Any number to Exit\n";
        HandleIntErrors(choiceLevel2);
        UserMenuLevel2(choiceLevel2);
    } while (choiceLevel2 == 1 || choiceLevel2 == 2 || choiceLevel2 == 3 || choiceLevel2 == 4);
}
void UserMenuLevel1caretaker()
{
    cout << "==================================================================\n\n";
    cout << "Welcome Caretaker\n";
    int choiceLevel2;
    do {

        cout << "Select Your Action\n";
        cout << "1) Display All Pets\n";
        cout << "Any number to Exit\n"; 
        HandleIntErrors(choiceLevel2);
        if (choiceLevel2 == 1)
            UserMenuLevel2(choiceLevel2);
        else
            break;
    } while (choiceLevel2 == 1);
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
        if (registerUser(userCount)) // Pass userCount as an argument without redeclaring its type
            Userlogin(userCount);
        break;
    case 3:
        Userlogin(userCount); // Pass userCount as an argument without redeclaring its type
        break;
    default:
        break;
    }
}

void main()
{
    InitializePets();
    int level1choice;
    do
    {
        cout << "Choose what you want to do with the system: \n";
        cout << "1) Admin Login \n";
        cout << "2) User Registration \n";
        cout << "3) User Login \n";
        cout << "Any number for Exit \n";
        HandleIntErrors(level1choice);
        cout << "==================================================================\n\n";
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
}