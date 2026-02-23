/*
        CCPROG2 MP PART 1 C SOURCE CODE
  
        GROUP NUMBER (2 digits): 35
        DATE SUBMITTED         : 02-23-26

        ESPIRITU, GENE CLEMENT                          SECTION1:S18A
        LEH, ELYSHA AUDREY                              SECTION2: S20B

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
/* Do NOT include other header files. */ 

/* 
    HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!
	
    1. You must apply arrays and strings in MP Part 1 (MP1).
    2. Use double data type (not float) for all floating point values/variables/functions/return type
    3. Do NOT use library functions that were NOT discussed in our class.    
    4. Do NOT use any global variables and goto statement with labels.
    5. Do NOT use a return statement if the function is of type void.
    6. Do NOT call printf() except inside the main() function.
    7. Do NOT use the following yet in this MP part.
          a. struct data type
	  b. file processing functions such as fopen(), fclose(), etc.
    8. Document your codes with SENSIBLE comments as specified below.
*/


/*
    You may declare any typedef that you need below this comment.
*/

//Constants for array size
#define MAX_TERRITORY 250
#define MAX_LENGTH 50
#define NUM 15 // baseline life expectancy + 14 risks

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


/* HELPER FUNCTION 
	Purpose: Processes the imported dataset.
	Returns: The number of countries there are in the dataset
		@ territory: Array where territory names are stored.
		@ riskFactors: Aray where the baseline life expectancy (index 0) and the 14 risk factors are stored (index 1 - 14).
    Pre-condition: the imported data follows the format: territoryname	baselinelifeexpectancy	riskfactor1	riskfactor2	riskfactor3 ... riskfactor14.
*/

int ProcessData(char territory[][MAX_LENGTH], double riskFactors[][NUM]) {
    int count = 0, i; // Counter and indexing variables.

	// Loops so long as the first line of text per row is a string (territory name).
    while (scanf("%s", territory[count]) == 1) {

		// Loops to store the numerical data per territory.
        for (i = 0; i < NUM; i++) {
            scanf("%lf", &riskFactors[count][i]);
        }
        count++;
    }

	// Returns the number of territories in the dataset.
    return count; 
}


/* HELPER FUNCTION
	Purpose: Gets the index of the test risk factor for testing purposes. 
	Returns: The index of the test risk factor.
		@ *riskName: The test risk factor in string format.
    Pre-condition: The test risk factor is written exactly as it is in names[][] (no typographical errors or use of spaces instead of _).
*/

int GetRiskFactorIndex(char *riskName){ 

	// defines the string formats of each risk factor for comparison
	char names[15][MAX_LENGTH] = {"Baseline_Life_Expectancy", "Air_Pollution", "Ambient_PM2.5", "Ozone", "Household_Air_Pollution",
								  "Environmental", "Occupational", "Unsafe_WaSH", "Metabolic", "Dietary", "High_Fasting_Plasma_Sugar",
								  "Tobacco", "Smoking", "Second_Hand_Smoke", "Unsafe_Sex"};
	int i; // indexing variable

	// Looks for the string in names[][] that matches the test risk factor.
	for (i = 0; i < 15; i++){
		if (strcmp(riskName, names[i]) == 0)
			return i; // Returns the index of the found string.
	}
	return -1; // If string is not found.
}


/* HELPER FUNCTION
	Purpose: Searches for the test territory in the dataset.
	Returns: The index of the found territory or -1 if the territory is not found.
		@ *territoryName: The name of the test territory.
		@ territory: The array containing all territory names.
		@ nTerritory: The number of territories in the dataset.
    Pre-condition: 
*/

int SearchTerritory(char *territoryName, char territory[][MAX_LENGTH], int nTerritory){
    
	int i; // indexing variable
    
    for (i = 0; i < nTerritory; i++) {
        if (strcmp(territory[i], territoryName) == 0) {
            return i; // Returns index of the territory if found.
        }
    }
    
    return -1; // If not found
}


/* HELPER FUNCTION
	Purpose: Counts the number of countries in the test case.
	Returns: The number of countries in the test case.
		@ test: The test test value that will be counted.
    Pre-condition: Test sets will have at most five countries.
*/

int CountCountries(char test[][MAX_LENGTH]){
		
	int i, count = 0; // indexing and counter variables
	
	for (i = 0; i < 5; i++){
		if(test[i][0] != '\0')
			count++; // Increments the count by one if the string in index i is emppty or null.
	}
	
	return count; // returns count of countries in the list.
}

