/*
 * WeightedExercise.cpp
 * Oshan Bhagat
 * This file contains the implementation of the WeightedExercise class.
 */

#include "WeightedExercise.h"
#include <iostream>

using namespace std;

WeightedExercise::WeightedExercise()
    : Exercise(){

}

WeightedExercise::WeightedExercise(string name, int targetSets, int targetReps, int weight)
    : Exercise(name, targetSets, targetReps, weight){

}

void WeightedExercise::display(){
    cout << "Exercise: " << getName() << endl;
    cout << "Sets: " << getTargetSets() << endl;
    cout << "Reps: " << getTargetReps() << endl;
    cout << "Weight: " << getWeight() << " lbs" << endl;
}

void WeightedExercise::update(int completedReps){

    // Increase weight if the user completed the target reps
    if(completedReps >= getTargetReps()){
        setWeight(getWeight() + 5);
    }
}