#define _DATE_
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <conio.h>


int  cardnumberarray[16]; // declaring the card number array as a global variable and as a integer data type and saying that the array maximum size of it is 16
long long cardnumber; // declaring the cardnumber as a global variable and asssigning the long long data type which means that the card number is a long number
int  noOfDigits; // delcaring the noOfDigits as as integer data type and as a global variable
int firstdigit; // delcaring the first digit as as integer data type and as a global variable


int entercardnumber() // This is the name of the function which is going to ask the user for a card mumber it is defined as a integer data type 
{
	printf("Please enter a 15 or 16 digit credit card  number:\n"); // This prints the following which is asking the user to enter a card number
	scanf_s("%lld", &cardnumber);
	// This is reading what the user has inputed, which in this case it is the"lld" means the datatype which is long long, the ampersand is to
	//concatinate the long long integer (%lld) and card number which means to link them together
	return cardnumber; //  this returns the value of the cardnumber 
}

int checkNoOfDigits() // This is the name of the function which is going to check how many digits is the card number. It is defined as a integer data type 

{

	if (cardnumber < 100000000000000 && cardnumber > 9999999999999)
		return 15;
	// This IF statement says if value is less than 99999999999999 and more than 1000000000000000 then the value that should be returned is 15



	if (cardnumber > 99999999999999 && cardnumber < 10000000000000000)
		return 16;
}
// This IF statement says if 99999999999999 value is less than  and more than 10000000000000000 then the value that should be returned is 16



int convertToArray()  // This is the name of the function which is going convert the cardnumber in to an array. It is defined as a integer data type 
{
	int i = 0; // data type of i is a integer and the value that is assigned to it is 0
	int ii = 00; // data type of ii is a integer and the value that is assigned to it is 00
	while (cardnumber / 10 > 0) // this is a while loop, it will carry on deviding the value of cardnumber by 10 if the value is more than 0 and until all the arrays are filled
	{


		cardnumberarray[i] = cardnumber % 10;
		// i as been assigned a value 0 so the value within the cardnumberarray is 0 and this as been assigned to the remainder of the divison
		// from the while loop
		cardnumber = cardnumber / 10;
		// assigning cardnumber to equal the value when the cardnumber is devided by 10


		i++; // increments the value of i by 1
	}

	cardnumberarray[i] = cardnumber; // assigning the value of i that is within the cardnumberarray  to card number
	firstdigit = cardnumber; // assiging the variable firstdigit the value of the card number 
	return 0; //  There is no values that need to be returned 
}
int luhnstest() // This is the name of the function which is going to carry out the luhns test which is the algorithim used to check the validity 
				//of the card number. It is defined as a integer data type 
{

	for (int i = 0;i < 16;i++) // This is a for statement here i is a integer data type and i is assigned the value 0. 
							   // this loop will to add 1 to the value of i until the value is greater than 16
	{
		if (i % 2 != 0)
			// this if statement means if the value of i leaves a remainder when it is devided by 2
		{

			cardnumberarray[i] = cardnumberarray[i] * 2; // i is assigned the value of cardnumberarray[i] and assigning the value of when the array
														 // is multiplied by 2. For example if the cardnumberarry[i] is 2 then the new value will be 4
			if (cardnumberarray[i] > 9)
				// this will carry on multiplied by 2 until the value of cardnumberarry[i] is more than 9 
			{
				cardnumberarray[i] = 1 + (cardnumberarray[i] % 10); // The new value of cardnumberarry[i] is now being asssigned the value of the result of 
																	// value of i when it devides by 10 and then 1 is added to it  
			}
		}
	}


	int sum = 0; //  here, sum is assigned the value of 0 and is a integer data type
	for (int i = 0;i < 16;i++) // this for loop assigns i (data type is integer) a value of 0  and i is increased by 1 and will stop once the value of i is more
							   // more than 16 

	{
		sum = sum + cardnumberarray[i]; // assigning the value of sum + cardnumber[i] to sum
	}
	if (sum % 10 == 0)
		printf("Valid card number entered\n"); // If the card number does not leave a remainder when it is devided by 10 it will print that the card number is valid
	else printf("Invalid Card number entered, Please try again"); // if this is false then it will print that the card is invalid

	return 0; //  There is no values that need to be returned 
}

