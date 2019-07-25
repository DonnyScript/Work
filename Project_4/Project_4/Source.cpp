#include "Initial_Train.h"
#include "Plane.h"

using namespace std;
int main()
{
	int numTrains;
	int numPlanes;
	int TrainItems;
	int PlaneItems;
	vector<int> TrainCargo;
	queue <int> PlaneCargo;
	DockTrain Dock;
	PlaneGuy planeLoader;


	cout << "Input Trains, Planes, Items on the train, items on the planes. Like(t p nt np):  ";
	cin >> numTrains >> numPlanes >> TrainItems >> PlaneItems;
	vector<vector<int>> Trains(numTrains);
	int LoadTimes[100] = { 0 };
	vector<int> trainSize;
	vector<vector<int>> Planes(numPlanes);
	vector<int> planeSizes;
	int planeLoadTime[10] = { 0 };
	TrainGuy Worker;
	


	cout << "Input number of items each train: "; 
	for (int index = 0; index < Trains.size(); index++)
	{
		int size;
		cin >> size;
		trainSize.push_back(size);
	}
	

	cout << "\n";
	cout << "Input number of items on each plane: ";
	for (int index = 0; index < Planes.size(); index++)
	{
		int planeSize;
		cin >> planeSize;
		planeSizes.push_back(planeSize);
	}
	

	cout << "\n";
	cout << "Cargo loaded into trains: ";
	for (int index = 0; index < TrainItems; index++)
	{
		int container;
		cin >> container;
		TrainCargo.push_back(container);
	}
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


	cout << "\n";
	cout << "Cargo loaded into planes: ";
	for (int index = 0; index < PlaneItems; index++)
	{
		int container;
		cin >> container;
		PlaneCargo.push(container);
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
    


	cout << '\n';
	for (int item = 0; item < numTrains; item++)
	{
		cout << LoadTimes[item] << " ";
	}
	cout << '\n';
	for (int item = 0; item < numPlanes; item++)
	{
		cout << planeLoadTime[item] << " ";
	}
    
    return 0; 
}