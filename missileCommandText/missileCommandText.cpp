// Student Name : Patrick Donnelly
// Student ID : C00236160

// Game :  Control trump as he eats cheetohs and launches deadly missiles across the world.
//		   The goal, destroy japan. Why....Trump has no reason. It's just a Trump thing to do.
//		   Various countries are hidden in different locations. You can destroy them if you want
//		   But it is not necessary.
//		   Only Nuclear missiles can travel as far as japan.

#include <iostream>
#include <stdlib.h>

using namespace std;

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
	bool gameover;

	int option;
	int launchCode;
	int remember;
	int attemptsLeft;
	int countdown;

	void oceanHit();
	void mexicoHit();
	void puertoRicoHit();
	void chinaHit();
	void japanHit();
	void southKoreaHit();
	void northKoreaHit();
	void irelandHit();
	void americaHit();
	void russiaHit();
	void title();
	void missileSelect();
	void missileConfirm();
	void enterCoOrdinates();
	void enterLaunchCode();
	void checkCollision();
	void selfDestruct();
	void arming();

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
	Missile missileControlPanel;
	
	missileControlPanel.remember = 0;
	missileControlPanel.attemptsLeft = 5;
	missileControlPanel.countdown = 60;
	missileControlPanel.gameover = false;

	if (!missileControlPanel.gameover)
	{
		missileControlPanel.missileSelect();
	}

	std::cout << std::endl;
	system("PAUSE");
	return 0;

}

void Missile::title()
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

}

void Missile::missileSelect()
{
	system("CLS");
	title();
	
	option = 0;
	std::cout << "President Trump Which missile should we arm ? \n" << std::endl;

	std::cout << "1) Explosive Missile " << std::endl;
	std::cout << "2) Nuclear Missile " << std::endl;
	std::cout << "3) Stop Arming Missiles and Eat Some Cheetohs Instead " << std::endl;

	std::cin >> option;

	if (option == 1)
	{
		payload = EXPLOSIVE;
		missileConfirm();
	}
	else if (option == 2)
	{
		payload = NUCLEAR;
		missileConfirm();
	}
	else if (option == 3)
	{
		system("CLS");
		title();
		std::cout << " * After launching many missiles and decimating the world's population * " << std::endl;
		std::cout << " * You retire to your underground bunker to gorge on cheetohs and await your fate * " << std::endl;
	}
	else
	{
		system("CLS");
		title();
		std::cout << "That is not a valid option mr. president. Please choose a warhead" << std::endl;
		system("Pause");
		missileSelect();
	}
}

void Missile::enterCoOrdinates()
{
	system("CLS");
	title();

	std::cout << "Please enter the x co-ordinates of your target Mr. President!" << std::endl;
	std::cin >> coordinates.x;

	if ((coordinates.x > 15 || coordinates.x < 0) && payload == EXPLOSIVE)
	{
		std::cout << "Sir that missile cannot travel within that range. Please reconfigure the target's co-ordinates" << std::endl;
		system("PAUSE");
		enterCoOrdinates();
	}
	if ((coordinates.x > 30 || coordinates.x < 0) && payload == NUCLEAR)
	{
		std::cout << "Sir that missile cannot travel within that range. Please reconfigure the target's co-ordinates" << std::endl;
		system("PAUSE");
		enterCoOrdinates();
	}

	std::cout << "Please enter the y co-ordinates of your target Mr. President!" << std::endl;
	std::cin >> coordinates.y;

	if ((coordinates.y > 15 || coordinates.y < 0) && payload == EXPLOSIVE)
	{
		std::cout << "Sir that missile cannot travel within that range. Please reconfigure the target's co-ordinates" << std::endl;
		system("PAUSE");
		enterCoOrdinates();
	}
	if ((coordinates.y > 30 || coordinates.y < 0) && payload == NUCLEAR)
	{
		std::cout << "Sir that missile cannot travel within that range. Please reconfigure the target's co-ordinates" << std::endl;
		system("PAUSE");
		enterCoOrdinates();
	}

	std::cout << "Co-ordinates have been entered successfully Mr. Trump" << std::endl;
	std::cout << "Our Systems are locking on to the location Sir" << std::endl;

	system("Pause");
	enterLaunchCode();
}


