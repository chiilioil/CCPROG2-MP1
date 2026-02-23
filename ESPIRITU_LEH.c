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
	Purpose: Gets the index of the user-inputted risk factor for testing purposes. 
	Returns: The index of the indicated risk factor.
		@ *riskName: The indicated risk factor in string format.
    Pre-condition: The user-inputted risk factor is written exactly as it is in names[][] (no typographical errors or use of spaces instead of _).
*/

int GetRiskFactorIndex(char *riskName){ 

	// defines the string formats of each risk factor for comparison
	char names[15][MAX_LENGTH] = {"Baseline_Life_Expectancy", "Air_Pollution", "Ambient_PM2.5", "Ozone", "Household_Air_Pollution",
								  "Environmental", "Occupational", "Unsafe_WaSH", "Metabolic", "Dietary", "High_Fasting_Plasma_Sugar",
								  "Tobacco", "Smoking", "Second_Hand_Smoke", "Unsafe_Sex"};
	int i; // indexing variable

	// Looks for the string in names[][] that matches the indicated risk factor.
	for (i = 0; i < 15; i++){
		if (strcmp(riskName, names[i]) == 0)
			return i; // Returns the index of the found string.
	}
	return -1; // Returns -1 if string is not found.
}


/* HELPER FUNCTION
	Purpose: 
	Returns:
		@ 
		@ 
    Pre-condition: 
*/

int SearchTerritory(char *territoryName, char territory[][MAX_LENGTH], int nTerritory){
    int i;
    
    for (i = 0; i < nTerritory; i++) {
        if (strcmp(territory[i], territoryName) == 0) {
            return i; //returns index of territory if found
        }
    }
    
    return -1; //if not found
}

int CountCountries(char test[][MAX_LENGTH]){
		
	int i, count = 0; // indexing and counter variables
	
	for (i = 0; i < 5; i++){
		if(test[i][0] != '\0')
			count++; // if the first element of the string is not null (the string is not empty), increments count by one.
	}
	
	return count; // returns count of existing countries back to the main function
}

/*-----------------------------------------------------------------------------------------*/

double Q1_Answer(char test[][MAX_LENGTH], int num, char territory[][MAX_LENGTH], double riskFactors[][NUM], int nTerritory){

	int i, index, count = 0;
	double sum = 0;
	
	for (i = 0; i < num; i++){
		index = SearchTerritory(test[i], territory, nTerritory);
	
		if (index != -1) {
            sum += riskFactors[index][0]; 
            count++;
        }
	}
	
	return (count > 0) ? (sum / count) : 0.0;
}


char* Q2_Answer(char territory[][MAX_LENGTH], double riskFactors[][NUM], int nTerritory, int risk){
	
	int i, index = 0; // indexing variable and to store the index for sorting
	double max = -1; // value of the maximum data value for comparison
	
	for (i = 0; i < nTerritory; i++){ // goes through each one of the countries in the data set
		if (riskFactors[i][risk] > max){ // checks for if the current country's data is greater than the maximum value
			max = riskFactors[i][risk];
			index = i; // if yes, update the maximum value and the corresponding index
		}
	}
	
	return territory[index]; // returns the index of the maximum value
}


void SelectionSort (char territory[][MAX_LENGTH], double values[], int n)
{
	int i, j, minIdx;
    double tempVal;
    char tempName[MAX_LENGTH];
    
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        
        for (j = i + 1; j < n; j++) {
            if (values[j] < values[minIdx]) {
                minIdx = j;
            }
        }
        
        if (minIdx != i) {
            tempVal = values[i];
            values[i] = values[minIdx];
            values[minIdx] = tempVal;
            
            strcpy(tempName, territory[i]);
            strcpy(territory[i], territory[minIdx]);
            strcpy(territory[minIdx], tempName);
        }
    }
}

void Q3_Answer(int riskIdx, char top5[][MAX_LENGTH],
          char territory[][MAX_LENGTH], double riskFactors[][NUM], int nTerritory)
{
    int i, count = 0;
    char tempTerritory[MAX_TERRITORY][MAX_LENGTH];
    double tempValues[MAX_TERRITORY];
    
    for (i = 1; i < nTerritory; i++) {
        strcpy(tempTerritory[count], territory[i]);
        tempValues[count] = riskFactors[i][riskIdx];
        count++;
    }

    SelectionSort(tempTerritory, tempValues, count);
    
    for (i = 0; i < 5 && i < count; i++) {
        strcpy(top5[i], tempTerritory[i]);  // Copy top 5 
    }
}

int Q4_Answer(double threshold, double riskFactors[][NUM], int nTerritory)
{
    int i, count = 0;
    
    for (i = 1; i < nTerritory; i++) {
        if (riskFactors[i][0] >= threshold) { // Index 0 is baseline LE
            count++;
        }
    }
    
    return count;
}

int Q5_Answer(char *countryName, char territory[][MAX_LENGTH], int nTerritory)
{
    return SearchTerritory(countryName, territory, nTerritory);
}

/*-----------------------------------------------------------------------------------------*/

