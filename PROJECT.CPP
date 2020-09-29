#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define MAXMISSES 6
#define MAXLENGTH 30

class player
{
    public:
    char name[30];
    long int score;

    player()
    {
	score=0;
	strcpy(name,"Unknown");
    }
    void determine_score(char[]);
}ob;

void player::determine_score(char word[])
{
    if(strlen(word)>10)
    score+=10;
    else if(strlen(word)>5)
    score+=20;
    else
    score+=30;
}

void display_rules()   //To display Rules of the game.
{
    clrscr();
    cout<<"\n\t\tWelcome to Hangman! Guess an Automobile Brand Name.";
    cout<<"\n\n\t\tEach letter is represented by a star.";
    cout<<"\n\n\t\tYou have to type only one CAPITAL letter in one try.";
    cout<<"\n\n\t\tIf the letter is in the word(s), then it would appear";
    cout<<"\n\n\t\teverywhere in the word(s).";
    cout<<"\n\n\t\tIf the letter isn't in the word(s), then a body part";
    cout<<"\n\n\t\tis added to the gallows.";
    cout<<"\n\n\t\tYou can continue guessing letters  until you get the";
    cout<<"\n\n\t\tword(s) or all 6 body parts are on the gallows.";
    cout<<"\n\n\n\t\tPress 'ENTER' to continue...";
    getchar();
}

void hangman(int b)   //Function for displaying hangman gallows.
{
    switch(b)
    {
       case 0 : cout<<"\n_____";
		cout<<"\n  |  ";
		break;
       case 1 : cout<<"\n_____";
		cout<<"\n  |  ";
		cout<<"\n  O  ";
		break;
       case 2 : cout<<"\n_____";
		cout<<"\n  |  ";
		cout<<"\n  O  ";
		cout<<"\n  |  ";
		break;
       case 3 : cout<<"\n_____";
		cout<<"\n  |  ";
		cout<<"\n  O  ";
		cout<<"\n /|  ";
		break;
       case 4 : cout<<"\n_____";
		cout<<"\n  |  ";
		cout<<"\n  O  ";
		cout<<"\n /|\\";
		break;
       case 5 : cout<<"\n_____";
		cout<<"\n  |  ";
		cout<<"\n  O  ";
		cout<<"\n /|\\";
		cout<<"\n /   ";
		break;
       case 6 : cout<<"\n_____";
		cout<<"\n  |  ";
		cout<<"\n  O  ";
		cout<<"\n /|\\";
		cout<<"\n / \\";
		break;
    }
}

void initword(char[],char[]);
int updateword(char,char[],char[]);

void main()
{
    display_rules();
    cout<<"\nEnter your name : ";
    cin>>ob.name;
    char choice='y';
    while(choice=='y'||choice=='Y')
    {

    int no_of_misses = 0 ,btcounter=0,j;
    char letter;
    char badtries[]="******";
    char word[MAXLENGTH], dummy[MAXLENGTH];
    char words[][MAXLENGTH]= {
				 "AUDI",
				 "PORSCHE",
				 "BMW",
				 "FIAT",
				 "HONDA",
				 "BAJAJ",
				 "TATA",
				 "TVS",
				 "VOLVO",
				 "FORCE",
				 "TOYOTA",
				 "JAGUAR",
				 "NISSAN",
				 "HYUNDAI",
				 "CHEVROLET",
				 "CHRYSLER",
				 "BENTLEY",
				 "FORD",
				 "BUGATTI",
				 "PREMIER",
				 "RENAULT",
				 "HUMMER",
				 "SKODA",
				 "FERRARI",
				 "MAHINDRA",
				 "STANDARD",
				 "MITSUBISHI",
				 "LAMBORGHINI",
				 "VOLKSWAGEN",
				 "MERCEDES BENZ",
				 "ASTON MARTIN",
				 "LAND ROVER",
				 "ASHOK LEYLAND",
				 "ROYAL ENFIELD"
			     };   //No. of strings:34

    randomize();
    int n = random(34);
    strcpy(word,words[n]);   //Generates a random string.
    initword(word,dummy);   //To create a hidden format of the string.

    while(no_of_misses < MAXMISSES)
    {
	 clrscr();
	 if(strcmp(badtries,"******")!=0)   //To show the letters entered
	 {                                 //by the user that are not
	    cout<<"\nBad Tries: ";        //present in the string.
	    for(j=0;j<no_of_misses;j++)
	    cout<<badtries[j]<<" ";
	 }

	 hangman(no_of_misses);
	 cout<<"\n\n";
	 puts(dummy);
	 cout<<"\nGuess a letter: ";
	 cin>>letter;

	 int temp = updateword(letter,word,dummy);   //To update the hidden format of the string
						    //with the letters present in the string that
	 if( temp==-1 )                            //are entered by the user.
	 {
	    cout<<"\n\nAlready Guessed, please TRY AGAIN!";   //Validation to prevent
	 }                                                   // same letter guessing.

	 else if( temp==0 )
	 {
	      int dtmnr=0;
	      for(int i=0;i<btcounter;i++)
	      if(letter==badtries[i])   //Validation to prevent same
	      {                        //letter guessing.
		 cout<<"\n\nAlready Guessed, please TRY AGAIN!";
		 ++dtmnr;
		 break;
	      }

	      if(!dtmnr)
	      {
		 cout<<"\n\nWhoops! That letter isn't in there!\n";
		 ++no_of_misses;
		 badtries[no_of_misses-1]=letter;
		 ++btcounter;
	      }
	 }

	 else {
		 cout <<"\n\nYou found a letter! Isn't that exciting!" ;
	      }//End of ELSE

	 cout << "\n\nYou have " << MAXMISSES - no_of_misses<< " guesses left.";

	 if (strcmp(word, dummy) == 0)
	 {
	     clrscr();
	     cout <<"\n"<<word;
	     cout <<"\nYeah! You got it!";
	     ob.determine_score(word);
	     break;
	 } //End of IF
	 cout<<"\n\nPress 'ENTER' to continue.";
	 getchar();
    }//END of 2nd WHILE

    if(no_of_misses == MAXMISSES)
    {
	clrscr();
	hangman(no_of_misses);
	cout << "\n\nSorry, you lose...you've been hanged." << endl;
	cout << "The word was : " << word << endl;
    }
    cout<<"\n\nDo you want to continue?(Y/N) ";
    cin>>choice;

    }//End of 1st WHILE
cout<<"\nPlayer name is "<<ob.name;
cout<<"\nPlayer score is "<<ob.score;
ofstream file("player-list.dat",ios::app|ios::binary);
if(!file)
{
   cout<<"Cannot open file!!";
   exit(1);
}
file<<ob.name<<" "<<ob.score<<"|";
file.close();
getch();
}

void initword(char word[], char dummy[])
{
     int i;
     for(i=0 ;word[i]!='\0' ; i++)
     {
	if(word[i]!=' ')
	dummy[i]='*';
	else
	dummy[i]=' ';
     }
      dummy[i]='\0';

}

int updateword(char letter, char word[], char dummy[])
{
     int i;
     int matches=0;
     for(i=0; word[i]!='\0'; i++)
     {
	 if(letter==dummy[i])
	 return -1;

	 if(letter==word[i])
	 {
	    dummy[i]=letter;
	    matches++;
	 }
     }
     return matches;
}