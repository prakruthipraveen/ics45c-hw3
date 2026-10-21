#ifndef STRING_HPP
#define STRING_HPP

#include <iosfwd>

constexpr int MAXLEN = 1024;

class String {
public: 
	//constructs this string from a C string, defaults to empty string
	explicit String(const char *s = "");

	//construct this string as a copy of string s
	String(const String &s);

	//assignment operator from one string, s, to this string
	String &operator=(const String &s);

	//allow indexing this string with notation s[i]
	char &operator[](int index);

	//returns the logical length of this string (# of chars up to '\0')
	int size() const;

	//returns a reversal of this string, does not modify this string
	String reverse() const;

	//returns index into this string for first occurrence of c
	int indexOf(char c) const;

	//returns index into this string for first occurrence of s
	int indexOf(const String &s) const;

	//relational operators for comparing this string to another string
	bool operator == (const String &s) const;
	bool operator != (const String &s) const;
	bool operator > (const String &s) const;
	bool operator < (const String &s) const;
	bool operator <= (const String &s) const;
	bool operator >= (const String &s) const;

	//concatenate this and s to form a return string
	String operator+(const String &s) const;

	//concatenate s onto the end of this string
	String &operator += (const String &s);

	//print this string
	void print(std::ostream &out);

	//read next word into this string
	void read(std::istream &in);


	//destructor for this string
	~String()

	bool in_bounds(int i) const {
		return i >= 0 && i < strlen(buf);
	}

	static int strlen(const char *s);
	static char *strcopy (char *dest, const char *src);
	static char *strncpy(char *dest, const char *src, int n);
	static char *strcat(char *dest, const char *src);
	static char *strncat(char *dest, const char *src, int n);
	static int strcmp(const char *left, const char *right);
	static int strncmp(const char *left, const char *, int n);
	static void reverse_cpy(char *dest, const char *src);
	static const char *strchr(const char *str, char c);
	static const char *strstr(const char *haystack, const char *needle);

private:
	//array for the characters in this String
	char buf[MAXLEN];

};

std::ostream &operator << (std::ostream &out, const String &s);
std::istream &operator >> (std::istream &in, String &s);
#endif
