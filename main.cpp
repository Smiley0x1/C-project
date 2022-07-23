#include <iostream>
#include <vector>
using namespace std;

class Employee {        // The class where everything is done
	public:              
	//Public variables
	vector<string> employees = {};
	vector<int> IDs = {};
	//Methods
	void ID(vector<int>, vector<string>);
	void General_Employee(); 
	void HR();
	void Management();
	
};

//Options available to HR
void Employee::HR(){
	char test;
	cout << "This is HR. ";
	while (true){ //Loops menu so you don't have to start over every time
		cout<< "What do you want to do?\n a:add to list of employees\n v:view all employees \n s:search employee file \n m:modify employee file \n d:delete employee\n";
		char action;
		cin>>action;
		
		if(action != 'a' && action != 'v' && action != 's' && action !='m' && action != 'd'){ //validation
			cout<<"Uh oh, something went wrong, try again";
			break;
		}
		
		int activeIndex;
		//Add employees
		if(action=='a'){
			string activeAddition;
			int activeAddition2;
			cout<<"Who are you adding?\n"; //adding employee name
			cin>>activeAddition;
			if(cin.fail()){ //validation
					cout<<"Uh oh, something went wrong, try again";
					break;
				}
			
			cout<<"What is their ID?"; //adding ID
			cin>>activeAddition2;
			if(cin.fail()){//validation
					cout<<"Uh oh, something went wrong, try again";
					break; 
				}
			
			employees.push_back(activeAddition);
			IDs.push_back(activeAddition2);
		}
		//View all employees
		if(action=='v'){
			if(employees.size() == 0){
				cout<<"There are no employees\n";
				break;
				}
			cout<<"The employees are: \n"; //List all employees
			for(int n =0; n<employees.size(); n++){
				cout<<employees[n]<<"\n";
			}
		}
	
		if(action=='s'){ //Search for employee file
			if(employees.size() == 0){
				cout<<"There are no employees\n";
				break;
					}
			
			bool run= true;
			while (run == true){
				
				for(int i=0; i<employees.size(); i++){ //list all employees
					cout<<"input "<< i<< " to see "<<employees[i] <<"'s file"<<"\n";
				}
				int inspect;
				cin>>inspect;
				if(cin.fail()){ //validation
						cout<<"Uh oh, something went wrong, try again";
						break;
					}
				
				cout<<"Employee: "<< employees[inspect]<<"\n"<<"ID: "<<IDs[inspect]; //list employee file
				run = false;
			}
		}
		
		if(action=='m'){ //Modify employees or IDs
			if(employees.size() == 0){
					cout<<"There are no employees\n";
					break;
				}
			char change;
			cout<<"What would you like to modify? \n e:employee list or i:ID\n or press q to quit" ;
			cin>>change;
			if(change == 'i'){ //Modify IDs
		
				int activeIndex;
				int activeAddition;
				cout<<"What is the new ID?\n";
				cin>>activeAddition;
				cout<<"Who's ID are you modifying? \n Employee: ";
				for(int i=0; i<employees.size(); i++){ //list all employees and idexes
					cout<<i<<":"<< employees[i]<<" ";
				}
				cin>>activeIndex;
				IDs[activeIndex] = activeAddition;
			}
			if(change == 'e'){ //Modify employees
		
				int activeIndex;
				string activeAddition;
				cout<<"What is the new name?\n";
				cin>>activeAddition;
				cout<<"Which employee are you modifying? \n Employee: ";
				for(int i=0; i<employees.size(); i++){ //lists all employees and indexes
					cout<<i<<":"<< employees[i]<<"\n";
				}
				cin>>activeIndex;
				employees[activeIndex] = activeAddition;
			}
			
		}
	if(action=='d'){ //If no employees
		if(employees.size() == 0){
			cout<<"There are no employees\n";
			break;
		}
		
		int activeIndex;
		cout<<"Who are you deleting? \n Employee: "; //Select employee to delete
		for(int i=0; i<employees.size(); i++){
			cout<<i<<":"<< employees[i]<<" ";
		}
		
		cin>>activeIndex;
		if(cin.fail()){ //Validation
			cout<<"Uh oh, something went wrong, try again";
			break;
		}
		
		employees[activeIndex] = "";
		IDs[activeIndex]=NULL;
	}
		
	cout<<"Input 'Q' to exit or enter anything else to continue\n";
	cin>>test;
	if(cin.fail()){ //Validation
		cout<<"Uh oh, something went wrong, try again";
		break;
	}
	if(test == 'q' or test == 'Q'){
		break;
		}
	}
}

//Options availabe to Management
void Employee::Management(){
	
	bool run= true;
	char test;
	while(run = true){
	if(employees.size() == 0){ //Checks if no employees
			cout<<"There are no employees\n";
			break;
		}
	for(int i=0; i<employees.size(); i++){ //lists all employees
		cout<<"input "<< i<< " to see "<<employees[i] <<"'s file"<<"\n";
}
	int inspect;
	cin>>inspect;
		if(cin.fail()){ //validation
			cout<<"Uh oh, something went wrong, try again"; 
			break;
		}
		
	cout<<"Employee: "<< employees[inspect]<<"\n"<<"ID: "<<IDs[inspect]<<"\n"; //Shows profile of selected employee
	
	cout<<"Input 'Q' to exit or enter anything else to continue\n";
	cin>>test;
		if(cin.fail()){ //validation
			cout<<"Uh oh, something went wrong, try again";
			break;
		}
	if(test == 'q' or test == 'Q'){ //exit
		break;
	}
	
}
}

//Options available to all employees
void Employee::General_Employee(){
	
	Employee myobj;
	char test;
	bool run = true;
	while(run ==true){
	myobj.ID(IDs, employees); //login
	cout<<"Input 'Q' to exit or enter anything else to continue\n";
	cin>>test;
		if(cin.fail()){ //validation
			cout<<"Uh oh, something went wrong, try again"; 
			break;
		}
	if(test == 'q' or test =='Q'){
		break;
	}
}
}

//Login for employees
void Employee::ID(vector<int> IDs, vector<string> employees){
	bool run= true;
	while (run == true){
	cout << "Enter your name:\n"; //Employee name
	string user;
	cin>> user;
	if(cin.fail()){ //validation
			cout<<"Uh oh, something went wrong, try again";
			break;
		}

	int pswd;
	cout << "Enter your ID \n"; //Password/ID
	cin>> pswd;
	if(cin.fail()){ //validation
			cout<<"Uh oh, something went wrong, try again";
			break;
		}
		
	for(int i =0; i<employees.size(); i++){

		if((user == employees[i]) && (pswd == IDs[i])){ //pulls up info on employee
			cout<<"Employee: "<< employees[i]<<"\n"<<"ID: "<<IDs[i]<<"\n"; 
		}
	}
		run = false;
	}
	}

//main function
int main() {
	Employee user; // Create an object 
	bool run = true;
	while(run){
	cout<<"Which are you? \n If you're a HR representative input '1', if you're a Managment representative, input '2', if you're a general employee, input '3'\n";
	int division;
	cin>>division;
	if(cin.fail()){ //validation
			cout<<"Uh oh, something went wrong, try again";
		break;
		}

	switch (division){ //Picks who to login as
		case 1:
		user.HR();
		break;
		case 2:
		user.Management();
		break;
		case 3:
		user.General_Employee(); 
		break;
		default:
		cout<<"Invalid input";
		break;
	}
		}
	
	return 0;
}
