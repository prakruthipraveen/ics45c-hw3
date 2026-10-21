char *String::strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    for (; src[i] != '\0' && i < n; ++i) {
        dest[i] = src[i];
    }

    dest[i] = '\0';
    return dest;
}

String::String(const char *s)
{
	strncpy(buf, s, MAXLEN - 1);
}


