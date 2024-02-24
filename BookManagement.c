//Book Management system project
#include<stdio.h>
#include<string.h>
typedef struct Book
{
    int id;
	char name[20];
	char author[20];
	double price;
	double rating;
	char language[20];
	char category[20];
}Book;
void storedata(Book*,int);
void display(Book*);
void searchBook(Book*,int); 
void removeBook(Book*,int);
void updateBookData(Book*,int); 
void displayTop3Books(Book*);

int ctr=0;
void main()
{
	Book* b;
	int size,id_num,i,ch,d,in;
	char bname,bauthor;
	printf("\n----------------Book Management System---------------------");
	printf("\n\nEnter the size of arrays:");
	scanf("%d",&size);
	b=(Book*)malloc(sizeof(Book)*size);
	do{
		
		printf("\n1.Store book data");
		printf("\n2.Display all books");
		printf("\n3.Search Book ");
		printf("\n4.Remove Book");
		printf("\n5.Update Book");
		printf("\n6.Display top 3 books");
		printf("\n7.exist");
		printf("\n8.Enter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			
			case 1:
			{
			   storedata(b,size);
				break;
		    }
			case 2:
			 {
			    display(b);
			 	break;
			 }
			case 3:
			{
				if (ctr > 0)
				 {
                    searchBook(b,id_num);
                } 
				else 
				{
                    printf("No books to search.\n");
                }
				
				  break;
			}
			
		    case 4:
			{
				
			  	if (ctr > 0) 
				{
                    int bookID;
                    printf("Enter the Book ID to remove: ");
                    scanf("%d", &bookID);
                    removeBook(b,bookID);
                } 
				else 
				{
                    printf("No books to remove.\n");
                }
                   break;
            }
            case 5:
           	{
           		
           		 updateBookData(b,size);
           		  break;
           		 
			}
			case 6:
			{
				
				 displayTop3Books(b);
					
			}
			case 7:
			{
				printf("Exist");
				break;
			}
			default:
			{
				printf("Invalid Choice");
				break;
			}
			  
           
	   }    
	}while(8!=ch);
}


void storedata(Book*b,int size)
{
	 int i;
//	 for(i=0;i<=ctr;i++)
  //  {
	 
	   if(ctr!=size)
	   {
	      printf("\nEnter a id of book=");
	      fflush(stdin);
	      scanf("%d",&b[ctr].id);
	      printf("Enter a name of book=");
	      scanf("%s",b[ctr].name);
	      printf("Enter a author of book=");
	      scanf	("%s",&b[ctr].author);
	      printf("Enter a price of book=");
	      scanf("%lf",&b[ctr].price);
	      printf("Enter a rating of book=");
	      scanf("%lf",&b[ctr].rating);
	      printf("Enter a language of book=");
	      scanf("%s",&b[ctr].language);
	      printf("Enter a category of book=");
	      scanf("%s",&b[ctr].category);
	      ctr++;
	      return;
	   }
//	}   
	     
	       printf("\nlist if full");		
		 
   
	      	
}
void display(Book*b)
{
	int i;
	printf("\n---------------Book Details---------------- ");
	for(i=0;i<ctr;i++)
   {
	  printf("\n\nBook id is %d",b[i].id);
	  printf("\nBook name %s",b[i].name);
	  printf("\nBook Author is %s",b[i].author);
	  printf("\nBook price is %.2lf",b[i].price);
	  printf("\nBook Rating is %.2lf",b[i].rating);
	  printf("\nBook language is %s",b[i].language);
	  printf("\nBook Category is %s",b[i].category);
	  printf("\n\n");
	  
   }
}

