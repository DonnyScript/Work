#ifndef TREKWAR_H
#define TREKWAR_H
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

enum Alignment { us, them, chaotic };

class Ship
{
protected:
	string name;
	Alignment align;
	int xLoc;
	int yLoc;
	int range;
	int currentHealth;
	int attackPower;
	int maxHealth;
private:
	virtual string getType()//Test wrote
	{
		return "ship";
	}
public:
	Ship(string name, int x, int y, Alignment align, int maxHealth, int range, int attackPower)//Test wrote
	{
		{
			this->name = name;
			xLoc = x;
			yLoc = y;
			this->align = align;
			this->maxHealth = maxHealth;
			this->range = range;
			this->attackPower = attackPower;
			this->currentHealth = maxHealth;
		}
	}
	void setHealth(int Health)
	{
		this->currentHealth = Health;
	}
	string getTypeTest()//test done
	{
		return this->getType();
	}
	void repairShip()//Test done
	{
		this->currentHealth = this->maxHealth;
	}
	int getMaxhealth()//test done
	{
		return this->maxHealth;
	}
	int getRange()//test done
	{
		return this->range;
	}
	int getHealth()//test done
	{
		return currentHealth;
	}
	string getName()//test Done 
	{
		return this->name;
	}
	int getAttackPower()
	{
		return this->attackPower;
	}


	virtual void attack(Ship* target)//test done 
	{
		int range;
		range = this->getRange(target);
		if ((this->range >= range) && (target->getAlign() != this->getAlign()))
		{
		
				target->accessDamage(this->attackPower);
			
		}
	}
	int getX()//Test done
	{
		return xLoc;
	}
	int getY()//test done 
	{
		return yLoc;
	}
	int getRange(Ship* target)//test Done 
	{
		int enemyRange;
		int targetX = target->getX();
		int targetY = target->getY();
		int thisX = this->getX();
		int thisY = this->getY();
		enemyRange = sqrt(pow(targetX - thisX, 2) + pow(thisY - targetY, 2));

		return enemyRange;
	}
	Alignment getAlign()//testDone 
	{
		return align;
	}
	string status()// Ask question for these 
	{
		string print = "Name: \n"
			"Type:  \n"
			"health:  \n"
			"Location:   \n";
		print.insert(5, name);
		print.insert(15, getType());
		string health1 = to_string(currentHealth);
		print.insert(32, health1);
		print.insert(47, "(");
		print.insert(49, ",");
		string xloc = to_string(this->xLoc);
		print.insert(48, xloc);
		string yloc = to_string(this->yLoc);
		print.insert(52, yloc);
		print.insert(53, ")");
		return print;
	}
	virtual void move()// Test done 
	{
		if (this->getHealth() != 0)
		{
			xLoc++;
			yLoc++;
		}
	}
	void changeAlign()//Done 
	{
		if(this->align == us)
		{
			this->align = them;
		}
		if(this->align == them)
		{
			this->align = us;
		}
	}

	void accessDamage(int amt)//test Done 
	{

		if (0 < (currentHealth + amt) < maxHealth)
		{
			currentHealth = currentHealth - amt;
		}
	}
};


