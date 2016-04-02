/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if(arr==NULL)
        return NULL;
	int i,c=0,diff=arr[c+1]-arr[c];
    int res[6];
	int x=0,start;
	for(i=0;i<len;i++)
    {       diff=arr[c+1]-arr[c];
            start=c;
            if(diff==(arr[c+1]-arr[c]) && diff==(arr[c+2]-arr[c+1])){
            while(diff==(arr[c+1]-arr[c]))
            {
                c++;
            }
            res[x]=start;
            res[x+1]=c;

            i=c-2;
           // printf("c=%d\n",c);
            x=2;
            }
            else
            {   printf("%d\n",c);
                start=c;
                diff=arr[c+1]/arr[c];c++;
                //printf("%d,%d,%d\n",arr[c],arr[c+1],diff);
                if(diff==(arr[c+1]/arr[c])){
                    while(diff==(arr[c+1]/arr[c])){
                        c++;
                    }
                    res[4]=start;
                    res[5]=c;
                    i+=2;
                }
            }


    }
    //for(i=0;i<6;i++)
   // {
    //    printf("%d,",res[i]);
    //}
	return res;

}

/*int main()
{
    int arr[]={ 1, 2, 3, 5, 10, 15, 30, 60};
    int len=8,i,*res;
    res=find_sequences(arr,len);
    for(i=0;i<6;i++)
    printf("%d,",res[i]);
    return 0;
}
*/
