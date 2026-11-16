/* main.cpp 
 * Oshan Bhagat
 * This file contains the main function for the Fitness Tracker application, including the user interface and program flow.
 
 */
#include <iostream>
#include "User.h"
#include "Exercise.h"
#include "Workout.h"
using namespace std;

int main(){
    cout << "Welcome to the Fitness Tracker! Please enter your details." << endl;
    cout << "Enter your name: " << endl;
    string name;
    cin >> name;
    cout << "Enter your age: " << endl;
    int age;
    cin >> age;
    cout << "Enter your weight (in lbs): " << endl;
    double weight;
    cin >> weight;
    cout << "Enter your squat, bench, and deadlift goals (in lbs) separated by spaces: " << endl;
    int squatGoal, benchGoal, deadliftGoal;
    cin >> squatGoal >> benchGoal >> deadliftGoal;

    cout << "Enter your squat, bench, and deadlift(in lbs) separated by spaces: " << endl;
    int squat, bench, deadlift;
    cin >> squat >> bench >> deadlift;
    
    //Create user object with the provided information

    User user(name, age, weight, squatGoal, benchGoal, deadliftGoal, squat, bench, deadlift);

    cout << endl;
    user.displayUserInfo();
    user.displayUserGoals();

    cout << "Thank you! Now let's set up your exercises." << endl;
    //create a workout
    Workout workout;
    // Generate a workout based on the user's weakest lift
    workout.generateWorkout(user);
    // REQUIRED CONCEPTS:
    // Workout stores Exercise pointers that can point to either
    // WeightedExercise or BodyweightExercise objects.
    workout.displayWorkout();

    cout << endl;
    cout << "Workout generated successfully." << endl;

    return 0;
}

