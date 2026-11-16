/*
 * Exercise.cpp
 * Oshan Bhagat
 * This file contains the implementation of the Exercise class.
 */

#include "Exercise.h"
using namespace std;
#include <string>
#include <iostream>

Exercise::Exercise() {
    name = "";
    targetSets = 0;
    targetReps = 0;
    weight = 0;
}

Exercise::Exercise(string name, int targetSets, int targetReps, int weight) {
    this->name = name;
    this->targetSets = targetSets;
    this->targetReps = targetReps;
    this->weight = weight;
}

string Exercise::getName() {
    return name;
}

int Exercise::getTargetSets() {
    return targetSets;
}

int Exercise::getTargetReps() {
    return targetReps;
}

int Exercise::getWeight() {
    return weight;
}

void Exercise::setName(string name) {
    this->name = name;
}

void Exercise::setTargetSets(int targetSets) {
    this->targetSets = targetSets;
}

void Exercise::setTargetReps(int targetReps) {
    this->targetReps = targetReps;
}

void Exercise::setWeight(int weight) {
    this->weight = weight;
}
