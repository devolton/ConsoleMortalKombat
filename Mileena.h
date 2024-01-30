#pragma once
#include <iostream>
#include "Character.h"
class Mileena : public Character, public Player {
private:
	int _statHealth;
	int _statArmor;
	int _id;
	bool _noFatality;
public:
	Mileena() {
		this->_health = 1100;
		this->_statHealth = 1100;
		this->_armor = 900;
		this->_statArmor = 900;
		this->_id = 4;
		this->_noFatality = true;
	}

	int QuickKickDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 10;
		int fatality = rand() % 18;
		if (evation == 8) {
			return damage;
		}
		else if (fatality == 3) {
			damage = 10000;
		}
		else {
			damage = rand() % 120 + 121;
		}
		return damage;
	}

	int PowerKickDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 6;
		int fatality = rand() % 17;
		if (evation == 4) {
			return damage;
		}
		else if (fatality == 8) {
			damage = 10000;
		}
		else {
			damage = rand() % 150 + 151;
		}
		return damage;
	}

	int ÑounterattackDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 15;
		int fatality = rand() % 14;
		if (evation == 14) {
			return damage;
		}
		else if (fatality == 8) {
			damage = 10000;
		}
		else {
			damage = rand() % 110 + 71;
		}
		return damage;
	}

	void TakingDamage(int damage) override {

		if (damage == 7000) {
			_armor = 0;
			return;
		}
		else if (damage >= _health) {
			if (_noFatality) {
				_noFatality = false;
				return;
			}
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

	bool CheckLose() override {
		if (_health == 0) {
			return true;
		}
		return false;
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
	int GetID() override {
		return _id;
	}
};