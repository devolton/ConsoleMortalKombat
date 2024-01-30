#include <iostream>
//#include <fstream>
#include <ctime>
//#include <string>
//#include <vector>
#include <chrono>
#include <thread>
#include <windows.h>
#include "PlayerDatabase.h"
#include "Character.h"
#include "SubZero.h"
#include "Kitana.h"
#include "Scorpion.h"
#include "Mileena.h"
#include "Kano.h"
#ifdef _WIN32

#endif
void PressEnter() {
#ifdef _WIN32
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = 0;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;


	input.ki.wVk = VK_RETURN;
	input.ki.dwFlags = 0;

	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));


#endif
}
void PrintMessageInputNameOfFirstPlayer() {
	std::cout << "--------------------------------" << std::endl;
	std::cout << "First player, input your name:";
}
void PrintMessageAboutFirstPlayerSelectCharacter(std::string firstPlayerName) {
	std::cout << "--------------------------------" << std::endl;
	std::cout << firstPlayerName << ", select character:";
}
void PrintMessageInputNameOfSecondPlayer() {
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Second player, input your name:";
}
void PrintMessageAboutSecondPlayerSelectCharacter(std::string secondPlayerName) {
	std::cout << "--------------------------------" << std::endl;
	std::cout << secondPlayerName << ", select character:";
}
void PrintInputNumberOfOperation() {
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Please, input number of operation: ";
}
void PrintInputCorrectNumberOfCharacter() {
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Please, input correct number of character:";
}
void PrintInputCorrectNumberOfOperation() {
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "Please, input correct number of operation: ";
}
void PrintMessageAboutSelectTypeOfKick(std::string playerName) {
	std::cout << playerName << ", select type of kick:";
}
void PrintMessageInputCorrectNumberOfKick() {
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Please, input correct number:";
}
void PrintMessageAboutFighterChoice() {
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Please, choice a fighter: ";
}
void PrintRevansh() {
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Input zero for revenge:";
}
void PrintPushBottom() {
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Please, input bottom to go back: ";
}
void SetZeroToGoBack() {
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Please, input zero to go back:";
}
void PrintMainMenu() {
	std::cout << "\t MORTAL KOMBAT" << std::endl;
	std::cout << "1 - New game" << std::endl;
	std::cout << "2 - Characters" << std::endl;
	std::cout << "3 - List of winners" << std::endl;
	std::cout << "0 - Exit" << std::endl;
	PrintInputNumberOfOperation();
}
void PrintSecondMenu(const int number) {
	system("cls");
	switch (number)
	{
	case 1:
		std::cout << "\tCHARACTERS" << std::endl;
		std::cout << "1 - Sub-Zero" << std::endl;
		std::cout << "2 - Kitana" << std::endl;
		std::cout << "3 - Scorpion" << std::endl;
		std::cout << "4 - Mileena" << std::endl;
		std::cout << "5 - Kano" << std::endl;
		std::cout << "0 - Back" << std::endl;
		break;
	case 2:
		std::cout << "\tCHARACTERS" << std::endl;
		std::cout << "1 - Sub-Zero" << std::endl;
		std::cout << "2 - Kitana" << std::endl;
		std::cout << "3 - Scorpion" << std::endl;
		std::cout << "4 - Mileena" << std::endl;
		std::cout << "5 - Kano" << std::endl;
		std::cout << "0 - Back" << std::endl;
		break;
	case 3:
		std::cout << "\tLIST OF WINNERS" << std::endl;
		std::cout << "1 - List all winners" << std::endl;
		std::cout << "2 - List the winners on a specific character" << std::endl;
		std::cout << "3 - List the winners by on a specific nickname" << std::endl;
		std::cout << "0 - Back" << std::endl;
		break;
	default:
		break;
	}

}
void PrintKickInfo() {
	std::cout << "\t\tTYPES OF KICK" << std::endl;
	std::cout << "1 - Quick Kick" << std::endl;
	std::cout << "2 - Power Kick" << std::endl;
	std::cout << "3 - Counterattack" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
}
void PrintMessageAllWinners() {
	std::cout << "\t\t\t" << "ALL WINNERS" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;

}
std::string FromNumberToCharacter(int number) {
	switch (number)
	{
	case 1:
		return "Sub-Zero";
	case 2:
		return "Kitana";
	case 3:
		return "Scorpion";
	case 4:
		return "Mileena";
	case 5:
		return "Kano";
	default:
		return"";
	}
}
void PrintCharactersInfo(const int number) {
	system("cls");
	switch (number) {
	case 1:
		std::cout << "\tSub-Zero" << std::endl;
		std::cout << "Health - 1500" << std::endl;
		std::cout << "Armor - 1000" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Quick kick: " << std::endl;
		std::cout << " -Damage(100-200)" << std::endl;
		std::cout << " -Enemy evasion probability(15%)" << std::endl;
		std::cout << " -Probability of fatality(2%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Power kick: " << std::endl;
		std::cout << " -Damage(120-220)" << std::endl;
		std::cout << " -Enemy evasion probability(25%)" << std::endl;
		std::cout << " -Probability of fatality(5%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Counterattack: " << std::endl;
		std::cout << " -Damage(70-120)" << std::endl;
		std::cout << " -Enemy evasion probability(5 %)" << std::endl;
		std::cout << " -Probability of fatality(10%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Superpower:" << std::endl;
		std::cout << " -Sub-Zero ability gives him a chance to deal double damage:" << std::endl;
		std::cout << "  1.Quick Kick(20%)" << std::endl;
		std::cout << "  2.Power Kick(10%)" << std::endl;
		std::cout << "  3.Counterattack(25%)";


		break;
	case 2:
		std::cout << "\tKitana" << std::endl;
		std::cout << "Health - 1200" << std::endl;
		std::cout << "Armor - 800" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Quick kick: " << std::endl;
		std::cout << " -Damage(150-220)" << std::endl;
		std::cout << " -Enemy evasion probability(10%)" << std::endl;
		std::cout << " -Probability of fatality(5%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Power kick: " << std::endl;
		std::cout << " -Damage(170-270)" << std::endl;
		std::cout << " -Enemy evasion probability(20%)" << std::endl;
		std::cout << " -Probability of fatality(7%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Counterattack: " << std::endl;
		std::cout << " -Damage(90-150)" << std::endl;
		std::cout << " -Enemy evasion probability(5 %)" << std::endl;
		std::cout << " -Probability of fatality(10%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Superpower:" << std::endl;
		std::cout << " -Kitana's ability allows her to recover 20% of her health if it reaches 0!";
		break;
	case 3:
		std::cout << "\tScorpion" << std::endl;
		std::cout << "Health - 1200" << std::endl;
		std::cout << "Armor - 1600" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Quick kick: " << std::endl;
		std::cout << " -Damage(70-150)" << std::endl;
		std::cout << " -Enemy evasion probability(20%)" << std::endl;
		std::cout << " -Probability of fatality(4%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Power kick: " << std::endl;
		std::cout << " -Damage(100-200)" << std::endl;
		std::cout << " -Enemy evasion probability(25%)" << std::endl;
		std::cout << " -Probability of fatality(7%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Counterattack: " << std::endl;
		std::cout << " -Damage(70-130)" << std::endl;
		std::cout << " -Enemy evasion probability(7 %)" << std::endl;
		std::cout << " -Probability of fatality(10%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Superpower:" << std::endl;
		std::cout << " -When Scorpion's health reaches 400 his damage is increases by 1.5 times!";
		break;
	case 4:
		std::cout << "\tMileena" << std::endl;
		std::cout << "Health - 1100" << std::endl;
		std::cout << "Armor - 900" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Quick kick: " << std::endl;
		std::cout << " -Damage(120-250)" << std::endl;
		std::cout << " -Enemy evasion probability(11%)" << std::endl;
		std::cout << " -Probability of fatality(5%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Power kick: " << std::endl;
		std::cout << " -Damage(150-300)" << std::endl;
		std::cout << " -Enemy evasion probability(18%)" << std::endl;
		std::cout << " -Probability of fatality(5%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Counterattack: " << std::endl;
		std::cout << " -Damage(70-180)" << std::endl;
		std::cout << " -Enemy evasion probability(7 %)" << std::endl;
		std::cout << " -Probability of fatality(7%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Superpower:" << std::endl;
		std::cout << " -Mileena's ability allows her to dodge the enemy's first fatality!";

		break;
	case 5:
		std::cout << "\tKano" << std::endl;
		std::cout << "Health - 1700" << std::endl;
		std::cout << "Armor - 1200" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Quick kick: " << std::endl;
		std::cout << " -Damage(90-190)" << std::endl;
		std::cout << " -Enemy evasion probability(15%)" << std::endl;
		std::cout << " -Probability of fatality(3%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Power kick: " << std::endl;
		std::cout << " -Damage(120-250)" << std::endl;
		std::cout << " -Enemy evasion probability(20%)" << std::endl;
		std::cout << " -Probability of fatality(4%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Counterattack: " << std::endl;
		std::cout << " -Damage(90-170)" << std::endl;
		std::cout << " -Enemy evasion probability(5%)" << std::endl;
		std::cout << " -Probability of fatality(8%)" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Superpower:" << std::endl;
		std::cout << " -Kano's ability gives him a chance to break enemy armor:" << std::endl;
		std::cout << "  Quick kick(8%)" << std::endl;
		std::cout << "  Power kick(10%)" << std::endl;
		std::cout << "  Counterattack(13%)";

	}
}
void PrintCharacterWinners(int number) {
	std::cout << "\t\t" << "ALL WINNERS " << "'" << FromNumberToCharacter(number) << "'" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
}
void PrintNameWinners(std::string name) {
	std::cout << "\t\t" << "ALL WINNERS WITH NAME " << "'" << name << "'" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------" << std::endl;
}

