/*
        CCPROG2 MP PART 1 C SOURCE CODE
  
        GROUP NUMBER (2 digits): 35
        DATE SUBMITTED         : 02-16-26 (first draft) && 02-17-26 (2nd/final draft)

        LASTNAME1, FIRSTNAME1: Leh, Elysha Audrey       SECTION1: S20B
        LASTNAME1, FIRSTNAME2:                          SECTION2:

        NOTE: encode ONLY your NAME if this code is for your own individual solution
              encode BOTH names and sections if this code is for your GROUP's FINAL solution

        Do not forget to encode your name, section and date of submission.      
		
	For your FINAL solution: Rename this file using your last names in alphabetical order, for example CRUZ_TAN.c
		
	Make sure to compile your C source code with a -Wall directive.  
	   Example: CCPROG2> gcc -Wall ESPIRITU_LEH.c
	   
	Fix all warnings.  Do NOT run the program if you still have a warning.  You must have
	0 error, 0 warning before running the program.
	   
	Run the resulting a.exe file in the command line with input and output (I/O) redirection.
	   Example: a < SoGA_DATASET.TXT > OUTPUT_ESPIRITU_LEH.TXT

*/

#include <stdio.h>
#include <string.h>

/* 
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!
	
    1. You must apply arrays and strings in MP Part 1 (MP1). - check!
    2. Use double data type (not float) for all floating point values/variables/functions/return type. - check!
    3. Do NOT use library functions that were NOT discussed in our class. - check!
    4. Do NOT use any global variables and goto statement with labels. - check!
    5. Do NOT use a return statement if the function is of type void. - check!
    6. Do NOT call printf() except inside the main() function. - check!
    7. Do NOT use the following yet in this MP part. - check!
          a. struct data type
	  b. file processing functions such as fopen(), fclose(), etc.
    8. Document your codes with SENSIBLE comments as specified below.
*/

/*
    Define any function that you need below this comment.  

    You are required to document your functions with SENSIBLE comments. Each function definition must
    be PRECEDED by an online documentation (in the form of comments) describing concisely the following:
       a. Purpose: describe succintly what the function is supposed to accomplish.
       b. Parameters: describe succintly the nature/purpose of each parameter.
       c. Return type: if the function is not void, describe succintly what it will return as a result.          
       
    Thereafter, document the body of the function by including comments alongside codes that you think
    may not be easy to understand to the person reading the codes. 

    Follow the online documentation style in the LinearSearch() example function definition given below.
*/

/*
    Specifically for the 5 functions that serve as answers to the questions: 

    1. The functions should be named as Q1_Answer(), Q2_Answer(), Q3_Answer(), Q4_Answer() and Q5_Answer().
       Specify the appropriate return type and the necessary parameters for your 5 functions.
    2. You may define helper functions that can be called inside any of these functions.
    3. Include also the following as comments/documentation BEFORE the function definition itself:
          a. Question number and the question.  
          b. Thereafter, type the answer number, and the corresponding example expected answer.

    Refer to the following Q1_Answer() function definition lines for an example.
*/

//------------------------------------------------------------------------------------------

/* Q1
	Purpose: computes and returns the answer to Q1.
	Returns: none, void datatype
		@ countryNames:  the array containing all the country names in the data set
		@ countryData: the array containing all the data per country in the data set
		@ *average: stores the average baseline life expectancy across the listed countries
		@ count: the number of countries that are to be considered (max-ed out at 5)
		@ test1: the array containing the (at most) five countries that are to be considered
    Pre-condition: all values are valid.

        Q1: What is the average baseline life expectancy across Barbados, Japan, Chile, Montenegro,
			and Australia? List the names of each country, their values, and the average across the countries.
        A1: Barbados                                 : 76.165622
			Japan                                    : 84.557851
			Chile                                    : 80.088079
			Montenegro                               : 75.836708
			Australia                                : 82.789955

			Average = 79.887643
*/

