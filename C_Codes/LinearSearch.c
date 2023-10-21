#include<stdio.h>
#include "STD_types.h"

u8 Global_index_Number=0;
u8 LinearSearch(u8 arr[50],u8 size,u8 User_number){
	for(u8 i=0;i<size;i++){
		if( arr[i]== User_number){
			Global_index_Number=i+1;
			return arr[i];
			
		}
		else{
		}
	}
}

void main(void){
	u8 local_arr[50],arr_size=0,User_number=0,Linear_output=0;
	printf("Linear Search!\nEnter size of Array:\n");
	scanf("%d",&arr_size);
	for(u8 i=0;i<arr_size;i++){
		printf("Enter element No. %d in the Array:",i+1);
		scanf("%d",&local_arr[i]);
	}
	printf("Enter the No you want to search for:");
	scanf("%d",&User_number);
	Linear_output=LinearSearch(local_arr,arr_size,User_number);
	printf("The number you searched for is %d and it's index %d\n",Linear_output,Global_index_Number);
	printf("Thank you!\nBye!");
	
}