void Missile::missileConfirm()
{
	system("CLS");
	title();
	option = 0;

	if (payload == EXPLOSIVE)
	{
		std::cout << "The explosive missile has a range of 15x15 do you think this will be far enough sir?" << std::endl;
		std::cout << "1) Yes. Melania launch that explosive missile!" << std::endl;
	}
	else
	{
		std::cout << "The nuclear missile has a range of 30x30 do you think this will be far enough sir?" << std::endl;
		std::cout << "1) Yes. Melania launch that nuclear missile!" << std::endl;
	}

	std::cout << "2) No how far is mexico" << std::endl;

	std::cin >> option;

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
		system("PAUSE");
		missileConfirm();
	}
}

void Missile::enterLaunchCode()
{
	system("CLS");
	title();

	option = 0;
	std::cout << "Mr. president, we need the launch code to arm the missile" << std::endl;
	if (attemptsLeft != 1)
	{
		std::cout << "You have " << attemptsLeft << " attempts left" << std::endl;
	}
	else
	{
		std::cout << "You have " << attemptsLeft << " attempt left" << std::endl;
	}

	std::cout << "1) Enter 4 Digit Launch Code" << std::endl;
	std::cout << "2) Change Target Co-Ordinates" << std::endl;
	std::cout << "3) Try to remember Launch Code" << std::endl;

	std::cin >> option;

	if (option == 3)
	{
		system("CLS");
		title();
		if (remember == 0)
		{
			std::cout << " * You check your tweets and see the first number of the launch code is 6 *" << std::endl;
		}
		else if (remember == 1)
		{
			std::cout << " * You check on the backside of your toupee and see the second number of the launch code is 1 *" << std::endl;
		}
		else if (remember == 2)
		{
			std::cout << " * You wipe the bottled tan from your forehead and see the third number of the launch code is 3 *" << std::endl;
		}
		else if (remember == 3)
		{
			std::cout << " * You call up obama and he reminds you the fourth number of the launch code is 9 *" << std::endl;
		}
		else
		{
			std::cout << " * You already remembered the launch code is 6139 *" << std::endl;
		}

		system("PAUSE");
		remember += 1;
		enterLaunchCode();
	}

	else if (option == 1)
	{
		system("CLS");
		title();

		std::cout << "Enter The Four Digit Launch Code To Arm The Missile Mr. President \n" << std::endl;
		std::cin >> launchCode;

		if (launchCode == 6139)
		{
			system("CLS");
			title();
			std::cout << " * Bzzzt - Launch Code Confirmed, Commence the missile Arming Process *" << std::endl;
			system("Pause");
			arming();
		}
		else
		{
			std::cout << "* Bzzzt - Launch Code Incorrect, Retry, Retry, Retry " << std::endl;
			std::cout << "If you enter the code incorrectly five times you'll initiate a self destruct process" << std::endl;

			attemptsLeft -= 1;

			if (attemptsLeft == 0)
			{
				selfDestruct();
			}

			system("PAUSE");

			if (attemptsLeft != 0)
			{
				enterLaunchCode();
			}
		}
	}
	else if (option == 2)
	{
		enterCoOrdinates();
	}
	else
	{
		system("CLS");
		title();
		std::cout << "Please stop tweeting Mr.Trump, we need the launch code!" << std::endl;
		system("PAUSE");
		enterLaunchCode();
	}
}


void Missile::arming()
{
	system("CLS");
	title();

	if (countdown >= 40)
	{
		std::cout << " 3 " << std::endl;
	}
	else if (countdown >=20)
	{
		std::cout << " 3 " << std::endl;
		std::cout << " 2 " << std::endl;
	}
	else if (countdown > 0)
	{
		std::cout << " 3 " << std::endl;
		std::cout << " 2 " << std::endl;
		std::cout << " 1 " << std::endl;
	}
	if (countdown != 0)
	{
		countdown -= 1;
		arming();
	}
	else
	{
		countdown = 60;
		std::cout << " 3 " << std::endl;
		std::cout << " 2 " << std::endl;
		std::cout << " 1 " << std::endl;
		std::cout << "Missile Armed And Ready To Launch Sir" << std::endl;

		system("Pause");
		checkCollision();

	}

}

