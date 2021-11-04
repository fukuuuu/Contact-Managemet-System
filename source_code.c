#include<stdio.h>
#include<conio.h> //console input
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>

struct contact
{
    long ph;
    char name[50], add[100], email[100];
} list;

char query[20],name[20];
FILE *fp, *ft;
int i, n, ch, l, found;

int main()
{
    system("cls"); //clear screen
    printf("\n\t **** Welcome to Contact Management System ****");
    
    main:  // main menu
    printf("\n_________________________________________________________________");
    printf("\n\n\t\t\tMAIN MENU\n\t\t==========================");
    printf("\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t");
    printf("[5] Delete a Contact\n\t\t[0] Exit");
    printf("\n\t\t==========================\n\t\t");
    printf("\n_________________________________________________________________");
    printf("\n\nEnter the choice:");

    scanf("%d", &ch);

    switch(ch)
    {
        case 0:
            printf("\n\n\t\tAre you sure you want to exit?\n");
            break;
            
        case 1:  // add a new contact
            system("cls");
            fp=fopen("contact.dll", "a"); //append file contact.dll
            for (;;)  // infinite loop
            {
                fflush(stdin);  // flush the the previous input
                printf("To exit enter blank space in the name input\nName (Use identical):");
                scanf("%[^\n]", &list.name);

                if(stricmp(list.name, "")==0 || stricmp(list.name, " ")==0)  // string compare if string == "" or " ", break
                    break;

                fflush(stdin);  
                printf("Phone:");
                scanf("%ld", &list.ph);

                fflush(stdin);
                printf("address:");
                scanf("%[^\n]", list.add);

                fflush(stdin);
                printf("email address:");
                gets(list.email);

                printf("\n");
                fwrite(&list, sizeof(list), 1, fp);

            }
            fclose(fp);
            break;

        case 2:  // list all contacts alphabetically
            system("cls");
            printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\n");
            printf("Name\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");
            for(i=97; i<=122; i=i+1)  // loop to print alphabetically
            {
                fp=fopen("contact.dll", "r");
                fflush(stdin);
                found=0;

                while(fread(&list, sizeof(list), 1, fp)==1) // read till end of file, (if sizeof the file == 1 byte do, if not break)
                {                  
                    if(list.name[0]==i || list.name[0]==i-32) // print alphabetically
                    {
                        printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);
                        found++;
                    }
                }

                if(found!=0)
                {                                                          
                    printf("=========================================================== [%c]-(%d)\n\n", i-32, found);
                }
                fclose(fp);
            }
            break;
    }

    main2:
    printf("\n\n\t\t  ..::Enter the Choice::..\n\n\t\t[1] Main Menu\t    [0] Exit\n");
    scanf("%d", &ch);

    switch (ch)
    {
        case 0:
            printf("Exit the program\n");
            break;

            default:
                printf("Invalid choice, Please choose only [0] or [1]\n");
                goto main2;
        case 1:
            system("cls");
            goto main;      
    }
    return 0;
}
