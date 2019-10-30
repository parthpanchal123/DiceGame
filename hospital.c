#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

void clearInput(void);
void addPatient(void);
void listAll(void);
void deletepatient(void);
void modifycontact(void);
int findcontact(void);
int prompt(void);
int findnum (int);

typedef struct contact {
    int number;
    char name[20];
    char phone[15];
  char email[20];
  char hprob[20];
  char hdoc[20];
    struct contact *next;
    int count;
    } Contact;
Contact *firstc,*currentc,*newc;
int cnum = 0;
int main()
{
    FILE *datafile;
    char *filename = "hospitaldatabase.dat";
    char ch;
    firstc = NULL;
    datafile = fopen(filename,"r");

    if(datafile)
    {
	    firstc = (struct contact *)malloc(sizeof(struct contact));

	    currentc = firstc;
	    while(1)
	    {
		    newc = (struct contact *)malloc(sizeof(struct contact));
		    fread(currentc,sizeof(struct contact),1,datafile);
		    if(currentc->next == NULL)
			    break;
		    currentc->next = newc;
		    currentc->count=0;
		    currentc = newc;
	    }
	    fclose(datafile);
	    cnum = currentc->number;

    }

    do
    {
	fflush(stdin);
	puts("\n***********Welcome To The Hospital*************");
	puts("-- -----------------------------");
	puts("1 - Add Patient Record");
	puts("2 - Delete patient record");
	puts("3 - List all Patients");
	puts("4 - Modify Patient details");
	puts("5 - Find a specific Patient ");
	puts("-- -----------------------------");
	puts("Q - Save and quit\n");
	printf("Your choice:");
	ch = getchar();
	ch = toupper(ch);
	switch(ch)
	{
	    case '1':
		puts("Add a new contact\n");
		fflush(stdin);
		addPatient();
		break;
	    case '2':
		puts("Delete a contact\n");
		deletepatient();
		break;
	    case '3':
		puts("List all patients\n");
		listAll();
		break;
	    case '4':
		puts("Modify patient details\n");
		modifycontact();
		break;
	    case '5':
		puts("Find a patient by phone number\n");
		findcontact();
		break;
	    case 'Q':
		puts("Save and quit\n");
		default:
		break;
	}
    }
    while(ch != 'Q');
    currentc = firstc;

    if(currentc == NULL)
	    return(0);

    datafile = fopen(filename,"w");

    if(datafile == NULL)
    {
	    printf("Error writing to %s\n",filename);
	    return(1);
    }

    while(currentc != NULL)
    {
	    fwrite(currentc,sizeof(struct contact),1,datafile);
	    currentc = currentc->next;
    }
    fclose(datafile);
    return(0);
}
/*----------------------------------------------------------------------------*/
void addPatient(void)
{
    newc = (struct contact *)malloc(sizeof(struct contact));
    if(firstc==NULL)
	firstc = currentc = newc;

    else
    {
	currentc = firstc;

	while(currentc->next != NULL)currentc = currentc->next;

	currentc->next = newc;
	currentc = newc;
    }
/* update the structure */
    cnum++;
    printf("%27s: %5i\n","Patient number",cnum);
    currentc->number = cnum;

    printf("%27s: ","Enter patient name");
    gets(currentc->name);
    printf("%27s: ","Enter patient Phone number");
    gets(currentc->phone);
    printf("%27s: ","Enter patient email");
    gets(currentc->email);
    printf("%27s: ","Enter patient health problem");
    gets(currentc->hprob);
    printf("%27s: ","Assign a suitable doctor for the patient");
    gets(currentc->hdoc);
    printf("Record added!");
    currentc->count=0;

    currentc->next = NULL;
}
/*----------------------------------------------------------------------------*/
void listAll(void)
{
    if(firstc==NULL)
	puts("There are no patients to display!");

    else
    {
	    printf("%5s %-13s %-13s %-15s %-10s %-10s\n","PatientID","Name","Phone","Email","Problem","Doctor");
	puts("---------- ------------ ----------- -------------  -------------- --------------");

	currentc=firstc;

	do
	{

		printf("%5d: %-15s %-15s %-15s %-10s %-10s\n",\
		currentc->number,\
		currentc->name,\
		currentc->phone,\
		currentc->email,\
		currentc->hprob,\
		currentc->hdoc);

	}

	while((currentc=currentc->next) != NULL);
    }
}
/*----------------------------------------------------------------------------*/
void deletepatient(void)
{
    int record;
    struct contact *previousa;
    if(firstc==NULL)
    {
	puts("There are no patient records to delete!");
	return;
    }

    listAll();
    printf("Enter patient ID number to delete: ");
    scanf("%d",&record);
    currentc = firstc;

    while(currentc != NULL)
    {
	if(currentc->number == record)
	{
	    if(currentc == firstc)
		firstc=currentc->next;
	    else
		previousa->next = currentc->next;

	free(currentc);
	    printf("patient %d deleted!\n",record);
	    return;
	}

	else
	{
	previousa = currentc;
	    currentc = currentc->next;
	}
    }
    printf("patient %d not found!\n",record);
 }
/*----------------------------------------------------------------------------*/
void modifycontact(void)
{
    int record, result;
    if(firstc==NULL)
    {
	puts("There are no patient records to modify!");
	return;
    }

    listAll();
    printf("Enter patient account number to modify or change: ");
    scanf("%d",&record);
    result = findnum(record);

    if( result >0 ){
	    printf("Contact %d:\n",currentc->number);
	    printf("Name: %s\n",currentc->name);
	    if(prompt())
		    gets(currentc->name);
	    printf("Phone: %s\n",currentc->phone);
	    if(prompt())
		    gets(currentc->phone);
	    printf("Email: %s\n",currentc->email);
	    if(prompt())
		    gets(currentc->email);
	    printf("Health Doctor: %s\n",currentc->hdoc);
	    if(prompt())
		    gets(currentc->hdoc);

	    return;
	}
    printf("Patient %d was not found!\n",record);
}
/*----------------------------------------------------------------------------*/
int findnum (int recordnum)
{
    int record;
    record = recordnum;
    currentc = firstc;
    while(currentc != NULL)
    {

	if(currentc->number == record)
	     {
	   return 1;
	 }

	else
	{
	    currentc = currentc->next;
	}
    }
    return -1;
}
/*----------------------------------------------------------------------------*/
int findcontact(void)
{
     char buff[20];

     if(firstc==NULL)
	{
	puts("There are no patient records to find!");
	    return 1;
    }

    printf("Enter patient phone number: ");
    fflush(stdin);
    gets(buff);

    currentc = firstc;
    while(currentc != NULL)
    {
	if( strcmp(currentc->phone, buff) == 0 )
	    {
			printf("%6s %-20s %-15s %-15s %-10s %-15s\n","Patient ID","Name","Phone","Email","Health Problem");

	    printf("%6d: %-20s %-15s %-20s %-15s %-15s\n",\
	    currentc->number,\
	    currentc->name,\
	    currentc->phone,\
	    currentc->email, \
	    currentc->hprob,\
	    currentc->hdoc);


			return 0;
	    }
		else
		{
			currentc = currentc->next;
		}
    }
    printf("patient %s was not found!\n",buff);
	  return 1;
}
/*----------------------------------------------------------------------------*/
int prompt(void)
{
	char ch;
    fflush(stdin);
	printf("Update? (Y to update any other key to not)");
	ch = getchar();
	ch = toupper(ch);
	fflush(stdin);
	if(ch == 'Y')
	{
		printf("Enter new value: ");
		return(1);
	}
	else
		return(0);
}
/*----------------------------------------------------------------------------*/
