/***
 * Exercise.h
 * Oshan Bhagat 
 * This file contains the declaration of the Exercise class.
 */

#ifndef EXERCISE_H
#define EXERCISE_H
using namespace std;
#include <string>

class Exercise {
    private:
        string name;
        int targetSets;
        int targetReps;
        int weight;
    public:
        Exercise();
        Exercise(string name, int targetSets, int targetReps, int weight);

        string getName();
        int getTargetSets();
        int getTargetReps();
        int getWeight();

        void setName(string name);
        void setTargetSets(int targetSets);
        void setTargetReps(int targetReps);
        void setWeight(int weight);
};

#endif