int cardtype() // This is the name of the function which is checks the value of the firstdigit and then prints the major  industry identifier.
			   // It is defined as a integer data type
{
	if (firstdigit == 1)
		printf("\nMajor Industry Identifier (MII): Airlines");
	// if the value of the firstdigit variable is 1,  then it prints airlines
	else if (firstdigit == 2)
		printf("\nMajor Industry Identifier (MII): Airlines and future industry assignments\n");
	// if the value of the firstdigit variable is 2,  then it prints Airlines and future industry assignments
	else if (firstdigit == 3)
		printf("\nMajor Industry Identifier (MII): Travel, entertainment, banking or financial\n");
	// if the value of the firstdigit variable is 3,  then it prints Travel, entertainment, banking / financial
	else if (firstdigit == 4)
		printf("\nMajor Industry Identifier (MII): Banking and Financial\n");
	// if the value of the firstdigit variable is 4,  then it prints Banking and financial 
	else if (firstdigit == 5)
		printf("\nMajor Industry Identifier (MII): Banking and Financial\n");
	// if the value of the firstdigit variable is 5,  then it prints Banking and financial
	else if (firstdigit == 6)
		printf("\nMajor Industry Identifier (MII): Merchandising or banking and financial\n");
	// if the value of the firstdigit variable is 6,  then it prints merchandising  Banking and financial
	else if (firstdigit == 7)
		printf("\nMajor Industry Identifier (MII): Petroleum and other future industry assignments\n");
	// if the value of the firstdigit variable is 7,  then it prints Petroleum and other future industry assignments
	else if (firstdigit == 8)
		printf("\nMajor Industry Identifier (MII): Healthcare, telecommunications, and future industry assignments\n");
	// if the value of the firstdigit variable is 8,  then it prints Healthcare, telecommunications, and future industry assignments
	else if (firstdigit == 9)
		printf("\nMajor Industry Identifier (MII): National assignment");
	// if the value of the firstdigit variable is 9,  National assignment

	return 0; //  There is no values that need to be returned 
}

