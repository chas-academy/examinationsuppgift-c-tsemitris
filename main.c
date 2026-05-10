//Write your code in this file
#include <stdio.h>
#include <ctype.h>

int main () {
    // Config
    int students_amount = 5;
    int test_amount = 13;

    char student_name[students_amount][30];
    int student_points[students_amount][test_amount];
    float students_average_scores[students_amount];
    float highest_average_score = 0;
    int best_student_index;
    float class_average = 0;

    // Get user input for students names and points
    for (int s = 0; s < students_amount; s++){
        int total_score = 0;
        float average_score;
        
        scanf("%s", student_name[s]);

        // Capitalize the first letter of the student's name
        student_name[s][0] = toupper(student_name[s][0]);
        for (int i = 1; student_name[s][i] != '\0'; i++) {
            student_name[s][i] = tolower(student_name[s][i]);
        }

        for (int i = 0; i < test_amount; i++) {
            scanf("%d", &student_points[s][i]);
            total_score += student_points[s][i];
        }

        // Calculate student's average score
        average_score = total_score / (float)test_amount;

        // Update highest average score and best student index if current student's average is higher
        if (average_score > highest_average_score) {
            highest_average_score = average_score;
            best_student_index = s;
        }

        // Store total and average score in a global variable
        students_average_scores[s] = average_score;
    }

    // Print the name of the student with the highest average score
    printf("%s\n", student_name[best_student_index]);

    // Calculate class average score
    for (int s = 0; s < students_amount; s++) {
        class_average += students_average_scores[s];
    }
    class_average = class_average / students_amount;

    for (int s = 0; s < students_amount; s++) {
        if (students_average_scores[s] < class_average) {
            printf("%s\n", student_name[s]);
        }
    }

    return 0;
}