class Battle : public Ship
{
public:
	Battle(string name, int x, int y, Alignment align, int maxHealth, int range, int attackPower) :Ship(name, x, y, align, maxHealth, range, attackPower)
	{
		torpedoes = 10;
		range = 10;
		maxHealth = 100;
		attackPower = 10;
		this->name = name;
		xLoc = x;
		yLoc = y;
		this->align = align;
		this->maxHealth = maxHealth;
		this->range = range;
		this->attackPower = attackPower;
		this->currentHealth = maxHealth;
	}
	virtual void move()
	{
		if (this->getHealth() != 0)
		{
			this->xLoc -= 1;
			this->yLoc -= 1;
		}
	}
	string status()//Ask about this
	{
		string print = "Name: \n"
			"Type:  \n"
			"health:  \n"
			"Location:  \n";
		print.insert(5, name);
		print.insert(15, getType());
		auto health1 = to_string(currentHealth);
		print.insert(47, "(");
		print.insert(49, ",");
		string xloc = to_string(xLoc);
		print.insert(48, xloc);
		auto yloc = to_string(yLoc);
		print.insert(52, yloc);
		print.insert(53, ")");
		print.insert(35, health1);
		print.insert(58, "Torpedoes: ");
		auto torpedo = to_string(torpedoes);
		print.insert(68, torpedo);
		return print;

	}
	virtual void attack(Ship* target)//Make so it takes in account range
	{
		int range;
		range = this->getRange(target);
		if ((this->range >= range) && (target->getAlign() != this->getAlign()))
		{

			if (torpedoes > 0)
			{
				target->accessDamage(this->attackPower + 10);
				torpedoes = torpedoes - 1;
			}
			else
			{
				target->accessDamage(this->attackPower);
			}

			if (target->getAlign() == chaotic)
			{
				if (torpedoes > 0)
				{
					target->accessDamage(10);
					torpedoes = torpedoes - 1;
				}
				else
				{
					target->accessDamage(10);
				}
			}

		}
	}
	void setTorpedoes(int Num)
	{
		this->torpedoes = Num;
	}
	int getTorpedoes()
	{
		return this->torpedoes;
	}
private:
	virtual string getType()
	{
		return "BattleShip";
	}
	int torpedoes;
};

class Cruiser : public Ship
{
public:
	Cruiser(string name, int x, int y, Alignment align, int maxHealth, int range, int attackPower) : Ship(name, x, y, align, maxHealth, range, attackPower)
	{
		range = 50;
		maxHealth = 50;
		attackPower = 5;
		this->name = name;
		xLoc = x;
		yLoc = y;
		this->align = align;
		this->maxHealth = maxHealth;
		this->range = range;
		this->attackPower = attackPower;
		this->currentHealth = maxHealth;

	}
	
	virtual void move()
	{
		if (this->getHealth() != 0)
		{
			xLoc = xLoc + 1;
			yLoc = yLoc + 2;
		}
	}

private:
	virtual string getType()
	{
		return "Cruiser";
	}
};
class Corvette : public Ship//finish constructor
{
public:
	Corvette(string name, int x, int y, Alignment align, int maxHealth, int range, int attackPower) :Ship(name, x, y, align, maxHealth, range, attackPower)
	{
		this->range = range;
		this->maxHealth = maxHealth;
		this->currentHealth = currentHealth; 
		this->name = name;
		xLoc = x;
		yLoc = y;
		this->align = align;
		this->maxHealth = maxHealth;
		this->range = range;
		this->attackPower = attackPower;
		this->currentHealth = maxHealth;
	}

	virtual void attack(Ship* target)//Make so it takes in account range
	{
		int range;
		range = this->getRange(target);
		if (this->range >= range)
		{
			if (target->getAlign() == us)
			{
				target->changeAlign();
			}
			if (target->getAlign() == them)
			{
				target->changeAlign();
			}
		}
	}
	virtual void move()
	{
		if (this->getHealth() != 0)
		{
			this->xLoc += 5;
			this->yLoc += 5;
		}
	}
private:
	virtual string getType()
	{
		return "Corvette";
	}
};

class Repair : public Cruiser//finish constructor 
{
private:
	virtual string getType()
	{
		return "Repair";
	}
public:
	Repair(string name, int x, int y, Alignment align, int maxHealth, int range, int attackPower) :Cruiser(name, x, y, align, maxHealth, range, attackPower)
	{
		this->range = range;
		this->maxHealth = maxHealth;
		this->currentHealth = currentHealth;
		this->name = name;
		xLoc = x;
		yLoc = y;
		this->align = align;
		this->maxHealth = maxHealth;
		this->range = range;
		this->attackPower = attackPower;
		this->currentHealth = maxHealth;
	}
	virtual void attack(Ship* target)//FINISH note made 06/14/19
	{
		int range;
		range = this->getRange(target);
		if ((this->range > range) && (target->getAlign() != this->getAlign()) && (target->getHealth() != 0))
		{
			target->repairShip();
		}
	}
};




#endif // TREKWAR_H