void Missile::checkCollision()
{
	system("CLS");
	title();
	option = 0;
	std::cout << " Missiles have been launched Mr.Trump" << std::endl;
	std::cout << " We're waiting for reports on the targets trajectory" << std::endl;

	system("Pause");

	system("CLS");
	title();

	if (payload == NUCLEAR)
	{
		if ((coordinates.x >= 2 && coordinates.x <= 6) && (coordinates.y >= 0 && coordinates.y <=30))
		{
			std::cout << "The nuclear missile has locked onto Mexico Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;
			
			std::cout << "1) Yes. Nuke them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				mexicoHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the nuclear missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else if ((coordinates.x >= 8 && coordinates.x <= 10) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			
			std::cout << "The nuclear missile has locked onto Puerto Rico Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Nuke them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				puertoRicoHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the nuclear missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else if ((coordinates.x >= 12 && coordinates.x <= 14) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			std::cout << "The nuclear missile has locked onto Ireland Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Nuke them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				irelandHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the nuclear missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
			
		}
		else if ((coordinates.x >= 15 && coordinates.x <= 20) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			std::cout << "The nuclear missile has locked onto Russia Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Nuke them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				russiaHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the nuclear missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else if ((coordinates.x >= 22 && coordinates.x <= 26) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			std::cout << "The nuclear missile has locked onto China Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Nuke them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				chinaHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the nuclear missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else if ((coordinates.x == 27) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			std::cout << "The nuclear missile has locked onto Japan Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Nuke them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				japanHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the nuclear missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else if ((coordinates.x == 29) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			std::cout << "The nuclear missile has locked onto South Korea Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Nuke them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				southKoreaHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the nuclear missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else if ((coordinates.x == 30) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			std::cout << "The nuclear missile has locked onto North Korea Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Nuke them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				northKoreaHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the nuclear missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else
		{
			oceanHit();
		}
	}
	else if (payload == EXPLOSIVE)
	{
		if ((coordinates.x >= 2 && coordinates.x <= 7) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			std::cout << "The explosive missile has locked onto Mexico Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Blast them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				mexicoHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the explosive missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else if ((coordinates.x >= 10 && coordinates.x <= 15) && (coordinates.y >= 0 && coordinates.y <= 30))
		{
			std::cout << "The explosive missile has locked onto Puerto Rico Mr.Trump. It is within range." << std::endl;
			std::cout << "Is this a viable target Sir ? " << std::endl;

			std::cout << "1) Yes. Blast them!" << std::endl;
			std::cout << "2) I've changed my mind. Deactivate the nuclear missile \n" << std::endl;

			std::cin >> option;

			if (option == 1)
			{
				puertoRicoHit();
			}
			else if (option == 2)
			{
				system("CLS");
				title();
				std::cout << "\n You deactivated the explosive missile Mr.Trump it will be redirected to the Ocean" << std::endl;
				system("Pause"); 
				oceanHit();
			}
			else
			{
				system("CLS");
				title();
				std::cout << "PLEASE STOP TWEETING MR. TRUMP, WE NEED CONFIRMATION!" << std::endl;
				system("PAUSE");
				checkCollision();
			}
		}
		else
		{
			oceanHit();
		}
	}
}


void Missile::oceanHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for the ocean" << std::endl;

	if (payload == EXPLOSIVE)
	{
		std::cout << "upon impact that explosive missile will decimate 10% of ocean life as we know it" << std::endl;
	}
	else
	{
		std::cout << "upon impact that nuclear missile will decimate 20% of ocean life as we know it" << std::endl;
	}
	system("PAUSE");
	missileSelect();
}

void Missile::mexicoHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for the centre of mexico" << std::endl;

	if (payload == EXPLOSIVE)
	{
		std::cout << "The missile landed in the desertlands. No casualties are being reported" << std::endl;
	}
	else
	{
		std::cout << "The nuke destoyed mexico city. I guess we won't be needing that wall anymore" << std::endl;

	}
	system("PAUSE");
	missileSelect();
}

void Missile::puertoRicoHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for the centre of Puerto Rico....an American territory" << std::endl;

	if (payload == EXPLOSIVE)
	{
		std::cout << "The missile landed in the Ocean. No casualties are being reported" << std::endl;
	}
	else
	{
		std::cout << "The nuke wiped out the entire population of puerto rico. What have you done Sir?" << std::endl;

	}
	system("PAUSE");
	missileSelect();
}

void Missile::chinaHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for China" << std::endl;

	/*if (payload == EXPLOSIVE)
	{
		std::cout << "The missile landed in chinese territory. Civilian casualties are being reported. Expect retaliation" << std::endl;
	}
	else
	{*/
		std::cout << "The nuke obliterated Beijing. The chinese are returning nukes sir. This is all out war" << std::endl;

	//}
	system("PAUSE");
	missileSelect();
}