class Action {
public:
	int DamageGanaration(Character* hero, int number) {
		if (number == 1) {
			return hero->QuickKickDamageGanaration();
		}
		else if (number == 2) {
			return hero->PowerKickDamageGanaration();
		}
		else {
			return hero->ÑounterattackDamageGanaration();
		}

	}
	void TakingDamage(Character* hero, int damage) {
		return hero->TakingDamage(damage);
	}
	bool ChackLose(Character* hero) {
		return	hero->CheckLose();
	}

	void PrintCharactersXP(Character* firstHero, Character* secondHero) {
		const int FIRSTHEALTH = firstHero->GetStatHealth();
		const int SECONDHEALTH = secondHero->GetStatHealth();
		const int FIRSTARMOR = firstHero->GetStatArmor();
		const int SECONDARMOR = secondHero->GetStatArmor();
		std::string firstName = FromNumberToCharacter(firstHero->GetID());
		std::string secondName = FromNumberToCharacter(secondHero->GetID());
		std::cout << "\t\t   " << "FIGHT!" << std::endl;
		std::cout << "\t" << firstName << "\t\t" << secondName << std::endl;
		std::cout << "   Armor:  " << firstHero->GetArmor() << "/" << FIRSTARMOR << "\t" << "   Armor: " << secondHero->GetArmor() << "/" << SECONDARMOR << std::endl;
		std::cout << "   Health: " << firstHero->GetHealth() << "/" << FIRSTHEALTH << "\t" << "   Health: " << secondHero->GetHealth() << "/" << SECONDHEALTH << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;

	}

