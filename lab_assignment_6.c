/*
	COP3502C-24 Spring 0023 Lab 5
	Copyright 2024 Shaquille_Miller
*/

#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	//Ensure high is higher than low, or item is not found
	if(high<low) return -1;

	//Since array is sorted, i will find the middle first and decide if i should search left or right
	int middleIndex = (high+low)/2;
	int middleVal = numbers[middleIndex];

	//Check if middle val is the value we are looking for 
	if(middleVal == value){
		return middleIndex;
	}else if(middleVal>value){ //If middle value is greater than what we are looking for then search left
		return search(numbers,low,middleIndex-1,value);
	}else{ //Middle value is less then value we are looking for then search right
		return search(numbers,middleIndex+1,high,value);
	}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}