int main()
{
	char territory[MAX_TERRITORY][MAX_LENGTH];
	double riskFactors[MAX_TERRITORY][NUM];
	int nTerritory;
	
	int i, j, k, idx, actualRisk;
	double average;
    int count;

	char riskText[15][40] = {
        "Baseline_LE", "Air_Pollution", "Ambient_PM2.5", "Ozone", 
        "Household_Air_Pollution", "Environmental", "Occupational", 
        "Unsafe_WaSH", "Metabolic", "Dietary", "High_Fasting_Plasma_Sugar", 
        "Tobacco", "Smoking", "Second_Hand_Smoke", "Unsafe_Sex"
    };
    
    nTerritory = ProcessData(territory, riskFactors);
   	
   	if (nTerritory < 2) {
        printf("ERROR: Insufficient data (only %d territories)\n", nTerritory);
        return 1;
    }
    
    printf("Successfully loaded %d territories.\n\n", nTerritory);


	/* ==================== QUESTION 1 ==================== */
    printf("Question 1:\n\n");
    
	char test1[5][5][MAX_LENGTH] = {
        {"Barbados", "Japan", "Chile", "Montenegro", "Australia"},
        {"Georgia", "Belize", "", "", ""},
        {"Peru", "Armenia", "Italy", "Cyprus", "Argentina"},
        {"France", "", "", "", ""},
        {"Portugal", "Afghanistan", "Greece", "Malta", "Argentina"}
    };
    
    for (i = 0; i < 5; i++) {
        count = CountCountries(test1[i]);
		average = Q1_Answer(test1[i], count, territory, riskFactors, nTerritory);
        
        printf("What is the average baseline life expectancy across ");
        for (j = 0; j < count; j++) {
            if ((j == count - 1) && (count > 1)) 
                printf("and ");
            if (j < count - 1) 
                printf("%s, ", test1[i][j]);
            else 
                printf("%s? List the names of each country, their values, and the average across the countries.\n", test1[i][j]);
        }
        
        printf("A:\n");
        for (k = 0; k < count; k++) {
            idx = SearchTerritory(test1[i][k], territory, nTerritory);
            
            if (idx != -1)
                printf("%-40s : %.6lf\n", territory[idx], riskFactors[idx][0]);
            else
                printf("%-40s : NOT FOUND\n", test1[i][k]);
        }
        
        printf("\nAverage = %.6lf\n\n", average);
    }


	/* ==================== QUESTION 2 ==================== */
	printf("\nQuestion 2:\n\n");
    
    char test2[5][MAX_LENGTH] = {"Air_Pollution", "Occupational", "Metabolic", "Tobacco", "Unsafe_Sex"};
    
    for (i = 0; i < 5; i++) {
        actualRisk = GetRiskFactorIndex(test2[i]);

		if (actualRisk != -1){
			printf("Which country has the highest (maximum) loss of life expectancy due to %s?\n", 
			       riskText[actualRisk]);
			
			char *highest = Q2_Answer(territory, riskFactors, nTerritory, actualRisk);
        	printf("A: %s\n\n", highest);
		}
		else{
			printf("Risk factor '%s' not recognized.\n\n", test2[i]);
		}
    }


	/* ==================== QUESTION 3 ==================== */
    printf("\nQuestion 3:\n\n");
    
    char test3[5][MAX_LENGTH] = {"Ambient_PM2.5", "Ozone", "High_Fasting_Plasma_Sugar", "Smoking", "Second_Hand_Smoke"};
    char answer3[5][MAX_LENGTH];
    
    for (i = 0; i < 5; i++) {
        actualRisk = GetRiskFactorIndex(test3[i]);
        
        if (actualRisk != -1) {
            Q3_Answer(actualRisk, answer3, territory, riskFactors, nTerritory);
            
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
    
    int test4[5] = {75, 80, 82, 85, 90};
    
    for (i = 0; i < 5; i++) {
        printf("How many countries have a baseline life expectancy of at least %d?\n", test4[i]);
        count = Q4_Answer((double)test4[i], riskFactors, nTerritory);
        printf("A: %d\n\n", count);
    }
    
    
    /* ==================== QUESTION 5 ==================== */
    printf("\nQuestion 5:\n\n");
    
    char testRisk5[5][MAX_LENGTH] = {"Ambient_PM2.5", "Ozone", "Occupational", 
                                      "High_Fasting_Plasma_Sugar", "Smoking"};
    char testCountry[5][MAX_LENGTH] = {"Argentina", "Chile", "Italy", "Solomon_Islands", "Philippines"};
	
    for (i = 0; i < 5; i++) {
        int cntIdx = Q5_Answer(testCountry[i], territory, nTerritory);
        actualRisk = GetRiskFactorIndex(testRisk5[i]);
        
        if (cntIdx != -1 && actualRisk != -1) {
            printf("What are the statistics for %s for %s?\n", 
                   riskText[actualRisk], territory[cntIdx]);
            printf("A:\n");
            printf("%-40s : %.6lf\n\n", territory[cntIdx], riskFactors[cntIdx][actualRisk]);
        } else {
            printf("Country %s not found.\n\n", testCountry[i]);
        }
    }
    
    return 0;
}