	void PrintTakingDamageMessage(Character* damagingHero, Character* damagedHero, int damage) {
		if (damage == 0) {
			std::cout << "------------------------------------------------------" << std::endl;
			std::cout << FromNumberToCharacter(damagedHero->GetID())
				<< " dodging " << FromNumberToCharacter(damagingHero->GetID()) << "'s powerfull blow!" << std::endl;
			std::cout << "------------------------------------------------------" << std::endl;
		}
		else if (damage == 7000) {
			std::cout << "------------------------------------------------------" << std::endl;
			std::cout << FromNumberToCharacter(damagingHero->GetID())
				<< " beats " << FromNumberToCharacter(damagedHero->GetID()) << "'s armor!" << std::endl;
			std::cout << "------------------------------------------------------" << std::endl;
		}
		else if (damage == 10000) {
			std::cout << "------------------------------------------------------" << std::endl;
			std::cout << FromNumberToCharacter(damagingHero->GetID())
				<< " inflicts " << FromNumberToCharacter(damagedHero->GetID()) << "'s fatality!!!" << std::endl;
			std::cout << "------------------------------------------------------" << std::endl;
		}
		else {
			std::cout << "------------------------------------------------------" << std::endl;
			std::cout << FromNumberToCharacter(damagingHero->GetID())
				<< " inflicts " << damage << " damage to " << FromNumberToCharacter(damagedHero->GetID()) << "!" << std::endl;
			std::cout << "------------------------------------------------------" << std::endl;
		}
	}

