/*
 * BodyweightExercise.h
 * Oshan Bhagat
 * This file contains the declaration of the BodyweightExercise class.
 */

#ifndef BODYWEIGHTEXERCISE_H
#define BODYWEIGHTEXERCISE_H

#include "Exercise.h"

using namespace std;

//Inheritance
class BodyweightExercise : public Exercise{
public:
    BodyweightExercise();
    BodyweightExercise(string name, int targetSets, int targetReps);

    //Polymorphism
    void display() override;
    void update(int completedReps) override;
};

#endif