/* HELPER FUNCTION
	Purpose: Sorts the territories according to the given values.
	Returns:
		@ territory: The array containing the names of the territories in the dataset.
		@ values: The array containing the values to sort.
		@ n: The number of territories to sort.
    Pre-condition:
*/

void SelectionSort (char territory[][MAX_LENGTH], double values[], int n)
{
	// indexing and temp variables
	int i, j, minIdx;
    double tempVal;
    char tempName[MAX_LENGTH];

    for (i = 0; i < n - 1; i++) {
        minIdx = i; // updates the index of the sorted part of the data

		// looks for the index of the minimum value.
        for (j = i + 1; j < n; j++) {
            if (values[j] < values[minIdx]) {
                minIdx = j;
            }
        }

		// updates the minimum index values.
        if (minIdx != i) {
            tempVal = values[i];
            values[i] = values[minIdx];
            values[minIdx] = tempVal;

			// updates the temp arrays with the newly sorted minimum value
            strcpy(tempName, territory[i]);
            strcpy(territory[i], territory[minIdx]);
            strcpy(territory[minIdx], tempName);
        }
    }
}

/*-----------------------------------------------------------------------------------------*/

/* Question 1 
	Purpose: Computes and returns the answer to Q1
	Returns: The average baseline life expectance of the test territories.
		@ test: The test territories.
		@ num: The number of territories in the test case.
		@ territory: The array containing the names of the territories in the dataset.
		@ riskFactors: The array containing the risk factors of each territory.
    Pre-condition: 

		Q1: What is the average baseline life expectancy across Barbados, Japan, Chile, Montenegro,
			and Australia? List the names of each country, their values, and the average across the countries.
        A1: Barbados                                 : 76.165622
			Japan                                    : 84.557851
			Chile                                    : 80.088079
			Montenegro                               : 75.836708
			Australia                                : 82.789955

			Average = 79.887643
		
*/

double Q1_Answer(char test[][MAX_LENGTH], int num, char territory[][MAX_LENGTH], double riskFactors[][NUM], int nTerritory){

	int i, index, count = 0; // indexing and count variables
	double sum = 0; // initialize sum for average computation

	// checks if the territory is a valid territory in the dataset and adds it to the sum and count counters
	for (i = 0; i < num; i++){
		index = SearchTerritory(test[i], territory, nTerritory);
	
		if (index != -1) {
            sum += riskFactors[index][0]; 
            count++;
        }
	}
	
	return (count > 0) ? (sum / count) : 0.0; // returns the average baseline life expectancy of the test territories
}


/* Question 2
	Purpose: Computes and returns the answer to Q2
	Returns: The name of the country with the highest loss of life expectancy due to the test risk.
		@ territory: The array containing the names of the territories in the dataset.
		@ riskFactors: The array containing the risk factors in the dataset.
		@ risk: The test risk factor.
    Pre-condition: 

        Q2:  Which country has the highest (maximum) loss of life expectancy due to Air_Pollution?
        A2:  Solomon_Islands
*/

char* Q2_Answer(char territory[][MAX_LENGTH], double riskFactors[][NUM], int nTerritory, int risk){
	
	int i, index = 0; // indexing variables
	double max = -1; // value of the maximum data value for comparison

	// Looks through the dataset and finds the maximum value for the test risk factor. 
	for (i = 0; i < nTerritory; i++){
		if (riskFactors[i][risk] > max){
			max = riskFactors[i][risk];
			index = i;
		}
	}
	
	return territory[index]; // Returns name of the territory with the maximum value.
}


/* Question 3
	Purpose: Computes and returns the answer for Q3. 
	Returns: N/A -- stores the answer via pointer
		@ riskIdx: The test risk.
		@ top5: The array that stores the answer to the question.
		@ territory: The array containing the names of the territories in the dataset.
		@ riskFactors: The array containing the risk factors in the dataset.
		@ nTerritory: The number of territories in the dataset.
    Pre-condition: 

	Q3:	Which five countries have the lowest loss of baseline life expectancy due to Ambient_PM?
        A3: 1) Sweden
			2) Finland
			3) Iceland
			4) Somalia
			5) New_Zealand
*/

