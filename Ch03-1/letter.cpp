#include "std_lib_facilities.h"

int main ()
{
	cout << "Enter the name of the person you want to write to:\n";
	
	string first_name;
	cin >> first_name;
	
	cout << "\nDear, " << first_name << "\n";

	cout << "\nHow are you? I am fine. I love you. I miss you.\n";
	cout << "If you come home, we will a have a big party. What do you think?\n";

	cout << "\nEnter a friend name:\n";
	string friend_name;
	cin >> friend_name;

	cout << "\nHave you seen " << friend_name << " lately?\n";

	char friend_sex = 0;
	cout << "\nPlease enter an M if the friend is male and an F is female.";
	cin >> friend_sex;

	if (friend_sex == 'M')
		cout << "\nIf you see " << friend_name << " please ask him to call me.\n";
	else if (friend_sex == 'F')
	{
		cout << "\nIf you see " << friend_name << " please ask her to call me.\n";
	}

	int age = 0;
	cout << "\nPlease enter the recipient's age:" << " \n";
	cin >> age;

	cout << "\nI hear you just had a birthday and you are " << age << " years old.\n";

	if (age <= 0 or age >= 110)
		simple_error("you are kidding!");

	if (age < 12)
		cout << "\nNext year you will be " << age+1 << "\n";
	if (age == 17)
		cout << "\nNext year you will be able to vote.\n";
	if (age > 70)
		cout << "\nI hope you are enjoying retirement.\n";

	cout << "\n Yours sincerely, \n\n";
	cout << "Zotya \n";


	return 0;
}