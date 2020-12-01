#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void readingQuestionsFromAFile(int number, char *fileName, const char **questions){
    int length_questions = 0;
    char line[255];
    int question_length;
    FILE *fpointer = fopen(fileName, "r");

// This reads the file and stores the questions
    for(int i=0; i < 5; i++){
        fgets(line, 255, fpointer);
        questions = malloc(5*sizeof(char*));
        question_length = line;
        questions[i] = malloc(question_length);
        strcpy(questions[i], line);
        length_questions++;
//This seperates the questons and answers
        char *piece = strtok(questions[i], "?");
        piece = strtok(NULL, " ");


    }
    fclose(fpointer);
// Prints the nymber of questions
    printf("The number of questions is: %d \n", length_questions);
    return line;

    }

int readingTheQuestions(const char **questions1, const char **answers1, int correct, int difficulty){
    char answer[10];
    int length;
// This displays the questions and asked the user for an answer and also diplays the clue levels 1 & 2
    for (int i = 0; i < 5; i++){
        printf("%s\n", questions1[i]);
        printf("What is your answer: \n");
        length = strlen(answers1[i]);

        if(difficulty == 1){
            printf("?");
        }
        else{
            for (int i = 0; i < length; i++){
            printf("_ ");
        }
        }
        printf("\n");
// Takes users answer
        scanf("%s", answer);
// Compares user inout to actual answer
        if (strcmp(answer, answers1[i]) == 1){
            printf("The answer is wrong \n");
        }
        else{
            printf("The answer is correct\n");
            correct++;

        }

    }
    return correct;
}

int main()
{


int difficulty;
char fileName[50];
const char **questions;

const char *questions1[5];
const char *answers1[5];

// Had to hard code in questions and asnwers as could not get them working from the file

questions1[0] = "What is the capital of France?";
questions1[1] = "Who is Liverpool's Manager (surname)?";
questions1[2] = "What is the capital if Ireland?";
questions1[3] = "Who makes the iPhone?";
questions1[4] = "Who makes the playstation?";

answers1[0] = "Paris";
answers1[1] = "Klopp";
answers1[2] = "Dublin";
answers1[3] = "Apple";
answers1[4] = "Sony";


// Asks user to enter file name and difficulty

printf("Please enter a fileName: \n");
scanf("%s", fileName);
printf("Please enter a diff level between 1-4: \n");
scanf("%i", &difficulty);

readingQuestionsFromAFile(difficulty, fileName, questions);
int correct = readingTheQuestions(questions1, answers1, 0, difficulty);
printf("You got %d/5 correct \n", correct);


// Appends file name to quiz_history
FILE *fpointer = fopen("quiz_history.txt" , "a");
fprintf(fpointer,"%s \n" ,fileName);
fclose(fpointer);


}

