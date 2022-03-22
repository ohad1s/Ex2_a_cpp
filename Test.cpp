/**
 * AUTHOR: Ohad Shirazi
 * Date: 21-3-2022
 */
#include "doctest.h"
#include "Notebook.hpp"
#include <string>
#include <algorithm>

using namespace ariel;

TEST_CASE ("bad col") {
    Notebook notebook1;
    CHECK_THROWS(notebook1.write(/*page=*/100, /*row=*/99, /*column=*/101, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook1.write(/*page=*/100, /*row=*/99, /*column=*/-10, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook1.write(/*page=*/100, /*row=*/99, /*column=*/-101, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook1.write(/*page=*/100, /*row=*/-99, /*column=*/-10, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook1.write(/*page=*/100, /*row=*/99, /*column=*/101, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook1.write(/*page=*/100, /*row=*/99, /*column=*/-10, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook1.write(/*page=*/100, /*row=*/99, /*column=*/-101, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook1.write(/*page=*/100, /*row=*/-99, /*column=*/-10, Direction::Vertical, "xyz"));
}

TEST_CASE ("bad row") {
    Notebook notebook2;
    CHECK_THROWS(notebook2.write(/*page=*/100, /*row=*/-10, /*column=*/101, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook2.write(/*page=*/100, /*row=*/-5, /*column=*/-10, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook2.write(/*page=*/100, /*row=*/-10, /*column=*/100, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook2.write(/*page=*/100, /*row=*/-5, /*column=*/10, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook2.write(/*page=*/100, /*row=*/-10, /*column=*/101, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook2.write(/*page=*/100, /*row=*/-5, /*column=*/-10, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook2.write(/*page=*/100, /*row=*/-10, /*column=*/100, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook2.write(/*page=*/100, /*row=*/-5, /*column=*/10, Direction::Vertical, "xyz"));
}

TEST_CASE ("bad write after erase") {
    Notebook notebook5;
    notebook5.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
    notebook5.erase(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical,3);
    CHECK_THROWS(notebook5.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz"));
    notebook5.write(/*page=*/2, /*row=*/2, /*column=*/22, Direction::Vertical, "abc");
    notebook5.erase(/*page=*/2, /*row=*/2, /*column=*/22,Direction::Vertical, 3);
    CHECK_THROWS(notebook5.write(/*page=*/2, /*row=*/2, /*column=*/22, Direction::Vertical, "abc"));
    notebook5.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
    notebook5.erase(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical,3);
    CHECK_THROWS(notebook5.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz"));
    notebook5.write(/*page=*/2, /*row=*/2, /*column=*/22, Direction::Vertical, "abc");
    notebook5.erase(/*page=*/2, /*row=*/2, /*column=*/22,Direction::Vertical, 3);
    CHECK_THROWS(notebook5.write(/*page=*/2, /*row=*/2, /*column=*/22, Direction::Vertical, "abc"));
    notebook5.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
    notebook5.erase(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical,3);
    CHECK_THROWS(notebook5.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz"));
    notebook5.write(/*page=*/2, /*row=*/2, /*column=*/22, Direction::Vertical, "abc");
    notebook5.erase(/*page=*/2, /*row=*/2, /*column=*/22,Direction::Vertical, 3);
    CHECK_THROWS(notebook5.write(/*page=*/2, /*row=*/2, /*column=*/22, Direction::Vertical, "abc"));
}

TEST_CASE ("good input") {
    Notebook notebook4;

    notebook4.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
            CHECK(notebook4.read(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, 3) == "xyz");
    notebook4.write(/*page=*/1, /*row=*/1, /*column=*/0, Direction::Horizontal, "abc");
            CHECK(notebook4.read(/*page=*/1, /*row=*/1, /*column=*/0, Direction::Horizontal, 3) == "abc");
    notebook4.write(/*page=*/3, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
            CHECK(notebook4.read(/*page=*/3, /*row=*/99, /*column=*/52, Direction::Vertical, 3) == "xyz");
    notebook4.write(/*page=*/8, /*row=*/7, /*column=*/0, Direction::Horizontal, "abc");
            CHECK(notebook4.read(/*page=*/8, /*row=*/7, /*column=*/0, Direction::Horizontal, 3) == "abc");
    notebook4.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
            CHECK(notebook4.read(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, 3) == "xyz");
    notebook4.write(/*page=*/1, /*row=*/1, /*column=*/0, Direction::Horizontal, "abc");
            CHECK(notebook4.read(/*page=*/1, /*row=*/1, /*column=*/0, Direction::Horizontal, 3) == "abc");
    notebook4.write(/*page=*/3, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
            CHECK(notebook4.read(/*page=*/3, /*row=*/99, /*column=*/52, Direction::Vertical, 3) == "xyz");
    notebook4.write(/*page=*/8, /*row=*/7, /*column=*/0, Direction::Horizontal, "abc");
            CHECK(notebook4.read(/*page=*/8, /*row=*/7, /*column=*/0, Direction::Horizontal, 3) == "abc");
    notebook4.write(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
            CHECK(notebook4.read(/*page=*/100, /*row=*/99, /*column=*/52, Direction::Vertical, 3) == "xyz");
    notebook4.write(/*page=*/1, /*row=*/1, /*column=*/0, Direction::Horizontal, "abc");
            CHECK(notebook4.read(/*page=*/1, /*row=*/1, /*column=*/0, Direction::Horizontal, 3) == "abc");
    notebook4.write(/*page=*/3, /*row=*/99, /*column=*/52, Direction::Vertical, "xyz");
            CHECK(notebook4.read(/*page=*/3, /*row=*/99, /*column=*/52, Direction::Vertical, 3) == "xyz");
    notebook4.write(/*page=*/8, /*row=*/7, /*column=*/0, Direction::Horizontal, "abc");
            CHECK(notebook4.read(/*page=*/8, /*row=*/7, /*column=*/0, Direction::Horizontal, 3) == "abc");


}