void Q1_Answer(char countryNames[203][40], double countryData[203][15], double *average, int count, char test1[5][40]){
	
	double total = 0; // total for average calculation
	int i, j, cntInd; // indexing variables and current country index variables
	
	for (i = 0; i < count; i++){ // loops for each country listed in the question
		cntInd = -1; // resets the index per entry
		
		for (j = 0; j < 203 && cntInd ==  -1; j++){ // goes through each country in the database and compares their names with the chosen countries if they are the same
			if (strcmp(test1[i], countryNames[j]) == 0){
				cntInd = j;	//keeps note of the found country's index			
			}
		}
			if (cntInd != -1){
				total += countryData[cntInd][0]; // updates the total for average calculation	
			}
	}
	
	if (count > 0)
		*average = total / count; // calculates for the average baseline life expectancy across the indicated countries
	
	else
		*average = 0;
}

/* Q2
	Purpose: computes and returns the answer to Q2.
	Returns: the number of countries that have at least the indicated baseline life expectancy.
		@ countryNames:  the array containing all the country names in the data set
		@ countryData: the array containing all the data per country in the data set
		@ risk: the risk that is being checked
    Pre-condition: risk is inputted as an integer, referring to the risk's index

        Q2:  Which country has the highest (maximum) loss of life expectancy due to Air_Pollution?
        A2:  Solomon_Islands
*/

char *Q2_Answer(char countryNames[203][40], double countryData[203][15], int risk){
	
	int i, index; // indexing variable and to store the index for sorting
	double max = 0; // value of the maximum data value for comparison
	
	for (i = 0; i < 203; i++){ // goes through each one of the countries in the data set
		if (countryData[i][risk] > max){ // checks for if the current country's data is greater than the maximum value
			max = countryData[i][risk];
			index = i; // if yes, update the maximum value and the corresponding index
		}
	}
	
	return countryNames[index]; // returns the index of the maximum value
}


/* Q3
	Purpose: computes and returns the answer to Q3.
	Returns: none, void datatype
		@ countryNames:  the array containing all the country names in the data set
		@ countryData: the array containing all the data per country in the data set
		@ risk: the risk that is being considered
		@ answer3[5][40]: the array that will receive the five countries
    Pre-condition: risk is inputted as an integer, referring to the risk's index

        Q3:	Which five countries have the lowest loss of baseline life expectancy due to Ambient_PM?
        A3: 1) Sweden
			2) Finland
			3) Iceland
			4) Somalia
			5) New_Zealand
*/

void Q3_Answer(char countryNames[203][40], double countryData[203][15], int risk, char answer3[5][40]){
	
	int i, j; // indexing variables
	int low_index, temp;
	int index[203]; // indexes to sort
	
	
	for (i = 0; i < 203; i++) // essentially copies the index for each country in the database
		index[i] = i;

	
	for (i = 0; i < 203; i++){
		low_index = i; // resets the position of the next sorted index 
		
		for (j = i + 1; j < 203; j++){ // checks for if the current value is lower than the 
			if (countryData[index[j]][risk] < countryData[index[low_index]][risk])
				low_index = j;
		}
			
		// swaps/updates index of lowest
		temp = index[low_index];
		index[low_index] = index[i]; 
		index[i] = temp;
	}
	
	for (i = 0; i < 5; i++){ // updates the answer array for printing in main
		strcpy(answer3[i], countryNames[index[i]]);
	}
	
}


 /* Q4
	Purpose: computes and returns the answer to Q4.
	Returns: the number of countries that have at least the indicated baseline life expectancy.
		@ countryData : @ countryData: the array containing all the data per country in the data set
		@ threshold : the life expectancy that will be checked
    Pre-condition: threshold is inputted as a positive integer between 0 and 100

		Q4: How many countries have a baseline life expectancy of at least 75?
		A4: 85
*/

int Q4_Answer(double countryData[203][15], int threshold){
	
	int i, count = 0; // indexing and counting variables
	
	for (i = 0; i < 203; i++){
		if (countryData[i][0] >= threshold)
			count++; // increments count by 1 when the current country's data is greater than or equal to the indicated threshold
	}
	
	return count; // returns the counted # of countries that fit the criteria
}


/* Q5
	Purpose: computes and returns the answer to Q5.
	Returns: the index of the found country or -1 if the country is not found
		@ testCountry : the array containing the test countries that will be searched.
		@ countryNames : the array containing all the country names in the data set 
    Pre-condition: threshold is inputted as a positive integer between 0 and 100

        Q5:  What are the statistics for Ambient_PM for Argentina?
        A5:  Argentina                                : 0.426051
*/

