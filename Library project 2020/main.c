#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global variables
typedef struct Books //Struct
{
    char name[200];
    int id;
    int quantity;
} Book;
Book ar[100]; //Array of struct
int line =4;
char loop[4];
char yes[4]="yes";

int main()
{
    do
    {
        int i,pos;


        FILE *fp=fopen("BOOKS.txt","r");//OPENING FILE ON READING MODE..
        if (fp!=NULL)
        {


            for (int i=0; i<line; i++)
            {
                fscanf(fp,"%s %d %d",ar[i].name,&ar[i].id,&ar[i].quantity); //READING BOOKS IN FILE..

            }
         }
            printf("my library contains %d books here you are.....\n",line);
            for (int i=0; i<line; i++)
            {
                printf(" %s\t %d\t %d\n\n",ar[i].name,ar[i].id,ar[i].quantity);//PRINT THE BOOKS AT THE OUTPUT SCREEN..
            }
            printf("*************************************\n");


        fclose(fp);//CLOSING FILE

//menu
        int n,ID; //N=NUM OF OPERATION.....
        printf("please select the number of operation........ \n");
        printf("select (1) :for add a book. \n");
        printf("select (2) :for delete a book by id. \n");
        printf("select (3) :for search a book by id. \n");
        printf("select (4) :for search books by name.\n");
        printf("select (5) :for sort books by name.\n");
        printf("select (6) :for print the books without sorting \n");
        scanf(" %d",&n);
//Add new book
        if(n==1)
        {
            FILE *fp=fopen("BOOKS.txt","w");//OPENING FILE ON WRITING MODE..
            if (fp!=NULL)
            {
                //GETTING THE BOOK INFO...
                printf("enter the info of book\n");
                printf(" enter the book name if contain two names write like this anwar_mhmd: ");
                scanf(" %s",ar[line].name);
                printf("\n enter the book id: ");
                scanf(" %d",&ar[line].id);
                printf("\n enter the book quantity: ");
                scanf(" %d",&ar[line].quantity);
                line++;
                for (int i=0; i<line; i++)
                {
                    fprintf(fp," %s %d %d\n",ar[i].name,ar[i].id,ar[i].quantity);//PRINT THE BOOKS ON THE FILE..
                }
                printf("\n *Books after adding the new book......\n");//PRINT THE NEW BOOKS ON THE OUTPUT SCREEN...
                for (int i=0; i<line; i++)
                {
                    printf(" %s\t %d\t %d\n",ar[i].name,ar[i].id,ar[i].quantity);
                }
            }
            fclose(fp);//CLOSING FILE

        }
//delete a book
        else if(n==2)
        {
            FILE *fp=fopen("BOOKS.txt","w");
            if (fp!=NULL)
            {
                printf("\n enter the book id \n"); //take an id and determine it's index
                scanf(" %d",&ID);
                int pos;
                for(i=0; i<line; i++)
                {
                    if(ar[i].id==ID)
                    {
                        pos=i;
                        break ;
                    }
                }
                while(pos<line)
                {
                    ar[pos]=ar[pos+1];//CORSPONDING THE ARRAY OF STRUCT.....
                    pos++;
                }
                line--;
                for (int i=0; i<line; i++)
                {
                    fprintf(fp," %s %d %d\n",ar[i].name,ar[i].id,ar[i].quantity);//PRINT THE BOOKS ON THE FILE..
                }
            }
            fclose(fp);//CLOSING FILE
        }
//search book by id...
        else if(n==3)
        {
            int key,res;
            printf("\n enter the book id \n");//GETTING THE BOOK ID...
            scanf(" %d",&key);
            for(int i=0; i<line; i++)//take an id and determine it's index
            {
                if(ar[i].id==key)
                {
                    res=i;
                    printf("%s\t %d\t %d",ar[res].name,ar[res].id,ar[res].quantity);
                    break;
                }
                if (i== line-1)//TO PRINT NOT FOUND....
                {
                    printf("\n not found");
                }
            }
        }
//search book by name
        else if(n==4)
        {
            char temb[200];
            char arr[9][200];
            for (int i=0; i<line; i++)
            {
                strcpy(arr[i],ar[i].name); //to copy the names of books in new array
            }
            for (int i = 0 ; i < line ; i++) //to compare names of the books and sorting it
            {
                for(int j = 0 ; j < line-1-i ; j++)
                {
                    if (strcmp(arr[j], arr[j+1]) == 1) //TO SWAP ELEMENTS IN THE NEW ARRAY....
                    {
                        strcpy(temb, arr[j]);
                        strcpy(arr[j], arr[j+1]);
                        strcpy(arr[j+1], temb);

                    }
                }
            }
            int j,i;
            for( i=0; i<line; i++)
            {
                for ( j=0; j<line; j++)
                {
                    if(strcmp(arr[i],ar[j].name)==0)
                        break;
                }
            }
//search by recursive
            int middle;
            int Search( const char arr[][200], char name[100], int low, int high )
            {
                middle=(low+high)/2;

                if (low >high)
                    return -1;
                if (strcmp(name,arr[middle])==0)
                    return middle;
                else if (strcmp(name,arr[middle])==1)
                {

                    Search ( arr, name, middle+1,  high);
                }

                else
                {

                    Search ( arr, name, low, middle-1 );
                }
            }
            int result;
            printf("enter the name of the book if contain two names write like this anwar_mhmd \n");
            char NAME[100];
            scanf("%s",NAME);
            result=Search ( arr, NAME, 0, line-1);
            for (int i = 0 ; i < line ; i++)
            {
                if (strcmp(arr[result],ar[i].name)==0)
                {
                    result=i;
                    break;
                }
            }
                if (result==-1)//TO PRINT NOT FOUND....
                {
                    printf("\n not found");
                    break;
                }

            printf(" %s\t %d\t %d\n",ar[result].name,ar[result].id,ar[result].quantity);

        }
//sort book by name
        else if(n==5)
        {
            printf("***************\n");
            char temb[200];
            char arr[9][200];
            for (int i=0; i<line; i++)
            {
                strcpy(arr[i],ar[i].name);
            }
            for (int i = 0 ; i < line ; i++)
            {
                for(int j = 0 ; j < line-1-i ; j++)
                {
                    if (strcmp(arr[j], arr[j+1]) == 1)
                    {
                        strcpy(temb, arr[j]);
                        strcpy(arr[j], arr[j+1]);
                        strcpy(arr[j+1], temb);
                    }
                }
            }
            int j,i;
            for( i=0; i<line; i++)
            {
                for ( j=0; j<line; j++)
                {
                    if(strcmp(arr[i],ar[j].name)==line-1)
                        break;
                }
                printf(" %s\t %d\t %d\n",ar[j].name,ar[j].id,ar[j].quantity);
            }
        }
//print book without sorting
        else if(n==6)
        {
            printf("************\n");
            for (int i=0; i<line; i++)
            {
                printf("\n %s\t %d\t %d\n",ar[i].name,ar[i].id,ar[i].quantity);
            }
        }
        printf("\n if you want another operation enter \"yes\"and press \"no\"to exit...\n ");

        for(int i=0;i<1;i++)
        {
            scanf("%s",&loop[i]);
        }
    }
    while(strcmp(loop,yes)==0);

    return 0;

}


