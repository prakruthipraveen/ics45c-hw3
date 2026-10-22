#include "string.hpp"
#include <iostream>
#include <istream>
#include <ostream>

// Static C-string helper functions

int String::strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0') {
		++i;
	}

	return i;
}

char *String::strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}

	dest[i] = '\0';
	return dest;
}


char *String::strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && i < n; ++i) {
        dest[i] = src[i];
    }

    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src)
{
	int i = 0;

	while (dest[i] != '\0') {
		++i;
	}

	int j = 0;

	while (src[j] != '\0') {
		dest[i] = src[j];
		++i;
		++j;
	}

	dest[i] = '\0';
	return dest;
}

char *String::strncat(char *dest, const char *src, int n)
{
	int i = 0;

	while (dest[i] != '\0') {
        ++i;
    }

	int j = 0;

	while (j < n && src[j] != '\0') {
		dest[i] = src[j];
		++i;
		++j;
	}

	dest[i] = '\0';
	return dest;
}

int String::strcmp(const char *left, const char *right)
{
	int i = 0;

	while (left[i] != '\0' && left [i] == right[i]) {
		++i;
	}

	return static_cast<unsigned char>(left[i]) - static_cast<unsigned char>(right[i]);
}

int String::strncmp(const char *left, const char *right, int n)
{
	int i = 0;

	while (i < n && left[i] != '\0' && left[i] == right[i]) {
		++i;
	}

	if (i == n) {
		return 0;
	}

	return static_cast<unsigned char>(left[i]) - static_cast<unsigned char>(right[i]);
}

void String::reverse_cpy(char *dest, const char *src)
{
	int len = 0;

	while (src[len] != '\0') {
		++len;
	}

	for (int i = 0; i < len; ++i) {
		dest[i] = src[len - 1 - i];
	}

	dest[len] = '\0';
}

const char *String::strchr(const char *str, char c)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == c) {
			return str + i;
		}
		++i;
	}

	if (c == '\0') {
		return str + i;
	}

	return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle)
{
	if (needle[0] == '\0') {
		return haystack;
	}

	for (int i = 0; haystack[i] != '\0'; ++i) {
		int j = 0;

		while (needle[j] != '\0' && haystack[i + j] != '\0' && haystack[i + j] == needle[j]) {
			++j;
		}

		if (needle[j] == '\0') {
			return haystack + i;
		}
	}

	return nullptr;
}


// Constructors, assignment operator, and deconstructor
String::String(const char *s)
{
	strncpy(buf, s, MAXLEN - 1);
}

String::String(const String &s)
{
	strcpy(buf, s.buf);
}

String &String::operator=(const String &s)
{
	if (this != &s) {
		strcpy(buf, s.buf);
	}

	return *this;
}

String::~String()
{
}


// Indexing and length
char &String::operator[](int index)
{
	if (!in_bounds(index)) {
		std::cerr << "ERROR: Index Out Of Bounds\n";
		return buf[0];
	}

	return buf[index];
}

int String::size() const
{
	return strlen(buf);
}


// Reversing and searching
String String::reverse() const
{
    String result;
    reverse_cpy(result.buf, buf);
    return result;
}

int String::indexOf(char c) const
{
    const char *result = strchr(buf, c);

    if (result == nullptr) {
        return -1;
    }

    return static_cast<int>(result - buf);
}

int String::indexOf(const String &s) const
{
    const char *result = strstr(buf, s.buf);

    if (result == nullptr) {
        return -1;
    }

    return static_cast<int>(result - buf);
}


// Comparison operators
bool String::operator==(const String &s) const
{
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const
{
    return strcmp(buf, s.buf) != 0;
}

bool String::operator>(const String &s) const
{
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<(const String &s) const
{
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>=(const String &s) const
{
    return strcmp(buf, s.buf) >= 0;
}

bool String::operator<=(const String &s) const
{
    return strcmp(buf, s.buf) <= 0;
}


// Concatenation operators
String String::operator+(const String &s) const
{
    String result(*this);
    result += s;
    return result;
}

String &String::operator+=(const String &s)
{
    int left_len = strlen(buf);
    int right_len = strlen(s.buf);
    int available = MAXLEN - 1 - left_len;

    if (right_len > available) {
        std::cerr << "ERROR: String Capacity Exceeded\n";
    }

    strncat(buf, s.buf, available);

    return *this;
}


// Input and output methods
void String::print(std::ostream &out) const
{
	out << buf;
}

void String::read(std::istream &in)
{
	in.width(MAXLEN);
	in >> buf;
}


// Stream operators
std::ostream &operator<<(std::ostream &out, const String &s)
{
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s)
{
    s.read(in);
    return in;
}


