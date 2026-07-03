#include <iostream>
#include <string>
using namespace std;

class Account {
public:

	string holder_name;
	double balance = 0;
	string acc_pin;
	int acc_number;

	void create_acc();
	
	void deposite(){
		double amount;
		cout << "Enter Your amount --> ";
		cin >> amount;
	
		while(amount < 0) {
			cout << "Amount can't be negative! Enter again --> ";
			cin >> amount;
		}
	
		balance += amount;
	
		cout << "Rs." << amount << " deposited successfully." << endl << endl;
		cout << "Current Balance = Rs." << balance << endl;
	}

	void withdraw() {
		
		double amount;
		cout << "Enter Your amount --> ";
		cin >> amount;
	
		while(amount < 0){
			cout << "Amount can't be negative! Enter again --> ";
			cin >> amount;
		}
	
		if(amount > balance) {
			cout << "Insufficient balance!" << endl << endl;
		} else{
			balance -= amount;
			cout << "Rs." << amount << " withdrawn successfully.\n";
			cout << "Current Balance = Rs." << balance << endl << endl;
		}
	}
	
	
	void transfer();
	
	void inquiry() {
		cout << "\n\nAccount Information" << endl;
		cout << "-------------------\n";
		cout << "Account Holder : " << holder_name << endl;
		cout << "Account Number : " << acc_number << endl;
		cout << "Current Balance: Rs." << balance << endl << endl;
	}
	
	void check_balance() {
		cout << "\n\nCurrent Balance = Rs." << balance << endl << endl;
	}
	
	
	void delete_account(int pos);
	
};

Account total_accounts[50];
int initial_acc_number = 1001;
int track_accounts = -1;

void Account::create_acc(){
		cin.ignore();
		cout << "Enter your full name --> ";
		getline(cin, holder_name);
	
		while(holder_name.length() == 0) {
			cout << "Enter your full name --> ";
			getline(cin, holder_name);
		}
	
		cout << "Enter deposit amount (minimum 500) -> ";
		cin >> balance;
		while(balance < 500){
			cout << "Minimum amount is 500! Enter again --> ";
			cin >> balance;
		}
	
		bool correct_pin = false;
		while(!correct_pin) {
			cout << "Enter exactlyy 4 digit PIN --> ";
			cin >> acc_pin;
	
			bool digit_only = true;
			if(acc_pin.length() != 4) {
				digit_only = false;
			}else{
				for(int i = 0; i < 4; i++) {
					if(acc_pin[i] < '0' || acc_pin[i] > '9') {
						digit_only = false;
						break;
					}
				}
			}
	
			if(digit_only){
				correct_pin = true;
			} else {
				cout << "PIN must contain exactly 4 digits." << endl;
			}
		}
	
		acc_number = initial_acc_number++;
		cout << "\nAccount Created Successfully!\n";
		cout << "Account Number: " << acc_number << endl;
	}


void Account::transfer() {
		int receiver_acc;
		cout << "Enter receiver account number --> ";
		cin >> receiver_acc;
	
		bool acc_found = false;
		int receiver_pos;
		for(int i = 0; i <= track_accounts; i++){
			if(total_accounts[i].acc_number == receiver_acc) {
				acc_found = true;
				receiver_pos = i;
				break;
			}
		}
	
		if(acc_found == false){
			cout << "Receiver accout not found!\n";
			return;
		}
	
		double amount;
		cout << "Enter the amount --> ";
		cin >> amount;
	
		while(amount < 0) {
			cout << "Amount can't be negative Enter again --> ";
			cin >> amount;
		}
	
		if(amount > balance){
			cout << "Insufficient balance!\n";
			return;
		}
		balance -= amount;
		total_accounts[receiver_pos].balance += amount;
		cout << "Rs." << amount << " transferred succesfully.\n" << endl;
	}


void Account::delete_account(int pos) {
		for(int i = pos; i < track_accounts; i++) {
			total_accounts[i] = total_accounts[i + 1];
		}
		
		track_accounts--;
		cout << "\n\nAccount deleted successfully!\n\n";
	}


int find_acc() {
	if(track_accounts == -1){
		cout << "\n\nFirst create an account!" << endl << endl;
		return -1;
	}

	int tries = 3;
	while(tries > 0){
		int acc_num;
		string pin;
		cout << "\n\nEnter your account number --> ";
		cin >> acc_num;
		cout << "Enter your 4 digit PIN --> ";
		cin >> pin;

		for(int i = 0; i <= track_accounts; i++) {
			if(total_accounts[i].acc_number == acc_num && total_accounts[i].acc_pin == pin) {
				return i;
			}
		}

		tries--;
		if(tries == 2){
			cout << "\nInvalid account number or PIN! " << tries << " tries left.\n";
		}
		if(tries == 1){
			cout << "\nInvalid account number or PIN! " << tries << " try left.\n";
		}
		
	}
		
	cout << "\nInvalid account numbr or PIN! Try later.\n";
	return -1;
}                                    



int main() {
	int choice;
	while(true) {
		cout << "\n-----------------------------------\n";
		cout << "1: Create Account" << endl;
		cout << "2: Deposite Money" << endl;
		cout << "3: Withdraw Money" << endl;
		cout << "4: Transfer Money" << endl;
		cout << "5: Account Inquiry" << endl;
		cout << "6: Check Balance" << endl;
		cout << "7: Delete Account" << endl;
		cout << "0: Exit\n";
		cout << "-----------------------------------\n";

		cout << "Enter your choice --> ";
		cin >> choice;

		while(choice < 0 || choice > 7){
			cout << "Invalid choice! Enter again between 0-7 --> ";
			cin >> choice;
		}

		if(choice == 0) {
			cout << "\n\nProgram endss...." << endl;
			break;
		} else if (choice == 1){
			if(track_accounts == 49) {
				cout << "Bank is full!\n";
			} else{
				track_accounts++;
				total_accounts[track_accounts].create_acc();
			}
		} else if(choice == 2) {
			int pos = find_acc();
			if(pos != -1){
				total_accounts[pos].deposite();
			}
		} else if(choice == 3) {
			int pos = find_acc();

			if(pos != -1) {
				total_accounts[pos].withdraw();
			}
		} else if(choice == 4){
			int pos = find_acc();

			if(pos != -1){
				total_accounts[pos].transfer();
			}
		} else if(choice == 5) {
			int pos = find_acc();

			if(pos != -1){
				total_accounts[pos].inquiry();
			}
		} else if(choice == 6){
			int pos = find_acc();
			if(pos != -1) {
				total_accounts[pos].check_balance();
			}
		} else if(choice == 7){
			int pos = find_acc();
		
			if(pos != -1){
				total_accounts[pos].delete_account(pos);
			}
			
		}
	}

	return 0;
}