#pragma once
#include <iostream>

class Character {
public:
	virtual int QuickKickDamageGanaration() = 0;
	virtual int PowerKickDamageGanaration() = 0;
	virtual int ÑounterattackDamageGanaration() = 0;
	virtual void TakingDamage(int damage) = 0;
	virtual bool CheckLose() = 0;
	virtual int GetArmor() = 0;
	virtual int  GetHealth() = 0;
	virtual int GetStatHealth() = 0;
	virtual int GetStatArmor() = 0;
	virtual int GetID() = 0;


};