#pragma once
#include <iostream>
#include "Character.h"



class Kitana :public Character, public Player {
private:
	int _statHealth;
	int _statArmor;
	int _id;
	bool _recovery;
public:
	Kitana() {
		this->_health = 1200;
		this->_statHealth = 1200;
		this->_armor = 800;
		this->_statArmor = 800;
		this->_id = 2;
		this->_recovery = true;
	}
	int QuickKickDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 10;
		int fatality = rand() % 20;
		if (evation == 3) {
			return damage;
		}
		else if (fatality == 0) {
			damage = 10000;
		}
		else {
			damage = rand() % 70 + 151;
		}
		return damage;
	}

	int PowerKickDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 5;
		int fatality = rand() % 20;
		if (evation == 4) {
			return damage;
		}
		else if (fatality == 12) {
			damage = 10000;
		}
		else {
			damage = rand() % 100 + 171;
		}
		return damage;
	}

	int ÑounterattackDamageGanaration() override {
		int damage = 0;
		int evation = rand() % 20;
		int fatality = rand() % 14;
		if (evation == 5) {
			return damage;
		}
		else if (fatality == 7) {
			damage = 10000;
		}
		else {
			damage = rand() % 60 + 90;
		}
		return damage;
	}

	void TakingDamage(int damage) override {
		if (damage == 7000) {
			_armor = 0;
			return;
		}
		else if (damage >= _health) {
			if (_recovery) {
				_recovery = false;
				_health = 0.2 * _statHealth;
				_armor = 0;
			}
			else {
				_health = 0;
				_armor = 0;
			}
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