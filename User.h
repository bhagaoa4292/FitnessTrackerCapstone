/***
 * User.h
 * Oshan Bhagat
 * This file contains the declaration of the User class.
 */

#ifndef USER_H
#define USER_H

#include <string>

using namespace std;
class User{
    private:
        string name;
        int age;
        double weight;
        int goals[3];
        int lifts[3];
    public:
        User();
        User(string name, int age, double weight, int squatGoal, int benchGoal, int deadliftGoal, int squat, int bench, int deadlift);

        string getName();
        int getAge();
        double getWeight();

        int getSquatGoal();
        int getBenchGoal();
        int getDeadliftGoal();

        void setName(string name);
        void setAge(int age);
        void setWeight(double weight);

        void setSquatGoal(int squatGoal);
        void setBenchGoal(int benchGoal);
        void setDeadliftGoal(int deadliftGoal);

        void displayUserInfo();
        void displayUserGoals();

        string WeakestLift();

};

#endif