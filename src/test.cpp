#include <gtest/gtest.h>

#include "Student.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
// Expect two strings not to be equal.
EXPECT_STRNE("hello", "world");
// Expect equality.
EXPECT_EQ(7 * 6, 42);
// Expect true.
EXPECT_TRUE(true);
}

TEST(StudentClassTest, getDataTest) {
    Student student("NAME",
                    "SURNAME",
                    "ST. STREET HOMENUM",
                    "CITY",
                    "yyyyMMdd",
                    "012345678901",
                    Gender::Male,
                    "012345",
                    "FACULTY",
                    "FIELD",
                    1);

    EXPECT_EQ(student.getName(), "NAME");
    EXPECT_EQ(student.getLastName(), "SURNAME");
    EXPECT_EQ(student.getAddress(), "ST. STREET HOMENUM");
    EXPECT_EQ(student.getCity(), "CITY");
    EXPECT_EQ(student.getBirthday(), "yyyyMMdd");
    EXPECT_EQ(student.getPesel(), "012345678901");
    EXPECT_EQ(student.getGender(), "Male");
    EXPECT_EQ(student.getIndexNumber(), "012345");
    EXPECT_EQ(student.getFaculty(), "FACULTY");
    EXPECT_EQ(student.getFieldOfStudy(), "FIELD");
    EXPECT_EQ(student.getCurrentSemester(), "1");
}

