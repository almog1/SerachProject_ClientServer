#include <iostream>
#include <string>
#include "State.h"
#include "StringReverser.h"
#include "Solver.h"
#include "Point.h"
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "Matrix.h"
#include "SolverBestSearch.h"
#include "DFS.h"

using namespace std;

int main() {
    //MySerialServer mySerialServer = new Server();
//    std::cout << "Hello, World!" << std::endl;
//    Point *point = new Point(4, 3, 15);
//    cout << point->getX() << endl;
//
//    State<string> *st = new State<string>("almog");
//    State<string> *st2 = new State<string>("chagit");
//    State<string> *st3 = new State<string>("3");
//    State<string> *st4 = new State<string>("3");
//    st->setFrom(st2);
//    st2->setFrom(st3);
//    State<string> *fromState = st->getFrom();
//    State<string> *from2 = st->getFrom()->getFrom();
//
//    if (st4->equals(st3) == true) {
//        cout << "equal" << endl;
//    }
//    cout << st->getState() << endl;
//    cout << fromState->getState() << endl;
//    cout << from2->getState() << endl; //need to be 3
//
//    //CacheManager<string, int> *ch = new FileCacheManager<string, int>("test.txt", 2);
//    CacheManager<string, string> *cacheManager = new FileCacheManager<string, string>(
//            "/home/chagit/CLionProjects/Project22/testFile", "check");
//    cacheManager->saveSolution("problem1", "solution1");
//    cacheManager->saveSolution("problem2", "solution2");
//    if (cacheManager->isSolutionExist("problem1") == true) {
//        cout << "solution from cache is " << cacheManager->getSolution("problem1") << endl;
//    }
//    if (cacheManager->isSolutionExist("problem2") == true) {
//        cout << "solution from cache is " << cacheManager->getSolution("problem2") << endl;
//    }
//
    MySerialServer *d = new MySerialServer();
    ISearchable<Point> * mat = new Matrix();
    Solver<ISearchable<Point>*, string> *matrixR = new SolverBestSearch<Point>();
    CacheManager<ISearchable<Point>*, string> *cacheManager = new FileCacheManager<ISearchable<Point>*, string>(
            "/home/chagit/CLionProjects/Project22/testFile", mat);
    ClientHandler *ds = new MyClientHandler<ISearchable<Point>*, string>(matrixR, cacheManager);
    d->open(5400, ds);

    //************for solver string revrse***********

//    Solver<string, string> *stringR = new StringReverser();
//    string stProb = "hello"; //problem
//    string stSol;
//
//    //check if solution exist
//    if (cacheManager->isSolutionExist(stProb) == false) {
//        cout << "SOLUTION NOT EXIST - SOLVING" << endl;
//        stSol = stringR->solve(stProb); //solution
//        cacheManager->saveSolution(stProb, stSol); //save solution of reverse
//    } else {
//        //get the solution
//        cout << "THE solution found in the cache is " << cacheManager->getSolution(stProb) << endl;
//    }

    while (true) {}
    return 0;
}