void Missile::japanHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for Japan" << std::endl;

	/*if (payload == EXPLOSIVE)
	{
		std::cout << "The missile landed just outside the japanese mainland causing a minor tsunami. 5,000 casualtiesnare expected" << std::endl;
	}
	else
	{*/
		std::cout << "The nuke flattened tokyo. The japanese have surrendered" << std::endl;

		system("PAUSE");
		system("CLS");
		title();

		std::cout << "\n\n***************************************************************************************" << std::endl;
		std::cout << "\n\nYou feel a sense of triumph inside you and retire to the white house. Well done i guess" << std::endl;
		std::cout << "\n\n***************************************************************************************" << std::endl;
		gameover = true;


	//}
	system("PAUSE");
	if (gameover == false)
	{
		missileSelect();
	}

}

void Missile::southKoreaHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for South Korea" << std::endl;

	/*if (payload == EXPLOSIVE)
	{
		std::cout << "You just destroyed the modern musuem of korean pop. Expect your twitter to blow up from enraged angsty teens" << std::endl;
	}
	else
	{*/
		std::cout << "You just obliterated the wrong side of korea. Kim is at the border celebrating gangnam style" << std::endl;

	//}
	system("PAUSE");
	missileSelect();
}

void Missile::northKoreaHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for North Korea" << std::endl;

	/*if (payload == EXPLOSIVE)
	{
		std::cout << "You just destroyed a north Korean Military base. Be prepared for retaliation" << std::endl;
	}
	else
	{*/
		std::cout << "You took out the North Korean Capital. The South Koreans are already moving in" << std::endl;

	//}

	system("PAUSE");
	missileSelect();
}

void Missile::irelandHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for Europe" << std::endl;

	/*if (payload == EXPLOSIVE)
	{
		std::cout << "You just destroyed Offaly. Lucky for you no one in Ireland knows where that is." << std::endl;
	}
	else
	{*/
		std::cout << "um....Mr.President you just nuked Ireland. The entire country has been decimated." << std::endl;

		std::cout << "Trump : 'Well i guess that's one less golf resort. I still have 12 though right. Send thoughts and prayers'" << std::endl;
	//}
	system("PAUSE");
	missileSelect();

}

void Missile::americaHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for the states....we're in the states Mr. President" << std::endl;

	/*if (payload == EXPLOSIVE)
	{
		std::cout << "What have you done, you've just caused 20,000 civilian deaths " << std::endl;
	}
	else
	{*/
		std::cout << "Sir.....You just nuked an entire city...here in the US. Millions of civilians are expected to be effected" << std::endl;

	//}
	system("PAUSE");
	missileSelect();
}

