#pragma once

#include <iostream>
#include "Character.h"


class Scorpion :public Character, public Player {
private:
	int _statHealth;
	int _statArmor;
	int _id;
public:
	Scorpion() {
		this->_health = 1200;
		this->_statHealth = 1200;
		this->_armor = 1600;
		this->_statArmor = 1600;
		this->_id = 3;
	}

	int QuickKickDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 5;
		int fatality = rand() % 25;
		if (evation == 0) {
			return damage;
		}
		else if (fatality == 11) {
			damage = 10000;
		}
		else {
			damage = rand() % 80 + 71;
			if (_health <= 400) {
				damage *= 1.5;
			}
		}
		return damage;
	}

	int PowerKickDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 4;
		int fatality = rand() % 15;
		if (evation == 3) {
			return damage;
		}
		else if (fatality == 13) {
			damage = 10000;
		}
		else {
			damage = rand() % 100 + 101;
			if (_health <= 300) {
				damage *= 1.5;
			}
		}
		return damage;
	}

	int ÑounterattackDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 15;
		int fatality = rand() % 10;
		if (evation == 12) {
			return damage;
		}
		else if (fatality == 5) {
			damage = 10000;
		}
		else {
			damage = rand() % 60 + 71;
			if (_health <= 300) {
				damage *= 1.5;
			}
		}
		return damage;
	}

	void TakingDamage(int damage) override {
		if (damage == 7000) {
			_armor = 0;
			return;
		}
		else if (damage >= _health) {
			_health = 0;
			_armor = 0;
		}
		else if (damage > _armor && _armor != 0) {
			_armor = 0;
			_health -= damage / 2;
		}
		else if (_armor == 0 && _health > 0) {
			_health -= damage;

		}

		else {
			_armor -= damage;
			_health -= damage / 2;

		}
	}
	int GetHealth() override {
		return _health;
	}

	int GetArmor() override {
		return _armor;
	}

	int GetStatHealth() override {
		return _statHealth;
	}
	int GetStatArmor() override {
		return _statArmor;
	}

	bool CheckLose() override {
		if (_health == 0) {
			return true;
		}
		return false;
	}
	int GetID() override {
		return _id;
	}


};
