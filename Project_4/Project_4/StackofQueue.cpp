
#include <iostream>
#include <stack> 
#include <queue>

using namespace std;

int main()
{
	queue<stack<int>> TrainYard;
	cout << "How many trains: ";
	int trainNum;
	cin >> trainNum;
	//stack <int> trains[trainNum];
	stack<int>* trains = new stack<int>[trainNum];
	for (int i = 0; i < trainNum; i++)
	{
		int num;
		cin >> num;
		trains[i].push(num);
	}
	for (int i = 0; i < trainNum; i++)
	{
		cout << trains[i].top();
	}
	 for (int i = 0; i < trainNum;i++)
	 {
		 TrainYard.push(trains[i]);
	 }
	 cout << "\n";
	 for (int i = 0; i < trainNum; i++)
	 {
		 cout << TrainYard.front().top();
		 TrainYard.pop();
	 }



	return 0;
}

void Load(vector<int> TrainCargo)
    {
        int iterator = 0;
        int Containers = TrainCargo.size() / 5;
        if (TrainCargo.size() % 5 != 0)
        {
            Containers++;
        }
        stack<int>* CargoItems = new stack<int>[Containers];

        for (int index = 0; index < Containers; index++)
        {
			//iterator = 0; 
            for (int contain = 0; contain < TrainCargo.size(); contain++)
            {
                //iterator++;
               // if(iterator <= TrainCargo.size())
               // {
                CargoItems[index].push(TrainCargo.at(0));
                TrainCargo.erase(TrainCargo.begin());
               // }
				if (contain == 4)
				{
					break;
				}
            }
            this->Train.push(CargoItems[index]);
        }
    }