void Q3_Answer(int riskIdx, char top5[][MAX_LENGTH], char territory[][MAX_LENGTH], double riskFactors[][NUM], int nTerritory)
{
    int i, count = 0; // indexing and temp variables
    char tempTerritory[MAX_TERRITORY][MAX_LENGTH];
    double tempValues[MAX_TERRITORY];

	// Copies each territory from the dataset and their corresponding values into the temporary arrays.
    for (i = 1; i < nTerritory; i++) {
        strcpy(tempTerritory[count], territory[i]);
        tempValues[count] = riskFactors[i][riskIdx];
        count++;
    }

    SelectionSort(tempTerritory, tempValues, count); // calls SelectionSort function to sort the top five countries.
    
    for (i = 0; i < 5 && i < count; i++) {
        strcpy(top5[i], tempTerritory[i]);  // Copy top 5 
    }
}

/* Question 4 
	Purpose: Calculates and returns the answer to Q4.
	Returns: The number of countries that have a baseline life expectancy within the threshold.
		@ threshold: The test threshold for checking.
		@ riskFactors: The array containing the risk factors in the dataset.
		@ nTerritory: The number of territories in the dataset.
    Pre-condition: The threshold is a number from 0 to 100 inclusive.

	Q4: How many countries have a baseline life expectancy of at least 75?
	A4: 85
*/

int Q4_Answer(double threshold, double riskFactors[][NUM], int nTerritory)
{
    int i, count = 0; // indexing and count variables

	// Increments count when the country's baseline LE is greater than or equal to the threshold.
    for (i = 1; i < nTerritory; i++) {
        if (riskFactors[i][0] >= threshold) { // Index 0 is baseline LE
            count++;
        }
    }
    
    return count;
}


/* Question 5
	Purpose: Calculates and returns the answer to Q5.
	Returns: The index of the found territory
		@ *countryName: The test territory name that will be searched.
		@ territory: The array containing the names of the territories in the dataset.
		@ nTerritory: The number of territories in the dataset.
    Pre-condition: The test case is in string format.

	Q5:  What are the statistics for Ambient_PM for Argentina?
    A5:  Argentina                                : 0.426051
		
*/

int Q5_Answer(char *countryName, char territory[][MAX_LENGTH], int nTerritory)
{
    return SearchTerritory(countryName, territory, nTerritory); // calls the SearchTerritory function, pushing the test country name as the parameter.
}

/*-----------------------------------------------------------------------------------------*/

