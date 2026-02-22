/*
        CCPROG2 MP PART 1 C SOURCE CODE
  
        GROUP NUMBER (2 digits): 35
        DATE SUBMITTED         : 

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

// feel like we shld include string typedefs here for the arrays

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

int processData(){


	
	//loop for reading risk factors
	for (int i = 0; i < MAX_TERRITORY < i++){
		for (int j = 1; j < 15; j++){
			scanf("%lf", riskFactors[i][j]);
	}
}

/*  galing notes ko -- scans indefinitely para di naka-cap ung read function natin 
while (scanf("%d %s %s %f", &ID, lastname, firstname, &grade) == 4){	
			printf("%d %-15s %-15s %.1f\n", ID, lastname, firstname, grade);
	}

*/



int main(){
	char countryNames[MAX_TERRITORY][MAX_LENGTH]; // stores country names
	double baselineExpectancy[MAX_TERRITORY]; // stores baseline life expectancy
	double riskFactors[MAX_TERRITORY][15]; // stores risk factors

	char riskText[15][40] = {
        "Baseline_LE", "Air_Pollution", "Ambient_PM2.5", "Ozone", 
        "Household_Air_Pollution", "Environmental", "Occupational", 
        "Unsafe_WaSH", "Metabolic", "Dietary", "High_Fasting_Plasma_Sugar", 
        "Tobacco", "Smoking", "Second_Hand_Smoke", "Unsafe_Sex"
    };

	int i, j, k, idx, actualRisk;

	  /* ==================== QUESTION 1 ==================== */
    printf("Question 1:\n\n");
	 char test1[5][5][MAX_LENGTH] = {
        {"Barbados", "Japan", "Chile", "Montenegro", "Australia"},
        {"Georgia", "Belize", "", "", ""},
        {"Peru", "Armenia", "Italy", "Cyprus", "Argentina"},
        {"France", "", "", "", ""},
        {"Portugal", "Afghanistan", "Greece", "Malta", "Argentina"}
    };

	double average = 0;
    int count = 0;
    
    for (i = 0; i < 5; i++) {
        count = CountElements(test1[i], 5);
        
        Q1_Answer(test1[i], count, &average, territory, baseline, nTerritory);
        
        /* Print question */
        printf("What is the average baseline life expectancy across ");
        for (j = 0; j < count; j++) {
            if ((j == count - 1) && (count > 1))
                printf("and ");
            if (j < count - 1)
                printf("%s, ", test1[i][j]);
            else
                printf("%s? List the names of each country, their values, and the average across the countries.\n", test1[i][j]);
        }
        
        /* Print answer */
        printf("A:\n");
        for (k = 0; k < count; k++) {
            idx = SearchTerritory(test1[i][k], territory, nTerritory);
            
            if (idx != -1)
                printf("%-40s : %.6lf\n", territory[idx], baseline[idx]);
            else
                printf("%-40s : NOT FOUND\n", test1[i][k]);
        }
        
        printf("\nAverage = %.6lf\n\n", average);
    }

	 /* ==================== QUESTION 2 ==================== */
    printf("\nQuestion 2:\n\n");
    
    int test2[5] = {AIR_POLLUTION, OCCUPATIONAL, METABOLIC, TOBACCO, UNSAFE_SEX};
    
    for (i = 0; i < 5; i++) {
        actualRisk = test2[i];
        printf("Which country has the highest (maximum) loss of life expectancy due to %s?\n", 
               riskText[actualRisk + 1]);  // +1 because riskText includes Baseline at [0]
        
        char *highest = Q2_Answer(actualRisk, territory, riskFactors, nTerritory);
        printf("A: %s\n\n", highest);
    }

	
}
