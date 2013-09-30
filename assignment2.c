/*Sanita Tifentale
    c11432632
    Assignment2 - Lotto game*/
    
#include<stdio.h>
#include<stdlib.h>

#define SIZE 6

/*prototype declaration for all 6 functions*/
void storing(int *, int *, int *);
void display(int *, int *);
void sorting(int *, int *);
void matching(int *, int *);
void frequency(int *);
void end(void);

main()
{
    /*declared array for users numbers and declared bonus number*/
    int my_numbers[SIZE]; 
    int bonus;
    
    /*this array is necesarry for fifth function when freaquency of the numbers are stored*/
    int count[43] = {0};
    
    /*declared variable for while loop so that user can keep entering the lottery numbers with out leaving the game*/
    int contin = 1;
    
    /*declared variable for user to select different functions*/
    int next;
    
    printf("~~~*WELCOME to LOTTO game*~~~\n");

    while(contin == 1)
    {
        /*call the functions*/
        storing(my_numbers, &bonus, count);
        
        /*this clears screan*/
        system ("cls");
        
        /*this allows user to pick different functions*/
        printf("\nWould you like to pick any functions? If yes press 1...\n");
        scanf("%d", &next);
        
        /*this clears screan*/
        system ("cls");
        
        while(next == 1)
        {
            printf("\nWould you like to see your numbers? If yes press 2...\n"
            "\nWould you like to sort your numbers in increasing order? If yes press 3...\n"
            "\nWould you like to see what have you won? If yes press 4...\n"
            "\nWould you like to see the frequency of the numbers you have entered? If yes press 5...\n");
            scanf("%d", &next);
            
            /*this clears screan*/
            system ("cls");
            
            /*this if statement allows user choose second function responcible for displaying the users numbers*/
            if(next == 2)
            {
                display(my_numbers, &bonus);
            }
            
            /*this if statement allows user to choose third function responcible for sorting the numbers in increasing order */
            if(next == 3)
            {
                sorting(my_numbers, &bonus);
            }
            
            /*this if statement allows user to choose fourth function responcible for comparing numbers to winning numbers*/
            if(next == 4)
            {
                matching(my_numbers, &bonus);
            }
            
            /*this if stament allows user to choose fifth function responcible for frequency of users numbers*/
            if(next == 5)
            {
                frequency(count);
            }
            
            printf("\nWould you like to pick any other function? If yes press 1...\n");
            scanf("%d", &next);
            
            /*this clears screan*/
            system ("cls");
            
        }//end of second while loop
        
        printf("\nWould you like to enter your other choice? If yes press 1...\n");
        scanf("%d", &contin);
        
        /*this clears screan*/
        system ("cls");
        
        /*this if statement calls the function that ends the game*/
        if(contin != 1)
        {
            end();
        }
    }
    
    fflush(stdin);
    getchar();
}

/*first function that allows user to enter their 6 numbers and bonus number and all validation is happening here 
and also counts freaquency for fifth function*/
void storing(int *num, int *pbonus, int *count)
{
    /*variable declaration and they used in for loops*/
    int i, j;
    
    printf("\nNow enter your 6 numbers from 1 till 42\n");
    
    /*this for loop allows user to enter 6 numbers*/
    for(i = 0; i < SIZE; i++)
    {
        scanf("%d",& *(num + i));
        
        /*this if statements checks if user enters less than 1 or bigger than 42 than ERROR accures and user need 
                to enter new correct number that is less than 42*/
        if(*(num + i) < 1 || *(num + i) > 42)
        {
            printf("Error! Enter again\n");
            scanf("%d",& *(num + i));
        }
                
        /*this for loop checks if user entered already entered number if yes ERROR accures and user need to enter 
                another number*/
        for(j = 0; j < SIZE; j++)
        {
            if(*(num + i) == *(num + j) && i != j)
            {
                printf("ERROR numbers match!! Enter again\n");
                scanf("%d",& *(num + i));
            } 
        }
        
        /*counts user entered numbers for fifth function*/
        ++count[num[i]];
    }
    
    /*this is for bonus number*/
    printf("\nAnd enter your bonus number\n");
    scanf("%d",pbonus);
    
    /*checking bonus number if its not bigger than 42 or smaller than 1. If it is then user enters again*/
    if(*pbonus < 1 || *pbonus > 42)
    {
        printf("ERROR! Enter again bonus number\n");
        scanf("%d", pbonus);
    }
    
    /*this checks bonus number if its not matching the 6 numbers already entered. If it is user needs to 
        enter again*/
    for(i = 0; i < SIZE; i++)
    {
        if(*pbonus == *(num + i))
        {
            printf("ERROR! Enter again bonus number\n");
            scanf("%d", pbonus);
        }
    }
    
    fflush(stdin);
}

