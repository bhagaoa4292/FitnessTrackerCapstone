#include "Exercise.h"
#include "User.h"
#include "Workout.h"
using namespace std;
#include <iostream>

Workout::Workout() {
    exercises.clear();
}

void Workout::addExercise(Exercise* exercise) {
    exercises.push_back(exercise);
}

void Workout::displayWorkout() {
    cout << "Workout:" << endl;

    for(int i = 0; i < exercises.size(); i++){
        cout << endl;
        cout << "Exercise: " << exercises[i]->getName() << endl;
        cout << "Sets: " << exercises[i]->getTargetSets() << endl;
        cout << "Reps: " << exercises[i]->getTargetReps() << endl;
        cout << "Weight: " << exercises[i]->getWeight() << " lbs" << endl;
    }
}

void Workout::clearWorkout() {
    exercises.clear();
}

int Workout::getExerciseCount() {
    return exercises.size();
}

Exercise* Workout::getExercise(int index) {
    if(index >= 0 && index < exercises.size()){
        return exercises[index];
    }
    return nullptr;
}