void searchBook(Book*b,int id_num) 
{
    int choice;
    printf("Search by:\n");
    printf("1. Book ID\n");
    printf("2. Book Name\n");
    printf("3. Book author\n ");
    printf("Enter your choice:");
    scanf("%d", &choice);

    int id,i;
    char bname[100];
    char bauthor[100];
    switch (choice) 
	{
        case 1:
			
            printf("Enter Book ID: ");
            scanf("%d", &id_num);
            for (i=0; i<ctr; i++) 
			{
              if (b[i].id == id_num) 
			  {
                printf("Book found:\n");
                printf("Book ID: %d\n", b[i].id);
                printf("Book Name: %s\n", b[i].name);
                printf("Author Name: %s\n", b[i].author);
                printf("Price: %.2f\n", b[i].price);
                printf("Rating: %.2f\n", b[i].rating);
                printf("Book Category is %s\n",b[i].category);
                return;
                }
            }
            
            printf("Book with ID %d not found.\n", id_num);
            break;
        
        case 2:
        
		
            printf("Enter Book Name: ");
            fflush(stdin); 
            scanf("%s",&bname);
		
            for (i=0;i<ctr;i++) 
			{
                if (strcmp(b[i].name,bname)==0)
                {
                   printf("\nBook id is %d",b[i].id);
	               printf("\nBook name %s",b[i].name);
	               printf("\nBook Author is %s",b[i].author);
	               printf("\nBook price is %lf",b[i].price);
	               printf("\nBook Rating is %lf",b[i].rating);
	               printf("\nBook language is %s",b[i].language);
	               printf("\n\nBook Category is %s",b[i].category);
	               return;
				}
	     	}
                    
					printf("Book name is not found",bname);    
                    break;
        
        case 3:
        
		
            for (i=0;i<ctr;i++) 
			{
				    
                    printf("\nEnter Book Author: "); 
					fflush(stdin); 
					scanf("%s",bauthor); 
                if (strcmp(b[i].author,bauthor)==0)
                {
                   printf("\nBook id is %d",b[i].id);
	               printf("\nBook name %s",b[i].name);
	               printf("\nBook Author is %s",b[i].author);
	               printf("\nBook price is %lf",b[i].price);
	               printf("\nBook Rating is %lf",b[i].rating);
	               printf("\nBook language is %s",b[i].language);
	               printf("\nBook Category is %s",b[i].category);
	               printf("\n\n");
	               return;
				}
            }   
			printf("\nBook with author is not present\n");
                    break;
        }
    

}


void removeBook(Book*b, int id_num) 
{   
     int i;
    int index;
    for (i=0;i<ctr;i++) 
	{
        if (b[i].id == id_num) 
		{
            index=i;
            break;
        }
    }

    if (index!=-1) 
	{
        for (i=index; i<ctr-1; i++)
		{
            b[i]=b[i+1];
        }
         ctr--;
        printf("Book removed successfully!\n");
    } 
	else
	{
        printf("Book with ID %d not found.\n", id_num);
    }
}

// Function to update book data (Price and Rating)
void updateBookData(Book*b, int size) 
{
	int id, i;
    printf("\nEnter Book ID to update the price: ");
    scanf("%d", &id);

    // Find the index of the book with the given ID
    int index = -1;
    for (i = 0; i < size; i++) {
        if (b[i].id == id) {
            index = i;
            break;
        }
    }

    // Check if the book with the given ID is found
    if (index != -1) {
        printf("\nEnter updated price: ");
        scanf("%lf", &b[index].price);
        printf("\nBook Data updated successfully.\n");

        // Display updated price
        printf("Updated Price for Book ID %d: %.2lf\n", b[index].id, b[index].price);
    } else {
        printf("\nBook with ID %d not found.\n", id);
    }
}

    

void displayTop3Books(Book*b)
 {
 	int i,j;
    // Sort the books based on price in descending order
    for (i=0;i<ctr-1;i++)
	 {
        for (j=0;j<ctr-i-1;j++)
		 {
            if (b[j].price < b[j+1].price) 
			{
                // Swap books[j] and books[j+1]
                Book temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

    // Display the top 3 books based on price
    printf("Top 3 books based on price:\n");
    for (i=0;i<ctr && i<3;i++)
	 {
        printf("Book ID: %d, Book Name: %s, Price: %.2f\n", b[i].id, b[i].name, b[i].price);
    }

    // Sort the books based on rating in descending order
    for (i=0;i<ctr-1;i++)
	 {
        for (j=0;j<ctr-i-1;j++)
		 {
            if (b[j].rating < b[j+1].rating) 
			{
                // Swap books[j] and books[j+1]
                Book temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;
            }
        }
    }

    // Display the top 3 books based on rating
    printf("Top 3 books based on rating:\n");
    for (i=0; i<ctr && i<3; i++) 
	{
        printf("Book ID: %d, Book Name: %s, Rating: %.2f\n", b[i].id, b[i].name, b[i].rating);
    }
}






