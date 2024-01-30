#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>


class PlayerDatabase;
class Player {
protected:
	int _health;
	int _armor;
	std::string _characterName;
private:
	std::string _playerName;

	std::string ToJsonString() {
		std::string result;
		nlohmann::json jsonObject;
		jsonObject["_characterName"] = _characterName;
		jsonObject["_playerName"] = _playerName;
		jsonObject["_armor"] = _armor;
		jsonObject["_health"] = _health;
		result = jsonObject.dump();
		return result;

	}


public:
	friend PlayerDatabase;
	void PrintInfo() {
		std::cout << "Player name: " << _playerName << " | Character: " << _characterName <<
			" | Health amount: " << _health << " | Armor amount: " << _armor << std::endl;
	}
	Player() {

	}
	Player(std::string characterName, std::string playerName) {
		this->_playerName = playerName;
		this->_characterName = characterName;
		if (characterName == "Sub-Zero") {
			this->_health = 1500;
			this->_armor = 1000;
		}
		else if (characterName == "Kitana") {
			this->_health = 1200;
			this->_armor = 800;
		}
		else if (characterName == "Scorpion") {
			this->_health = 1200;
			this->_armor = 1600;
		}
		else if (characterName == "Mileena") {
			this->_health = 1100;
			this->_armor = 900;
		}
		else if (characterName == "Kano") {
			this->_health = 1700;
			this->_armor = 1200;
		}
	}


};

class PlayerDatabase: public Player {
private:
	std::string _databaseFileName = "database.txt";
	std::vector<Player> database;

	Player FromJsonStringToCharacter(std::string jsonString) {
		Player result;
		nlohmann::json jsonObject = nlohmann::json::parse(jsonString);
		result._health = jsonObject["_health"].get<int>();
		result._armor = jsonObject["_armor"].get<int>();
		result._characterName = jsonObject["_characterName"].get<std::string>();
		result._playerName = jsonObject["_playerName"].get<std::string>();

		return result;

	}
public:
	void SavePlayerToFile() {
		std::ofstream fout(_databaseFileName, std::fstream::app);
		for (int i = 0; i < database.size(); i++) {
			fout << database[i].ToJsonString() << std::endl;
		}
		fout.close();
		database.clear();
	}
	void LoadPlayerFromFile() {
		std::ifstream fin(_databaseFileName);
		std::string line;
		database.clear();
		if (!fin.is_open()) {
			std::cout << "File error!" << std::endl;
			return;
		}
		while (!fin.eof()) {
			getline(fin, line);
			if (line == "") {
				continue;
			}
			Player temp = FromJsonStringToCharacter(line);
			AddNewPlayer(temp);
		}
		fin.close();
	}
	void AddNewPlayer(Player player) {
		database.push_back(player);
	}
	void PrintAllPlayer() {
		for (Player character : database) {
			character.PrintInfo();
		}
	}
	void PrintInfoByCharacter(std::string character) {
		for (int i = 0; i < database.size(); i++) {
			if (database[i]._characterName == character) {
				database[i].PrintInfo();
			}
		}
	}
	void PrintInfoByPlayer(std::string player) {
		bool pass = true;
		for (int i = 0; i < database.size(); i++) {
			if (database[i]._playerName == player) {
				database[i].PrintInfo();
				pass = false;
			}
		}
		if (pass) {
			std::cout << "Player with this name not found!" << std::endl;
		}
	}
	~PlayerDatabase() {
		database.clear();
	}
};
