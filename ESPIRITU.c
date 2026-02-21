/*
        CCPROG2 MP PART 1 C SOURCE CODE
  
        GROUP NUMBER (2 digits):
        DATE SUBMITTED         : February 16, 2026

        ESPIRITU, GENE CLEMENT                          SECTION1:S18A
        LASTNAME1, FIRSTNAME2:                          SECTION2:

        NOTE: encode ONLY your NAME if this code is for your own individual solution
              encode BOTH names and sections if this code is for your GROUP's FINAL solution

        Do not forget to encode your name, section and date of submission.      
		
	For your FINAL solution: Rename this file using your last names in alphabetical order, for example CRUZ_TAN.c
		
	Make sure to compile your C source code with a -Wall directive.  
	   Example: CCPROG2> gcc -Wall LASTNAME1_LASTNAME2.c
	   
	Fix all warnings.  Do NOT run the program if you still have a warning.  You must have
	0 error, 0 warning before running the program.
	   
	Run the resulting a.exe file in the command line with input and output (I/O) redirection.
	   Example: a < SoGA_DATASET.TXT > OUTPUT_LASTNAME1_LASTNAME2.TXT

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
#define NUM 14

//Risk factors indices
#define AIR_POLLUTION 0
#define AMBIENT_PM25 1
#define OZONE 2
#define HOUSEHOLD_AIR_POLLUTION 3
#define ENVIRONMENTAL 4
#define OCCUPATIONAL 5
#define UNSAFE_WASH 6
#define METABOLIC 7
#define DIETARY 8
#define HIGH_FASTING_PLASMA_SUGAR 9
#define TOBACCO 10
#define SMOKING 11
#define SECOND_HAND_SMOKE 12
#define UNSAFE_SEX 13
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
    Purpose: reads the SoGA dataset
    Returns: the number of territories
    @param: territory is the array to store territory names
    @param: baseline is the array to store baseline life expectancy values
    @param: riskfactors is the 2D array to store risk factor values
    Pre-condition: arrays are properly allocated 
*/

int 
ReadData(char territory[][MAX_LENGTH], double baseline[], double riskfactors[][NUM])
{
    int count = 0;
    int i;
    
    //loop for reading all data 
    while (scanf("%s", territory[count]) == 1) {
        scanf("%lf", &baseline[count]);
        
    //loop for reading the risk factors
        for (i = 0; i < NUM; i++) {
            scanf("%lf", &riskfactors[count][i]);
        }
        count++;
    }
    
    return count;
}

/*
    Purpose:Uses lineear search for territory name
    Returns: the index if found, -1 if not found
    @param: territoryName is the name to search for
    @param: territory is the array of territory names
    @param: nTerritory is the number of territories in the array
    Pre-condition: all parameters are valid
*/
int 
SearchTerritory(char *territoryName, char territory[][MAX_LENGTH], int nTerritory)
{
    int i;
    
    for (i = 0; i < nTerritory; i++) {
        if (strcmp(territory[i], territoryName) == 0) {
            return i; //returns index of territory if found
        }
    }
    
    return -1; //if not found
}