int Q5_Answer(char testCountry[], char countryNames[203][40]){
		
		int i; // indexing operator
		
		for (i = 0; i < 203; i++){ // looks through each country and looks for the one matching the target country (testCountry)
			if (strcmp(testCountry, countryNames[i]) == 0)
				return i; // if found, returns the index of the found country
		}
		
		return -1; // returns -1 if the country is not found in the dataset
	}

//------------------------------------------------------------------------------------------


/* Import
	Purpose: helper function that organizes the data into arrays
		@ countryNames:  the array containing all the country names in the data set
		@ countryData: the array containing all the data per country in the data set
    Pre-condition: SoGA_DATASET file is imported when running this program
*/

void import(char countryNames[203][40], double countryData[203][15]){
	
	int i, j;
	
	for (i = 0; i < 203; i++){ // loops through all countries in the dataset
		scanf(" %s", countryNames[i]); // stores the names of each country in the countryNames array
		
		for (j = 0; j < 15; j++){ // loops through all 15 risks risks per country
			scanf("%lf", &countryData[i][j]); // stores the 15 pieces of data per country
		}
	}
	
	//without this loop format, the scanf will not be able to differenciate between country names and the data
}


/* countElements
	Purpose: helper function that counts the number of countries the user inputs (used in question 1)
	Returns: the number of countries that the user inputs
		@ test1: the array containing the user's inputted countries
    Pre-condition: if the user inputs less than 5 countries, it will be noted as -1 instead of 0
*/

int countElements(char test1[5][40]){
		
	int i, count = 0; // indexing and counter variables
	
	for (i = 0; i < 5; i++){
		if(test1[i][0] != '\0')
			count++; // if the first element of the string is not null (the string is not empty), increments count by one.
	}
	
	return count; // returns count of existing countries back to the main function
}


//------------------------------------------------------------------------------------------


