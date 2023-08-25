#include <gtest/gtest.h>

#include "Student.h"
#include "Database.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
// Expect two strings not to be equal.
EXPECT_STRNE("hello", "world");
// Expect equality.
EXPECT_EQ(7 * 6, 42);
// Expect true.
EXPECT_TRUE(true);
}

struct StudentClassTest : ::testing::Test {
    Student student = Student("NAME",
                              "LASTNAME",
                              "ST. STREET HOMENUM",
                              "CITY",
                              "yyyyMMdd",
                              "012345678901",
                              Gender::Male,
                              "012345",
                              "FACULTY",
                              "FIELD",
                              1);
};

struct DatabaseClassTest : ::testing::Test {
    Database database;
    Student a = Student("NAME",
                              "LASTNAME",
                              "ST. STREET HOMENUM",
                              "CITY",
                              "yyyyMMdd",
                              "012345678901",
                              Gender::Male,
                              "012345",
                              "FACULTY",
                              "FIELD",
                              1);
    Student b = Student("NAME2",
                        "LASTNAME2",
                        "ST. STREET HOMENUM2",
                        "CITY2",
                        "YYYYmmDD",
                        "012345678909",
                        Gender::Female,
                        "012346",
                        "FACULTY2",
                        "FIELD2",
                        3);
};


TEST_F(StudentClassTest, getData) {
    EXPECT_EQ(student.getName(), "NAME");
    EXPECT_EQ(student.getLastName(), "LASTNAME");
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

TEST_F(StudentClassTest, changeData) {
    student.setName("NEWNAME");
    EXPECT_EQ(student.getName(), "NEWNAME");
    student.setLastName("NEWLASTNAME");
    EXPECT_EQ(student.getLastName(), "NEWLASTNAME");
    student.setAddress("NEWST. STREET HOMENUM");
    EXPECT_EQ(student.getAddress(), "NEWST. STREET HOMENUM");
    student.setCity("NEWCITY");
    EXPECT_EQ(student.getCity(), "NEWCITY");
    student.setBirthday("newyyyyMMdd");
    EXPECT_EQ(student.getBirthday(), "newyyyyMMdd");
    student.setPesel("012345678902");
    EXPECT_EQ(student.getPesel(), "012345678902");
    student.setGender(Gender::Female);
    EXPECT_EQ(student.getGender(), "Female");
    student.setIndexNumber("012346");
    EXPECT_EQ(student.getIndexNumber(), "012346");
    student.setFaculty("NEWFACULTY");
    EXPECT_EQ(student.getFaculty(), "NEWFACULTY");
    student.setFieldOfStudy("NEWFIELD");
    EXPECT_EQ(student.getFieldOfStudy(), "NEWFIELD");
    student.setCurrentSemester(2);
    EXPECT_EQ(student.getCurrentSemester(), "2");
}

TEST_F(StudentClassTest, studentToString) {
    EXPECT_EQ(student.toString(), "NAME LASTNAME 012345678901 yyyyMMdd Male\nST. STREET HOMENUM CITY\n012345 FACULTY FIELD 1");
}



TEST_F(DatabaseClassTest, addStudents) {
    EXPECT_TRUE(database.addStudent(&a));
    EXPECT_TRUE(database.addStudent(&b));
    EXPECT_FALSE(database.addStudent(&a));
    EXPECT_FALSE(database.addStudent(&b));
}

TEST_F(DatabaseClassTest, findStudent) {
    database.addStudent(&a);
    database.addStudent(&b);
    EXPECT_EQ(database.findStudent("012345678901"), a.toString());
    EXPECT_EQ(database.findStudent("012345678909"), b.toString());
    EXPECT_EQ(database.findStudent("012345678902"), "Student not found");
}

