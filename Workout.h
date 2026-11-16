/***
 * Workout.h
 * Oshan Bhagat
 * This file contains the declaration of the Workout class.
 */

#ifndef WORKOUT_H
#define WORKOUT_H

#include <vector>
#include "Exercise.h"
#include "User.h"

using namespace std;

class Workout{
private:
    vector<Exercise*> exercises;
    
    void addGeneratedExercise(string exerciseName, User& user, int sets);
    int calculateSets(int age);
    int calculateWeight(double baseWeight, double percentage);

public:
    Workout();
    ~Workout();

    void generateWorkout(User& user);

    void addExercise(Exercise* exercise);
    void displayWorkout();
    void clearWorkout();

    int getExerciseCount();
    Exercise* getExercise(int index);
};

#endif