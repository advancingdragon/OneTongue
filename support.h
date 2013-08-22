#ifndef ONE_HEADER
#define ONE_HEADER

#define NIL NULL

enum oneTag {
    TAG_CHAR, TAG_INT, TAG_LIST
};

struct oneListNode {
    struct oneValue *value;
    struct oneListNode *next;
};

struct oneValue {
    enum oneTag tag;
    union {
        char charValue;
        int intValue;
        struct {
            struct oneListNode *listValueFirst;
            struct oneListNode *listValueLast;
        };
    };
};

struct oneValue *oneNewChar(char c);
struct oneValue *oneNewInt(int i);
struct oneValue *oneNewList(void);
void oneAppend(struct oneValue *list, struct oneValue *value);

void onePrint(struct oneValue *value);

struct oneValue *oneMatchChar(char c);
struct oneValue *oneMatchInt(int i);
struct oneValue *oneMatchString(char *s);

struct oneValue *oneMul(struct oneValue *x, struct oneValue *y);
struct oneValue *oneDiv(struct oneValue *x, struct oneValue *y);
struct oneValue *oneMod(struct oneValue *x, struct oneValue *y);
struct oneValue *oneAdd(struct oneValue *x, struct oneValue *y);
struct oneValue *oneSub(struct oneValue *x, struct oneValue *y);
struct oneValue *oneConcat(struct oneValue *x, struct oneValue *y);
struct oneValue *oneEq(struct oneValue *x, struct oneValue *y);
struct oneValue *oneNe(struct oneValue *x, struct oneValue *y);
struct oneValue *oneLt(struct oneValue *x, struct oneValue *y);
struct oneValue *oneGt(struct oneValue *x, struct oneValue *y);
struct oneValue *oneLe(struct oneValue *x, struct oneValue *y);
struct oneValue *oneGe(struct oneValue *x, struct oneValue *y);
struct oneValue *oneAnd(struct oneValue *x, struct oneValue *y);
struct oneValue *oneOr(struct oneValue *x, struct oneValue *y);

extern struct oneValue *oneInput;
extern struct oneListNode *oneCurrentNode;

#endif
