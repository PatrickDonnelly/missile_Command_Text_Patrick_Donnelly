

#include <iostream>
typedef struct Position
{
	int x;
	int y;

	void print()
	{
		std::cout << x << y << std::endl;
	}

}Coordinates;

enum WarHead { EXPLOSIVE, NUCLEAR };

typedef struct Enemy {
	Coordinates coordinates;
}Target;


struct Missile {
	WarHead payload;

	Coordinates coordinates;

	Target target;

	bool explosiveMissileSelected;
	bool nuclearMissileSelected;

	bool armed;

	void oceanHit();
	void missileSelect();
	void explosiveMissileSelect();
	void nuclearMissileSelect();
	void missileConfirm();
	void enterCoOrdinates();

	int option;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update() {
		coordinates.x += 1;
		coordinates.y += 2;
	}
};



int main()
{
	std::cout << "---------------------------------------------------------------------------------------------------------" << std::endl;

	std::cout << " _______                          __      __    _______ _           __          __        _     _ " << std::endl;
	std::cout << "|__   __|                         \\ \\    / /   |__   __| |          \\ \\        / /       | |   | |" << std::endl;
	std::cout << "   | |_ __ _   _ _ __ ___  _ __    \\ \\  / /__     | |  | |__   ___   \\ \\  /\\  / /__  _ __| | __| |" << std::endl;
	std::cout << "   | | '__| | | | '_ ` _ \\| '_ \\    \\ \\/ / __|    | |  | '_ \\ / _ \\   \\ \\/  \\/ / _ \\| '__| |/ _` |" << std::endl;
	std::cout << "   | | |  | |_| | | | | | | |_) |    \\  /\\__ \\    | |  | | | |  __/    \\  /\\  / (_) | |  | | (_| |" << std::endl;
	std::cout << "   |_|_|   \\__,_|_| |_| |_| .__/      \\/ |___/    |_|  |_| |_|\\___|     \\/  \\/ \\___/|_|  |_|\\__,_|" << std::endl;
	std::cout << "                          |_|                                                                     " << std::endl;
	std::cout << "\t    __  __ _         _ _         _____                                          _           " << std::endl;
	std::cout << "\t   |  \\/  (_)       (_) |       / ____|                                        | |          " << std::endl;
	std::cout << "\t   | \\  / |_ ___ ___ _| | ___  | |     ___  _ __ ___  _ __ ___   __ _ _ __   __| |          " << std::endl;
	std::cout << "\t   | |\\/| | / __/ __| | |/ _ \\ | |    / _ \\| '_ ` _ \\| '_ ` _ \\ / _` | '_ \\ / _` |          " << std::endl;
	std::cout << "\t   | |  | | \\__ \\__ \\ | |  __/ | |___| (_) | | | | | | | | | | | (_| | | | | (_| |          " << std::endl;
	std::cout << "\t   |_|  |_|_|___/___/_|_|\\___|  \\_____\\___/|_| |_| |_|_| |_| |_|\\__,_|_| |_|\\__,_| " << std::endl;

	std::cout << "\n---------------------------------------------------------------------------------------------------------" << std::endl;

	Missile missileControlPanel;

	missileControlPanel.missileSelect();

	std::cout << std::endl;
	system("PAUSE");
	return 0;

}

void Missile::missileSelect()
{
	option = 0;
	std::cout << "President Trump Which missile should we arm ? \n" << std::endl;

	std::cout << "1) Explosive Missile " << std::endl;
	std::cout << "2) Nuclear Missile " << std::endl;

	std::cin >> option;

	if (option == 1)
	{
		explosiveMissileSelected = true;
		nuclearMissileSelected = false;
		explosiveMissileSelect();
	}
	else if (option == 2)
	{
		explosiveMissileSelected = false;
		nuclearMissileSelected = true;
		nuclearMissileSelect();
	}
	else
	{
		std::cout << "That is not a valid option mr. president" << std::endl;
	}
}

void Missile::enterCoOrdinates()
{
	
	std::cout << "Please enter the x co-ordinates of your target Mr. President!" << std::endl;
	std::cin >> coordinates.x;

	std::cout << "Please enter the y co-ordinates of your target Mr. President!" << std::endl;
	std::cin >> coordinates.y;

	if ((coordinates.x >= 0 && coordinates.x <= 3) && (coordinates.y >= 0 && coordinates.y <= 3))
	{
		oceanHit();
	}
	else
	{
		std::cout << "You missed" << std::endl;
		enterCoOrdinates();
	}
}

void Missile::explosiveMissileSelect()
{
	std::cout << "The explosive missile has a range of 15x15 do you think this will be far enough sir?" << std::endl;
	missileConfirm();
}

void Missile::nuclearMissileSelect()
{
	std::cout << "The nuclear missile has a range of 30x30 do you think this will be far enough sir?" << std::endl;
	missileConfirm();
}

void Missile::missileConfirm()
{
	option = 0;

	if (explosiveMissileSelected == true)
	{
		std::cout << "1) Yes. Melania launch that explosive missile!" << std::endl;
	}
	else
	{
		std::cout << "1) Yes. Melania launch that nuclear missile!" << std::endl;
	}

	std::cout << "2) No how far is mexico" << std::endl;

	std::cin >> option ;

	if (option == 1)
	{
		enterCoOrdinates();
	}
	else if (option == 2)
	{
		missileSelect();
	}
	else
	{
		std::cout << "Please stop tweeting mr.president, do you want to launch that missile?" << std::endl;
		missileConfirm();
	}
}

void Missile::oceanHit()
{
	std::cout << "Mr. President that missile is headed straight for the ocean" << std::endl;

	if (explosiveMissileSelected)
	{
		std::cout << "upon impact that explosive missile will decimate 10% of ocean life as we know it" << std::endl;
	}
	else
	{
		std::cout << "upon impact that nuclear missile will decimate 20% of ocean life as we know it" << std::endl;
	}
}

void japanHit()
{
	std::cout << "Yes Melania launch that missile!" << std::endl;
}

void irelandHit()
{
	std::cout << "Yes Melania launch that missile!" << std::endl;
}

void americaHit()
{
	std::cout << "Yes Melania launch that missile!" << std::endl;
}

void russiaHit()
{
	std::cout << "Yes Melania launch that missile!" << std::endl;
}


