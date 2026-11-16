/*
 * User.cpp
 * Oshan Bhagat
 * This file contains the implementation of the User class.
 */

#include "User.h"
using namespace std;
#include <string>
#include <iostream>

User::User() {
    name = "";
    age = 0;
    weight = 0.0;
    goals[0] = 0;
    goals[1] = 0;
    goals[2] = 0;
    lifts[0] = 0;
    lifts[1] = 0;
    lifts[2] = 0;
}

User::User(string name, int age, double weight, int squatGoal, int benchGoal, int deadliftGoal, int squat, int bench, int deadlift) {
    this->name = name;
    this->age = age;
    this->weight = weight;
    this->goals[0] = squatGoal;
    this->goals[1] = benchGoal;
    this->goals[2] = deadliftGoal;
    this->lifts[0] = squat;
    this->lifts[1] = bench;
    this->lifts[2] = deadlift;
}

string User::getName() {
    return name;
}

int User::getAge() {
    return age;
}

double User::getWeight() {
    return weight;
}

int User::getSquatGoal() {
    return goals[0];
}

int User::getBenchGoal() {
    return goals[1];
}

int User::getDeadliftGoal() {
    return goals[2];
}

void User::setName(string name) {
    this->name = name;
}

void User::setAge(int age) {
    this->age = age;
}

void User::setWeight(double weight) {
    this->weight = weight;
}

void User::setSquatGoal(int squatGoal) {
    this->goals[0] = squatGoal;
}

void User::setBenchGoal(int benchGoal) {
    this->goals[1] = benchGoal;
}

void User::setDeadliftGoal(int deadliftGoal) {
    this->goals[2] = deadliftGoal;
}

void User::displayUserInfo() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
}

void User::displayUserGoals() {
    cout << "Squat Goal: " << goals[0] << endl;
    cout << "Bench Goal: " << goals[1] << endl;
    cout << "Deadlift Goal: " << goals[2] << endl;
    cout << "Weakest Lift: " << WeakestLift() << endl;
}
string User::WeakestLift() {
    double squatProgress = (double)lifts[0] / goals[0];
    double benchProgress = (double)lifts[1] / goals[1];
    double deadliftProgress = (double)lifts[2] / goals[2];

    if(squatProgress <= benchProgress && squatProgress <= deadliftProgress){
        return "Squat";
    }
    else if(benchProgress <= squatProgress && benchProgress <= deadliftProgress){
        return "Bench";
    }
    else{
        return "Deadlift";
    }
}

int User::getSquat() {
    return lifts[0];
}
int User::getBench() {
    return lifts[1];
}
int User::getDeadlift() {
    return lifts[2];
}