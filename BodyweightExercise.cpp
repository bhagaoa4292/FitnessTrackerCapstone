/*
 * BodyweightExercise.cpp
 * Oshan Bhagat
 * This file contains the implementation of the BodyweightExercise class.
 */

#include "BodyweightExercise.h"
#include <iostream>
using namespace std;


BodyweightExercise::BodyweightExercise()
    : Exercise(){
}

BodyweightExercise::BodyweightExercise(string name, int targetSets, int targetReps)
    : Exercise(name, targetSets, targetReps, 0){
}
void BodyweightExercise::display(){
    cout << "Exercise: " << getName() << endl;
    cout << "Sets: " << getTargetSets() << endl;
    cout << "Reps: " << getTargetReps() << endl;
    cout << "Weight: Bodyweight" << endl;
}


void BodyweightExercise::update(int completedReps){
    // Increase target repetitions if the user completed the target
    if(completedReps >= getTargetReps()){
        setTargetReps(getTargetReps() + 2);
    }
}