
#include<iostream>
using namespace std;
#define MAX 101//lenght of array used in program.i assumed the MAX lenght as 101 here.it can be changed according to desire lenght.
#define VALUE 1//used to avoid hard coded values.

int main(){
	
	unsigned int L = 0,max_num = 0,heart_one,heart_two;//i used unsigned int here to prevent averflow while printing the febonachi series.
	unsigned int arr1[MAX] = {0},arr2[MAX] = {0},arr3[MAX] = {0};//i used unsigned int here to prevent averflow while printing the febonachi series.
	int i,j,temp,check = 0;//int variables.

	/*since array concept is used in this program i limited the size to be  100 so you can't Enter a number bigger than hundered in this case*/
	
	cin >>L;//get the num from the user
	temp = L;//used to implement program
	
	if (temp %2 == 0){//checks if the num is even or odd
		
		++temp;
		temp =temp/2+2;
	}
	else{
		
		temp = temp/2+2;
	}
	if (L == 1){//if user enters 1
		
		heart_one = VALUE;
		heart_two = VALUE;
		check = VALUE;
		max_num = VALUE;
		cout << VALUE <<endl;//i printed the first and second line for value 1 manually so that make my program easier in the next levels
		cout << VALUE << " " << VALUE << endl;//i printed the first and second line for value 1 manually so that make my program easier in the next levels
	}
	else{//if your enters different than 1
		
		L++;//increment number.
		
		for(i = 0; i < L; ++i){//outer loop used to traverce from upward to downward of triangle in this case.

			if(i == 0){	//condition for first line of feboachi triangle 
				
				arr1[i] = VALUE;
				cout << arr1[i];//print one on the first line
				
				max_num = VALUE;//set max as 1
				heart_one = VALUE;//set heart_one as 1
			}
			else if(i == 1){//condition for second line of febonachi triangle
					
				arr2[i-1] = VALUE;
				arr2[i] = VALUE;
				
				max_num = VALUE;//set max as one
				heart_two = VALUE;//set heart_two as one

				cout << arr2[i-1]<<" "<< arr2[i];//this object prints the last number in each line 
			}
			else{//this else bloch will execute after 3th line or when i > 1
				
				for(j = 0; j <=i; ++j){//inner loop to traverse the each line's correspondint numbers.
					
					if(j!=i){//condition to check if the current location it not last num in corresponding line
						
						arr3[j] = arr2[j] + arr1[j];//assing arr1 + arr2 to arr3 to be used in the next iteration and down lines.
						arr1[j] = arr2[j];//upated the arr1 to be used in the next iteration of loop
						arr2[j] = arr3[j];//upated the arr2 to be used in the next iteration of loop
						
						if(arr3[j] > max_num){//block to find and update the max value.
							
							max_num = arr3[j];	
						}
						cout << arr3[j] << " ";				
					}
					else{//conditio to implement for line num of corresponding line
						
						arr3[j] = arr1[j-1]+arr1[j-2];//here i just found a pattern wich is next lines last num is sum of previes lines last and second last nums
						arr1[j] = arr2[j];//update arr1 to be used in the next iteration of inner loop
						arr2[j] = arr3[j];//update arr2 to be used in the next iteration of inner loop
						
						if(arr3[j] > max_num){//block to find and update the max value.
							
							max_num = arr3[j];	
						}
						cout << arr3[j];//print the number
					}
		 		}
		 	}
		 	if(i == temp-1){//condition to find the heart of piramid which is in this case (L+1)/2+1.if l is even then add one more and if it si odd do not add one//find heart of piramid

		 		heart_one = arr3[i/2];//find heart of piramid heart_one means the first num of hear of piramid 
		 		heart_two = arr3[i/2+1];//find heart of piramid  heart_two means the second num of corresponding piramid of the num is odd it will be printed.
		 	
		 		if ((i+1) % 2 == 0){//condition to check if the heart corresponding line's quantity is even or odd so that we can print according to that
		 							//if its odd then heart_one and heart_two both will be printed and else only heart_one will be printed at down lines. 
		 			check = 1;
		 		}
		 	}
		 	cout << endl;
		}
	}
    cout << "Biggest number: " << max_num<<endl;//print the biggeest or max numbers of febonachi piramid
    
    if(check == 1){//condition to print heart of piramid with two values
    	
    	cout << "Heart of the pyramid: "<< heart_one << " " << heart_two<< endl;
    }
    else{//block to print heart of piramid with one value.

    	cout << "Heart of the pyramid is : "<< heart_one<< endl;
    }

	return 0;
}//end of main funciton
/*in this program i simply used concep of 1D arrays to implement the program */