// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// number of menu items
// adjust this value (10) to number of items input below
#define NUM_ITEMS 10

// menu items have item name and price
typedef struct
{
    string item;
    float price;
} menu_item;

// array of menu items
menu_item menu[NUM_ITEMS];

// add items to menu
void add_items(void);

// calculate total cost
float get_cost(string item);

int main(void)
{
    // initialize the menu array
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    // print the menu with item names and prices
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i].price);
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        // prompt the user to enter a food item
        string item = get_string("Enter a food item: ");
        // if the user presses enter without entering an item, break out of the loop
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }

        // calculate the total cost by finding the cost of the entered item
        total += get_cost(item);
    }

    // print the total cost of the selected items
    printf("Your total cost is: $%.2f\n", total);
}

// add at least the first four items to the menu array
void add_items(void)
{
    // TODO: Add more items to the menu array
    menu[0].item = "Burger";
    menu[0].price = 9.50;

    menu[1].item = "Vegan Burger";
    menu[1].price = 11.00;

    menu[2].item = "Hot Dog";
    menu[2].price = 5.00;

    menu[3].item = "Cheese Dog";
    menu[3].price = 7.00;
}

// search through the menu array to find an item's cost
float get_cost(string item)
{
    // iterate through the menu array
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        // make the search case-insensitive by using strcasecmp
        if (strcasecmp(menu[i].item, item) == 0)
        {
            // return the price of the matching item
            return menu[i].price;
        }
    }

    // If the item is not found, return 0.0
    return 0.0;
}
