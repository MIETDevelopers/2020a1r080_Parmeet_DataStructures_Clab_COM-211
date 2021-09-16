// Find the cheapest walnuts in Raghunath Bazaar of Jammu
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct shop
{
	char shopName[50];
	int rate;
	struct shop *next;
} *head = NULL;

void shopRegister() //function to register a shop
{
	struct shop *ptr;
	struct shop *temp;
	ptr = (struct shop *)malloc(sizeof(struct shop));

	printf("\nEnter the name of the shop:\n");
	scanf("%s", ptr->shopName);
	printf("Enter the price of Walnuts per kg:\n");
	scanf("%d", &ptr->rate);
	ptr->next = NULL;
	if (head == NULL) //if the list is empty
	{
		head = ptr; //changing head to point to recently created node
	}
	else
	{
		temp = head;			   //assigning the value of head to a temporary variable temp
		while (temp->next != NULL) //traversing the list to the last element of the list
		{
			temp = temp->next;
		}
		temp->next = ptr; //assigning the next of temp the address of ptr which is the new node
	}
}

void minPrice() //function to find the minimum rate of walnuts amongst all the shops
{
	int min;
	char *nameOfShop;
	struct shop *ptr, *temp;
	temp = head;

	if (head == NULL) //if the list is empty
	{
		printf("No shops registered till now\n");
	}
	else
	{
		nameOfShop = temp->shopName;
		min = temp->rate;
		while (temp != NULL)
		{
			if (min > temp->rate)
			{
				nameOfShop = temp->shopName;
				min = temp->rate;
			}
			temp = temp->next;
		}
		printf("\nShop selling the cheapest walnuts is: %s\n", nameOfShop);
		printf("Lowest price of walnuts: %d/kg\n", min);
	}
}

void viewShops() //function to view all the registered shops
{
	struct shop *temp;
	if (head == NULL) //if the list is empty
	{
		printf("\nNo shops registered till now\n");
	}
	else
	{
		temp = head;
		while (temp != NULL) //traversing the list
		{
			printf("\nShop name: %s\n", temp->shopName);	 //printing the name of the shop
			printf("Price of walnuts: %d/kg\n", temp->rate); //printing the price of walnuts
			temp = temp->next;
		}
	}
}

int main()
{
	int option;
	printf("\n\t\t\t\t\tWelcome to Raghunath Bazaar, Jammu\n");
	do
	{
		printf("\nChoose the desired option:\n");
		printf("1.Register a shop\n");
		printf("2.Find the minimum price of Walnuts\n");
		printf("3.View all shops\n");
		printf("4.Exit\n");
		scanf("%d", &option);

		switch (option)
		{
			case 1:
				shopRegister();
				break;

			case 2:
				minPrice();
				break;

			case 3:
				viewShops();
				break;

			case 4:
				exit(0);
				break;

			default:
				printf("Please enter the correct option\n");
		}
	} while (option != 4);
} 