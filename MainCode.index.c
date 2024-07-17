#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FRIENDS 100
#define MAX_PHONE_LENGTH 13


	typedef struct {						// use of typedef struct to allow easy access to each array stored within BookStruct ( holds each asepct needed to be stored in the phonebook)
	    char firstName[20];
	    char lastName[20];
	    char phoneNumber[MAX_PHONE_LENGTH];
	} BookStruct;


// Global Variables; allows for pass by reference without the use of pointers

	BookStruct *StructPtr;
	int numFriends = 0;


// Beginning of the list of functions

	void addFriend() {
		
	    if (numFriends >= MAX_FRIENDS)  {
	    	
	    	system("cls");
	    	
	        printf("Phone book is full! Cannot add more friends.\n");
	        return;
	    } 
	    
		else  {
			
			system("cls");
			
	        printf("\nPlease enter the name of the contact you wish to add.");
	        printf("\nFirst name : ");
	        fgets(StructPtr[numFriends].firstName, 20, stdin);
	        StructPtr[numFriends].firstName[strcspn(StructPtr[numFriends].firstName, "\n")] = 0;
	        
	        printf("Last name : ");
	        fgets(StructPtr[numFriends].lastName, 20, stdin);
	        StructPtr[numFriends].lastName[strcspn(StructPtr[numFriends].lastName, "\n")] = 0;
	        
	        printf("\nPlease enter a phone number in form XXX-XXX-XXXX (Where X is a # 0-9)");
	        printf("\nPhone number : ");
		    fgets(StructPtr[numFriends].phoneNumber, MAX_PHONE_LENGTH, stdin);
	        StructPtr[numFriends].phoneNumber[strcspn(StructPtr[numFriends].phoneNumber, "\n")] = 0;        
		    
		        if (strlen(StructPtr[numFriends].phoneNumber)!= 12)  {
				    printf("\nInvalid phone number length! Please use XXX-XXX-XXXX.\n");
				    return;																	// two conditions check if the phone number is both exactly 12 characters along with the 4th and 8th element are both ' - '
		       	}																			// this effectively checks if the phone number enter
																								
				
		        if (StructPtr[numFriends].phoneNumber[3] != '-' || StructPtr[numFriends].phoneNumber[7] != '-')  {
		            printf("\nInvalid phone number format! Please use XXX-XXX-XXXX.\n");
		            return;
		        }
	        
	        system("cls");	
	        printf("\n%s %s has been added to the phone book!\n\n", StructPtr[numFriends].firstName, StructPtr[numFriends].lastName);   									
	        numFriends++;	
	    }
	}


	void deleteFriend() {
		
	    if (numFriends == 0) {
	    	
	    	system("cls");
	    	
	        printf("\nPhone book is empty! Cannot delete friends.\n");
	        return;
	    }
	
	    char firstDel[20];
	    char lastDel[20];
	    
		    system("cls");
		    
		    printf("\nPlease enter the first name you wish to delete.");
		    printf("\nFirst name : ");
		    scanf("%19s", firstDel);
		    getchar();
		    firstDel[strcspn(firstDel, "\n")] = 0;
			
		    printf("\nPlease enter the last name you wish to delete.");
		    printf("\nLast name : ");
		    scanf("%19s", lastDel);
		    getchar();
		    lastDel[strcspn(lastDel, "\n")] = 0;
		
		    for (int i = 0; i < numFriends; i++) {
		        if (strcmp(StructPtr[i].firstName, firstDel) == 0 && strcmp(StructPtr[i].lastName, lastDel) == 0) {
		         
		            for (int j = i; j < numFriends - 1; j++) {
		                StructPtr[j] = StructPtr[j + 1];		// will reassign every value of StructPtr (which points to the structure) to the value of the array's following values ( j -> j+1 ; [3] is set = to [4] )
		            }     
					      
		            numFriends--;   
					         
			            if (numFriends >= 0)  {	            	
			            	
			            }
			            
			            printf("\nContact successfully deleted from the phonebook\n");
			            return;
		        }
		    }
	
	    printf("\nFriend not found in phone book!\n\n");
	}


	void printPhonebook() {
	    if (numFriends == 0) {
	    	
	    	system("cls");
	    	
	        printf("\nPhone book is empty!\n");
	        return;
	    }
	
	    system("cls");
	    
	    printf("Phone Book: \n");						// For loop will iterate through all values of StructPtr up to 1 less of numFriends, which then prints each contact's info with a newline after
	    for (int i = 0; i < numFriends; i++) {
	        printf("Contact %d -- %s %s : %s", (i+1), StructPtr[i].firstName, StructPtr[i].lastName, StructPtr[i].phoneNumber);
	        printf("\n");
	    }
	
	    printf("\n\n");
	}
	
	
	int SortCompare(const void *a, const void *b)  {
		
		BookStruct *SortA = (BookStruct*) a;				// (BookStruct*) a is necessary to turn void-type pointer a into a pointer to structure BookStruct.
		BookStruct *SortB = (BookStruct*) b;
		
			int Comparison = strcmp(SortA -> firstName, SortB -> firstName);
			
				if (Comparison != 0)  {							
				
					return Comparison;		// will only continue to else branch if Comparison == 0 (i.e. SortA -> firstName == SortB -> firstName ; same first names, will use last names to sort)
				}
			
			else  {
				
				return strcmp(SortA -> lastName, SortB -> lastName);
			}		
	}
	
	
	void findPhoneNum()  {
		
		char firstFind[20];
		char lastFind[20];
		
		system("cls");
		
		if (numFriends == 0)  {
			
			printf("\nPhonebook empty! No phone number to find.\n");
		}
		
			printf("Please enter the first and last name of the contact's number you wish to find :\n");
			printf("First name : ");
			fgets(firstFind, 20, stdin);
			firstFind[strcspn(firstFind, "\n")] = 0;
			
			printf("Last Name : ");
			fgets(lastFind, 20, stdin);
			lastFind[strcspn(lastFind, "\n")] = 0;
			
				for (int i = 0; i < numFriends; i++)  {
					
					if (strcmp(StructPtr[i].firstName, firstFind) == 0 && strcmp(StructPtr[i].lastName, lastFind) == 0)					
						printf("\n%s %s's phone number is : %s\n", firstFind, lastFind, StructPtr[i].phoneNumber);
						return;
				}
				printf("\nContact not found! Please enter a first and last name already in the phonebook.\n");	
	}	
	

	void RandomCall()  {
		
		if (numFriends == 0) {
			
			system("cls");
			
        	printf("\nPhone book is empty! Cannot call a friend.\n");
        	return;
        }
		
		system("cls");
		
		srand(time(0));					// initializes the time-function ( typically a large integer) to generate random numbers
		
			int RandomInt = rand() % numFriends;			// will generate a random number between 0 to (1 - numFriends), and will 'call' the contact stored in that int. value array of StructPtr			
			
			printf("\nCalling %s %s at %s...\n\n", StructPtr[RandomInt].firstName, StructPtr[RandomInt].lastName, StructPtr[RandomInt].phoneNumber);
	}	
	

	void DeleteAll()  {
		
		system("cls");
		
		free(StructPtr);										// with free(StructPtr), all array values within StructPtr will become string-value NULL, which deletes each contact's info
		printf("\nAll contacts have been deleted!\n");
		
			numFriends = 0;
	}
	
	
	void StoreInFile() {
		
	    char fileName[50];
	    
	    system("cls");
	    
	    printf("\nPlease enter the file name you wish to save your contacts to : ");
	    printf("\nFile Name : ");
	    
			if (scanf("%49s", fileName) != 1) {
		        printf("\nError reading file name!\n");				// Ensures a null string is not inputed as 'filename'
		        return;
		    }
		    
			    getchar();
			    fileName[strcspn(fileName, "\n")] = 0;
			
			    FILE *fp = fopen(fileName, "w");					// Must have the file in read - mode in order to send data to ( 'read - to' ) the file
			    
					if (fp == NULL) {														// will exit out of the function via return if the read file (copy-contacts file) fails to open
				        printf("\nError opening read-from.txt file! Please try again with a valid file name.\n");		
				        return;
				    }
				
					    for (int i = 0; i < numFriends; i++) {
					        if (fprintf(fp, "%s %s %s\n", StructPtr[i].firstName, StructPtr[i].lastName, StructPtr[i].phoneNumber) < 0) {
					            printf("\nError writing to file!\n");
					            fclose(fp);
					            return;
					        }
		    			}
	    printf("\nAll contacts have been copied to %s.txt file.\n\n", fileName);
	    fclose(fp);
	}
	

	void RetrieveFromFile() {
		
	    char fileName[50];
	    
	    system("cls");
	    
		    printf("\nPlease enter a file name you wish to retrieve contacts from : ");
		    scanf("%49s", fileName);
		    getchar();
		    fileName[strcspn(fileName, "\n")] = 0;
	
	    	FILE *fp = fopen(fileName, "r");							// Must have the file in write - mode in order to recieve data  from ( 'write - from' ) the file
	    
			    if (fp == NULL) {
			        printf("\nError opening write-to txt file! Please try again with a valid file name.\n");
			        return;
			    }
			    
			        if (feof(fp)) {
				        printf("\nFile %s.txt is empty or doesn't exist!\n", fileName);				// check if file is either empty or does not exist, if so, it will enter the if-branch and close fp
				        fclose(fp);
				        return;
				    }
	
			    int fileContacts = numFriends;
			    
				    while (fileContacts < MAX_FRIENDS && fscanf(fp, "%s %s %s\n", StructPtr[fileContacts].firstName, StructPtr[fileContacts].lastName, StructPtr[fileContacts].phoneNumber) == 3) {
				        numFriends = ++fileContacts;
				    }
		    printf("\n contacts have been retrieved from %s.txt file.\n", fileName);
		    fclose(fp);
	}
	