int IINtype()// This is the name of the function which is used to check the value of the first 2, 3 or 4 array values
			 //and then prints the Issuer identification number (IIN). It is defined as a integer data type
{

	if ((noOfDigits == 16 && cardnumberarray[16] == 3 && cardnumberarray[15] == 4) || (noOfDigits == 16 && cardnumberarray[16] == 3 && cardnumberarray[15] == 7) || (noOfDigits == 15 && cardnumberarray[15] == 3 && cardnumberarray[14] == 4) || (noOfDigits == 15 && cardnumberarray[15] == 3 && cardnumberarray[14] == 7))
		printf("Issuer Identification Number (IIN): American Express \n");
	// This is a if statement. if the value of noOfDigits is 16 
	//AND the 16th value of the cardnumber array is 3 
	// AND the 15t value of the cardnumberarry is 4
	// OR if the value of noOfDigits is 16 AND the 16th value of the cardnumber array is 3 AND the 15th value of the cardnumberarry is 7
	// OR if the value of noOfDigits is 15 AND the 15th value of the cardnumber array is 3 AND the 14th value of the cardnumberarry is 4
	// OR if the value of noOfDigits is 15 AND the 15th value of the cardnumber array is 3 AND the 14th value of the cardnumberarry is 7
	// 

	{
		{

			if ((noOfDigits == 16 && cardnumberarray[16] == 6 && cardnumberarray[15] == 0 && cardnumberarray[14] == 1 && cardnumberarray[13] == 1) || (noOfDigits == 16 && cardnumberarray[16] == 6 && cardnumberarray[15] == 4 && cardnumberarray[14] == 4) || (noOfDigits == 16 && cardnumberarray[16] == 6 && cardnumberarray[15] == 5) || (noOfDigits == 15 && cardnumberarray[15] == 6 && cardnumberarray[14] == 0 && cardnumberarray[13] == 1 && cardnumberarray[12] == 1) || (noOfDigits == 15 && cardnumberarray[15] == 6 && cardnumberarray[14] == 4 && cardnumberarray[13] == 4) || (noOfDigits == 15 && cardnumberarray[15] == 6 && cardnumberarray[14] == 5))
				printf(" Issuer Identification Number (IIN): Discover \n");
			// This is a if statement. 
			// IF the value of noOfDigits is 16 
			// AND the 16th value of the cardnumber array is 6
			//AND the 15th value of the cardnumberarry is 0
			// AND the 14th value of the cardnumberarray is 1 
			// AND the 13th value of the cardnumberarray is 1 
			// OR if the value of noOfDigits is 16 
			// AND the 16th value of the cardnumber array is 6 
			// AND the 15th value of the cardnumberarry is 4
			// AND the 14th value of the cardnumberarray is 4
			// OR if the value of noOfDigits is 16 
			// AND the 16th value of the cardnumber array is 6 
			// AND the 15th value of the cardnumberarry is 5
			// OR if the value of noOfDigits is 15 
			// AND the 15th value of the cardnumber array is 6 
			// AND the 14th value of the cardnumberarry is 4
			// AND the 13th value of the cardnumberarry is 4
			// OR if the value of noOfDigits is 15 
			// AND the 15th value of the cardnumber array is 6 
			// AND the 14th value of the cardnumberarry is 5
			// Then it will print the ITN discover 
		}
		{
			if
				((noOfDigits == 16 && cardnumberarray[16] == 5 && cardnumberarray[15] == 0) || (noOfDigits == 16 && cardnumberarray[16] == 5 && cardnumberarray[15] == 1) || (noOfDigits == 16 && cardnumberarray[16] == 5 && cardnumberarray[15] == 2) || (noOfDigits == 16 && cardnumberarray[16] == 5 && cardnumberarray[15] == 3) || (noOfDigits == 16 && cardnumberarray[16] == 5 && cardnumberarray[15] == 4) || (noOfDigits == 16 && cardnumberarray[16] == 5 && cardnumberarray[15] == 5) || (noOfDigits == 15 && cardnumberarray[15] == 5 && cardnumberarray[14] == 0) || (noOfDigits == 15 && cardnumberarray[15] == 5 && cardnumberarray[14] == 1) || (noOfDigits == 15 && cardnumberarray[15] == 5 && cardnumberarray[14] == 2) || (noOfDigits == 15 && cardnumberarray[15] == 5 && cardnumberarray[14] == 3) || (noOfDigits == 15 && cardnumberarray[15] == 5 && cardnumberarray[14] == 4) || (noOfDigits == 15 && cardnumberarray[15] == 5 && cardnumberarray[14] == 5))
				printf("\nIssuer Identification Number (IIN): MasterCard \n");
		}

		// this is a if statement. 
		// if the value of noOfDigits is 16 
		// AND the 16th value of the cardnumber array is 5
		//AND the 15th value of the cardnumberarry is 0
		// OR if the value of noOfDigits is 16 
		// AND the 16th value of the cardnumber array is 5 
		// AND the 15th value of the cardnumberarry is 1
		// OR if the value of noOfDigits is 16
		// AND the 16th value of cardnumberarray is 5
		// AND the 15th value of cardnumber array is 2
		// OR if the value of noOfDigits is 16 
		// AND the 16th value of the cardnumber array is 5 
		// AND the 15th value of the cardnumberarry is 3
		// OR if the value of noOfDigits is 16 
		// AND the 16th value of the cardnumber array is 5 
		// AND the 15th value of the cardnumberarry is 4
		// OR if the value of noOfDigits is 16 
		// AND the 16th value of the cardnumber array is 5 
		// AND the 15th value of the cardnumberarry is 5 
		// OR if the value of noOfDigits is 15 
		// AND the 15th value of the cardnumber array is 5
		// AND the 14th value of the cardnumberarry is 0
		// OR if the value of noOfDigits is 15 
		// AND the 15th value of the cardnumber array is 5
		// AND the 14th value of the cardnumberarry is 1
		// OR if the value of noOfDigits is 15 
		// AND the 15th value of the cardnumber array is 5
		// AND the 14th value of the cardnumberarry is 2
		// OR if the value of noOfDigits is 15 
		// AND the 15th value of the cardnumber array is 5
		// AND the 14th value of the cardnumberarry is 3
		// OR if the value of noOfDigits is 15 
		// AND the 15th value of the cardnumber array is 5
		// AND the 14th value of the cardnumberarry is 4
		// OR if the value of noOfDigits is 15 
		// AND the 15th value of the cardnumber array is 5
		// AND the 14th value of the cardnumberarry is 5 
		// It will print IIN: MasterCard


		if ((noOfDigits == 16 && cardnumberarray[16] == 4 || (noOfDigits == 15 && cardnumberarray[15] == 4)))
			printf("\nIssuer Identification number (IIN): Visa\n");
		// This is another IF statement
		// IF the value of noOfDigits is 16 
		// AND the 16th value of the cardnumberarray is 4
		// OR if the value of noOfDigits is 15
		// AND the 15th value of the cardnumberarray is 4
		// It will then print IIN: Visa
		return 0;
	}
}
// A value does not need to be returned for this function 

