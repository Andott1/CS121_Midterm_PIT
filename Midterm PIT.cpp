#include <iostream>
#include <string>
using namespace std;

int record_total = 0, record_size = 0;
char null;
string student_name [100] = {};
string student_id [100] = {};
string student_course [100] = {};
string student_mobile [100] = {};

void sms_intro()
{
	cout << "-----------------------------------------------" << endl
		 << "------     STUDENT MONITORING SYSTEM     ------" << endl
		 << "----------     CS121 Midterm PIT     ----------" << endl
		 << "-----------------------------------------------" << endl << endl << endl;
	
}

void sms_login() 
{
	string username, password, adminU = "admin", adminP = "12345";
	
	cout << "----------------     Login     ----------------" << endl << endl;
	
	while (true) {
	
		cout << "> Enter Username: ";
		cin >> username;
	
		cout << "> Enter Password: ";
		cin >> password;
	
		if ((username == adminU) && (password == adminP)) {
			cout << endl << "------     ! Sucessfully Logged In !     ------" << endl << endl;
			break;
		}
		else {
			cout << endl << "Invalid Username and/or Password" << endl << endl;
			continue;
		}
	}
}

void sms_input_record()
{
	record_size += 1;
	cout << "> Enter Student Name: ";
	cin.ignore();
	getline(cin, student_name[record_total]);
	
	cout << "> Enter Student ID: ";
	getline(cin, student_id[record_total]);
	
	cout << "> Enter Student Course: ";
	getline(cin, student_course[record_total]);
	
	cout << "> Enter Student Mobile Number: ";
	getline(cin, student_mobile[record_total]);
	
	record_total += 1;
	cout << endl << "-------     ! Student Record Added !     ------" << endl << endl;
}

void sms_view_record()
{
	for (int i = 0 ; i < record_size ; i++) {
		cout << "- Record Number [" << i + 1 << "]" << endl << endl;
		cout << "- Student Name: " << student_name[i] << endl;
		cout << "- Student ID: " << student_id[i] << endl;
		cout << "- Student Course: " << student_course[i] << endl;
		cout << "- Student Mobile Number: " << student_mobile[i] << endl << endl;	
	}
	cout << "-----     * Press enter to continue *     -----" << endl;
	cin.ignore();
	while (true) {
		null = cin.get();
		
		if (null == '\n') {
			break;
		}
	}
}

void sms_find_record()
{
	int index = -1;
	string student_id_ref;
	
	cout << "> Enter Student ID: ";
	cin >> student_id_ref;
	
	for (int i = 0 ; i < record_size ; i++)
		if (student_id[i] == student_id_ref) {
			index = i;
			cout << endl << "--------    ! Student Record Found !    -------" << endl << endl;
			break;
		}
	
	if (index != -1) {
		cout << "- Record Number [" << index + 1 << "]" << endl << endl;
		cout << "- Student Name: " << student_name[index] << endl;
		cout << "- Student ID: " << student_id[index] << endl;
		cout << "- Student Course: " << student_course[index] << endl;
		cout << "- Student Mobile Number: " << student_mobile[index] << endl << endl;	
	}
	else { 
		cout << endl << "-----     ! Student Record Not Found !     ----" << endl << endl;
	}
	
	cout << "-----     * Press enter to continue *     -----" << endl;
	cin.ignore();
	while (true) {
		null = cin.get();
		
		if (null == '\n') {
			break;
		}
	}
}

void sms_delete_record()
{
	int record_number;
	
	for (int i = 0 ; i < record_size ; i++) {
		cout << "- Record Number [" << i + 1 << "]" << endl << endl;
		cout << "- Student Name: " << student_name[i] << endl;
		cout << "- Student ID: " << student_id[i] << endl;
		cout << "- Student Course: " << student_course[i] << endl;
		cout << "- Student Mobile Number: " << student_mobile[i] << endl << endl;	
	}
	
	cout << "> Choose Record Number to Delete: ";
	cin >> record_number;
}

void sms_update_record()
{
	
}

void sms_store_record()
{
	
}

void sms_exit()
{
	
}

void sms_menu()
{
	int option;
	
	while (option != 6) {
		cout << endl << "--------------     Main Menu     --------------" << endl
			 << "--                                           --" << endl
		 	 << "--       1. Input Student Record             --" << endl
		 	 << "--       2. View All Student Record          --" << endl
		 	 << "--       3. Find Student Record              --" << endl
		 	 << "--       4. Delete Student Record            --" << endl
		 	 << "--       5. Update Student Record            --" << endl
		 	 << "--       6. Exit Program                     --" << endl
		 	 << "--                                           --" << endl
		 	 << "-----------------------------------------------" << endl << endl;
		cout << "> Enter an option: ";
		cin >> option;
		cout << endl;
		
		switch (option) {
			case 1:
				sms_input_record();
				sms_store_record();
				break;
			case 2:
				sms_view_record();
				break;
			case 3:
				sms_find_record();
				break;
			case 4:
				sms_delete_record();
				break;
			case 5:
				sms_update_record();
				sms_store_record();
				break;
			case 6:
				sms_exit();
				break;
			default:
				cout << "----     ! Invalid option, try again !     ----" << endl;
				continue;
		}
		
		
	}
	
	
}

int main()
{
	sms_intro();
	sms_login();
	sms_menu();
}