int main()
{
	char territory[MAX_TERRITORY][MAX_LENGTH]; // array containing the names of the territories in the dataset
	double riskFactors[MAX_TERRITORY][NUM]; // array containing the risk factors of each territory in the dataset
	int nTerritory; // the number of territories in the dataset

	int i, j, k, idx, count; // indexing variables
	int actualRisk; // stores the test risk for testing
	double average; // stores the average for Q1

	// arrayed risks for printing
	char riskText[15][40] = {
        "Baseline_LE", "Air_Pollution", "Ambient_PM2.5", "Ozone", 
        "Household_Air_Pollution", "Environmental", "Occupational", 
        "Unsafe_WaSH", "Metabolic", "Dietary", "High_Fasting_Plasma_Sugar", 
        "Tobacco", "Smoking", "Second_Hand_Smoke", "Unsafe_Sex"
    };
    
    nTerritory = ProcessData(territory, riskFactors); // sets nTerritory to the number of territories in the data set. Also processes the data.

	// safety check
   	if (nTerritory < 2) {
        printf("ERROR: Insufficient data (only %d territories)\n", nTerritory);
        return 1;
    }
    
    printf("Successfully loaded %d territories.\n\n", nTerritory);
	
	/* ==================== QUESTION 1 ==================== */
    
	printf("Question 1:\n\n");

	// Test cases for Q1
	char test1[5][5][MAX_LENGTH] = {
        {"Barbados", "Japan", "Chile", "Montenegro", "Australia"},
        {"Georgia", "Belize", "", "", ""},
        {"Peru", "Armenia", "Italy", "Cyprus", "Argentina"},
        {"France", "", "", "", ""},
        {"Portugal", "Afghanistan", "Greece", "Malta", "Argentina"}
    };

	// loops per test case.
    for (i = 0; i < 5; i++) 
        count = CountCountries(test1[i]); // counts the number of countries in the test case
		average = Q1_Answer(test1[i], count, territory, riskFactors, nTerritory); // calculates the answer for Q1

		// prints the question according to the test territories.
        printf("What is the average baseline life expectancy across ");
        for (j = 0; j < count; j++) {
            if ((j == count - 1) && (count > 1)) 
                printf("and ");
            if (j < count - 1) 
                printf("%s, ", test1[i][j]);
            else 
                printf("%s? List the names of each country, their values, and the average across the countries.\n", test1[i][j]);
        }

		// prints the answer to q1
        printf("A:\n");
        for (k = 0; k < count; k++) {
            idx = SearchTerritory(test1[i][k], territory, nTerritory);
            
            if (idx != -1)
                printf("%-40s : %.6lf\n", territory[idx], riskFactors[idx][0]);
            else // safety check
                printf("%-40s : NOT FOUND\n", test1[i][k]);
        }
        printf("\nAverage = %.6lf\n\n", average);
    }


	/* ==================== QUESTION 2 ==================== */
	
	printf("\nQuestion 2:\n\n");

	// test cases for Q2
    char test2[5][MAX_LENGTH] = {"Air_Pollution", "Occupational", "Metabolic", "Tobacco", "Unsafe_Sex"};

	// loop for test cases
    for (i = 0; i < 5; i++) {
        actualRisk = GetRiskFactorIndex(test2[i]); // gets the index of the test risk

		// prints the question
		if (actualRisk != -1){
			printf("Which country has the highest (maximum) loss of life expectancy due to %s?\n", riskText[actualRisk]);

			// prints the answer to Q2
			char *highest = Q2_Answer(territory, riskFactors, nTerritory, actualRisk);
        	printf("A: %s\n\n", highest);
		}
		else{ // safety check
			printf("Risk factor '%s' not recognized.\n\n", test2[i]);
		}
    }


	/* ==================== QUESTION 3 ==================== */
  
	printf("\nQuestion 3:\n\n");

	// test cases for Q3
    char test3[5][MAX_LENGTH] = {"Ambient_PM2.5", "Ozone", "High_Fasting_Plasma_Sugar", "Smoking", "Second_Hand_Smoke"};
    char answer3[5][MAX_LENGTH]; // array that will hold the answer for Q3


	// loops for the test cases
    for (i = 0; i < 5; i++) {
        actualRisk = GetRiskFactorIndex(test3[i]); // gets the index of the test risk
        
        if (actualRisk != -1) {
            Q3_Answer(actualRisk, answer3, territory, riskFactors, nTerritory); // calculates the answer for Q3

			// prints the question and answer to Q3
            printf("Which five countries have the lowest loss of baseline life expectancy due to %s?\n", 
                   riskText[actualRisk]);
            printf("A:\n");

            for (j = 0; j < 5; j++) {
                printf("%d) %s\n", j + 1, answer3[j]);
            }
            printf("\n");
        }
    }


	/* ==================== QUESTION 4 ==================== */
	
	printf("\nQuestion 4:\n\n");

	// test cases for Q4
    int test4[5] = {75, 80, 82, 85, 90};

	// loops for the test cases
    for (i = 0; i < 5; i++) {
        printf("How many countries have a baseline life expectancy of at least %d?\n", test4[i]);
        count = Q4_Answer((double)test4[i], riskFactors, nTerritory);
        printf("A: %d\n\n", count);
    }
    
    /* ==================== QUESTION 5 ==================== */
  
	printf("\nQuestion 5:\n\n");

	// test cases for Q5
    char testRisk5[5][MAX_LENGTH] = {"Ambient_PM2.5", "Ozone", "Occupational", 
                                      "High_Fasting_Plasma_Sugar", "Smoking"};
    char testCountry[5][MAX_LENGTH] = {"Argentina", "Chile", "Italy", "Solomon_Islands", "Philippines"};

	// loops for the test cases
    for (i = 0; i < 5; i++) {
        int cntIdx = Q5_Answer(testCountry[i], territory, nTerritory); // looks for the index of the test territory.
        actualRisk = GetRiskFactorIndex(testRisk5[i]); // gets the index of the test risk.

		// prints the question and answer for Q5
        if (cntIdx != -1 && actualRisk != -1) {
            printf("What are the statistics for %s for %s?\n", 
                   riskText[actualRisk], territory[cntIdx]);
            printf("A:\n");
            printf("%-40s : %.6lf\n\n", territory[cntIdx], riskFactors[cntIdx][actualRisk]);
        } else { // safety check
            printf("Country %s not found.\n\n", testCountry[i]);
        }
    }
    
    return 0; // ends the program
}

