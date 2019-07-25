#ifndef INITIAL_TRAIN_H
#define INITIAL_TRAIN_H

#include <iostream>
#include <queue>
#include <stack> 
using namespace std;

class DockTrain
{
    private:
    queue <stack<int>> Train;

    public:

    void Load(vector<int> TrainCargo)
    {
        int iterator = 0;
		int itSecond = 0;
        int Containers = TrainCargo.size() / 5;
        if (TrainCargo.size() % 5 != 0)
        {
            Containers++;
        }
        stack<int>* CargoItems = new stack<int>[Containers];

			for (int stack = 0; stack < TrainCargo.size(); stack++)
			{ 
				CargoItems[iterator].push(TrainCargo.at(stack));
				if ((itSecond % 4 == 0) && (itSecond != 0))
				{
					this->Train.push(CargoItems[iterator]);
					iterator++;
					itSecond = -1; 
				}
				itSecond++;
			}
			if (TrainCargo.size() % 5 != 0)
			{
				this->Train.push(CargoItems[iterator]);
			}
    }

    int unLoad()
    {
        if (Train.front().empty())
        {
            Train.pop();
        }
        int CargoItem;
        CargoItem = Train.front().top();
        Train.front().pop();
        return CargoItem;
    }
    bool DockTrainNotEmpty()
    {
        return Train.empty();
    }
};

class TrainGuy
{
    private:
        int time;
        int CurrentCargo;

    public:
		TrainGuy()
		{
			time = 0;
		}

        int giveTime()
        {
            return time;
        }

        int getCurrentCargo()
        {
            return CurrentCargo;
        }

		void setCurrentCargo(int cargo)
		{
			this->CurrentCargo = cargo;
		}
        
		int UnloadCargo()
		{
			time = time + CurrentCargo;
			return CurrentCargo;
		}
		
		void BackToTrain()
		{
			time = time + CurrentCargo;
		}
		
       

};

#endif

