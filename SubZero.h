#pragma once
#include <iostream>
#include "Character.h"

class SubZero : public Character, public Player {
private:
	int _statHealth;
	int _statArmor;
	int _id;
public:
	SubZero() {
		this->_health = 1500;
		this->_statHealth = 1500;
		this->_armor = 1000;
		this->_statArmor = 1000;
		this->_id = 1;
	}
	int QuickKickDamageGanaration() override {
		int damage = 0;
		int evasion = rand() % 7;
		int fatality = rand() % 50;
		int doubleDamage = rand() % 5;
		if (evasion == 5) {
			return damage;
		}
		else if (fatality == 5) {
			damage = 10000;
		}
		else {
			damage = rand() % 80 + 71;
			if (doubleDamage == 1) {
				damage *= 2;
			}
		}
		return damage;
	}
	int PowerKickDamageGanaration() override {
		int damage = 0;
		int evasion = rand() % 4;
		int fatality = rand() % 20;
		int doubleDamage = rand() % 10;
		if (evasion == 2) {
			return damage;
		}
		else if (fatality == 10) {
			damage = 10000;
		}
		else {
			damage = rand() % 100 + 121;
			if (doubleDamage == 1) {
				damage *= 2;
			}
		}
		return damage;
	}
	int ÑounterattackDamageGanaration() override {
		int damage = 0;
		int evasion = rand() % 20;
		int fatality = rand() % 10;
		int doubleDamage = rand() % 4;
		if (evasion == 7) {
			return damage;
		}
		else if (fatality == 1) {
			damage = 10000;
		}
		else {
			damage = rand() % 50 + 71;
			if (doubleDamage == 3) {
				damage *= 2;
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