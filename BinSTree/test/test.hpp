//
// Created by KAVOSH on 12/25/2023.
//
#ifndef TREES_TEST_HPP
#define TREES_TEST_HPP

namespace TestBinSTree{
    void printResult(bool t);

    bool test_copy_constr();

    bool test_copy_assign();

    bool test_move_constr();

    bool test_move_assign();

    bool test_makeEmpty();

    bool test_insert();

    bool test_remove();

    bool test_contain();

    bool test_findMax();

    bool test_findMin();

    const std::vector<std::function<bool()>> testFuncs{test_contain,
                                                       test_insert,
                                                       test_remove,
                                                       test_move_constr,
                                                       test_findMax,
                                                       test_findMin,
                                                       test_makeEmpty,
                                                       test_copy_assign,
                                                       test_move_assign,
                                                       test_copy_constr};
}

#endif //TREES_TEST_HPP