/*second function that displays the users numbers*/
void display(int *num, int *pbonus)
{
    /*variable declaration and it is used in for loop*/
    int i;
    
    printf("\nYour numbers are: ");
    
    /*this for loop is for displaying the user numbers*/
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ", *(num + i));
    }
    
    /*this prints out the user bonus number*/
    printf("  %d\n", *pbonus);
}

/*third function that sorts users numbers in increasing order by using Bubble sort*/
void sorting(int *num, int *pbonus)
{
    /*variable declaration necesarry for the for loop*/
    int i, j;
    
    /*this declared variable contains the temporarry value when swapping is happening*/
    int temp;
 
    /*this is implementing Bubble sort*/
    for (i = (SIZE - 1); i > 0; i--)
    {
        for (j = 1; j <= i; j++)
        {
            if ((*(num + (j-1))) > (*(num + j)))
            {
                temp = *(num + (j-1));
                *(num + (j-1)) = *(num + j);
                *(num + j) = temp;
            }
        }
    }
  
    /*this displays users sorted numbers */
    printf("\nYour sorted numbers are: ");
    
    for(i =0; i < SIZE; i++)
    {
        printf("%d ", *(num + i));
    }
    
    printf("  %d\n", *pbonus);
}

/*fourth function that matches the winning numbers*/
void matching(int *num, int *pbonus)
{
    /*declared array with winning 6 numbers*/
    int winning_num[SIZE]={1,3,5,7,9,11};
    
    /*declared variable with the winning bonus number*/
    int winning_bonus = 42;
    
    /*declared variables for the for loop*/
    int i, j;
    
    /*this declared variable is used temporarry hold the users number and compare if it matches 
        winning number*/
    int temp;
    
    /*this declared variable is set to 0 because its like counter variable*/
    int match = 0;
    
    /*this for loop checks for matching numbers*/
    for(i = 0; i < SIZE; i++)
    {
        temp = *(num + i);
        
        for(j = 0; j < SIZE; j++)
        {
           if(temp == *(winning_num + j))
           {
                /*this is incremented when the numbers match*/
                match++;
           }               
        }
    }
    
    /*if variable match is 6 then user won a Jackpot*/
    if(match == 6)
    {
        printf("~~~JACKPOT~~~\n");
    }
    
    /*if variable match is 5 and bonus number match then they almost won*/
    if((match == 5) && (winning_bonus == *pbonus))
    {
        printf("~~~Almost - just 1 away~~~\n");
    }
    
    /*if variable match is 5 then they won a holidays*/
    if((match == 5) && (winning_bonus != *pbonus))
    {
        printf("~~~Holidays~~~\n");
    }
    
    /*if variable match is 4 and bonus number match then they won night out*/
    if((match == 4) && (winning_bonus == *pbonus))
    {
        printf("~~~Night out~~~\n");
    }
    
    /*if varible match is 4 then they won a petrol*/
    if((match == 4) && (winning_bonus != *pbonus))
    {
        printf("~~~Full petrol tank~~~\n");
    }
    
    /*if variable match is 3 and bonus numbers match then they won a scratch card*/
    if((match == 3) && (winning_bonus == *pbonus))
    {
        printf("~~~Free Lotto scratch card~~~\n");
    }
    
    /*if the match is 3 or less then they didnt won*/
    if((match <= 3 ) && (winning_bonus != *pbonus))
    {
        printf("~~~Sorry you loose~~~\n");
    }
}

/*fifth function that counts user number frequency*/
void frequency(int *count)
{
    int i;
    
    /*this for loop displays the frequency of the numbers that user has entered*/
    for(i = 1; i < 43; i++)
    {
        if(*(count + i) != 0)
        {
            printf("Number %d is %d times\n", i, *(count + i));
        }
    }
}

/*sixth function that ends the game*/
void end()
{
    exit(1);
}