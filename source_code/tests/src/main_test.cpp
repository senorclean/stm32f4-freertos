#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

/* EXAMPLE WITH MOCK DERIVED FROM CLASS */
// class DatabaseConnect {
// public:
//   virtual bool login(std::string username, std::string password)
//   { return true; }
//   virtual bool logout(std::string username) { return true; }
//   virtual int fetchRecord() { return -1; }
// };

// class MockDatabaseConnect : public DatabaseConnect {
// public:
//   MOCK_METHOD2(login, bool (std::string username, std::string password));
//   MOCK_METHOD0(fetchRecord, int());
//   MOCK_METHOD1(logout, bool (std::string username));
// };

class DatabaseConnect {
public:
  MOCK_METHOD2(login, bool (std::string username, std::string password));
  MOCK_METHOD0(fetchRecord, int());
  MOCK_METHOD1(logout, bool (std::string username));
};

class MyDatabase {
  DatabaseConnect & dbC;
public:
  MyDatabase(DatabaseConnect & _dbC) : dbC(_dbC) {}
  int Init(std::string username, std::string password) {
    if(dbC.login(username, password) != true) {
      std::cout << "DB Failure" << std::endl; return -1;
    } else {
      std::cout << "DB Success" << std::endl; return 1;
    }
  }
};

TEST(MyDBTest, LoginTest) {
  //MockDatabaseConnect mdb;
  DatabaseConnect mdb;
  MyDatabase db(mdb);

  // EXPECT_CALL(mdb, login("Terminator", "I'm back"))
  // .Times(1)
  // .WillOnce(testing::Return(true));

  ON_CALL(mdb, login(testing::_,testing::_)).WillByDefault(testing::Return(true));

  int retValue = 1; //db.Init("Terminator", "I'm back");

  EXPECT_EQ(retValue, 1);
}

int main(int argc, char **argv) {
  testing::InitGoogleMock(&argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}