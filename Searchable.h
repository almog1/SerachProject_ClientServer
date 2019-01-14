//
// Created by almogg on 1/9/19.
//

#ifndef PROJECT2_SEARCHABLE_H
#define PROJECT2_SEARCHABLE_H

#include "ISearchable.h"
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;

template<class T>
class Searchable : public ISearchable<T> {
protected:
    std::vector<State<T> *> structure;
    State<T> *initialState;
    State<T> *goalState;
public:
    //return the initialize state of our 'problem'
    virtual State<T> *getInitializeState() {
        return this->initialState;
    }

    //return the goal state of our 'problem'
    virtual State<T> *getGoalState() {
        return this->goalState;
    }

    virtual vector<State<T> *> getStructure() {
        return this->structure;
    }

    //get the possible moves to the next step
    virtual vector<State<T> *> getAllPossibleStates(State<T> *currentState) =0;

    //apply the structure that we got from the user - our problem
    void setStructure(vector<State<T> *> structure) {
        this->structure = structure;
    }

    //set the initial state of the searchable item
    void setInitialState(State<T> *initialState) {
        this->initialState = initialState;
    }

    //set the goal state of the searchable item
    void setGoalState(State<T> *goalState) {
        this->goalState = goalState;
    }

    string getRoute() override {
        return "PATH";
    }
    //todo check how to do it using open-close
    //get the string of our way to the end
    //string getRoute() {
        //the route is from the end to the begining
//        State<T> *current = getGoalState();
//        string path="";
//        //end when getting to the start
//        while (current->getFrom() != nullptr) {
//            //go on the state of your structure
//            for (State<T> *state:structure) {
//                if (state->getFrom() != nullptr) {
//                    //find father node of current
//                    if (current->getFrom()->equals(state)) {
//                        path += current->getState().getMove(state->getState());
//                        break;
//                    }
//                }
//            }
//            current = current->getFrom();
//            //when the current is the initial state
//            if (current->getFrom()->equals(getInitializeState())) {
//                break;
//            }
//        }
//        //find the last move to the initial state
//        path += current->getState().getMove(getInitializeState()->getState());
//        reverse(path.begin(), path.end());
//        return path;
      //      return "THIS PATH";
//    }

//    virtual vector<State<T> *> getAllPossibleStates(State<T>* state) = 0;
};



#endif //PROJECT2_SEARCHABLE_H
