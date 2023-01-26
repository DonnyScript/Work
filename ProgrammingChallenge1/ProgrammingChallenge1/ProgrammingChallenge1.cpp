#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> BinaryConvert(int num) // Finished
{
    vector<int> BinaryOutput;
    int remainder;

    for (int i = 0; i <= 7; i++)
    {
        remainder = num % 2;
        num = num / 2;
        BinaryOutput.push_back(remainder);
    }

    return BinaryOutput;
}

vector<string> HexConvert(int num)  //Finished
{
    vector<string> HexOut;
    int remainder;

    for (int i = 0; i <= 1; i++)
    {
        remainder = num % 16;
        num = num / 16;
        if((remainder <= 15) && (remainder >=10))
        {
            if (remainder == 10) { HexOut.push_back("A"); }
            if (remainder == 11) { HexOut.push_back("B"); }
            if (remainder == 12) { HexOut.push_back("C"); }
            if (remainder == 13) { HexOut.push_back("D"); }
            if (remainder == 14) { HexOut.push_back("E"); }
            if (remainder == 15) { HexOut.push_back("F"); }
        }
        else
        {
            HexOut.push_back(to_string(remainder));
        }
    }
    

    return HexOut;
}

vector<int>BcdConvert(int num) // Finished
{
    vector<int> BcdOut;
    vector<int> BreakNum;
    int digit[3];

    for (int i = 0; i <= 2; i++) //Read in digits
    {
        digit[i] = num % 10;
        num = num / 10;
    }

    for (int j = 2; j >= 0; j--) // Read out BCD
    {
        for (int i = 3; i >= 0; i--)
        {
            BcdOut.push_back(BinaryConvert(digit[j]).at(i));
        }
        
    }
    
    return BcdOut;
}

int main()
{
    int number;
   
   cout << "Enter number equal to or less than 255: ";
   cin >> number;
   cout << "DECIMAL                          BINARY                                 HEXADECIMAL                                         BCD" << endl;
   cout << number << "                            ";

   for (int i = 7; i >= 0; i--)
   {
       cout << BinaryConvert(number).at(i);
       if (i == 4) {
           cout << " ";
       }
   }
   cout << "                                    ";

   for (int i = 1; i >= 0; i--)
   {
       cout << HexConvert(number).at(i);
   }
   cout << "                                         ";

   for (int i = 0; i <= 11; i++) // Read out BCD
   {
       cout << BcdConvert(number).at(i);
       if ((i == 3) || (i == 7)) 
       {
           cout << " ";
       }
   }
 

    return 0;
}

