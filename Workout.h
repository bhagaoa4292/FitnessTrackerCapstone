/***
 * Workout.h
 * Oshan Bhagat
 * This file contains the declaration of the Workout class.
 */

#ifndef WORKOUT_H
#define WORKOUT_H

#include <vector>
#include "Exercise.h"

using namespace std;

class Workout{
private:
    vector<Exercise*> exercises;

public:
    Workout();

    void addExercise(Exercise* exercise);
    void displayWorkout();
    void clearWorkout();

    int getExerciseCount();
    Exercise* getExercise(int index);
};

#endif