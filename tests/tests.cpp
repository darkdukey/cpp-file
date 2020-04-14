#include "FileUtil.h"
#include "gtest/gtest.h"

using namespace std;
using namespace NT::FileUtil;

// Setup test
class UtilTest : public ::testing::Test {
   protected:
    UtilTest() {}
    ~UtilTest() override {}
};

TEST_F(UtilTest, File_Name) {
    auto filename = getFileName("hello\\test\\test.txt");
    EXPECT_EQ(filename, "test.txt");

    filename = getFileName("hello/test/test2.txt");
    EXPECT_EQ(filename, "test2.txt");

    filename = getFileName("");
    EXPECT_EQ(filename, "");

    auto file_ext = getExtension("hello\\test\\test.txt");
    EXPECT_EQ(file_ext, "txt");
}

TEST_F(UtilTest, File_Read) {
    string file_path = "../tests/data/test1.txt";
    auto content = readFile(file_path);
    EXPECT_EQ(content, "test is test1.txt");

    vector<unsigned char> data;
    bool result = loadFile(file_path, data);

    EXPECT_EQ(data.size(), 17);
    EXPECT_EQ(data[0], 't');
}

TEST_F(UtilTest, File_Path) {
    string path_a = "../tests/";
    string path_b = "data";
    string path_c = join(path_a, path_b);
    EXPECT_EQ(path_c, "../tests/data");

    path_a = "../tests";
    path_b = "data";
    path_c = join(path_a, path_b);
    EXPECT_EQ(path_c, "../tests/data");
}
