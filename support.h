#ifndef ONE_HEADER
#define ONE_HEADER

#define NIL NULL

enum oneTag {
    TAG_CHAR, TAG_INT, TAG_LIST, TAG_STRING
};

struct oneList {
    struct oneValue *node;
    struct oneList *next;
};

struct oneValue {
    enum oneTag tag;
    union {
        char charValue;
        int intValue;
        struct {
            struct oneList *listValueFirst;
            struct oneList *listValueLast;
        };
        char *stringValue; // optimization; strings are lists of chars
    };
};

struct oneValue *oneNewChar(char c);
struct oneValue *oneNewInt(int i);
struct oneValue *oneNewList(void);
void oneAppend(struct oneValue *list, struct oneValue *item);

struct oneValue *oneMatchInt(int i);
struct oneValue *oneMatchString(char *s);
void oneEnterList(void);
void oneLeaveList(void);

extern struct oneValue *oneInput;

#endif
