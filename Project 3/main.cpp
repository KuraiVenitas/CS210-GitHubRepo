#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Item {
public:
	void IncreaseAmount();
	string GetItemName();
	int GetItemQuantity();
public:
	Item(string name) {
		itemName = name;
		itemQuantity = 1;
	}
private: 
	string itemName;
	int itemQuantity;
};
void Item::IncreaseAmount() {
	itemQuantity++;
}
string Item::GetItemName() {
	return itemName;
}
int Item::GetItemQuantity() {
	return itemQuantity;
}

int MainMenu() {
	cout << "Please select an option from the menu: " << endl;
	cout << "1. Search for an item" << endl;
	cout << "2. Show all items..." << endl;
	cout << "3. Show all items via histogram..." << endl;
	cout << "4. Exit Program..." << endl;

	int menuSelection;

	try {
		cin >> menuSelection;
		if (cin.fail() || menuSelection > 4 || menuSelection < 1) {
			throw invalid_argument("Invalid selection...\n");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what();
		cin.clear();
		cin.ignore();
	}
	return menuSelection;
}

void SearchForItem(vector<Item> itemList, string name) {
	system("CLS");
	cout << "=== Item Search ===" << endl;

	bool iFound = false;
	
	for(Item item: itemList){
		if (item.GetItemName() == name) {
			cout << name << ": " << item.GetItemQuantity() << "\n";
			iFound = true;
		}
	}
	if (iFound == false) {
		cout << "The item could not be found...\n";
	}
}
void ShowAllItems(vector<Item> itemList) {
	system("CLS");
	ofstream outFS;
	outFS.open("CS210_Project_Three_Output_File_AllItems.txt");
	cout << "=== All Grocery Items Sold ===" << endl;
	outFS << "=== All Grocery Items Sold ===" << endl;

	for (Item item : itemList) {
		cout <<item.GetItemName() << " " << item.GetItemQuantity() << endl;
		outFS << item.GetItemName() << " " << item.GetItemQuantity() << endl;
	}
	
	outFS.close();
}
void ShowHistogram(vector<Item> itemList) {
	system("CLS");
	ofstream outFS;
	outFS.open("CS210_Project_Three_Output_File_Histogram.txt");
	cout << "=== Grocery Item Histogram ===" << endl;
	outFS << "=== Grocery Item Histogram ===" << endl;

	for (Item item : itemList) {
		cout << setw(15) << left << item.GetItemName() << ": ";
		outFS << setw(15) << left << item.GetItemName() << ": ";
		for (int i = 0; i < item.GetItemQuantity(); ++i) {
			cout << '*';
			outFS << '*';
		}
		cout << endl;
		outFS << endl;
	}
	outFS.close();
}

int main() {

	ifstream inFS;

	vector<Item> items;
	string itemName;
	string lookForItem;

	int itemIndex;
	int userSelection;

	bool go = true;
	bool isFound = false;

	// Opening the file to read grocery information and sorting the items by name and frequency purchased
	inFS.open("CS210_Project_Three_Input_File.txt");

	do{
		inFS >> itemName;
		isFound = false;
		// Create a vector that has all items
		for (int i = 0; i < items.size(); i++) {
			if (itemName == items[i].GetItemName()) {
				isFound = true;
				itemIndex = i;
			}
		}
		if (isFound == true) {
			items[itemIndex].IncreaseAmount();
		}
		if (isFound == false) {
			Item* item = new Item(itemName);
			items.push_back(*item);	
		}
		if (inFS.eof()) {go = false;}
	} while (go);

	inFS.close(); // File is closed for use
	
	cout << "=== Grocery Item Sell History ===\n" << endl;

	userSelection = MainMenu();
	
	while (userSelection != 4) {
		switch (userSelection) {
			case 1:
				system("CLS");
				cout << "Please enter the item you wish to search: \n";
				cin >> lookForItem;
				lookForItem[0] = toupper(lookForItem[0]);
				SearchForItem(items, lookForItem);
				break;
			case 2:
				system("CLS");
				ShowAllItems(items);
				break;
			case 3:
				system("CLS");
				ShowHistogram(items);
				break;
			default:
				break;
		}
		cout << "\n";
		userSelection = MainMenu();
	}
	return 0;
}