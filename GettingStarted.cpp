/*This is a guide for people intrested in C++, this will mostly cover absolute basics.
For starters at the top of every C++ file you need "#include <iostream>" as seen below. */
/* to follow along got to: https://www.onlinegdb.com/online_c++_compiler and you can copy 
and pase the code into the online compiler to see how it works*/
#include <iostream> 
/* Next what I reconmend is adding "using namespace std;" after that, so when you 'cout'\
you dont need to put a std:: before it and for someone new to the C family it makes it more 
confusing, but I will still show this alternate way ! */
#include <iostream> 
using namespace std;
/*Now we need an area to work so lets add our main function */
#include <iostream>
using namespace std;
int main() 
{
    return 0;
}
/*Every function in C++ needs to retrun a value except "void", so a common thing to do is return 0 in main 
so when our program is done we will see an 0 being output to the console output. Now for the Fun part lets make our 
display "Hello, World!" message on the screen */
#include <iostream> 
using namespace std;

int main() 
{
    cout << "Hello, World!";

    return 0;   
}
/*NOTE: to make a return or get the same affect as hitting return put \n at the end like: "Hello, World! \n" */
/* What we just did is output a string to the console output when you put something between " " it becomes a string.
 We can also create variables and give them values, so it makes our program more easy to understand, for example:  */
 #include <iostream> 
using namespace std;

int main() 
{
    int number;

    return 0;   
}
/*This is called declaring a variable, we can assign a value when we declare it like so. */
 #include <iostream> 
using namespace std;

int main() 
{
    int number = 10; 

    return 0;   
}
/*This variable is called an integer which can only store values without decimals including negatives, another king of variable which you already used is called 
a string which holds phrases, and is made up of multiple characters, when we use a string we have to include the "string" library*/
 #include <iostream> 
 #include <string> //When using a string add this 
using namespace std;

int main() 
{
    string name = "Donovan";

    return 0;   
}
/*Now lets talk about how to input values, to input values we use something called "cin" and after you write cin you need to put ">>" after. The program below
asks for your name then you input whatever you want then it says hi to you */
#include <iostream> 
 #include <string> //When using a string add this 
using namespace std;

int main() 
{
    string name; //make the variable to store our name 
    cout << "What is your name: ";//Ask for it 
    cin  >> name; // Type your name to store it 
    cout << "HI " << name << '\n';

    return 0;   
}