	void PrintWinner(std::string playerName, Character* firstHero, Character* secondHero, int damage) {
		const int FIRSTHEALTH = firstHero->GetStatHealth();
		const int SECONDHEALTH = secondHero->GetStatHealth();
		const int FIRSTARMOR = firstHero->GetStatArmor();
		const int SECONDARMOR = secondHero->GetStatArmor();
		std::string firstName = FromNumberToCharacter(firstHero->GetID());
		std::string secondName = FromNumberToCharacter(secondHero->GetID());
		std::cout << "\t\t   END OF THE GAME!!!" << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << "\t" << firstName << "\t\t" << secondName << std::endl;
		std::cout << "   Armor:  " << firstHero->GetArmor() << "/" << FIRSTARMOR << "\t" << "   Armor: " << secondHero->GetArmor() << "/" << SECONDARMOR << std::endl;
		std::cout << "   Health: " << firstHero->GetHealth() << "/" << FIRSTHEALTH << "\t" << "   Health: " << secondHero->GetHealth() << "/" << SECONDHEALTH << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;
		if (damage == 10000) {
			std::cout << firstName << " inflicts a fatality and defeats " << secondName << "!!!" << std::endl;
		}
		else {
			std::cout << firstName << " defeats " << secondName << " with a powerful blow!!!" << std::endl;
		}
		std::cout << "------------------------------------------------------" << std::endl;
		std::cout << playerName << " is winner!" << std::endl;
	}
};