void Missile::russiaHit()
{
	system("CLS");
	title();

	std::cout << "\nMr. President that missile is headed straight for the Soviets" << std::endl;

	/*if (payload == EXPLOSIVE)
	{
		std::cout << "The missile destroyed a Russian military base. Putin has vowed to not help rig your re-election campaign" << std::endl;
	}
	else
	{*/
		std::cout << "You took out the kremlin. Russia has declared war" << std::endl;

	//}
	system("PAUSE");
	missileSelect();
}

void Missile::selfDestruct()
{
	system("CLS");
	title();

	std::cout << "\n\nYou have entered the incorrect launch code to many times. The facilty will now self destruct." << std::endl;
	std::cout << "To prevent the system being jepordised. Doors are now Locked And no one may leave or enter." << std::endl;

	system("PAUSE");

	system("CLS");
	title();

	std::cout << "\n\n Death is imminent you idiot. How could you forget the most important password on the planet Trump" << std::endl;
	
	system("CLS");

	std::cout << "         )  (    (        )   (    (        )      )  (  " << std::endl;
	std::cout << "      ( /(  )\\ ) )\\ )  ( /(   )\\ ) )\\ )  ( /(   ( /(  )\\ ) " << std::endl;
	std::cout << " (    )\\())(()/((()/(  )\\()) (()/((()/(  )\\())  )\\())(()/( " << std::endl;
	std::cout << " )\\  ((_)\\  /(_))/(_))((_)\\   /(_))/(_))((_)\\  ((_)\\  /(_))" << std::endl;
	std::cout << "((_) __((_)(_)) (_))    ((_) (_)) (_))    ((_)  _((_)(_)) " << std::endl;
	std::cout << "| __|\\ \\/ /| _ \\| |    / _ \\ / __||_ _|  / _ \\ | \\| |/ __|  " << std::endl;
	std::cout << "| _|  >  < |  _/| |__ | (_) |\\__ \\ | |  | (_) || .` |\\__ \\ " << std::endl;
	std::cout << "|___|/_/\\_\\|_|  |____| \\___/ |___/|___|  \\___/ |_|\\_||___/ " << std::endl;
	std::cout << "" << std::endl;

	system("PAUSE");

	system("CLS");

	std::cout << "                   *              )               (" << std::endl;
	std::cout << " (        (      (  `          ( /(               )\\ ) " << std::endl;
	std::cout << " )\\ )     )\\     )\\))(   (     )\\()) (   (   (   (()/(" << std::endl;
	std::cout << "(()/(  ((((_)(  ((_)()\\  )\\   ((_)\\  )\\  )\\  )\\   /(_))" << std::endl;
	std::cout << " /(_))_ )\\ _ )\\ (_()((_)((_)    ((_)((_)((_)((_) (_)) " << std::endl;
	std::cout << "(_)) __|(_)_\\(_)|  \\/  || __|  / _ \\\\ \\ / / | __|| _ \\" << std::endl;
	std::cout << "  | (_ | / _ \\  | |\\/| || _|  | (_) |\\ V /  | _| |   /" << std::endl;
	std::cout << "   \\___|/_/ \\_\\ |_|  |_||___|  \\___/  \\_/   |___||_|_\\ " << std::endl;
	std::cout << "   *     (               (             *     (  " << std::endl;
	std::cout << "(  `    )\\ )      *   ) )\\ )        (  `    )\\ )" << std::endl;
	std::cout << " )\\))(  (()/(    ` )  /((()/(    (   )\\))(  (()/( " << std::endl;
	std::cout << "((_)()\\  /(_))    ( )(_))/(_))   )\\ ((_)()\\  /(_)) " << std::endl;
	std::cout << "(_()((_)(_))     (_(_())(_))  _ ((_)(_()((_)(_)) " << std::endl;
	std::cout << "|  \\/  || _ \\    |_   _|| _ \\| | | ||  \\/  || _ \\ " << std::endl;
	std::cout << "| |\\/| ||   / _    | |  |   /| |_| || |\\/| ||  _/ " << std::endl;
	std::cout << "|_|  |_||_|_\\(_)   |_|  |_|_\\ \\___/ |_|  |_||_|  " << std::endl;

	gameover = true;

	system("PAUSE");
}




