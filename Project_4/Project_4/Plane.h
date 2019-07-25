#include "Initial_Train.h"


class PlaneGuy
{
    private:
		int time;
		int CurrentCargo;
    
    public:
		PlaneGuy()
		{
			time = 0; 
		}

        int getTime()
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

		int unloadCargo()
		{
			time = time + (5 * CurrentCargo);
			return CurrentCargo;
		}

		void BacktoTrain()
		{
			time = time + (5 * CurrentCargo);
		}
};