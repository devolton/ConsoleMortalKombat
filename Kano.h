#pragma once
#include <iostream>
#include "Character.h"


class Kano :public Character, public Player {
private:
	int _statHealth;
	int _statArmor;
	int _id;
public:
	Kano() {
		this->_health = 1700;
		this->_statHealth = 1700;
		this->_armor = 1200;
		this->_statArmor = 1200;
		this->_id = 5;
	}

	int QuickKickDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 7;
		int fatality = rand() % 33;
		int noArmor = rand() % 13;
		if (evation == 2) {
			return damage;
		}
		else if (fatality == 31) {
			damage = 10000;
		}
		else if (noArmor == 5) {
			damage = 7000;
		}
		else {
			damage = rand() % 100 + 91;
		}
		return damage;
	}

	int PowerKickDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 5;
		int fatality = rand() % 25;
		int noArmor = rand() % 10;
		if (evation == 3) {
			return damage;
		}
		else if (fatality == 27) {
			damage = 10000;
		}
		else if (noArmor == 5) {
			damage = 7000;
		}
		else {
			damage = rand() % 130 + 121;
		}
		return damage;
	}

	int ÑounterattackDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 20;
		int fatality = rand() % 13;
		int noArmor = rand() % 8;
		if (evation == 19) {
			return damage;
		}
		else if (fatality == 7) {
			damage = 10000;
		}
		else if (noArmor == 5) {
			damage = 7000;
		}
		else {
			damage = rand() % 80 + 91;
		}
		return damage;
	}

	void TakingDamage(int damage) override {
		if (damage >= _health) {
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