int
main()
{
	
	char countryNames[203][40];   // contains the names of each country -- 203 countries, max 40 letters each
	double countryData[203][15];    // contains the data points of reach country -- 203 countries, 203 countries, 15 data points each
	// 		0      		    1          		2          		3  		4          		5          			6          				7          					8          			9          			10 		       		11  		12         		13   	       	14
	//	Baseline 	LE	Air Pollution	ambient PM	   	ozone		HAP		environmental hazards	occupation	 unsafe water, sanitizion, hygene	metabolic syndrome		dietary		high fasting plasma glucose		tobacco		smoking		2nd hand smoke	unsafe sex
	
	import(countryNames, countryData); // organizes the imported data into the arrays countryNames and countryData
	
	// test import helper function
	{
	/*
	printf("Testing Import:\n");
    for (int i = 0; i < 5; i++) {
        printf("Country: %s\n", countryNames[i]);
        printf("First Risk Value: %lf\n", countryData[i][0]);
        printf("Last Risk Value:  %lf\n\n", countryData[i][14]);	
	}
	*/
	}
	
	int i, j, k, m, idx, actualRisk; // indexing and risk variables for test loops

	char riskText[15][40] = {"Baseline_LE", "Air_Pollution", "Ambient_PM", "Ozone", "HAP",
						 "Environmental_Hazards", "Occupation", "Unsafe_Water__Sanitizion__Hygene",
						 "Metabolic_Syndrome", "Dietary", "High_Fasting_Plasma_Glucose", "Tobacco",
						 "Smoking", "2nd_Hand_Smoke", "Unsafe_Sex"}; // lists out all the risk factors into strings for printing
	
	
	// Question 1 Printing

		printf("Question 1:\n\n");
		char test1[5][5][40] = { // the test cases for question 1
										{"Barbados", "Japan", "Chile", "Montenegro", "Australia"},
    									{"Georgia", "Belize", "", "", ""},
    									{"Peru", "Armenia", "Italy", "Cyprus", "Argentina"},
    									{"France", "", "", "", ""},
    									{"Portugal", "Afghanistan", "Greece", "Malta", "Argentina"}
};
	
	double average = 0; // holds the average baseline life expectancy among the given countries
	int count = 0; // holds the number of countries the user inputs
	
	for (i = 0; i < 5; i++){ // counts how many countries the user inputs
		count = countElements(test1[i]);
		
	Q1_Answer(countryNames, countryData, &average, count, test1[i]); // calls the Q1_Answer function	
	
	printf("What is the average baseline life expectancy across ");

	for (j = 0; j < count; j++){ // prints out the question according to the list of countries the user inputs
		
		if ((j == (count - 1)) && (count > 1))
			printf("and ");
		
		if(j < count - 1)
			printf("%s, ", test1[i][j]);
		
		else
			printf("%s? List the names of each country, their values, and the average across the countries.\n", test1[i][j]);
		}
			
	printf("A:\n");
	for (k = 0; k < count; k++){ // loop for the five test cases
		idx = -1; // initialize index of the country to "not found"
		for (m = 0; m < 203 && idx == -1; m++) { //  loops through the data set while the country is not found
               if (strcmp(test1[i][k], countryNames[m]) == 0) {
                   idx = m; // updates idx to the index of the found country
               }
           }
		   
		if (idx != -1) // Safety check for found/notfound; prints the countries and their data
			printf("%-40s : %lf\n", countryNames[idx], countryData[idx][0]);
		else
			printf("%-40s : NOT FOUND\n", test1[i][k]);
	}
		
	printf("\nAverage = %lf\n\n", average); // prints the average of the listed countries
}
	
	// Question 2 Printing
	{
	printf("\nQuestion 2:\n\n");
	int test2[5] = {1, 5, 8, 10, 14}; // test cases for question 2
	
	for (i = 0; i < 5; i++){ // loops through the five test cases
		actualRisk = test2[i]; // moves the current risk into a variable, actualRisk
		printf("Which country has the highest (maximum) loss of life expectancy due to %s?\n", riskText[actualRisk]);
		char *highest = Q2_Answer(countryNames, countryData, actualRisk); // assigns Q2_Answer to *highest
		printf("A: %s\n\n", highest); // prints the answer
	}
	}
	
	
	// Question 3 Printing
	{
	printf("\nQuestion 3:\n\n");
	int test3[5] = {2, 3, 9, 11, 12}; // test cases for question 3
	char answer3[5][40];
	
	for (i = 0; i < 5; i++){ // loops through the five test cases
		actualRisk = test3[i]; // assigns the current risk to actualRisk
		Q3_Answer(countryNames, countryData, actualRisk, answer3); // calls the Q3_Answer functions
		
		printf("Which five countries have the lowest loss of baseline life expectancy due to %s?\n", riskText[actualRisk]);
		printf("A:\n");
		
		for (j = 0; j < 5; j++){ // loops and prints through the five countries in each answer
			printf("%d) %s\n", j + 1, answer3[j]);
			}
		printf("\n");
	}
	}
	
	// Question 4 Printing
	{
	printf("\nQuestion 4:\n\n");
	int test4[5] = {75, 80, 82, 98, 100}; // test cases for question 4
	for (i = 0; i < 5; i++){ // loops through the five test cases
		printf("How many countries have a baseline life expectancy of at least %d?\n", test4[i]);
		int count = Q4_Answer(countryData, test4[i]); // assigns the answer for Q4 to count
		printf("A: %d\n\n", count); // prints the answer to Q4
	}
	}
	
	//Question 5 Printing
	//note: altered question 5 to only search for one risk and one country.
	
	{
	printf("\nQuestion 5:\n\n");
	int testRisk5[5] = {2, 3, 5, 9, 11}; // test cases for question 5 (risks)
	char testCountry[5][40] = {"Argentina", "Chile", "Italy", "Solomon_Islands", "Niue"}; // test cases for question 5 (countries)
		
	for (i = 0; i < 5; i++){ // loops through the five test cases
		int cntInd = Q5_Answer(testCountry[i], countryNames); // assigns the answer to Q5 to cntInd
		actualRisk = testRisk5[i]; // updates the current test risk to actualRisk
		
		if (cntInd != -1){ // if the country is found, prints the question and answer to Q5
			printf("What are the statistics for %s for %s?\n", riskText[actualRisk], countryNames[cntInd]);
			printf("A:\n");
			printf("%-40s : %lf\n\n", countryNames[cntInd], countryData[cntInd][actualRisk]);
		}
		else // prints if country is not found.
			printf("Country %s not found. \n\n", testCountry[i]);	
	}	
	}

    return 0;
}