int main() {
	srand(time(0));
	PlayerDatabase database;
	int number;
	PrintMainMenu();
	while (true) {
		bool pass = false;
		std::cin >> number;
		if (number > 3 || number < 0) {
			PrintInputCorrectNumberOfOperation();
			continue;
		}
		else if (number == 0) {
			system("exit");
			break;
		}
		while (true) {
			PrintSecondMenu(number);
			if (number == 0) {
				break;
			}
			else if (number == 1) {
				PrintSecondMenu(number);
				std::string firstPlayerName;
				int firstNumber;
				int secondNumber;
				std::string secondPlayerName;
				PrintMessageInputNameOfFirstPlayer();
				std::cin.ignore();
				getline(std::cin, firstPlayerName);
				PrintMessageAboutFirstPlayerSelectCharacter(firstPlayerName);
				while (true) {
					std::cin >> firstNumber;
					if (firstNumber > 5 || firstNumber < 1) {
						PrintInputCorrectNumberOfCharacter();
						continue;
					}
					break;
				}
				std::cin.ignore();
				PrintMessageInputNameOfSecondPlayer();
				getline(std::cin, secondPlayerName);
				PrintMessageAboutSecondPlayerSelectCharacter(secondPlayerName);
				while (true) {
					std::cin >> secondNumber;
					if (secondNumber > 5 || secondNumber < 1) {
						PrintInputCorrectNumberOfCharacter();
						continue;
					}
					break;
				}
				while (true) {
					bool fightPass = false;
					Player firstPlayer(FromNumberToCharacter(firstNumber), firstPlayerName);
					Player secondPlayer(FromNumberToCharacter(secondNumber), secondPlayerName);
					Character* firstHero;
					Character* secondHero;
					if (firstNumber == 1) {
						SubZero subzero;
						firstHero = &subzero;
					}
					else if (firstNumber == 2) {
						Kitana kitana;
						firstHero = &kitana;
					}
					else if (firstNumber == 3) {
						Scorpion scorpion;
						firstHero = &scorpion;
					}
					else if (firstNumber == 4) {
						Mileena mileena;
						firstHero = &mileena;
					}
					else {
						Kano kano;
						firstHero = &kano;
					}

					if (secondNumber == 1) {
						SubZero subzero;
						secondHero = &subzero;
					}
					else if (secondNumber == 2) {
						Kitana kitana;
						secondHero = &kitana;
					}
					else if (secondNumber == 3) {
						Scorpion scorpion;
						secondHero = &scorpion;
					}
					else if (secondNumber == 4) {
						Mileena mileena;
						secondHero = &mileena;
					}
					else {
						Kano kano;
						secondHero = &kano;
					}

					Action act;
					int damageNumber;
					int damage;
					while (true) {
						system("cls");
						PrintKickInfo();
						act.PrintCharactersXP(firstHero, secondHero);
						PrintMessageAboutSelectTypeOfKick(firstPlayerName);
						while (true) {
							std::cin >> damageNumber;
							if (damageNumber > 3 || damageNumber < 1) {
								PrintMessageInputCorrectNumberOfKick();
								continue;
							}
							break;
						}
						damage = act.DamageGanaration(firstHero, damageNumber);
						act.TakingDamage(secondHero, damage);
						act.PrintTakingDamageMessage(firstHero, secondHero, damage);
						if (act.ChackLose(secondHero)) {
							system("cls");
							database.AddNewPlayer(firstPlayer);
							database.SavePlayerToFile();
							act.PrintWinner(firstPlayerName, firstHero, secondHero, damage);
							int passLine;
							PrintRevansh();
							std::cin >> passLine;
							if (passLine == 0) {
								fightPass = true;
							}
							else {
								pass = true;
							}
							break;
						}
						PrintMessageAboutSelectTypeOfKick(secondPlayerName);
						while (true) {
							std::cin >> damageNumber;
							if (damageNumber > 3 || damageNumber < 1) {
								PrintMessageInputCorrectNumberOfKick();
								continue;
							}
							pass = true;
							break;
						}
						damage = act.DamageGanaration(secondHero, damageNumber);
						act.TakingDamage(firstHero, damage);
						act.PrintTakingDamageMessage(secondHero, firstHero, damage);

						if (act.ChackLose(firstHero)) {
							system("cls");
							database.AddNewPlayer(secondPlayer);
							database.SavePlayerToFile();
							act.PrintWinner(secondPlayerName, secondHero, firstHero, damage);
							int passLine;
							PrintRevansh();
							std::cin >> passLine;
							if (passLine == 0) {
								fightPass = true;
							}
							else {
								pass = true;
							}
							break;
						}
						std::chrono::seconds sec(1);
						std::this_thread::sleep_for(sec);

					}

					if (fightPass) {
						continue;
					}

					break;
				}




			}
			else if (number == 2) {
				while (true) {
					PrintMessageAboutFighterChoice();
					while (true) {
						std::cin >> number;
						if (number > 5 || number < 0) {
							PrintInputCorrectNumberOfOperation();
							continue;
						}
						break;
					}
					if (number == 0) {
						pass = true;
						break;
					}
					PrintCharactersInfo(number);
					std::cout << std::endl;
					std::string bottom;
					PrintPushBottom();
					std::cin >> bottom;

					PressEnter();
					std::cin.ignore();
					PrintSecondMenu(2);
					continue;

					break;
				}
			}
			else if (number == 3) {
				while (true) {
					bool internalPass = false;
					PrintInputNumberOfOperation();
					while (true) {
						std::cin >> number;
						if (number < 0 || number>3) {
							PrintInputCorrectNumberOfOperation();
							continue;
						}
						break;
					}
					if (number == 0) {
						pass = true;
						break;
					}
					database.LoadPlayerFromFile();
					system("cls");
					if (number == 1) {
						while (true) {
							PrintMessageAllWinners();
							database.PrintAllPlayer();
							std::string bottom;
							PrintPushBottom();
							std::cin >> bottom;
							PressEnter();
							internalPass = true;

							break;
						}
					}
					else if (number == 2) {
						PrintSecondMenu(number);
						PrintMessageAboutFighterChoice();
						while (true) {
							std::cin.ignore();
							std::cin >> number;
							if (number > 5 || number < 0) {
								PrintInputCorrectNumberOfOperation();
								continue;
							}
							else if (number == 0) {
								internalPass = true;
								break;
							}
							system("cls");
							PrintCharacterWinners(number);
							database.PrintInfoByCharacter(FromNumberToCharacter(number));
							std::string bottom;
							PrintPushBottom();
							std::cin >> bottom;
							internalPass = true;
							PressEnter();
							break;
						}
					}
					else if (number == 3) {
						while (true) {
							std::string name;
							std::cin.ignore();
							std::cout << "Please, input your name:";
							getline(std::cin, name);
							system("cls");
							PrintNameWinners(name);
							database.PrintInfoByPlayer(name);
							PrintPushBottom();
							std::cin >> name;
							PressEnter();
							internalPass = true;

							break;

						}
					}
					if (internalPass) {
						std::cin.ignore();
						PrintSecondMenu(3);
						continue;

					}
					break;
				}

			}

			break;
		}


		if (pass) {
			std::cin.ignore();
			system("cls");
			PrintMainMenu();
			continue;
		}
		break;

	}


}