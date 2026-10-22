#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
	char result[10];

	EXPECT_EQ(String::strncpy(result, "foo", 10), result);
	EXPECT_STREQ(result, "foo");

	EXPECT_EQ(String::strncpy(result, "hello", 3), result);
    EXPECT_STREQ(result, "hel");

    EXPECT_EQ(String::strncpy(result, "", 5), result);
    EXPECT_STREQ(result, "");

    EXPECT_EQ(String::strncpy(result, "hello", 0), result);
    EXPECT_STREQ(result, "");

    EXPECT_EQ(String::strncpy(result, "hello", 5), result);
    EXPECT_STREQ(result, "hello");

}

TEST(StringFunction, strcat) {
	char result[20] = "foo";

    EXPECT_EQ(String::strcat(result, "bar"), result);
    EXPECT_STREQ(result, "foobar");

    char empty[20] = "";
    EXPECT_EQ(String::strcat(empty, "hello"), empty);
    EXPECT_STREQ(empty, "hello");

    char unchanged[20] = "hello";
    EXPECT_EQ(String::strcat(unchanged, ""), unchanged);
    EXPECT_STREQ(unchanged, "hello");
}

TEST(StringFunction, strncat) {
    char result[20] = "foo";

    EXPECT_EQ(String::strncat(result, "bar", 2), result);
    EXPECT_STREQ(result, "fooba");

    char empty[20] = "";
    EXPECT_EQ(String::strncat(empty, "hello", 3), empty);
    EXPECT_STREQ(empty, "hel");

    char unchanged[20] = "foo";
    EXPECT_EQ(String::strncat(unchanged, "bar", 0), unchanged);
    EXPECT_STREQ(unchanged, "foo");
}

TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("foo", "foo"), 0);

    EXPECT_LT(String::strcmp("abc", "abd"), 0);
    EXPECT_GT(String::strcmp("abd", "abc"), 0);

    EXPECT_LT(String::strcmp("", "a"), 0);
    EXPECT_GT(String::strcmp("a", ""), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("foo", "foo", 3), 0);
    EXPECT_EQ(String::strncmp("foo", "far", 1), 0);

    EXPECT_LT(String::strncmp("abc", "abd", 3), 0);
    EXPECT_GT(String::strncmp("abd", "abc", 3), 0);

    EXPECT_EQ(String::strncmp("foo", "bar", 0), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[20];

    String::reverse_cpy(result, "hello");
    EXPECT_STREQ(result, "olleh");

    String::reverse_cpy(result, "");
    EXPECT_STREQ(result, "");

    String::reverse_cpy(result, "a");
    EXPECT_STREQ(result, "a");
}

TEST(StringFunction, strchr) {
    const char *result = String::strchr("hello", 'e');
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "ello");

    result = String::strchr("hello", 'h');
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "hello");

    EXPECT_EQ(String::strchr("hello", 'z'), nullptr);
    EXPECT_EQ(String::strchr("", 'a'), nullptr);

    // The null terminator is part of a C string.
    result = String::strchr("hello", '\0');
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strstr) {
   const char *result = String::strstr("hello world", "world");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "world");

    result = String::strstr("hello", "ell");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "ello");

    result = String::strstr("hello", "hello");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "hello");

    EXPECT_EQ(String::strstr("hello", "xyz"), nullptr);
    EXPECT_EQ(String::strstr("", "a"), nullptr);

    // An empty pattern is found at the start of the string.
    result = String::strstr("hello", "");
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "hello");
}

