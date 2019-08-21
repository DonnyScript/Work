#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project1/trekwar.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestShip)
		{
			//Arrange
			string expName = "Don";
			Alignment extAlign = us;
			int expXloc = 4;
			int expYloc = 6;
			int expRange = 50; 
			int expcurrentHealth = 88;
			int expattackPower = 10;
			int expmaxHealth = 100; 
			string expGetType = "ship";
			string expgetStatus;
			Ship* testShipPtr = nullptr;
			testShipPtr = new Ship(expName, expXloc, expYloc, extAlign, expmaxHealth, expRange, expattackPower);
			Ship* targetShip = nullptr;
			targetShip = new Ship("Ken", 10, 20, them, 100, 50, 30);
			//Act 
			string actGetType = testShipPtr->getTypeTest();
			testShipPtr->repairShip();
			int actmaxHealth = testShipPtr->getMaxhealth();
			int actRange = testShipPtr->getRange();
			int actAttackPower = testShipPtr->getAttackPower();
			int actHealth = testShipPtr->getHealth();//Should not equal expected
			string actname = testShipPtr->getName();
			int expHealth = targetShip->getHealth();
			testShipPtr->attack(targetShip);
			int actHealthattack = targetShip->getHealth();
			int actXloc = testShipPtr->getX();
			int actYloc = testShipPtr->getY();
			int expTargetrange = 15;
			int actTargetrange = testShipPtr->getRange(targetShip);
			Alignment actAlign = testShipPtr->getAlign();
			testShipPtr->move();
			int actnewX = testShipPtr->getX();
			int actnewY = testShipPtr->getY();
			int expnewx = 5;
			int expnewY = 7;
			Alignment TactAlign = targetShip->getAlign();
			targetShip->changeAlign();
			Alignment newAlign = targetShip->getAlign();
			
			

			//Assert 
			Assert::AreEqual(expName, actname);
			Assert::IsTrue(extAlign==actAlign);
			Assert::AreEqual(expXloc, actXloc);
			Assert::AreEqual(expYloc, actYloc);
			Assert::AreEqual(expRange, actRange);
			Assert::AreNotEqual(expcurrentHealth, actHealth);
			Assert::AreEqual(expattackPower, actAttackPower);
			Assert::AreEqual(expmaxHealth, actmaxHealth);
			Assert::AreEqual(expGetType,actGetType);
			Assert::AreNotEqual(expHealth, actHealthattack);
			Assert::AreEqual(expRange, actRange);
			Assert::AreEqual(expnewx, actnewX);
			Assert::AreEqual(expnewY, actnewY);
			Assert::IsFalse(TactAlign == newAlign);
			Assert::AreEqual(expTargetrange, actTargetrange);
			
		}
		TEST_METHOD(testbBattleShip)
		{
			//Arrange
			int expXloc = 4;
			int expYloc = 6;
			string expType = "BattleShip";
			Battle* BattleShip = nullptr;
			BattleShip = new Battle("Don", expXloc, expYloc, them, 100, 10, 10);
			int startHealth = 100;
			Battle* target = nullptr;
			target = new Battle("SS Detroit", 1, 3, chaotic, startHealth, 10, 10);

			//Act
			BattleShip->move();
			int actXloc = BattleShip->getX();
			int actYloc = BattleShip->getX();
			int expTorp = 10;
			int actTorp = BattleShip->getTorpedoes(); 
			BattleShip->attack(target);
			int targetHealth = target->getHealth();
			int newTop = BattleShip->getTorpedoes();
			string actType = BattleShip->getTypeTest();
			BattleShip->setTorpedoes(0);
			int newTorp = BattleShip->getTorpedoes();
			BattleShip->attack(target);
			int targetHealth2 = target->getHealth();

			//Assert
			Assert::AreNotEqual(expXloc, actXloc);
			Assert::AreNotEqual(expYloc, actYloc);
			Assert::AreEqual(expTorp, actTorp);
			Assert::AreEqual(expType, actType);
			Assert::AreNotEqual(targetHealth, targetHealth2);
			Assert::AreNotEqual(expTorp, newTop);
			Assert::AreNotEqual(startHealth, targetHealth);
			Assert::AreNotEqual(targetHealth, targetHealth2);
		}
		TEST_METHOD(TestCruiser)
		{
			//Arrange
			int expXloc = 1;
			int expYloc = 2;
			Cruiser* TestCruiser = nullptr;
			TestCruiser = new Cruiser("Don", expXloc, expYloc, us, 50, 50, 5);
			string expType = "Cruiser";
			//Act 
			TestCruiser->move();
			int actXloc = TestCruiser->getX();
			int actYloc = TestCruiser->getY();
			string actType = TestCruiser->getTypeTest();

			//Assert
			Assert::AreNotEqual(expXloc, actXloc);
			Assert::AreNotEqual(expYloc, actYloc);
			Assert::AreEqual(expType, actType);
		}
		TEST_METHOD(testCorvette)
		{
			//Arrange
			int expXloc = 1;
			int expYloc = 2;
			Corvette* TestCorvette = nullptr;
			TestCorvette = new Corvette("Don", expXloc, expYloc, us, 50, 50, 5);
			string expType = "Corvette";
			Battle* target = nullptr;
			int startHealth = 100;
			target = new Battle("SS Detroit", 1, 3, chaotic, startHealth, 10, 10);
			//Act
			TestCorvette->move();
			int actXloc = TestCorvette->getX();
			int actYloc = TestCorvette->getY();
			string actType = TestCorvette->getTypeTest();
			Alignment initalAlign = target->getAlign();
			TestCorvette->attack(target);
			Alignment postAlign = target->getAlign();
			//Assert
			Assert::AreNotEqual(expXloc, actXloc);
			Assert::AreNotEqual(expYloc, actYloc);
			Assert::AreEqual(expType, actType);
			Assert::IsTrue(initalAlign == postAlign);

		}
		TEST_METHOD(TestRepairShip)
		{
			//Arrange
			int expXloc = 1;
			int expYloc = 2;
			string expType = "Repair";
			Repair* TestRepair = nullptr;
			TestRepair = new Repair("Don", expXloc, expYloc, us, 50, 50, 5);
			Battle* target = nullptr;
			int startHealth = 100;
			target = new Battle("SS Detroit", 1, 3, chaotic, startHealth, 10, 10);
			int damageHealth = 80;
			target->setHealth(damageHealth);
			//Act
			string actType = TestRepair->getTypeTest();
			TestRepair->attack(target);
			int FixHealth = target->getHealth();

			//Assert
			Assert::IsTrue(expType == actType);
			Assert::AreNotEqual(damageHealth, FixHealth);


		}
	};
}