/*
    Purpose: Index for a risk factor based on its name
    Returns: the index of the risk factor, or -1 if invalid
    @param: riskName is the name of the risk factor
    Pre-condition: riskName is a valid string
*/
int 
GetRiskFactorIndex(char *riskName)
{
	//returns the index of the risk factor
    if (strcmp(riskName, "Air_Pollution") == 0) return AIR_POLLUTION;
    if (strcmp(riskName, "Ambient_PM2.5") == 0) return AMBIENT_PM25;
    if (strcmp(riskName, "Ozone") == 0) return OZONE;
    if (strcmp(riskName, "Household_Air_Pollution") == 0) return HOUSEHOLD_AIR_POLLUTION;
    if (strcmp(riskName, "Environmental") == 0) return ENVIRONMENTAL;
    if (strcmp(riskName, "Occupational") == 0) return OCCUPATIONAL;
    if (strcmp(riskName, "Unsafe_WaSH") == 0) return UNSAFE_WASH;
    if (strcmp(riskName, "Metabolic") == 0) return METABOLIC;
    if (strcmp(riskName, "Dietary") == 0) return DIETARY;
    if (strcmp(riskName, "High_Fasting_Plasma_Sugar") == 0) return HIGH_FASTING_PLASMA_SUGAR;
    if (strcmp(riskName, "Tobacco") == 0) return TOBACCO;
    if (strcmp(riskName, "Smoking") == 0) return SMOKING;
    if (strcmp(riskName, "Second_Hand_Smoke") == 0) return SECOND_HAND_SMOKE;
    if (strcmp(riskName, "Unsafe_Sex") == 0) return UNSAFE_SEX;
    
    return -1; 
}
/*
    Q1: What is the average baseline life expectancy across <parameter_country>. 
        List the names of each country, their values, and the average across the countries.
        
    A1: When parameter_country includes "Kiribati" and "Samoa", the answer is:
        Kiribati 60.722550
        Samoa 70.566013
        Average Life Expectancy: 65.644282
        
    Purpose: Computes the average baseline life expectancy for specified countries Computes
    Returns: Averages baseline life expectancy
    @param: countryNames is the array of country names to search for
    @param: numCountries is the number of countries in the array
    @param: foundCountry is the array to store found country names
    @param: values is the array to store baseline life expectancy values for found countries
    @param: nFound is pointer to store the number of countries found
    @param: territory is the array of all territory names
    @param: baseline is the array of baseline life expectancy values
    @param: nTerritory is the total number of territories
    Pre-condition: all parameters are valid
*/
double 
Q1_Answer(char countryNames[][MAX_LENGTH], int numCountries, 
          char foundCountry[][MAX_LENGTH], double values[], int *nFound,
          char territory[][MAX_LENGTH], double baseline[], int nTerritory)
{
    int i, index;
    double sum = 0.0;
    *nFound = 0;
    
    //Searches the countries then accumulates it
   		 for (i = 0; i < numCountries; i++) {
   		 	index = SearchTerritory(countryNames[i], territory, nTerritory);
        
        	if (index != -1) {
  	//Copies the country name and value
            strcpy(foundCountry[*nFound], territory[index]);
            values[*nFound] = baseline[index];
            sum += baseline[index];
            (*nFound)++;
        }
    }
    
    
    if (*nFound > 0) {
        return sum / (*nFound);
    }//averages
    
    return 0;
}
/*
    Q2: Which country has the highest (maximum) loss of life expectancy due to <parameter_risk>?
    
    A2: When parameter_risk is "Metabolic", an example answer could be:
        Turkmenistan
        
    Purpose: Given the risk factor, finds the country with the max loss
    Returns: Value of the max loss country
    @param: riskName is the name of the risk factor
    @param: maxCountry is the string to store the name of the country with maximum loss
    @param: territory is the array of territory names
    @param: riskfactors is the 2D array of risk factor values
    @param: nTerritory is the number of territories
    Pre-condition: all parameters are valid
*/
double 
Q2_Answer(char *riskName, char *maxCountry,
          char territory[][MAX_LENGTH], double riskfactors[][NUM], 
          int nTerritory)
{
    int riskIndex = GetRiskFactorIndex(riskName); 
    int i;
    double maxValue;
    int maxIndex; 
    
    if (riskIndex == -1) {
        maxCountry[0] = '\0';
        return 0.0;
    }
    
    //Initialization
    maxIndex = 1;
    maxValue = riskfactors[1][riskIndex];
    
    //Loop for max value
    for (i = 2; i < nTerritory; i++) {
        if (riskfactors[i][riskIndex] > maxValue) {
            maxValue = riskfactors[i][riskIndex];
            maxIndex = i;
        }
    }
    
    strcpy(maxCountry, territory[maxIndex]);
    return maxValue;
}
/*
    Purpose: Performs selection sort based on risk factor values  
    @param: territory is the array of territory names to sort
    @param: values is the array of values to sort by
    @param: n is the number of elements to sort
    Pre-condition: arrays have at least n elements
*/
void 
SelectionSort(char territory[][MAX_LENGTH], double values[], int n)
{
    int i, j, minIndex;
    double tempVal;
    char tempName[MAX_LENGTH];
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        
        //Loop for finding the mininum element
        for (j = i + 1; j < n; j++) {
            if (values[j] < values[minIndex]) {
                minIndex = j;
            }
        }
        
        //Swaps with the first element
        if (minIndex != i) {
            //Value swapping
            tempVal = values[i];
            values[i] = values[minIndex];
            values[minIndex] = tempVal;
            
    		//Name swap
            strcpy(tempName, territory[i]);
            strcpy(territory[i], territory[minIndex]);
            strcpy(territory[minIndex], tempName);
        }
    }
}
/*
    Q3: Which five countries have the lowest loss of baseline life expectancy due to <parameter_risk>?
    
    A3: When parameter_risk is "Metabolic", an example answer is:
        1. Japan 2.546600
        2. Lesotho 2.626596
        3. Central_African_Republic 2.825729
        4. France 2.991462
        5. Somalia 2.991605
        
    Purpose: Uses selection sort to find the country with the lowest loss
    @param: riskName is the name of the risk factor
    @param: top5Countries is the array to store the names of the top 5 countries
    @param: top5Values is the array to store the corresponding values
    @param: territory is the array of all territory names
    @param: riskfactors is the 2D array of risk factor values
    @param: nTerritory is the number of territories
    Pre-condition: all parameters contain valid values
*/
void 
Q3_Answer(char *riskName, char top5Countries[][MAX_LENGTH], double top5Values[],
          char territory[][MAX_LENGTH], double riskfactors[][NUM], 
          int nTerritory)
{
    int riskIndex = GetRiskFactorIndex(riskName); 
    int i;
    char tempTerritory[MAX_TERRITORY][MAX_LENGTH];
    double tempValues[MAX_TERRITORY];
    int count = 0;
    
    if (riskIndex == -1) {
        return;
    }
    
    //Copy territories and values, i = 1 due to 0 is global
    for (i = 1; i < nTerritory; i++) {
        strcpy(tempTerritory[count], territory[i]);
        tempValues[count] = riskfactors[i][riskIndex];
        count++;
    }
    
    
    SelectionSort(tempTerritory, tempValues, count);
    
    //Copy the top 5
    for (i = 0; i < 5 && i < count; i++) {
        strcpy(top5Countries[i], tempTerritory[i]);
        top5Values[i] = tempValues[i];
    }
}
/*
    Q4: How many countries have a baseline life expectancy of at least <parameter_number>?
    
    A4: When parameter_number is 70, the answer is the count of countries and their names
    
    Purpose: Counts the number of countries with baseline life expectancy >= threshold  
    Returns: the count of countries meeting the criteria
    @param: threshold is the minimum baseline life expectancy value
    @param: matchingCountries is the array to store names of matching countries
    @param: territory is the array of territory names
    @param: baseline is the array of baseline life expectancy values
    @param: nTerritory is the number of territories
    Pre-condition: all parameters contain valid values
*/
int 
Q4_Answer(double threshold, char matchingCountries[][MAX_LENGTH],
          char territory[][MAX_LENGTH], double baseline[], int nTerritory)
{
    int i;
    int count = 0;

    for (i = 1; i < nTerritory; i++) {
        if (baseline[i] >= threshold) {
            strcpy(matchingCountries[count], territory[i]);
            count++;
        }
    }
    
    return count;
}
/*
    Q5: What are the statistics for <parameter_risk> for <parameter_country>?
    
    A5: When parameter_risk is "Metabolic" and parameter_country is "South_Sudan", 
        the answer is: South_Sudan 3.067292
        
    Purpose: Finds the value of a specific risk factor for a specific country        Finds
    Returns: the risk factor value, or -1 if not found
    @param: riskName is the name of the risk factor
    @param: countryName is the name of the country
    @param: territory is the array of territory names
    @param: riskfactors is the 2D array of risk factor values
    @param: nTerritory is the number of territories
    Pre-condition: all parameters contain valid values
*/
double 
Q5_Answer(char *riskName, char *countryName,
          char territory[][MAX_LENGTH], double riskfactors[][NUM], 
          int nTerritory)
{
    int riskIndex = GetRiskFactorIndex(riskName);
    int countryIndex = SearchTerritory(countryName, territory, nTerritory);
    
    if (riskIndex == -1 || countryIndex == -1) {
        return -1;
    }
    
    return riskfactors[countryIndex][riskIndex];
}


