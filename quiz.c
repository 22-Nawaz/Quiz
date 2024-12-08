#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_QUESTIONS 50
#define QUIZ_QUESTIONS 10
#define TEST_QUESTIONS 25

typedef struct {
    char question[256];
    char options[4][100];
    int correct_option; // Correct option index (0-3)
} Question;

// Categories
Question mental_ability[MAX_QUESTIONS];
Question general_knowledge[MAX_QUESTIONS];
Question c_programming[MAX_QUESTIONS];
Question test_questions[TEST_QUESTIONS];

// Function prototypes
void initialize_questions();
void shuffle(int arr[], int size);
void conduct_quiz(const char* category, Question questions[], int question_count, int num_questions);
void prepare_test_category();

void shuffle(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}



int main() {
    char name[50];
    int choice;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Quiz!\n");
    printf("Enter your name: ");
    scanf("%49s", name);

    printf("\nHello, %s! Please select a category:\n", name);
    printf("1. Mental Ability\n2. General Knowledge\n3. C Programming\n4. Test\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Initialize questions
    initialize_questions();

    switch (choice) {
        case 1:
            conduct_quiz("Mental Ability", mental_ability, MAX_QUESTIONS, QUIZ_QUESTIONS);
            break;
        case 2:
            conduct_quiz("General Knowledge", general_knowledge, MAX_QUESTIONS, QUIZ_QUESTIONS);
            break;
        case 3:
            conduct_quiz("C Programming", c_programming, MAX_QUESTIONS, QUIZ_QUESTIONS);
            break;
        case 4:
            prepare_test_category();
            conduct_quiz("Test", test_questions, TEST_QUESTIONS, TEST_QUESTIONS);
            break;
        default:
            printf("Invalid choice! Please restart the program.\n");
    }

    printf("\nThank you for participating, %s! Keep up the great work!\n", name);
    return 0;
}

void initialize_questions() {
    // Example Mental Ability Questions
    strcpy(mental_ability[0].question, "Look at this series: 12, 11, 13, 12, 14, 13, � What number should come next?");
    strcpy(mental_ability[0].options[0], "10");
    strcpy(mental_ability[0].options[1], "16");
    strcpy(mental_ability[0].options[2], "13");
    strcpy(mental_ability[0].options[3], "615");
    mental_ability[0].correct_option = 3;

    strcpy(mental_ability[1].question, "Look at this series: 36, 34, 30, 28, 24, � What number should come next?");
    strcpy(mental_ability[1].options[0], "22");
    strcpy(mental_ability[1].options[1], "26");
    strcpy(mental_ability[1].options[2], "23");
    strcpy(mental_ability[1].options[3], "20");
    mental_ability[1].correct_option = 0;
    
    strcpy(mental_ability[2].question, "Look at this series: 7, 10, 8, 11, 9, 12, � What number should come next?");
    strcpy(mental_ability[2].options[0], "7");
    strcpy(mental_ability[2].options[1], "12");
    strcpy(mental_ability[2].options[2], "10");
    strcpy(mental_ability[2].options[3], "13");
    mental_ability[2].correct_option = 2;
    
    strcpy(mental_ability[3].question, "Look at this series: 2, 1, (1/2), (1/4), � What number should come next?");
    strcpy(mental_ability[3].options[0], "(1/3)");
    strcpy(mental_ability[3].options[1], "(1/8)");
    strcpy(mental_ability[3].options[2], "(1/4)");
    strcpy(mental_ability[3].options[3], "(1/16)");
    mental_ability[3].correct_option = 1;
    
    strcpy(mental_ability[4].question, " Look at this series: 80, 10, 70, 15, 60, � What number should come next?");
    strcpy(mental_ability[4].options[0], "20");
    strcpy(mental_ability[4].options[1], "25");
    strcpy(mental_ability[4].options[2], "30");
    strcpy(mental_ability[4].options[3], "50");
    mental_ability[4].correct_option = 0;
    
    strcpy(mental_ability[5].question, "Which word does NOT belong with the others?");
    strcpy(mental_ability[5].options[0], "Index");
    strcpy(mental_ability[5].options[1], "Glossary");
    strcpy(mental_ability[5].options[2], "Chapter");
    strcpy(mental_ability[5].options[3], "Book");
    mental_ability[5].correct_option = 3;
    
    strcpy(mental_ability[6].question, "Which word is the odd one out?");
    strcpy(mental_ability[6].options[0], "Trivial");
    strcpy(mental_ability[6].options[1], "Unimportant");
    strcpy(mental_ability[6].options[2], "Important");
    strcpy(mental_ability[6].options[3], "Insignificant");
    mental_ability[6].correct_option = 2;
    
    strcpy(mental_ability[7].question, "Which word does NOT belong with the others?");
    strcpy(mental_ability[7].options[0], "Wing");
    strcpy(mental_ability[7].options[1], "Fin");
    strcpy(mental_ability[7].options[2], "Beak");
    strcpy(mental_ability[7].options[3], "Rudder");
    mental_ability[7].correct_option = 2;
    
    strcpy(mental_ability[8].question, "Which word is the odd one out?");
    strcpy(mental_ability[8].options[0], "Hate");
    strcpy(mental_ability[8].options[1], "Fondness");
    strcpy(mental_ability[8].options[2], "Liking");
    strcpy(mental_ability[8].options[3], "Attachment");
    mental_ability[8].correct_option = 1;
    
    strcpy(mental_ability[9].question, "Pick the odd man out?");
    strcpy(mental_ability[9].options[0], "Fair");
    strcpy(mental_ability[9].options[1], "Just");
    strcpy(mental_ability[9].options[2], "Equitable");
    strcpy(mental_ability[9].options[3], "Biased");
    mental_ability[9].correct_option = 3;
    
    strcpy(mental_ability[10].question, " CUP : LIP :: BIRD : ?");
    strcpy(mental_ability[10].options[0], "Grass");
    strcpy(mental_ability[10].options[1], "Forest");
    strcpy(mental_ability[10].options[2], "Beak");
    strcpy(mental_ability[10].options[3], "Bush");
    mental_ability[10].correct_option = 2;
    
    strcpy(mental_ability[11].question, "Paw : Cat :: Hoof :?");
    strcpy(mental_ability[11].options[0], "Lamb");
    strcpy(mental_ability[11].options[1], "Horse");
    strcpy(mental_ability[11].options[2], "Elephant");
    strcpy(mental_ability[11].options[3], "Tiger");
    mental_ability[11].correct_option = 1;
    
    strcpy(mental_ability[12].question, "Safe : Secure :: Protect :?");
    strcpy(mental_ability[12].options[0], "Lock");
    strcpy(mental_ability[12].options[1], "Guard");
    strcpy(mental_ability[12].options[2], "Sure");
    strcpy(mental_ability[12].options[3], "conserve");
    mental_ability[12].correct_option = 1;
    
    strcpy(mental_ability[13].question, "Melt : Liquid :: Freeze :?");
    strcpy(mental_ability[13].options[0], "Ice");
    strcpy(mental_ability[13].options[1], "Solid");
    strcpy(mental_ability[13].options[2], "Condense");
    strcpy(mental_ability[13].options[3], "Push");
    mental_ability[13].correct_option = 1;
    
    strcpy(mental_ability[14].question, "Parts : Strap :: Wolf :?");
    strcpy(mental_ability[14].options[0], "Flow");
    strcpy(mental_ability[14].options[1], "Animal");
    strcpy(mental_ability[14].options[2], "Wood");
    strcpy(mental_ability[14].options[3], "Fox");
    mental_ability[14].correct_option = 0;
    
    strcpy(mental_ability[15].question, "An Informal Gathering occurs when a group of people get together in a casual, relaxed manner. Which situation below is the best example of an Informal Gathering?");
    strcpy(mental_ability[15].options[0], "Debating club meets on the first Sunday morning of every month.");
    strcpy(mental_ability[15].options[1], "After finding out about his salary raise, Jay and a few colleagues go out for a quick dinner after work.");
    strcpy(mental_ability[15].options[2], "Meena sends out 10 invitations for a bachelorette party she is giving for her elder sister.");
    strcpy(mental_ability[15].options[3], "Whenever she eats at a Chinese restaurant, Roop seems to run into Dibya.");
    mental_ability[15].correct_option = 1;
    
    strcpy(mental_ability[16].question, "A Tiebreaker is an additional contest carried out to establish a winner among tied contestants. Choose one situation from the options below that best represents a Tiebreaker?");
    strcpy(mental_ability[16].options[0], "At halftime, the score is tied at 2-2 in a football match.");
    strcpy(mental_ability[16].options[1], " Serena and Maria have each secured 1 set in the game.");
    strcpy(mental_ability[16].options[2], "The umpire tosses a coin to decide which team will have bat first.");
    strcpy(mental_ability[16].options[3], "RCB and KKR each finished at 140 all out.");
    mental_ability[16].correct_option = 3;
    
    strcpy(mental_ability[17].question, "Arrange the words given below in a meaningful sequence.?");
    strcpy(mental_ability[17].options[0], "Presentation");
    strcpy(mental_ability[17].options[1], "Recommendation");
    strcpy(mental_ability[17].options[2], "Arrival ");
    strcpy(mental_ability[17].options[3], "Discussion");
    mental_ability[17].correct_option = 2;
    
    strcpy(mental_ability[18].question, "Find the missing number in the following series 3, 5, 5, 19, 7, 41, 9?");
    strcpy(mental_ability[18].options[0], "71");
    strcpy(mental_ability[18].options[1], "61");
    strcpy(mental_ability[18].options[2], "79");
    strcpy(mental_ability[18].options[3], "69");
    mental_ability[18].correct_option = 0;
    
    strcpy(mental_ability[19].question, "C L R T B Q S M A P D I  N F J K G Y X Four of the following  five are alike in a certain way and so form group. Which is the one that does not belong to the group?");
    strcpy(mental_ability[19].options[0], "LBT  ");
    strcpy(mental_ability[19].options[1], "IJF");
    strcpy(mental_ability[19].options[2], "PID");
    strcpy(mental_ability[19].options[3], "BMS");
    mental_ability[19].correct_option = 2; 
	   
    strcpy(mental_ability[20].question, "Arrange these words in alphabetical order and tick the one that comes last?");
    strcpy(mental_ability[20].options[0], "ACTUATE");
    strcpy(mental_ability[20].options[1], "ACCUMULATE");
    strcpy(mental_ability[20].options[2], "ACQUIT");
    strcpy(mental_ability[20].options[3], "ACHIEVE");
    mental_ability[20].correct_option = 0;
    
    strcpy(mental_ability[21].question, "In a certain code language COMPUTER is written as RFUVQNPC. How will MEDICINE be written in that code language?");
    strcpy(mental_ability[21].options[0], "MFEDJJOE");
    strcpy(mental_ability[21].options[1], "EOJDEJFM");
    strcpy(mental_ability[21].options[2], "MFEJDJOE");
    strcpy(mental_ability[21].options[3], "EOJDJEFM");
    mental_ability[21].correct_option = 3;
    
    strcpy(mental_ability[22].question, "S L U A Y J V E I O N Q G Z B D R H What will come in place of question (?) mark in the following series : LA UJ YI EG?");
    strcpy(mental_ability[22].options[0], "ZH");
    strcpy(mental_ability[22].options[1], "IB");
    strcpy(mental_ability[22].options[2], "NR");
    strcpy(mental_ability[22].options[3], "QH");
    mental_ability[22].correct_option = 3;
    
    strcpy(mental_ability[23].question, "What should come next in the following letter sequence : A A B A B C A B C D A B C D E A B C D?");
    strcpy(mental_ability[23].options[0], "A");
    strcpy(mental_ability[23].options[1], "E");
    strcpy(mental_ability[23].options[2], "C");
    strcpy(mental_ability[23].options[3], "B");
    mental_ability[23].correct_option = 1;
    
    strcpy(mental_ability[24].question, "Introducing a man, a woman said, He is the only son of my mother's mother. How is the woman related to the man?");
    strcpy(mental_ability[24].options[0], "MOTHER");
    strcpy(mental_ability[24].options[1], "AUNT");
    strcpy(mental_ability[24].options[2], "SISTER");
    strcpy(mental_ability[24].options[3], "NIECE");
    mental_ability[24].correct_option = 3;
    
    strcpy(mental_ability[25].question, "Introducing a man, Neeraj said, �His wife is the only daughter of my wife.� How is Neeraj related to that man?");
    strcpy(mental_ability[25].options[0], "FATHER");
    strcpy(mental_ability[25].options[1], "GRANDFATHER");
    strcpy(mental_ability[25].options[2], "FATHER IN LAW");
    strcpy(mental_ability[25].options[3], "SON");
    mental_ability[25].correct_option = 2;
    
    strcpy(mental_ability[26].question, "In a code, CORNER is written as GSVRIV. How can CENTRAL be written in that code?");
    strcpy(mental_ability[26].options[0], "DFOUSBM");
    strcpy(mental_ability[26].options[1], "GIRXVEP");
    strcpy(mental_ability[26].options[2], "GNFJKER");
    strcpy(mental_ability[26].options[3], "NONE");
    mental_ability[26].correct_option = 1;
    
    strcpy(mental_ability[27].question, "Amir was born on Feb 29th of 2012 which was a Wednesday. If he lives to be 101 years old, how many birthdays would he celebrate on a Wednesday?");
    strcpy(mental_ability[27].options[0], "3");
    strcpy(mental_ability[27].options[1], "4");
    strcpy(mental_ability[27].options[2], "5");
    strcpy(mental_ability[27].options[3], "1");
    mental_ability[27].correct_option = 1;
    
    strcpy(mental_ability[28].question, "What should come in the place of question mark (?) in the following alpha-numeric series : C-3,E-5,G-7,I-9,?,? ?");
    strcpy(mental_ability[28].options[0], "X-24,M-21");
    strcpy(mental_ability[28].options[1], "K-11,M-13");
    strcpy(mental_ability[28].options[2], "O-15,X-24");
    strcpy(mental_ability[28].options[3], "M-18,K-14");
    mental_ability[28].correct_option = 1;
    
    strcpy(mental_ability[29].question, "A clock is started at noon. By 10 min past 5, the hour hand has turned through :?");
    strcpy(mental_ability[29].options[0], "145");
    strcpy(mental_ability[29].options[1], "150");
    strcpy(mental_ability[29].options[2], "155");
    strcpy(mental_ability[29].options[3], "160");
    mental_ability[29].correct_option = 2;
    
    strcpy(mental_ability[30].question, "The year next to 1896 that will have the same calendar as that of the year 1896 :?");
    strcpy(mental_ability[30].options[0], "1902");
    strcpy(mental_ability[30].options[1], "1904");
    strcpy(mental_ability[30].options[2], "1905");
    strcpy(mental_ability[30].options[3], "1908");
    mental_ability[30].correct_option = 3;
    
    strcpy(mental_ability[31].question, "If the English letters A to Z are written in a reverse order then what is the fourth letter to the right of 12th letter from the left?");
    strcpy(mental_ability[31].options[0], "K");
    strcpy(mental_ability[31].options[1], "J");
    strcpy(mental_ability[31].options[2], "R");
    strcpy(mental_ability[31].options[3], "L");
    mental_ability[31].correct_option = 0;
    
    strcpy(mental_ability[32].question, "If REASON is coded as 5 and BELIEVED as 7, then what is the code for GOVERNMENT?");
    strcpy(mental_ability[32].options[0], "6");
    strcpy(mental_ability[32].options[1], "8");
    strcpy(mental_ability[32].options[2], "9");
    strcpy(mental_ability[32].options[3], "10");
    mental_ability[32].correct_option = 2;
    
    strcpy(mental_ability[33].question, "A clock which gains 10 minutes in 24 hours, is set right at 12 AM. What will be the true time when the clock indicates 5 AM on the following day?");
    strcpy(mental_ability[33].options[0], "4:48 AM");
    strcpy(mental_ability[33].options[1], "5:12 AM");
    strcpy(mental_ability[33].options[2], "4:50 AM");
    strcpy(mental_ability[33].options[3], "5:15 AM");
    mental_ability[33].correct_option = 0;

    
    strcpy(mental_ability[34].question, "What is 2 + 2?");
    strcpy(mental_ability[34].options[0], "3");
    strcpy(mental_ability[34].options[1], "4");
    strcpy(mental_ability[34].options[2], "5");
    strcpy(mental_ability[34].options[3], "6");
    mental_ability[34].correct_option = 1;

   strcpy(mental_ability[35].question, "Next number in the number sequence is 22, 11, 33, 16.5, 49.5,?");
    strcpy(mental_ability[35].options[0], "20.75");
    strcpy(mental_ability[35].options[1], "22.75");
    strcpy(mental_ability[35].options[2], "24.75");
    strcpy(mental_ability[35].options[3], "26.75");
    mental_ability[35].correct_option = 2;
    
  strcpy(mental_ability[36].question, "Choose the number pair/group which is different from others?");
    strcpy(mental_ability[36].options[0], "15:46");
    strcpy(mental_ability[36].options[1], "12:37");
    strcpy(mental_ability[36].options[2], "10:15");
    strcpy(mental_ability[36].options[3], "8:33");
    mental_ability[36].correct_option = 3;
    
    strcpy(mental_ability[37].question, "Pointing to a photograph, Vipul said, She is the daughter of my grandfather's only son. How is Vipul related to the girl in the photograph ?");
    strcpy(mental_ability[37].options[0], "BROTHER");
    strcpy(mental_ability[37].options[1], "FATHER");
    strcpy(mental_ability[37].options[2], "COUSIN");
    strcpy(mental_ability[37].options[3], "INSUFFICIENT DATA");
    mental_ability[37].correct_option = 0;
    
    strcpy(mental_ability[38].question, "CGE, RNP, FJH, OKM, IMK,?");
    strcpy(mental_ability[38].options[0], "HJL");
    strcpy(mental_ability[38].options[1], "JKL");
    strcpy(mental_ability[38].options[2], "JHL");
    strcpy(mental_ability[38].options[3], "LHJ");
    mental_ability[38].correct_option = 3;
    
    strcpy(mental_ability[39].question, "In a certain code language STUDENT is written as TUTDNES.How will SOURCES be writte in that code language?");
    strcpy(mental_ability[39].options[0], "SOURSEC");
    strcpy(mental_ability[39].options[1], "SRUOCES");
    strcpy(mental_ability[39].options[2], "SOURCES");
    strcpy(mental_ability[39].options[3], "SUORECS");
    mental_ability[39].correct_option = 3;
    // Add 10 more questions for Mental Ability (placeholder)

    // General Knowledge Questions
    strcpy(general_knowledge[0].question, "What is the capital of France?");
    strcpy(general_knowledge[0].options[0], "Berlin");
    strcpy(general_knowledge[0].options[1], "Madrid");
    strcpy(general_knowledge[0].options[2], "Paris");
    strcpy(general_knowledge[0].options[3], "Rome");
    general_knowledge[0].correct_option = 2;

    strcpy(general_knowledge[1].question, "Who wrote 'Romeo and Juliet'?");
    strcpy(general_knowledge[1].options[0], "William Shakespeare");
    strcpy(general_knowledge[1].options[1], "Charles Dickens");
    strcpy(general_knowledge[1].options[2], "Jane Austen");
    strcpy(general_knowledge[1].options[3], "Mark Twain");
    general_knowledge[1].correct_option = 0;

    strcpy(general_knowledge[2].question, "Which is the largest species of penguin?");
    strcpy(general_knowledge[2].options[0], "Emperor Penguin");
    strcpy(general_knowledge[2].options[1], "King Penguin");
    strcpy(general_knowledge[2].options[2], "Adelie Penguin");
    strcpy(general_knowledge[2].options[3], "Little Penguin");
    general_knowledge[2].correct_option = 0;

    strcpy(general_knowledge[3].question, "What is the fastest land animal in the world?");
    strcpy(general_knowledge[3].options[0], "Cheetah");
    strcpy(general_knowledge[3].options[1], "Lion");
    strcpy(general_knowledge[3].options[2], "Greyhound");
    strcpy(general_knowledge[3].options[3], "Horse");
    general_knowledge[3].correct_option = 0;

    strcpy(general_knowledge[4].question, "What is a group of lions called?");
    strcpy(general_knowledge[4].options[0], "Flock");
    strcpy(general_knowledge[4].options[1], "Pride");
    strcpy(general_knowledge[4].options[2], "Herd");
    strcpy(general_knowledge[4].options[3], "Pack");
    general_knowledge[4].correct_option = 1;

    strcpy(general_knowledge[5].question, "What is the only mammal capable of true flight?");
    strcpy(general_knowledge[5].options[0], "Bat");
    strcpy(general_knowledge[5].options[1], "Flying Squirrel");
    strcpy(general_knowledge[5].options[2], "Sugar Glider");
    strcpy(general_knowledge[5].options[3], "Kangaroo Rat");
    general_knowledge[5].correct_option = 0;

    strcpy(general_knowledge[6].question, "Which animal has the longest gestation period?");
    strcpy(general_knowledge[6].options[0], "Elephant");
    strcpy(general_knowledge[6].options[1], "Blue Whale");
    strcpy(general_knowledge[6].options[2], "Giraffe");
    strcpy(general_knowledge[6].options[3], "Rhino");
    general_knowledge[6].correct_option = 0;

    strcpy(general_knowledge[7].question, "Which animal is known to have the largest brain relative to its body size?");
    strcpy(general_knowledge[7].options[0], "Dolphin");
    strcpy(general_knowledge[7].options[1], "Elephant");
    strcpy(general_knowledge[7].options[2], "Octopus");
    strcpy(general_knowledge[7].options[3], "Human");
    general_knowledge[7].correct_option = 3;

    strcpy(general_knowledge[8].question, "What type of animal is a Komodo dragon?");
    strcpy(general_knowledge[8].options[0], "Snake");
    strcpy(general_knowledge[8].options[1], "Lizard");
    strcpy(general_knowledge[8].options[2], "Crocodile");
    strcpy(general_knowledge[8].options[3], "Turtle");
    general_knowledge[8].correct_option = 1;

    strcpy(general_knowledge[9].question, "How many hearts does an octopus have?");
    strcpy(general_knowledge[9].options[0], "1");
    strcpy(general_knowledge[9].options[1], "2");
    strcpy(general_knowledge[9].options[2], "3");
    strcpy(general_knowledge[9].options[3], "5");
    general_knowledge[9].correct_option = 2;

    strcpy(general_knowledge[10].question, "What does RAM stand for in mobile phones and Computers?");
    strcpy(general_knowledge[10].options[0], "Process data from storage");
    strcpy(general_knowledge[10].options[1], "Improve network performance");
    strcpy(general_knowledge[10].options[2], "Render graphics and visuals");
    strcpy(general_knowledge[10].options[3], "Manage power consumption");
    general_knowledge[10].correct_option = 2;

    strcpy(general_knowledge[11].question, " Which type of storage is faster and more reliable in modern laptops?");
    strcpy(general_knowledge[11].options[0], "Hard Disk Drive (HDD)");
    strcpy(general_knowledge[11].options[1], "Solid State Drive (SSD)");
    strcpy(general_knowledge[11].options[2], "Floppy Disk");
    strcpy(general_knowledge[11].options[3], "USB Flash Drive");
    general_knowledge[11].correct_option = 1;

    strcpy(general_knowledge[12].question, "Which of the following connectors is commonly used to charge mobile devices?");
    strcpy(general_knowledge[12].options[0], "HDMI");
    strcpy(general_knowledge[12].options[1], "USB-C");
    strcpy(general_knowledge[12].options[2], "Ethernet");
    strcpy(general_knowledge[12].options[3], "VGA");
    general_knowledge[12].correct_option = 1;

    strcpy(general_knowledge[13].question, "What is the primary purpose of a firewall in a computer system?");
    strcpy(general_knowledge[13].options[0], "Store files securely");
    strcpy(general_knowledge[13].options[1], "Boost processor speed");
    strcpy(general_knowledge[13].options[2], "Prevent unauthorized access to or from a private network");
    strcpy(general_knowledge[13].options[3], "Manage system updates");
    general_knowledge[13].correct_option = 2;

    strcpy(general_knowledge[14].question, "Which company developed the iOS operating system used in iPhones?");
    strcpy(general_knowledge[14].options[0], "Google");
    strcpy(general_knowledge[14].options[1], "Microsoft");
    strcpy(general_knowledge[14].options[2], "Samsung");
    strcpy(general_knowledge[14].options[3], "Apple");
    general_knowledge[14].correct_option = 3;

    strcpy(general_knowledge[15].question, "What is a primary advantage of using a cloud storage service on your mobile or PC?");
    strcpy(general_knowledge[15].options[0], "Increases battery life");
    strcpy(general_knowledge[15].options[1], "Provides physical data storage");
    strcpy(general_knowledge[15].options[2], "Allows access to files from anywhere with an internet connection");
    strcpy(general_knowledge[15].options[3], "Enhances the device's processing power");
    general_knowledge[15].correct_option = 2;

    strcpy(general_knowledge[16].question, "Which of the following is a well-known mobile processor manufacturer?");
    strcpy(general_knowledge[16].options[0], "Intel");
    strcpy(general_knowledge[16].options[1], "Qualcomm");
    strcpy(general_knowledge[16].options[2], "NVIDIA");
    strcpy(general_knowledge[16].options[3], "AMD");
    general_knowledge[16].correct_option = 1;

    strcpy(general_knowledge[17].question, "What is the most abundant gas in Earth's atmosphere?");
    strcpy(general_knowledge[17].options[0], "Oxygen");
    strcpy(general_knowledge[17].options[1], "Carbon Dioxide");
    strcpy(general_knowledge[17].options[2], "Nitrogen");
    strcpy(general_knowledge[17].options[3], "Hydrogen");
    general_knowledge[17].correct_option = 2;

    strcpy(general_knowledge[18].question, "What is the primary function of mitochondria in cells?");
    strcpy(general_knowledge[18].options[0], "Photosynthesis");
    strcpy(general_knowledge[18].options[1], "Protein synthesis");
    strcpy(general_knowledge[18].options[2], "Energy production");
    strcpy(general_knowledge[18].options[3], "Waste removal");
    general_knowledge[18].correct_option = 2;

    strcpy(general_knowledge[19].question, "Who is credited with the invention of the World Wide Web?");
    strcpy(general_knowledge[19].options[0], "Steve Jobs");
    strcpy(general_knowledge[19].options[1], "Tim Berners-Lee");
    strcpy(general_knowledge[19].options[2], "Bill Gates");
    strcpy(general_knowledge[19].options[3], "Larry Page");
    general_knowledge[19].correct_option = 1;

    strcpy(general_knowledge[20].question, "Which planet in our solar system has the largest number of moons?");
    strcpy(general_knowledge[20].options[0], "Mars");
    strcpy(general_knowledge[20].options[1], "Earth");
    strcpy(general_knowledge[20].options[2], "Jupiter");
    strcpy(general_knowledge[20].options[3], "Saturn");
    general_knowledge[20].correct_option = 2;

    strcpy(general_knowledge[21].question, "What is the name of the process by which plants convert sunlight into energy?");
    strcpy(general_knowledge[21].options[0], "Respiration");
    strcpy(general_knowledge[21].options[1], "Fermentation");
    strcpy(general_knowledge[21].options[2], "Photosynthesis");
    strcpy(general_knowledge[21].options[3], "Digestion");
    general_knowledge[21].correct_option = 2;

    strcpy(general_knowledge[22].question, "Which element is used in the manufacture of computer chips?");
    strcpy(general_knowledge[22].options[0], "Silicon");
    strcpy(general_knowledge[22].options[1], "Iron");
    strcpy(general_knowledge[22].options[2], "Copper");
    strcpy(general_knowledge[22].options[3], "Aluminum");
    general_knowledge[22].correct_option = 0;

    strcpy(general_knowledge[23].question, "What was the first artificial satellite to be launched into space?");
    strcpy(general_knowledge[23].options[0], "Explorer 1");
    strcpy(general_knowledge[23].options[1], "Sputnik 1");
    strcpy(general_knowledge[23].options[2], "Apollo 11");
    strcpy(general_knowledge[23].options[3], "Luna 2");
    general_knowledge[23].correct_option = 1;

    strcpy(general_knowledge[24].question, "In what year was the first iPhone released?");
    strcpy(general_knowledge[24].options[0], "2005");
    strcpy(general_knowledge[24].options[1], "2007");
    strcpy(general_knowledge[24].options[2], "2009");
    strcpy(general_knowledge[24].options[3], "2010");
    general_knowledge[24].correct_option = 1;

    strcpy(general_knowledge[25].question, "Which planet is known as the Red Planet?");
    strcpy(general_knowledge[25].options[0], "Earth");
    strcpy(general_knowledge[25].options[1], "Jupiter");
    strcpy(general_knowledge[25].options[2], "Mars");
    strcpy(general_knowledge[25].options[3], "Saturn");
    general_knowledge[25].correct_option = 2;

    strcpy(general_knowledge[26].question, "Who wrote the play Romeo and Juliet?");
    strcpy(general_knowledge[26].options[0], "Charles Dickens");
    strcpy(general_knowledge[26].options[1], "William Shakespeare");
    strcpy(general_knowledge[26].options[2], "Leo Tolstoy");
    strcpy(general_knowledge[26].options[3], "Mark Twain");
    general_knowledge[26].correct_option = 1;

    strcpy(general_knowledge[27].question, "What is the chemical symbol for Gold?");
    strcpy(general_knowledge[27].options[0], "Au");
    strcpy(general_knowledge[27].options[1], "Ag");
    strcpy(general_knowledge[27].options[2], "Fe");
    strcpy(general_knowledge[27].options[3], "Pb");
    general_knowledge[27].correct_option = 0;

    strcpy(general_knowledge[28].question, "Which country hosted the 2020 Summer Olympics (held in 2021)?");
    strcpy(general_knowledge[28].options[0], "Brazil");
    strcpy(general_knowledge[28].options[1], "China");
    strcpy(general_knowledge[28].options[2], "Japan");
    strcpy(general_knowledge[28].options[3], "France");
    general_knowledge[28].correct_option = 2;

    strcpy(general_knowledge[29].question, "Who was the first person to step on the moon?");
    strcpy(general_knowledge[29].options[0], "Yuri Gagarin");
    strcpy(general_knowledge[29].options[1], "Neil Armstrong");
    strcpy(general_knowledge[29].options[2], "Buzz Aldrin");
    strcpy(general_knowledge[29].options[3], "John Glenn");
    general_knowledge[29].correct_option = 1;

    strcpy(general_knowledge[30].question, "What is the largest ocean on Earth?");
    strcpy(general_knowledge[30].options[0], "Atlantic Ocean");
    strcpy(general_knowledge[30].options[1], "Indian Ocean");
    strcpy(general_knowledge[30].options[2], "Southern Ocean");
    strcpy(general_knowledge[30].options[3], "Pacific Ocean");
    general_knowledge[30].correct_option = 3;

    strcpy(general_knowledge[31].question, "In which year did World War II end?");
    strcpy(general_knowledge[31].options[0], "1918");
    strcpy(general_knowledge[31].options[1], "1945");
    strcpy(general_knowledge[31].options[2], "1965");
    strcpy(general_knowledge[31].options[3], "1980");
    general_knowledge[31].correct_option = 1;

    strcpy(general_knowledge[32].question, "Who is the author of The Theory of Relativity?");
    strcpy(general_knowledge[32].options[0], "Isaac Newton");
    strcpy(general_knowledge[32].options[1], "Galileo Galilei");
    strcpy(general_knowledge[32].options[2], "Albert Einstein");
    strcpy(general_knowledge[32].options[3], "Nikola Tesla");
    general_knowledge[32].correct_option = 2;

    strcpy(general_knowledge[33].question, "What is the smallest prime number?");
    strcpy(general_knowledge[33].options[0], "0");
    strcpy(general_knowledge[33].options[1], "1");
    strcpy(general_knowledge[33].options[2], "2");
    strcpy(general_knowledge[33].options[3], "3");
    general_knowledge[33].correct_option = 2;

    strcpy(general_knowledge[34].question, "Which organ in the human body is responsible for pumping blood?");
    strcpy(general_knowledge[34].options[0], "Liver");
    strcpy(general_knowledge[34].options[1], "Brain");
    strcpy(general_knowledge[34].options[2], "Heart");
    strcpy(general_knowledge[34].options[3], "Kidney");
    general_knowledge[34].correct_option = 2;

    strcpy(general_knowledge[35].question, "What is the primary cause of the extreme tilt of Uranus's axis?");
    strcpy(general_knowledge[35].options[0], "Tidal forces from Neptune");
    strcpy(general_knowledge[35].options[1], "A massive collision early in its history");
    strcpy(general_knowledge[35].options[2], "Gravitational interactions with its moons");
    strcpy(general_knowledge[35].options[3], "Resonance with Saturn's orbit");
    general_knowledge[35].correct_option = 1;

    strcpy(general_knowledge[36].question, "Which exoplanet detection method is most effective for finding planets that are close to their stars?");
    strcpy(general_knowledge[36].options[0], "Radial velocity method");
    strcpy(general_knowledge[36].options[1], "Direct imaging");
    strcpy(general_knowledge[36].options[2], "Microlensing");
    strcpy(general_knowledge[36].options[3], "Transit method");
    general_knowledge[36].correct_option = 0;

    strcpy(general_knowledge[37].question, "What is the approximate surface temperature of Neptune?");
    strcpy(general_knowledge[37].options[0], "-200°C");
    strcpy(general_knowledge[37].options[1], "-220°C");
    strcpy(general_knowledge[37].options[2], "-240°C");
    strcpy(general_knowledge[37].options[3], "-260°C");
    general_knowledge[37].correct_option = 2;

    strcpy(general_knowledge[38].question, "How long does it take light to travel from the Sun to Neptune?");
    strcpy(general_knowledge[38].options[0], "4.2 hours");
    strcpy(general_knowledge[38].options[1], "3.8 hours");
    strcpy(general_knowledge[38].options[2], "5.5 hours");
    strcpy(general_knowledge[38].options[3], "7.8 hours");
    general_knowledge[38].correct_option = 0;

    strcpy(general_knowledge[39].question, "Which AI technique allows systems to improve performance with more data over time?");
    strcpy(general_knowledge[39].options[0], "Static programming");
    strcpy(general_knowledge[39].options[1], "Machine learning");
    strcpy(general_knowledge[39].options[2], "Manual coding");
    strcpy(general_knowledge[39].options[3], "Traditional algorithms");
    general_knowledge[39].correct_option = 1;

    strcpy(general_knowledge[40].question, " What does NLP stand for in the field of AI?");
    strcpy(general_knowledge[40].options[0], "Natural Language Processing");
    strcpy(general_knowledge[40].options[1], "Neural Logical Programming");
    strcpy(general_knowledge[40].options[2], "Network Learning Procedure");
    strcpy(general_knowledge[40].options[3], "Nonlinear Processing");
    general_knowledge[40].correct_option = 0;

    strcpy(general_knowledge[41].question, "What is the primary goal of reinforcement learning in AI?");
    strcpy(general_knowledge[41].options[0], "To find patterns in large datasets");
    strcpy(general_knowledge[41].options[1], "To mimic human reasoning");
    strcpy(general_knowledge[41].options[2], "To learn by interacting with the environment and receiving feedback");
    strcpy(general_knowledge[41].options[3], "To train models with labeled datasets");
    general_knowledge[41].correct_option = 2;

    strcpy(general_knowledge[42].question, "Which of the following is an example of unsupervised learning?");
    strcpy(general_knowledge[42].options[0], "Regression analysis");
    strcpy(general_knowledge[42].options[1], "Decision trees");
    strcpy(general_knowledge[42].options[2], "K-means clustering");
    strcpy(general_knowledge[42].options[3], "Random forests");
    general_knowledge[42].correct_option = 2;

    strcpy(general_knowledge[43].question, "Which of the following is a fundamental component of a robot?");
    strcpy(general_knowledge[43].options[0], "Sensors");
    strcpy(general_knowledge[43].options[1], "Web browser");
    strcpy(general_knowledge[43].options[2], "Television");
    strcpy(general_knowledge[43].options[3], "Smartphone");
    general_knowledge[43].correct_option = 0;

    strcpy(general_knowledge[44].question, "In which field is a manipulator robot typically used");
    strcpy(general_knowledge[44].options[0], "Cooking");
    strcpy(general_knowledge[44].options[1], "Medical surgery");
    strcpy(general_knowledge[44].options[2], "Data processing");
    strcpy(general_knowledge[44].options[3], "Textile design");
    general_knowledge[44].correct_option = 1;

    strcpy(general_knowledge[45].question, "What is the primary function of actuators in a robot?");
    strcpy(general_knowledge[45].options[0], "To sense the environment");
    strcpy(general_knowledge[45].options[1], "To process data");
    strcpy(general_knowledge[45].options[2], "To move and control the robot");
    strcpy(general_knowledge[45].options[3], "To store energy");
    general_knowledge[45].correct_option = 2;

    strcpy(general_knowledge[46].question, "Which of the following is an example of a mobile robot?");
    strcpy(general_knowledge[46].options[0], "SCARA robot");
    strcpy(general_knowledge[46].options[1], "Industrial welding arm");
    strcpy(general_knowledge[46].options[2], "Mars rover");
    strcpy(general_knowledge[46].options[3], "CNC machine");
    general_knowledge[46].correct_option = 2;

    strcpy(general_knowledge[47].question, "What is the primary goal of swarm robotics?");
    strcpy(general_knowledge[47].options[0], "To build large individual robots");
    strcpy(general_knowledge[47].options[1], "To coordinate small robots to work together");
    strcpy(general_knowledge[47].options[2], "To develop humanoid robots");
    strcpy(general_knowledge[47].options[3], "To design flying robots");
    general_knowledge[47].correct_option = 1;

    strcpy(general_knowledge[48].question, " Which bowler has taken the most wickets in Test cricket?");
    strcpy(general_knowledge[48].options[0], "Shane Warne");
    strcpy(general_knowledge[48].options[1], "Muttiah Muralitharan");
    strcpy(general_knowledge[48].options[2], "Anil Kumble");
    strcpy(general_knowledge[48].options[3], "Glenn McGrath");
    general_knowledge[48].correct_option = 1;

    strcpy(general_knowledge[49].question, "In which year did the first-ever T20 International match take place?");
    strcpy(general_knowledge[49].options[0], "2003");
    strcpy(general_knowledge[49].options[1], "2005");
    strcpy(general_knowledge[49].options[2], "2006");
    strcpy(general_knowledge[49].options[3], "2008");
    general_knowledge[49].correct_option = 2;

    //C Programming Questions
    strcpy(c_programming[0].question, "Which header file is required for printf?");
    strcpy(c_programming[0].options[0], "stdio.h");
    strcpy(c_programming[0].options[1], "conio.h");
    strcpy(c_programming[0].options[2], "stdlib.h");
    strcpy(c_programming[0].options[3], "string.h");
    c_programming[0].correct_option = 0;

    strcpy(c_programming[1].question, "Which data type can store 10.5?");
    strcpy(c_programming[1].options[0], "int");
    strcpy(c_programming[1].options[1], "float");
    strcpy(c_programming[1].options[2], "char");
    strcpy(c_programming[1].options[3], "double");
    c_programming[1].correct_option = 1;

    strcpy(c_programming[2].question, "What is a correct syntax to output Hello World in C?");
    strcpy(c_programming[2].options[0], "cout << Hello World");
    strcpy(c_programming[2].options[1], "printf(Hello World)");
    strcpy(c_programming[2].options[2], "System.out.printline(Hello World)");
    strcpy(c_programming[2].options[3], "Console.WriteLine(Hello World)");
    c_programming[2].correct_option = 1;

    strcpy(c_programming[3].question, "How do you insert COMMENTS in C code?");
    strcpy(c_programming[3].options[0], "#");
    strcpy(c_programming[3].options[1], "//");
    strcpy(c_programming[3].options[2], "*");
    strcpy(c_programming[3].options[3], "--");
    c_programming[3].correct_option = 1;

    strcpy(c_programming[4].question, "When a variable is created in C, a memory address is assigned to the variable?");
    strcpy(c_programming[4].options[0], "False");
    strcpy(c_programming[4].options[1], "True");
    strcpy(c_programming[4].options[2], "Both are True and False");
    c_programming[4].correct_option = 0;

    strcpy(c_programming[5].question, "In C, code statements must end with a semicolon (;)?");
    strcpy(c_programming[5].options[0], "True");
    strcpy(c_programming[5].options[1], "False");
    strcpy(c_programming[5].options[2], "Both are True and False");
    c_programming[5].correct_option = 1;

    strcpy(c_programming[6].question, "How can you create a variable with the numeric value 5?");
    strcpy(c_programming[6].options[0], "int num = 5");
    strcpy(c_programming[6].options[1], "val num = 5");
    strcpy(c_programming[6].options[2], "num = 5 int");
    strcpy(c_programming[6].options[3], "num = 5");
    c_programming[6].correct_option = 0;

    strcpy(c_programming[7].question, "How can you create a variable with the floating number 2.8?");
    strcpy(c_programming[7].options[0], "num = 2.8 float");
    strcpy(c_programming[7].options[1], "val num = 2.8");
    strcpy(c_programming[7].options[2], "float num = 2.8");
    strcpy(c_programming[7].options[3], "num = 2.8 double");
    c_programming[7].correct_option = 2;

    strcpy(c_programming[8].question, "Which operator is used to add together two values?");
    strcpy(c_programming[8].options[0], "The & sign");
    strcpy(c_programming[8].options[1], "The ADD keyword");
    strcpy(c_programming[8].options[2], "The + sign");
    strcpy(c_programming[8].options[3], "The * sign");
    c_programming[8].correct_option = 2;

    strcpy(c_programming[9].question, "Which function is often used to output values and print text?");
    strcpy(c_programming[9].options[0], "printf()");
    strcpy(c_programming[9].options[1], "printword()");
    strcpy(c_programming[9].options[2], "output()");
    strcpy(c_programming[9].options[3], "write()");
    c_programming[9].correct_option = 0;

    strcpy(c_programming[10].question, "Which format specifier is often used to print integers?");
    strcpy(c_programming[10].options[0], "%f");
    strcpy(c_programming[10].options[1], "%s");
    strcpy(c_programming[10].options[2], "%c");
    strcpy(c_programming[10].options[3], "%d");
    c_programming[10].correct_option = 3;

    strcpy(c_programming[11].question, "Which operator can be used to compare two values?");
    strcpy(c_programming[11].options[0], "=");
    strcpy(c_programming[11].options[1], "> <");
    strcpy(c_programming[11].options[2], "= =");
    strcpy(c_programming[11].options[3], "< >");
    c_programming[11].correct_option = 2;

    strcpy(c_programming[12].question, "Which operator can be used to find the memory size (in bytes) of a data type or variable?");
    strcpy(c_programming[12].options[0], "The len property");
    strcpy(c_programming[12].options[1], "The length property");
    strcpy(c_programming[12].options[2], "The sizer property");
    strcpy(c_programming[12].options[3], "The sizeof property");
    c_programming[12].correct_option = 3;

    strcpy(c_programming[13].question, "Which keyword can be used to make a variable unchangeable/read-only?");
    strcpy(c_programming[13].options[0], "final");
    strcpy(c_programming[13].options[1], "constant");
    strcpy(c_programming[13].options[2], "const");
    strcpy(c_programming[13].options[3], "readonly");
    c_programming[13].correct_option = 2;

    strcpy(c_programming[14].question, "What do we call the following? int myNumbers[] = {25, 50, 75, 100}?");
    strcpy(c_programming[14].options[0], "An array");
    strcpy(c_programming[14].options[1], "None of the above");
    strcpy(c_programming[14].options[2], "A pointer");
    strcpy(c_programming[14].options[3], "A class");
    c_programming[14].correct_option = 0;

    strcpy(c_programming[15].question, "Array indexes start with?");
    strcpy(c_programming[15].options[0], "1");
    strcpy(c_programming[15].options[1], "0");
    strcpy(c_programming[15].options[2], "n");
    strcpy(c_programming[15].options[3], "i");
    c_programming[15].correct_option = 1;

    strcpy(c_programming[16].question, "How do you call a function in C?");
    strcpy(c_programming[16].options[0], "myFunction");
    strcpy(c_programming[16].options[1], "myFunction()");
    strcpy(c_programming[16].options[2], "(myFunction)");
    strcpy(c_programming[16].options[3], "myFunction[]");
    c_programming[16].correct_option = 1;

    strcpy(c_programming[17].question, "How do you start writing a while loop in C?");
    strcpy(c_programming[17].options[0], "while (x < y)");
    strcpy(c_programming[17].options[1], "if x > y while");
    strcpy(c_programming[17].options[2], "while x < y");
    strcpy(c_programming[17].options[3], "while x < y then");
    c_programming[17].correct_option = 0;

    strcpy(c_programming[18].question, "Which keyword is used to return a value inside a function?");
    strcpy(c_programming[18].options[0], "return");
    strcpy(c_programming[18].options[1], "break");
    strcpy(c_programming[18].options[2], "void");
    strcpy(c_programming[18].options[3], "get");
    c_programming[18].correct_option = 0;

    strcpy(c_programming[19].question, "How do you start writing a for loop in C?");
    strcpy(c_programming[19].options[0], "for (int i = 0; switch < 5; i++)");
    strcpy(c_programming[19].options[1], "for (int i = 0; while < 5; i++)");
    strcpy(c_programming[19].options[2], "for (int i = 0; i < 5; i++)");
    strcpy(c_programming[19].options[3], "for (x in y)");
    c_programming[19].correct_option = 2;

    strcpy(c_programming[20].question, "Which statement can be used to select one of many code blocks to be executed?");
    strcpy(c_programming[20].options[0], "switch");
    strcpy(c_programming[20].options[1], "when");
    strcpy(c_programming[20].options[2], "default");
    strcpy(c_programming[20].options[3], "break");
    c_programming[20].correct_option = 0;

    strcpy(c_programming[21].question, "Which statement is used to stop a loop?");
    strcpy(c_programming[21].options[0], "stop");
    strcpy(c_programming[21].options[1], "exit");
    strcpy(c_programming[21].options[2], "break");
    strcpy(c_programming[21].options[3], "void");
    c_programming[21].correct_option = 2;

    strcpy(c_programming[22].question, "Which keyword is used to create a class in C?");
    strcpy(c_programming[22].options[0], "class");
    strcpy(c_programming[22].options[1], "class = myClass");
    strcpy(c_programming[22].options[2], "class()");
    strcpy(c_programming[22].options[3], "None of the above");
    c_programming[22].correct_option = 3;

    strcpy(c_programming[23].question, "What is ptr in the following code known as? int* ptr = &myAge?");
    strcpy(c_programming[23].options[0], "A pointer");
    strcpy(c_programming[23].options[1], "An array");
    strcpy(c_programming[23].options[2], "A parameter");
    strcpy(c_programming[23].options[3], "A class");
    c_programming[23].correct_option = 1;

    strcpy(c_programming[24].question, "In C, it is possible to inherit class properties and functions from one class to another?");
    strcpy(c_programming[24].options[0], "True");
    strcpy(c_programming[24].options[1], "False");
    c_programming[24].correct_option = 1;

    strcpy(c_programming[25].question, "Which keyword is used to create a structure?");
    strcpy(c_programming[25].options[0], "str");
    strcpy(c_programming[25].options[1], "struct");
    strcpy(c_programming[25].options[2], "structure");
    strcpy(c_programming[25].options[3], "structs");
    c_programming[25].correct_option = 1;

    strcpy(c_programming[26].question, "Who is the father of C language?");
    strcpy(c_programming[26].options[0], "Steve Jobs");
    strcpy(c_programming[26].options[1], "James Gosling");
    strcpy(c_programming[26].options[2], "Dennis Ritchie");
    strcpy(c_programming[26].options[3], "Rasmus Lerdorf");
    c_programming[26].correct_option = 2;

    strcpy(c_programming[27].question, "Which of the following is not a valid C variable name?");
    strcpy(c_programming[27].options[0], "int number");
    strcpy(c_programming[27].options[1], "float rate");
    strcpy(c_programming[27].options[2], "int variable_count");
    strcpy(c_programming[27].options[3], "int $main");
    c_programming[27].correct_option = 3;

    strcpy(c_programming[28].question, "All keywords in C are in?");
    strcpy(c_programming[28].options[0], "LowerCase letters");
    strcpy(c_programming[28].options[1], "UpperCase letters");
    strcpy(c_programming[28].options[2], "CamelCase letters");
    strcpy(c_programming[28].options[3], "None of the mentioned");
    c_programming[28].correct_option = 0;

    strcpy(c_programming[29].question, "What is short int in C programming?");
    strcpy(c_programming[29].options[0], "The basic data type of C");
    strcpy(c_programming[29].options[1], "Qualifier");
    strcpy(c_programming[29].options[2], "Short is the qualifier and int is the basic data type");
    strcpy(c_programming[29].options[3], "All of the mentioned");
    c_programming[29].correct_option = 2;

    strcpy(c_programming[30].question, "Which of the following declaration is not supported by C language?");
    strcpy(c_programming[30].options[0], "String str");
    strcpy(c_programming[30].options[1], "char *str");
    strcpy(c_programming[30].options[2], "float str = 3e2");
    strcpy(c_programming[30].options[3], "Both “String str;” and “float str = 3e2");
    c_programming[30].correct_option = 0;

    strcpy(c_programming[31].question, "Which keyword is used to prevent any changes in the variable within a C program?");
    strcpy(c_programming[31].options[0], "immutable");
    strcpy(c_programming[31].options[1], "mutable");
    strcpy(c_programming[31].options[2], "const");
    strcpy(c_programming[31].options[3], "volatile");
    c_programming[31].correct_option = 2;

    strcpy(c_programming[32].question, "What is the result of logical or relational expression in C?");
    strcpy(c_programming[32].options[0], "True or False");
    strcpy(c_programming[32].options[1], "0 or 1");
    strcpy(c_programming[32].options[2], "0 if an expression is false and any positive number if an expression is true");
    strcpy(c_programming[32].options[3], "None of the mentioned");
    c_programming[32].correct_option = 1;

    strcpy(c_programming[33].question, "Which of the following typecasting is accepted by C language?");
    strcpy(c_programming[33].options[0], "Widening conversions");
    strcpy(c_programming[33].options[1], "Narrowing conversions");
    strcpy(c_programming[33].options[2], "Widening & Narrowing conversions");
    strcpy(c_programming[33].options[3], "None of the mentioned");
    c_programming[33].correct_option = 2;

    strcpy(c_programming[34].question, "Where in C the order of precedence of operators do not exist?");
    strcpy(c_programming[34].options[0], "Within conditional statements, if, else");
    strcpy(c_programming[34].options[1], "Within while, do-while");
    strcpy(c_programming[34].options[2], "Within a macro definition");
    strcpy(c_programming[34].options[3], "Within a macro definition");
    c_programming[34].correct_option = 3;

    strcpy(c_programming[35].question, "Which of the following is NOT possible with any 2 operators in C?");
    strcpy(c_programming[35].options[0], "Different precedence, same associativity");
    strcpy(c_programming[35].options[1], "Different precedence, different associativity");
    strcpy(c_programming[35].options[2], "Same precedence, different associativity");
    strcpy(c_programming[35].options[3], "All of the mentioned");
    c_programming[35].correct_option = 2;

    strcpy(c_programming[36].question, "What is an example of iteration in C?");
    strcpy(c_programming[36].options[0], "for");
    strcpy(c_programming[36].options[1], "while");
    strcpy(c_programming[36].options[2], "do-while");
    strcpy(c_programming[36].options[3], "all of the mentioned");
    c_programming[36].correct_option = 3;

    strcpy(c_programming[37].question, "Functions can return enumeration constants in C?");
    strcpy(c_programming[37].options[0], "true");
    strcpy(c_programming[37].options[1], "false");
    strcpy(c_programming[37].options[2], "depends on the compiler");
    strcpy(c_programming[37].options[3], "depends on the standard");
    c_programming[37].correct_option = 0;

    strcpy(c_programming[38].question, "Functions in C Language are always?");
    strcpy(c_programming[38].options[0], "Internal");
    strcpy(c_programming[38].options[1], "External");
    strcpy(c_programming[38].options[2], "Both Internal and External");
    strcpy(c_programming[38].options[3], "External and Internal are not valid terms for functions");
    c_programming[38].correct_option = 1;

    strcpy(c_programming[39].question, "Which of following is not accepted in C?");
    strcpy(c_programming[39].options[0], "static a = 10; //static as");
    strcpy(c_programming[39].options[1], "static int func (int); //parameter as static");
    strcpy(c_programming[39].options[2], "static static int a; //a static variable prefixed with static");
    strcpy(c_programming[39].options[3], "all of the mentioned");
    c_programming[39].correct_option = 2;

    strcpy(c_programming[40].question, " Property which allows to produce different executable for different platforms in C is called?");
    strcpy(c_programming[40].options[0], "File inclusion");
    strcpy(c_programming[40].options[1], "Selective inclusion");
    strcpy(c_programming[40].options[2], "Conditional compilation");
    strcpy(c_programming[40].options[3], "Recursive macros");
    c_programming[40].correct_option = 2;

    strcpy(c_programming[41].question, "What is #include <stdio.h>?");
    strcpy(c_programming[41].options[0], "Preprocessor directive");
    strcpy(c_programming[41].options[1], "Inclusion directive");
    strcpy(c_programming[41].options[2], "File inclusion directive");
    strcpy(c_programming[41].options[3], "None of the mentioned");
    c_programming[41].correct_option = 0;

    strcpy(c_programming[42].question, "C preprocessors can have compiler specific features?");
    strcpy(c_programming[42].options[0], "True");
    strcpy(c_programming[42].options[1], "False");
    strcpy(c_programming[42].options[2], "Depends on the standard");
    strcpy(c_programming[42].options[3], "Depends on the platform");
    c_programming[42].correct_option = 0;

    strcpy(c_programming[43].question, "Which of the following are C preprocessors?");
    strcpy(c_programming[43].options[0], "#ifdef");
    strcpy(c_programming[43].options[1], "#define");
    strcpy(c_programming[43].options[2], "#endif");
    strcpy(c_programming[43].options[3], "all of the mentioned");
    c_programming[43].correct_option = 3;

    strcpy(c_programming[44].question, "The C-preprocessors are specified with _________ symbol");
    strcpy(c_programming[44].options[0], "#");
    strcpy(c_programming[44].options[1], "$");
    strcpy(c_programming[44].options[2], "” ”");
    strcpy(c_programming[44].options[3], "&");
    c_programming[44].correct_option = 0;

    strcpy(c_programming[45].question, "How many number of pointer (*) does C have against a pointer variable declaration?");
    strcpy(c_programming[45].options[0], "7");
    strcpy(c_programming[45].options[1], "127");
    strcpy(c_programming[45].options[2], "255");
    strcpy(c_programming[45].options[3], "No limits");
    c_programming[45].correct_option = 3;

    strcpy(c_programming[46].question, "Which of the following is not possible statically in C language?");
    strcpy(c_programming[46].options[0], " Jagged Array");
    strcpy(c_programming[46].options[1], "Rectangular Array");
    strcpy(c_programming[46].options[2], "Cuboidal Array");
    strcpy(c_programming[46].options[3], "Multidimensional Array");
    c_programming[46].correct_option = 0;

    strcpy(c_programming[47].question, "Which of the following return-type cannot be used for a function in C?");
    strcpy(c_programming[47].options[0], "char");
    strcpy(c_programming[47].options[1], "struct");
    strcpy(c_programming[47].options[2], "void");
    strcpy(c_programming[47].options[3], "none of the mentioned");
    c_programming[47].correct_option = 1;

    strcpy(c_programming[48].question, "The standard header _______ is used for variable list arguments (…) in C?");
    strcpy(c_programming[48].options[0], "<stdio.h>");
    strcpy(c_programming[48].options[1], "<stdlib.h>");
    strcpy(c_programming[48].options[2], "<math.h>");
    strcpy(c_programming[48].options[3], "<stdarg.h>");
    c_programming[48].correct_option = 1;

    strcpy(c_programming[49].question, "In C language, FILE is of which data type?");
    strcpy(c_programming[49].options[0], "int");
    strcpy(c_programming[49].options[1], "struct");
    strcpy(c_programming[49].options[2], "char");
    strcpy(c_programming[49].options[3], "None of the mentioned");
    c_programming[49].correct_option = 1;

}



void conduct_quiz(const char* category, Question questions[], int question_count, int num_questions) {
    printf("\nStarting %s Quiz!\n", category);

    if (question_count == 0) {
        printf("Sorry, there are no questions available in this category.\n");
        return;
    }

    if (num_questions > question_count) {
        num_questions = question_count;
    }

    int selected_questions[question_count];
    for (int i = 0; i < question_count; i++) selected_questions[i] = i;

    shuffle(selected_questions, question_count);

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        int q_index = selected_questions[i];
        printf("\nQ%d: %s\n", i + 1, questions[q_index].question);

        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[q_index].options[j]);
        }

        int answer;
        printf("Your answer: ");
        scanf("%d", &answer);

        while (answer < 1 || answer > 4) {
            printf("Invalid choice! Please enter a number between 1 and 4: ");
            scanf("%d", &answer);
        }

        if (answer - 1 == questions[q_index].correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %s\n",
                   questions[q_index].options[questions[q_index].correct_option]);
        }
    }

    printf("\nYou scored %d out of %d in the %s Quiz.\n", score, num_questions, category);
}


void prepare_test_category() {
    int total_questions = 0;
    for (int i = 0; i < MAX_QUESTIONS && total_questions < TEST_QUESTIONS; i++) {
        if (i < MAX_QUESTIONS) test_questions[total_questions++] = mental_ability[i];
        if (i < MAX_QUESTIONS && total_questions < TEST_QUESTIONS)
            test_questions[total_questions++] = general_knowledge[i];
        if (i < MAX_QUESTIONS && total_questions < TEST_QUESTIONS)
            test_questions[total_questions++] = c_programming[i];
    }
}
