#include <iostream>

using namespace std;

const int defaultpin = 0000;

int main() 
{	
	int attempts = 0;
	int select;
	char option;
	int recipient_num, confirm_num;
	float amount;
	string ref;
	int pin, new_pin;
	float balance;
	balance = 1000;

    cout << "WELCCOME TO MTN MOMO SERVICE" <<endl;
    cout<<"\n\n";
	
	cout << "Main Menu" << endl;
	
	cout << "1. Check Balance" << endl;
	
	cout << "2. Reset/Change Pin" << endl;
	
	cout << "3. Send Money" << endl;
	
	cout << "4. Deposit Money" << endl;
 
    cout  << "5. Buy Airtime" << endl;
    
	cout <<"\n";
   
   
    
	cout << "Select an option" <<endl;
	cin >> select;



// AUTHENTICATION & RESETTING PIN



	if(select == 1)
	{
		do {
			cout << "Please enter your 4-digit PIN: " << endl;
			cin >> pin;
			attempts++;

			if (pin != defaultpin) {
				cout << "Incorrect PIN. Please try again." << endl;
			}
			else if (pin == defaultpin) {
				cout << "Your balance is GHS " << balance << endl;	
			}

		} while (pin != defaultpin && attempts < 3);

		if(attempts >= 3) {
			cout << "Maximum attempts reached. Exiting Program." << endl;
			return 0;
		}
	}

	
	 else if(select == 2)

	 {
			
			cout << "Are you sure you want to change your PIN?"<<endl;
			cout << "Y/N" <<endl;
			cin >> option;

			if(option == 'Y') {
				
				cout << "Please enter your old PIN: " << endl;
		cin >> pin;

		if (pin != defaultpin) {
			cout << "Incorrect PIN. Exiting Program." << endl;
		
			return 0;
		}
		    else {
			
				cout<< "Enter new PIN: " << endl;
				cin >> new_pin;
				pin = new_pin;
				cout << "Your new PIN is " << new_pin << endl;
		    }
		}
	}



// SENDING MONEY



	else if(select == 3)
	{
		cout << "Enter mobile number: " << endl;
		cin >> recipient_num;
	
        cout << "Confirm mobile number : " << endl;
		cin >> confirm_num;

      // Checking if the numbers entered are both the same
 
		if (recipient_num != confirm_num) { 
			cout << "Mismatch in numbers" << endl;
			return 0;
		}
        
        cout<<"Enter Reference "<<endl;
       	cin>>ref;
        
		cout << "Enter amount to transfer: " << endl;
		cin >> amount;

		if(amount > balance) {
			cout << "Insufficient funds." << endl;
			return 0;
		}

		cout << "Transfer GHS " << amount << " to " << confirm_num << " with Reference: " << ref <<"."<< endl;
		cout << "Please enter your PIN: " << endl;
		cin >> pin;

		do{
			attempts++;

			if (pin != defaultpin){
				cout<<"Invalid PIN. Please try again." << endl;
			}
			else if (pin == defaultpin){
				cout << "You have successfully sent GHS " << amount << " to " << confirm_num << endl;
				cout << "Your current balance is GHS " << balance - amount << endl;
			}

		} while (pin != defaultpin && attempts > 3);

		if(attempts >= 3) {
			cout << "Maximum attempts reached. Exiting Program." << endl;
			return 0;
		}
	}


// DEPOSITING MONEY


	else if(select == 4)
	{
		cout << "Enter amount to deposit: " << endl;
		cin >> amount;
		balance += amount;
		cout << "You have successfully deposited GHS " << amount << ". Your new balance is " << balance << endl;

	} 
	


// BUYING OF AIRTIME

else if (select == 5)

{
    cout << "Buy Airtime" << endl;
    cout << "1. Self" << endl;
    cout << "2. Others" << endl;
    cout << "Select an option: " << endl;
    int option;
    cin >> option;

    if (option == 1)
    {
       
	    // Buy airtime for self
       
	   
	    cout << "Enter amount: " << endl;
        cin >>amount;

        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
            return 0;
        }

        balance -= amount;
        cout << "Airtime purchased successfully. Your new balance is GHS " << balance << endl;
    }
    else if (option == 2)
    {
       
	   
	    // Buy airtime for others on the same network
       
	   
	    cout << "Enter recipient's number: " << endl;
        cin >>recipient_num;
		
		cout << "Confirm number" <<endl;
        cin >>confirm_num;
    
	 // This is to check if the numbers entered are the same.
	 
       	if (recipient_num != confirm_num) { 
			
			cout << "Mismatch in numbers" << endl;
			return 0;
		}

        cout << "Enter amount: " << endl;
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
            return 0;
        }

        balance -= amount;
        cout << "Airtime purchased successfully for " << confirm_num << ". Your new balance is GHS " << balance << endl;
    }
}


	return 0;
}

