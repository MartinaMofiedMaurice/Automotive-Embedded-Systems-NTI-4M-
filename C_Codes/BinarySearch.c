#include<stdio.h>


u8 Global_index_Number=0;
u8 BinarySearch(u8 arr[50],u8 size,u8 User_number){
	u8 temp=0;
	for(u8 i=0;i<size;i++){
		for(u8 j=0;j<size-1;j++){
			
			if(arr[j+1]<arr[j]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("Array After being Sorted \n");
	for(u8 i=0;i<size;i++){
	printf("%d\t",arr[i]);
	if(i==size-1){
	 printf("%d\n",arr[i]);
	}
	}
	u8 Left= 0,Right=size-1;
	u8 Middle=0;
	while(Left<=Right){
		Middle=Left+(Right-Left)/2;
		if(arr[Middle]==User_number){
			Global_index_Number=Middle+1;
			return arr[Middle];
			break;
		}
		else{
			
		}
		if(arr[Middle]<Left){
			Left=Middle+1;
		}
		else{
			Right=Middle-1;
		}
	}
}

void main(void){
	u8 local_arr[50],arr_size=0,User_number=0,Binary_output=0;
	printf("Binary Search!\nEnter size of Array:\n");
	scanf("%d",&arr_size);
	for(u8 i=0;i<arr_size;i++){
		printf("Enter element No. %d in the Array:",i+1);
		scanf("%d",&local_arr[i]);
	}
	printf("Enter the No you want to search for:");
	scanf("%d",&User_number);
	Binary_output=BinarySearch(local_arr,arr_size,User_number);
	printf("The number you searched for is %d and it's index %d\n",Binary_output,Global_index_Number);
	printf("Thank you!\nBye!");
	
}