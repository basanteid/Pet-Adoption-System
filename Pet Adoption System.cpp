//كله يحط شغله هنا واسمه جمب كل حاجة عاملها 
//محدش يعدل في شغل حد حتا لو في ايرورز انا هتصرف
//قللو global variables على اد ما تقدرو
#include <iostream>
#include<string>
using namespace std;
//alaa 
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

}//alaa

bool request_decision; //JOHN begin // used to know if user wants to purchase or not
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
}//John end

void main()
{
	//متحطوش حاجة هنا غير الفنكشن النهائية لكل جزء بس
}