int
main()
{
	//Storing the dataset
		char territory[MAX_TERRITORY][MAX_LENGTH];
		double baseline[MAX_TERRITORY];
		double riskfactors[MAX_TERRITORY][NUM];
		int nTerritory;
	
	//Function outputs
		char foundCountry[MAX_TERRITORY][MAX_LENGTH];
		double values[MAX_TERRITORY];
		int nFound;
		double average;
		
		char maxCountry[MAX_LENGTH];
		double maxValue;
		
		char top5Countries[5][MAX_LENGTH];
    	double top5Values[5];
    
    	char matchingCountries[MAX_TERRITORY][MAX_LENGTH];
    	int count;
    	double statValue;
    
    //Test cases
    	int i;
    	char test_countries[10][MAX_LENGTH];
    	int num_test_countries;
    
    //Reads the data set
   	 nTerritory = ReadData(territory, baseline, riskfactors);
    
    
    /* 
       Call the functions that answer the 5 questions. Thereafter, use printf() to print the questions and the corresponding answers.  

       Make sure to keep the displayed ANSWER for each question plain and simple.  Do NOT printf anything that is unnecessary.  
   
       // 
       // Example #1: Call to a function that answers sample question Q1 resulting to a unique answer.    
       //
       expectancy = Q1_Answer(territory, param_x, param_y); // where expectancy, territory, param_x and param_y are example local variables
                                                            // pass all the parameters you'll need to answer the question
       
       printf("Q1: Which territory has the lowest baseline life expectancy? [minimum]\n");
       printf("A1: %s %lf\n", territory, expectancy); // keep the answer simple; just print the value(s) that tells us the answer     
 
       MULTIPLE TEST CASES HARD REQUIREMENTS FOR QUESTIONS WITH PARAMETERS:
         You should have at least 3 to at most 5 function calls to test the functions that answer questions with parameter(s).  
         There should be function calls with different actual parameter values.  For questions that require linear or binary search,
         make sure to test for both found and not found scenarios.
   
       //
       // Example #2: Call a function 5 times each time with a different actual parameter value
       //
       double parameter_number[5] = {0.5, 1.0, 1.5, 2.0, 3.0}; // 5 test values for parameter_number
       int count;

       for (int i = 0; i < 5; i++) { // note that there are 5 test cases in this example
           printf("\n"); // print an empty line to separate the next set of lines of output from the previous displayed results.
           printf("Q4: How many territories have a reduction of at least %lf year(s) in \n", parameter_number); 
           printf("    in life expectancy due to air pollution? List the territories with the corresponding reduction values\n");
           printf("    in the same order as they appear in the source data. [count]\n");
      
           count = Q4_Answer(parameter_number[i], ..., ...);  // ... means you'll need to provide the other necessary parameters
           printf("A4: %d\n", count);                         
       }

    */
    
    //----------------TEST CASE FOR QUESTION 1-----------------//
    
    /* Test Case 1: Kiribati and Samoa */
    printf("\n");
    printf("Q1: What is the average baseline life expectancy across <parameter_country>.\n");
    printf("    List the names of each country, their values, and the average across the countries.\n");
    
    num_test_countries = 2;
    strcpy(test_countries[0], "Kiribati");
    strcpy(test_countries[1], "Samoa");
    
    average = Q1_Answer(test_countries, num_test_countries, foundCountry, values, 
                        &nFound, territory, baseline, nTerritory);
    
    printf("A1: Test Case 1 - Countries: Kiribati, Samoa\n");
    for (i = 0; i < nFound; i++) {
        printf("    %s %.6lf\n", foundCountry[i], values[i]);
    }
    printf("    Average Life Expectancy: %.6lf\n", average);
    
    /* Test Case 2: Philippines, Thailand, Vietnam */
    printf("\n");
    printf("Q1: What is the average baseline life expectancy across <parameter_country>.\n");
    printf("    List the names of each country, their values, and the average across the countries.\n");
    
    num_test_countries = 3;
    strcpy(test_countries[0], "Philippines");
    strcpy(test_countries[1], "Thailand");
    strcpy(test_countries[2], "Vietnam");
    
    average = Q1_Answer(test_countries, num_test_countries, foundCountry, values, 
                        &nFound, territory, baseline, nTerritory);
    
    printf("A1: Test Case 2 - Countries: Philippines, Thailand, Vietnam\n");
    for (i = 0; i < nFound; i++) {
        printf("    %s %.6lf\n", foundCountry[i], values[i]);
    }
    printf("    Average Life Expectancy: %.6lf\n", average);
    
    /* Test Case 3: Japan, Singapore, Switzerland */
    printf("\n");
    printf("Q1: What is the average baseline life expectancy across <parameter_country>.\n");
    printf("    List the names of each country, their values, and the average across the countries.\n");
    
    num_test_countries = 3;
    strcpy(test_countries[0], "Japan");
    strcpy(test_countries[1], "Singapore");
    strcpy(test_countries[2], "Switzerland");
    
    average = Q1_Answer(test_countries, num_test_countries, foundCountry, values, 
                        &nFound, territory, baseline, nTerritory);
    
    printf("A1: Test Case 3 - Countries: Japan, Singapore, Switzerland\n");
    for (i = 0; i < nFound; i++) {
        printf("    %s %.6lf\n", foundCountry[i], values[i]);
    }
    printf("    Average Life Expectancy: %.6lf\n", average); 
    
    
     //----------------TEST CASE FOR QUESTION 2-----------------//
      /* Test Case 1: Metabolic */
    printf("\n");
    printf("Q2: Which country has the highest (maximum) loss of life expectancy due to <parameter_risk>?\n");
    
    maxValue = Q2_Answer("Metabolic", maxCountry, territory, riskfactors, nTerritory);
    
    printf("A2: Test Case 1 - Risk: Metabolic\n");
    printf("    %s %.6lf\n", maxCountry, maxValue);
    
    /* Test Case 2: Air_Pollution */
    printf("\n");
    printf("Q2: Which country has the highest (maximum) loss of life expectancy due to <parameter_risk>?\n");
    
    maxValue = Q2_Answer("Air_Pollution", maxCountry, territory, riskfactors, nTerritory);
    
    printf("A2: Test Case 2 - Risk: Air_Pollution\n");
    printf("    %s %.6lf\n", maxCountry, maxValue);
    
    /* Test Case 3: Tobacco */
    printf("\n");
    printf("Q2: Which country has the highest (maximum) loss of life expectancy due to <parameter_risk>?\n");
    
    maxValue = Q2_Answer("Tobacco", maxCountry, territory, riskfactors, nTerritory);
    
    printf("A2: Test Case 3 - Risk: Tobacco\n");
    printf("    %s %.6lf\n", maxCountry, maxValue);
    
     //----------------TEST CASE FOR QUESTION 3-----------------//
      /* Test Case 1: Metabolic */
    printf("\n");
    printf("Q3: Which five countries have the lowest loss of baseline life expectancy due to <parameter_risk>?\n");
    
    Q3_Answer("Metabolic", top5Countries, top5Values, territory, riskfactors, nTerritory);
    
    printf("A3: Test Case 1 - Risk: Metabolic\n");
    for (i = 0; i < 5; i++) {
        printf("    %d. %s %.6lf\n", i + 1, top5Countries[i], top5Values[i]);
    }
    
    /* Test Case 2: Air_Pollution */
    printf("\n");
    printf("Q3: Which five countries have the lowest loss of baseline life expectancy due to <parameter_risk>?\n");
    
    Q3_Answer("Air_Pollution", top5Countries, top5Values, territory, riskfactors, nTerritory);
    
    printf("A3: Test Case 2 - Risk: Air_Pollution\n");
    for (i = 0; i < 5; i++) {
        printf("    %d. %s %.6lf\n", i + 1, top5Countries[i], top5Values[i]);
    }
    
    /* Test Case 3: Dietary */
    printf("\n");
    printf("Q3: Which five countries have the lowest loss of baseline life expectancy due to <parameter_risk>?\n");
    
    Q3_Answer("Dietary", top5Countries, top5Values, territory, riskfactors, nTerritory);
    
    printf("A3: Test Case 3 - Risk: Dietary\n");
    for (i = 0; i < 5; i++) {
        printf("    %d. %s %.6lf\n", i + 1, top5Countries[i], top5Values[i]);
    }
    
      //----------------TEST CASE FOR QUESTION 4-----------------//
     /* Test Case 1: threshold = 70 */
    printf("\n");
    printf("Q4: How many countries have a baseline life expectancy of at least <parameter_number>?\n");
    
    count = Q4_Answer(70.0, matchingCountries, territory, baseline, nTerritory);
    
    printf("A4: Test Case 1 - Threshold: 70.000000\n");
    printf("    Count: %d\n", count);
    printf("    Countries:\n");
    for (i = 0; i < count; i++) {
        printf("    %s\n", matchingCountries[i]);
    }
    
    /* Test Case 2: threshold = 75 */
    printf("\n");
    printf("Q4: How many countries have a baseline life expectancy of at least <parameter_number>?\n");
    
    count = Q4_Answer(75.0, matchingCountries, territory, baseline, nTerritory);
    
    printf("A4: Test Case 2 - Threshold: 75.000000\n");
    printf("    Count: %d\n", count);
    printf("    Countries:\n");
    for (i = 0; i < count; i++) {
        printf("    %s\n", matchingCountries[i]);
    }
    
    /* Test Case 3: threshold = 80 */
    printf("\n");
    printf("Q4: How many countries have a baseline life expectancy of at least <parameter_number>?\n");
    
    count = Q4_Answer(80.0, matchingCountries, territory, baseline, nTerritory);
    
    printf("A4: Test Case 3 - Threshold: 80.000000\n");
    printf("    Count: %d\n", count);
    printf("    Countries:\n");
    for (i = 0; i < count; i++) {
        printf("    %s\n", matchingCountries[i]);
    }
    
      //----------------TEST CASE FOR QUESTION 5-----------------//
    /* Test Case 1: Metabolic for South_Sudan */
    printf("\n");
    printf("Q5: What are the statistics for <parameter_risk> for <parameter_country>?\n");
    
    statValue = Q5_Answer("Metabolic", "South_Sudan", territory, riskfactors, nTerritory);
    
    printf("A5: Test Case 1 - Risk: Metabolic, Country: South_Sudan\n");
    printf("    South_Sudan %.6lf\n", statValue);
    
    /* Test Case 2: Air_Pollution for Philippines */
    printf("\n");
    printf("Q5: What are the statistics for <parameter_risk> for <parameter_country>?\n");
    
    statValue = Q5_Answer("Air_Pollution", "Philippines", territory, riskfactors, nTerritory);
    
    printf("A5: Test Case 2 - Risk: Air_Pollution, Country: Philippines\n");
    printf("    Philippines %.6lf\n", statValue);
    
    /* Test Case 3: Tobacco for China */
    printf("\n");
    printf("Q5: What are the statistics for <parameter_risk> for <parameter_country>?\n");
    
    statValue = Q5_Answer("Tobacco", "China", territory, riskfactors, nTerritory);
    
    printf("A5: Test Case 3 - Risk: Tobacco, Country: China\n");
    printf("    China %.6lf\n", statValue);
    
    /* Test Case 4: Dietary for Japan */
    printf("\n");
    printf("Q5: What are the statistics for <parameter_risk> for <parameter_country>?\n");
    
    statValue = Q5_Answer("Dietary", "Japan", territory, riskfactors, nTerritory);
    
    printf("A5: Test Case 4 - Risk: Dietary, Country: Japan\n");
    printf("    Japan %.6lf\n", statValue);
     

    return 0;
}
