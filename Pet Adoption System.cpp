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

bool user_request()
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
    cout << "your pet is : " << pets[i].name << endl; // user will search for a specific pet so i means the pet he wants
    cout << "pet price is : " << pets[i].price << endl;
    cout << "Do you want to purchase this pet?(yes or no) \t";
    cin >> request_decision;
    if (request_decision)
        cout << "\nyour request has been sent successfully..please wait for response soon";

    return user_request; // 1 if he wants to purchase 0 if not
}

void main()
{
	//متحطوش حاجة هنا غير الفنكشن النهائية لكل جزء بس
}
