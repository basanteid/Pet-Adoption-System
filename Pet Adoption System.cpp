//كله يحط شغله هنا واسمه جمب كل حاجة عاملها 
//محدش يعدل في شغل حد حتا لو في ايرورز انا هتصرف
//قللو global variables على اد ما تقدرو
#include <iostream>
using namespace std;
bool request_decision; // used to know if user wants to purchase or not
const int no_pets = 5;
struct pet
{
    string name;
    int price;
} pets[no_pets]; // array of pets we have

bool user_request()
{
    cout << "your pet is : " << pets[i].name << endl; // user will search for a specific pet so i means the pet he wants
    cout << "pet price is : " << pets[i].price << endl;
    cout << "Do you want to purchase this pet? \t";
    cin >> request_decision;
    if (request_decision)
        cout << "\nyour request has been sent successfully..please wait for response soon";

    return user_request; // 1 if he wants to purchase 0 if not
}

void main()
{
	//متحطوش حاجة هنا غير الفنكشن النهائية لكل جزء بس
}
