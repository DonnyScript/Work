#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project_4/Initial_Train.h"
#include "..//Project_4/Plane.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_Orginal)// Stayed up for hours trying to figure this out but it just would not test my values 
		{
			using namespace std;
			
			
				int numTrains = 3;
				int numPlanes = 2;
				int TrainItems = 10;
				int PlaneItems = 5;
				vector<int> TrainCargo = { 2,2,2,1,3,2,2,2,1,2};
				queue <int> PlaneCargo;
				DockTrain Dock;
				PlaneGuy planeLoader;


				
				vector<vector<int>> Trains(numTrains);
				int LoadTimes[100] = { 0 };
				vector<int> trainSize = { 2,7,1 };
				vector<vector<int>> Planes(numPlanes);
				vector<int> planeSizes = { 3,2 };
				int planeLoadTime[10] = { 0 };
				TrainGuy Worker;





					TrainCargo.push_back(2);
					TrainCargo.push_back(1);
					TrainCargo.push_back(1);
					TrainCargo.push_back(2);
					TrainCargo.push_back(1);
				
				Dock.Load(TrainCargo);

				for (int index = 0; index < TrainItems; index++)
				{
					Worker.setCurrentCargo(Dock.unLoad());
					Trains.at(Worker.getCurrentCargo() - 1).push_back(Worker.UnloadCargo());
					if (Trains.at(Worker.getCurrentCargo() - 1).size() == trainSize.at(Worker.getCurrentCargo() - 1))
					{
						LoadTimes[Worker.getCurrentCargo() - 1] = Worker.giveTime();

					}
					Worker.BackToTrain();
				}


				for (int index = 0; index < PlaneItems; index++)
				{
					planeLoader.setCurrentCargo(PlaneCargo.front());
					Planes.at(planeLoader.getCurrentCargo() - 1).push_back(planeLoader.unloadCargo());
					PlaneCargo.pop();
					if (Planes.at(planeLoader.getCurrentCargo() - 1).size() == planeSizes.at(planeLoader.getCurrentCargo() - 1))
					{
						planeLoadTime[planeLoader.getCurrentCargo() - 1] = planeLoader.getTime();
					}
					planeLoader.BacktoTrain();
				}
				int expLoadTimes[] = { 25,36,3 };
				int expPlaneLoadTimes[] = { 65,50 };


				Assert::IsTrue(expLoadTimes[0]==LoadTimes[0]);
				Assert::IsTrue(expLoadTimes[1]== LoadTimes[1]);
				Assert::IsTrue(expLoadTimes[2]== LoadTimes[2]);
				Assert::IsTrue(expPlaneLoadTimes[0]== planeLoadTime[0]);
				Assert::IsTrue(expPlaneLoadTimes[1]== planeLoadTime[1]);
				Assert::IsTrue(expPlaneLoadTimes[2]== planeLoadTime[2]);

				

				
			
		}
	};
}
