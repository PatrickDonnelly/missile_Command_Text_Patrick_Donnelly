

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

	bool armed;

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

	std::cout << "Please Select a WarHead : " << std::endl;
	std::cout << "1) Explosive Missile " << std::endl;
	std::cout << "2) Nuclear Missile " << std::endl;



}

