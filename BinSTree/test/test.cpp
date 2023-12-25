//
// Created by KAVOSH on 12/25/2023.
//
#include <vector>
#include <iostream>
#include <functional>
#include "test.hpp"
#include "../BinSTree.hpp"




namespace TestBinSTree{

    void printResult(bool t){

        switch(t){
            case true:
                std::cout<<"success"<<std::endl;
                break;
            case false:
                std::cout<<"failed"<<std::endl;
                break;
        }
    }

    bool test_copy_constr(){
        std::cout<<"Start testing copy constructor:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }

        BinSTree<int> t2{t1};

        for(int  x: j) {
            if(!t2.contain(x)){
                return false;
            }
        }
        return true;
    }

    bool test_copy_assign(){
        std::cout<<"Start testing copy assignment:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }

        BinSTree<int> t2;
        t2 = t1;

        bool t{};
        for(int  x: j) {
            if(!t2.contain(x)){
                return false;
            }
        }
        return true;
    }

    bool test_move_constr(){
        std::cout<<"Start testing move constructor:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }

        BinSTree<int> t2{std::move(t1)};

        bool t{true};
        for(int  x: j) {
            if(!t2.contain(x)){
                t = false;
                break;
            }
        }

        return t && t1.isEmpty();
    }

    bool test_move_assign(){
        std::cout<<"Start testing copy assignment:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }

        BinSTree<int> t2;

        t2 = std::move(t1);

        bool t{true};
        for(int  x: j) {
            if(!t2.contain(x)){
                t = false;
                break;
            }
        }

        return t && t1.isEmpty();
    }

    bool test_makeEmpty(){
        std::cout<<"Start testing makeEmpty function:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 4, 3, 2, 22, 55, 455, 333,
                           2, 444, 33,3 ,35, 12, 34, 3 ,
                           2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }

        t1.makeEmpty();


        for(int  x: j) {
            if(t1.contain(x)){
                return false;
            }
        }

        return t1.isEmpty();
    }

    bool test_insert(){
        std::cout<<"Start testing insert function:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,7, 6, 45 , 5, 2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }

        for(int  x: j) {
            if(!t1.contain(x)){
                return false;
            }
        }
        return true;
    }

    bool test_remove(){
        std::cout<<"Start testing remove function:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }


        for(int x: j){
            t1.remove(x);
            if(t1.contain(x)){
                return false;
            }
        }
        return true;
    }

    bool test_contain(){
        std::cout<<"Start testing contain function:"<<std::endl;

        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }


        for(int  x: j) {
            if(!t1.contain(x)){
                return false;
            }
        }

        return true;
    }

    bool test_findMax(){
        std::cout<<"Start testing findMax function:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }
        return t1.findMax() == 1002;
    }

    bool test_findMin(){
        std::cout<<"Start testing findMin function:"<<std::endl;
        BinSTree<int> t1;
        std::vector<int> j{6, 5, 4, 3 ,2 ,1, 100, 1002, 34, 89, 67, 9};

        for(int  x: j){
            t1.insert(x);
        }

        return t1.findMin() == 1;
    }

}