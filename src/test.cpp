#include <gtest/gtest.h>

#include "Student.h"
#include "Database.h"
#include "Interface.h"

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
                              "1");
};

struct DatabaseClassTest : ::testing::Test {
    Database database;
    std::string Aname = "NAME";
    std::string Alastname = "LASTNAME";
    std::string Aaddress = "ST. STREET HOMENUM";
    std::string Acity = "CITY";
    std::string Abirthday = "yyyyMMdd";
    std::string Apesel = "01234567890";
    std::string Agender = "Male";
    std::string AindexNumber = "012345";
    std::string Afaculty = "FACULTY";
    std::string AfieldOfStudy = "FIELD";
    std::string AcurrentSemester = "1";

    std::string Bname = "NAME2";
    std::string Blastname = "LASTNAME2";
    std::string Baddress = "ST. STREET HOMENUM2";
    std::string Bcity = "CITY2";
    std::string Bbirthday = "YYYYmmDD";
    std::string Bpesel = "01234567899";
    std::string Bgender = "Female";
    std::string BindexNumber = "012346";
    std::string Bfaculty = "FACULTY2";
    std::string BfieldOfStudy = "FIELD2";
    std::string BcurrentSemester = "3";
};

struct InterfaceClassTest : ::testing::Test {
    Interface interface;

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
    student.setCurrentSemester("2");
    EXPECT_EQ(student.getCurrentSemester(), "2");
}

TEST_F(StudentClassTest, studentToString) {
    EXPECT_EQ(student.toString(), "NAME LASTNAME 012345678901 yyyyMMdd Male\nST. STREET HOMENUM CITY\n012345 FACULTY FIELD 1");
}



TEST_F(DatabaseClassTest, addStudents) {
    EXPECT_TRUE(database.addStudent(Aname, Alastname, Aaddress, Acity, Abirthday, Apesel, Agender, AindexNumber, Afaculty, AfieldOfStudy, AcurrentSemester));
    EXPECT_TRUE(database.addStudent(Bname, Blastname, Baddress, Bcity, Bbirthday, Bpesel, Bgender, BindexNumber, Bfaculty, BfieldOfStudy, BcurrentSemester));
    EXPECT_FALSE(database.addStudent(Aname, Alastname, Aaddress, Acity, Abirthday, Apesel, Agender, AindexNumber, Afaculty, AfieldOfStudy, AcurrentSemester));
    EXPECT_FALSE(database.addStudent(Bname, Blastname, Baddress, Bcity, Bbirthday, Bpesel, Bgender, BindexNumber, Bfaculty, BfieldOfStudy, BcurrentSemester));
}

TEST_F(DatabaseClassTest, findStudent) {
    database.addStudent(Aname, Alastname, Aaddress, Acity, Abirthday, Apesel, Agender, AindexNumber, Afaculty, AfieldOfStudy, AcurrentSemester);
    database.addStudent(Bname, Blastname, Baddress, Bcity, Bbirthday, Bpesel, Bgender, BindexNumber, Bfaculty, BfieldOfStudy, BcurrentSemester);
    EXPECT_EQ(database.findStudent("01234567890")->getCity(), "CITY");
    EXPECT_EQ(database.findStudent("01234567899")->getCity(), "CITY2");
    EXPECT_EQ(database.findStudent("01234567892"), nullptr);
}

TEST_F(DatabaseClassTest, removeStudent) {
    database.addStudent(Aname, Alastname, Aaddress, Acity, Abirthday, Apesel, Agender, AindexNumber, Afaculty, AfieldOfStudy, AcurrentSemester);
    database.addStudent(Bname, Blastname, Baddress, Bcity, Bbirthday, Bpesel, Bgender, BindexNumber, Bfaculty, BfieldOfStudy, BcurrentSemester);
    EXPECT_TRUE(database.removeStudent("01234567890"));
    EXPECT_TRUE(database.removeStudent("01234567899"));
    EXPECT_FALSE(database.removeStudent("01234567892"));
    EXPECT_FALSE(database.removeStudent("01234567890"));
}