// End of functions / start of int main() i.e. main body / start of the code

	int main() {
		
	    StructPtr = (BookStruct*) malloc(MAX_FRIENDS * sizeof(BookStruct));
	    
	    if (StructPtr == NULL)  {
	    	
	        printf("Error: malloc failed to allocate memory for StructPtr\n");
	        return 1; 
	    }
		
	    	int selection;
	    	
		    while (1) {
		    	
		    	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
				printf("\n\tWelcome To The Phonebook Program!");
				printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");  	
		        printf("Phone Book Application\n");
		        printf(" Enter 1 to : Add friend\n");
		        printf(" Enter 2 to : Delete friend\n");
		        printf(" Enter 3 to : Show phone book\n");
		        printf(" Enter 4 to : Sort list of contacts (by first name) alphabetically\n");
		        printf(" Enter 5 to : Find the phone number of a given contact name\n");
		        printf(" Enter 6 to : Randomly select a contact to call\n");
		        printf(" Enter 7 to : Delete ALL contacts all at once\n");
		        printf(" Enter 8 to : Store all current contacts into a text file on your computer\n");
		        printf(" Enter 9 to : Retrieve info / contacts sent to the text file\n");
		        printf("Enter 10 to : Quit program\n ");
		        printf(" Selection : ");
		        
		        scanf("%d", &selection); 
				getchar();			// When using scanf it is necessary to include getchar() after in order to consume the newline at the end of value 'selection'. If not, next scanf may take the newline as it's input
		
			        switch (selection) {
			            case 1:
			                addFriend();
			                break;
			                
			            case 2:
			                deleteFriend();
			                break;
			                
			            case 3:
			                printPhonebook();
			                break;
			                
			            case 4 : {
			            	
			            	qsort(StructPtr, numFriends, sizeof(BookStruct), SortCompare);					// sorts each name in alphabetical order (by first name)
							system("cls");			  
			            	printf("\nContacts sorted sucessfully. Re-print contacts to see!\n");											            	
							break;
						}
						
						case 5 :
							findPhoneNum();
							break;
							
						case 6 : 
							RandomCall();
							break;
							
						case 7 :
							DeleteAll();
							break;
							
						case 8 :
							StoreInFile();
							break;
							
						case 9 :
							RetrieveFromFile();
							break;		
						
			            case 10 :  {
			            	
			            	printf("\nClosing out of phonebook, goodbye!");
			            	free(StructPtr);
			            	
			    			return 0;												// closes out of the program							
						}
			            
			            default:
			            	system("cls");
			                printf("Invalid choice!\n");
			        }
			    }			
	}
	