void help() // This function provides a help screen for the user 
{

	printf("Welcome to the card validator! \n");
	printf("this program checks card numbers to see if they are valid or invalid. \n");
	printf("The algorithm this program it uses is the Luhns algorithm. \n");
	printf("To get started press 1 on the welcome menu and then press enter. \n");
	printf("The next stage is to enter a 15 or 16 digit card number. \n");
	printf("The program will then print weather the card number that you have entered is valid or invalid.\n");
	printf("The program will also give you the type of card it is(Visa, MasterCard, American Experess or Discover \n");
	printf("by checking thw Issuer Identification number(IIN) \n");
	printf("and the program will also give you the Major Industry Identifier(MII) which will tell you \n");
	printf("the issuing organisation of the card. \n");
	printf("If you want to exit the program press 3 at welcome menu and then press enter. \n");
	printf("\nThank you for using the program!!");

	// The above printf statements tells the user how to use the program and what is the program does. This variale will only run if
	// the user enters 2 at the welcome menu, when the program is first started 

}

 int main() { // This is the main  function where all local variables throughout the program are called from 



	int mainArray[3];  // This is the name of the function which is declaring an array, with a size of 3 characters. It is defined as a integer data type
	int choice;  //This is the name of the function which is used
				 // to declare the name of the options of the switch case statement. It is defined as a integer data type

	do // the switch case statement e.g. the Welcome meu is a do while loop.
	   // A do while loop is similar to while loop apart from the fact that a do While loop runs at least 1 condition no matter weather the outcome
	   // is true or false

	{

		time_t t;
		time(&t);

		// this stting gets the current time and date I have added it in because I wanted to learn how to add the date and time in C programming
		printf("\n==============================================================\n");
		printf(" Welcome to the card validator program\n");
		printf("Today's date and time is : %s", ctime(&t)); // this prints the current date and time 
		printf("\n===============================================================\n ");
		printf("please select a option\n");

		printf("[1] Please press 1 to run the card validator \n");
		printf("[2] Please press 2 to open the help file \n");
		printf("[3] Please press 3 to Exit the program \n");

		// The printf's statements print the welcome menu and asks the user to select a option 


		scanf_s("%d", &choice); // The scanf_s reads the users input and concatenates the input with the choice variable
		switch (choice) // this opens the switch case statement and names the cases as "choice"

		{

		case 1: // This is if the user inputs 1 at the welcome menu

			entercardnumber();
			noOfDigits = checkNoOfDigits();
			convertToArray();
			luhnstest();
			cardtype();
			IINtype();
			// All these are variables that are being declared and that are being called from within other parts of the code,
			// The reason they are in case 1 is becausae option 1 is to run the program
			break;
			// The break means that the loop will stop if the user enters this specific option

		case 2: // This is if the user inputs 2 at the welcome menu

			help();

			// This is a variable that is being declared and that are being called from within other parts of the program, 
			// The reason it is in case 2 is becausae option 2 is to see the Help page
			break;
			// The break means that the loop will stop if the user enters this specific option


		case 3:// This is if the user inputs 3 at the welcome menu

			printf("Thank you for using the program \n");
			printf("Program is now exiting ....\n");
			printf("End of the program \n");
			printf("\n", ctime(&t)); // this also prints the current date and time 


									 // It prints thank you and goodbye messages as well as the date and time 
			break;
			// The break means that the loop will stop if the user enters this specific option
		}
	} while (choice != 3);
	// this means if the choice is equal to 3 or different the program will quit and user will be asked to quit


	printf("Thank you for using the program press enter to close\n");
	// Prints a thank you message

	_getch();

	// Keeps the command prompt window open 
}



