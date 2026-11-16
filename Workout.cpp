/*
 * Workout.cpp
 * Oshan Bhagat
 * This file contains the implementation of the Workout class. Creates a workout from a workout list, picks your 
 * exercises based on your weakest lift (lift/goal), and displays the workout to the user.
 */

#include "Workout.h"
#include "Exercise.h"
#include "User.h"
#include "WeightedExercise.h"
#include "BodyweightExercise.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

Workout::Workout(){
    exercises.clear();
}

Workout::~Workout(){
    clearWorkout();
}

void Workout::addExercise(Exercise* exercise){
    exercises.push_back(exercise);
}

void Workout::generateWorkout(User& user){

    clearWorkout();

    static bool seeded = false;

    if(!seeded){
        srand(time(0));
        seeded = true;
    }

    // Exercise library
    string squatExercises[3] = {
        "Squat",
        "Leg Press",
        "Bulgarian Split Squat"
    };

    string benchExercises[3] = {
        "Bench Press",
        "Incline Bench Press",
        "Push-Ups"
    };

    string deadliftExercises[3] = {
        "Deadlift",
        "Romanian Deadlift",
        "Pull-Ups"
    };

    string weakestLift = user.WeakestLift();

    int sets = calculateSets(user.getAge());

    // Pick two different exercises for the weakest lift
    int firstExercise = rand() % 3;
    int secondExercise = rand() % 3;

    while(secondExercise == firstExercise){
        secondExercise = rand() % 3;
    }

    // Pick one exercise from each of the other two lift groups
    int otherExercise1 = rand() % 3;
    int otherExercise2 = rand() % 3;

    if(weakestLift == "Squat"){

        addGeneratedExercise(
            squatExercises[firstExercise],
            user,
            sets
        );

        addGeneratedExercise(
            squatExercises[secondExercise],
            user,
            sets
        );

        addGeneratedExercise(
            benchExercises[otherExercise1],
            user,
            sets
        );

        addGeneratedExercise(
            deadliftExercises[otherExercise2],
            user,
            sets
        );
    }

    else if(weakestLift == "Bench"){

        addGeneratedExercise(
            benchExercises[firstExercise],
            user,
            sets
        );

        addGeneratedExercise(
            benchExercises[secondExercise],
            user,
            sets
        );

        addGeneratedExercise(
            squatExercises[otherExercise1],
            user,
            sets
        );

        addGeneratedExercise(
            deadliftExercises[otherExercise2],
            user,
            sets
        );
    }

    else{

        addGeneratedExercise(
            deadliftExercises[firstExercise],
            user,
            sets
        );

        addGeneratedExercise(
            deadliftExercises[secondExercise],
            user,
            sets
        );

        addGeneratedExercise(
            squatExercises[otherExercise1],
            user,
            sets
        );

        addGeneratedExercise(
            benchExercises[otherExercise2],
            user,
            sets
        );
    }
}

void Workout::addGeneratedExercise(string exerciseName, User& user, int sets){

    int reps;
    int weight;

    // Bodyweight exercises
    if(exerciseName == "Push-Ups"){

        reps = 10;

        Exercise* newExercise = new BodyweightExercise(
            exerciseName,
            sets,
            reps
        );

        addExercise(newExercise);

        return;
    }

    if(exerciseName == "Pull-Ups"){

        reps = 6;

        Exercise* newExercise = new BodyweightExercise(
            exerciseName,
            sets,
            reps
        );

        addExercise(newExercise);

        return;
    }

    // Main lifts use lower repetitions
    if(exerciseName == "Squat" ||
       exerciseName == "Bench Press" ||
       exerciseName == "Deadlift"){

        reps = 5;
    }

    // Supporting weighted exercises use more repetitions
    else{
        reps = 8;
    }

    // Squat supporting exercises
    if(exerciseName == "Squat"){

        weight = calculateWeight(user.getSquat(), 0.70);
    }

    else if(exerciseName == "Leg Press"){

        weight = calculateWeight(user.getWeight(), 1.00);
    }

    else if(exerciseName == "Bulgarian Split Squat"){

        weight = calculateWeight(user.getWeight(), 0.25);
    }

    // Bench supporting exercises
    else if(exerciseName == "Bench Press"){

        weight = calculateWeight(user.getBench(), 0.70);
    }

    else if(exerciseName == "Incline Bench Press"){

        weight = calculateWeight(user.getBench(), 0.55);
    }

    // Deadlift supporting exercises
    else if(exerciseName == "Deadlift"){

        weight = calculateWeight(user.getDeadlift(), 0.70);
    }

    else if(exerciseName == "Romanian Deadlift"){

        weight = calculateWeight(user.getDeadlift(), 0.55);
    }

    else{

        weight = 0;
    }

    Exercise* newExercise = new WeightedExercise(
        exerciseName,
        sets,
        reps,
        weight
    );

    addExercise(newExercise);
}

int Workout::calculateSets(int age){

    if(age < 60){
        return 3;
    }

    return 2;
}

int Workout::calculateWeight(double baseWeight, double percentage){

    double weight = baseWeight * percentage;

    // Round to nearest 5 pounds
    int roundedWeight = round(weight / 5.0) * 5;

    return roundedWeight;
}

void Workout::displayWorkout(){

    cout << endl;
    cout << "----- YOUR WORKOUT -----" << endl;

    for(int i = 0; i < exercises.size(); i++){

        cout << endl;

        // REQUIRED CONCEPT: Polymorphism
        // Calls either WeightedExercise::display()
        // or BodyweightExercise::display()
        exercises[i]->display();
    }
}

void Workout::clearWorkout(){

    for(int i = 0; i < exercises.size(); i++){
        delete exercises[i];
    }

    exercises.clear();
}

int Workout::getExerciseCount(){
    return exercises.size();
}

Exercise* Workout::getExercise(int index){

    if(index >= 0 && index < exercises.size()){
        return exercises[index];
    }

    return nullptr;
}