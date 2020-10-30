#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <list>


//define operation type
#define initial 0
#define right_operation 1
#define insert_operation 2
#define delete_operation 3
#define replace_operation 4
#define final 5


//define operation Cost
#define right_cost 0
#define delete_cost 2
#define insert_cost 3
#define replace_cost 4


using namespace std; 


// The function to find the minimum of three numbers 
int min(int x, int y, int z) 
{
	return min(min(x, y), z); 
}


//A function to print the operation table
void print(char* x, int m, char* y, int n, int** distance, int** operation_table)
{
	int i = 0, j = 0;
	int each_cost = 0, total_cost = 0;
	int operation_taken;
	const char *operation_name;
	
	
	//create linked list z_link[1..s] string to store the updated characters
	//then copy z_link[1..s] = x[1..m]
	list<char> z_link (x, x + m / sizeof(char));
	
	//declare an index that will loop through z_link
	list<char>::iterator it_index;


	//assign the index at the beginning of the linked list
	it_index = z_link.begin();

	//print the output table
	printf("%-15s \t cost \t Total \t z \n", "Operation");
	printf("------------------------------------------------------------------\n");
	printf("%-15s \t %d \t %d \t %s\n", "initial string", each_cost, total_cost, x);
	
	//loop through the operation_table until it reaches the final charcter
	while (operation_table[i][j] != final)
	{
		//do the right operation
		if(operation_table[i][j] == right_operation)
		{			
			each_cost = right_cost;
			operation_name = "right";
			i++;
			j++;
			advance (it_index,1);
		}
		
		//do the replace operation
		//replace operation will be done by delete + insert
		else if(operation_table[i][j] == replace_operation)
		{
			it_index = z_link.erase (it_index);
			z_link.insert (it_index,y[j]);
			each_cost = replace_cost;
			operation_name = "replace";
			i++;
			j++;	
		}
		
		//do the insert operation
		else if(operation_table[i][j] == insert_operation)
		{
			z_link.insert (it_index,y[j]);
			each_cost = insert_cost;
			operation_name = "insert";
			j++;	
		}
		
		//do the delete operation
		else if(operation_table[i][j] == delete_operation)
		{
			
			it_index = z_link.erase (it_index);
			each_cost = delete_cost;
			operation_name = "delete";
			i++;	
		}

    		total_cost += each_cost;

		//print the operation name, cost and total cost
		printf("%-15s \t %d \t %d \t ", operation_name, each_cost, total_cost);
		
		
		//print the modified z linked list
		for (list<char>::iterator it = z_link.begin(); it != z_link.end(); it++)
		{
			cout << *it;
		}

    		printf("\n");
	}
}
	

//The function to compute the edit distance for dynamic programming table
void Edit_Distance(char* x, int m, char* y, int n) 
{
	
	int RepOrRight_op_cost, Insert_op_cost, Delete_op_cost, Min_cost;
	
	int operation_type = 0, operation_taken = 0;
	
	//create the dynamic programming table
	int** distance;
	distance = new int *[m+1];
	
	//create the operation table to keep track of operation type
	int** operation_table;
	operation_table = new int *[m+1];
	
	//create 2D array for both tables
	for (int i = 0; i <= m; i++)
	{
	    	distance[i] = new int[n+1];
	    	operation_table[i] = new int[n+1];
    	}
	
	//assign 0 at the end of both strings. Edit distance is 0
	distance[m][n] = 0;
	
	//final is the end of the table. So, all operations are done
  	operation_table[m][n] = final;

	//assign [x-axis][n] to delete operation
  	for (int i = 0; i < m; i++)
	{
		distance[i][n] = delete_cost*(m-i);
		operation_table[i][n] = delete_operation;
	}
	
  	//assign [m][y-axis] to insert operation
  	for (int j = 0; j < n; j++)
	{
		distance[m][j] = insert_cost*(n-j);
		operation_table[m][j] = insert_operation;
  	}
  	
  	//loop through 2D array[m][n] to fill the whole table 
  	for (int i = m-1; i >=0; i--)
	{
    		for (int j = n-1; j >= 0; j--)
		{
			if(x[i] == y[j])
			{
				RepOrRight_op_cost = distance[i+1][j+1] + right_cost;
			}
			else if(x[i] != y[j])
			{
				RepOrRight_op_cost = distance[i+1][j+1] + replace_cost;
			}
    		    		
		    	Insert_op_cost = distance[i][j+1] + insert_cost;
	
		    	Delete_op_cost = distance[i+1][j] + delete_cost;
	    		
	    		
	    		//find the minumum cost of three different operation
	    		Min_cost = min(RepOrRight_op_cost, Insert_op_cost, Delete_op_cost);
	    		 
				   		
	    		//if minumum == right_operation or replace cost, assign the right or replace operation
	    		if(Min_cost == RepOrRight_op_cost)
	    		{
			    	if (x[i] == y[j])
				{
					operation_taken = right_operation;
				}
				else
				{
					operation_taken = replace_operation;
				}
			}
	    		
	    		//if minumum == insert cost, assign the insert operation
	    		if (Min_cost == Insert_op_cost)
			{
				operation_taken = insert_operation;
	      		}
	      		
	      		//if minumum == delete cost, assign the delete operation
	      		if (Min_cost == Delete_op_cost)
			{
				operation_taken = delete_operation;
	      		}
	      		
			//each cost is inserted into distance table
	      		distance[i][j] = Min_cost;

			//each operation taken is recored into operation table
	      		operation_table[i][j] = operation_taken;

    		}
	}
	
	
  	printf("\n\nEdit Distance =  %d\n\n", distance[0][0]);
  	
  	//limit the string lenght to print
	if ((m < 100) && (n < 100)) 
	{
		print(x, m, y, n, distance, operation_table);
	}
}


int main(int argc, char* argv[])
{

	FILE* f;
	int inputSize = 0, outputSize = 0;
	int i;

	// Make sure to input the file name
	if (argc < 2)
	{
		printf("Please input .txt file name\n");
		return 0;
	}

	// Open the file
	f = fopen(argv[1], "r");
	assert(f != NULL);

	//Read in the input string size
	fscanf(f, "%d\n", &inputSize);

	//declare input array with input size
	char inputArray[inputSize];

	//copy the characters into the input string
	for (i = 0; i < inputSize; i++)
	{
		fscanf(f, "%c", &inputArray[i]);
	}

	//put NULL at the end of the array
	inputArray[inputSize] = '\0';

  	assert(strlen(inputArray) == inputSize);

	//Read in the output string length
	fscanf(f, "%d\n", &outputSize);

	//declare output array with output length
	char outputArray[outputSize];

	//copy the characters into the output string
	for (i = 0; i < outputSize; i++)
	{
		fscanf(f, "%c", &outputArray[i]);
	}

	//put NULL at the end of the array
	outputArray[outputSize] = '\0';

  	assert(strlen(outputArray) == outputSize);
  
	Edit_Distance(inputArray, inputSize, outputArray, outputSize);

	// Close the file
	fclose(f);
	
	
	return 0;
}



