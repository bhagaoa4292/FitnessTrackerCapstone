/*
 * WeightedExercise.h
 * Oshan Bhagat
 * This file contains the declaration of the WeightedExercise class.
 */

#ifndef WEIGHTEDEXERCISE_H
#define WEIGHTEDEXERCISE_H

#include "Exercise.h"

using namespace std;

//Inheritance
class WeightedExercise : public Exercise{
public:
    WeightedExercise();
    WeightedExercise(string name, int targetSets, int targetReps, int weight);

    //Polymorphism
    void display() override;
    void update(int completedReps) override;
};

#endif