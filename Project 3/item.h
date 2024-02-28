#pragma once

class Item {
	
	string name;
	int quantity;


public:
	Item() {
		name = "";
		quantity = 0;
	}

public:
	void IncreaseAmount();
	string GetItemName();

};