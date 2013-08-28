#include "support.h"
#include <stdlib.h>
#include <stdio.h>

struct oneValue *oneInput;
struct oneListNode *oneCurrentNode;

struct oneValue *oneNewChar(char c)
{
    struct oneValue *result;
    result = malloc(sizeof(struct oneValue));
    result->tag = TAG_CHAR;
    result->charValue = c;
    return result;
}

struct oneValue *oneNewInt(int i)
{
    struct oneValue *result;
    result = malloc(sizeof(struct oneValue));
    result->tag = TAG_INT;
    result->intValue = i;
    return result;
}

struct oneValue *oneNewList(void)
{
    struct oneValue *result;
    result = malloc(sizeof(struct oneValue));
    result->tag = TAG_LIST;
    result->listValueFirst = NIL;
    result->listValueLast = NIL;
    return result;
}

void oneAppend(struct oneValue *list, struct oneValue *value)
{
    struct oneListNode *newNode;

    if (list == NIL || value == NIL) {
        return;
    }

    newNode = malloc(sizeof(struct oneListNode));
    newNode->value = value;
    newNode->next = NIL;

    if (list->listValueFirst == NIL && list->listValueLast == NIL) {
        // empty list
        list->listValueFirst = newNode;
        list->listValueLast = newNode;
    } else {
        // list with at least one element
        list->listValueLast->next = newNode;
        list->listValueLast = newNode;
    }
}

void onePrint(struct oneValue *value)
{
    struct oneListNode *node;

    if (value == NIL) {
        printf("NIL");
    } else if (value->tag == TAG_CHAR) {
        printf("'%c'", value->charValue);
    } else if (value->tag == TAG_INT) {
        printf("%d", value->intValue);
    } else if (value->tag == TAG_LIST) {
        printf("[");
        node = value->listValueFirst;
        if (node != NIL) {
            onePrint(node->value);
            node = node->next;
        }
        while (node != NIL) {
            printf(" ");
            onePrint(node->value);
            node = node->next;
        }
        printf("]");
    }
}

// returns the SAME value, as char values are immutable
struct oneValue *oneMatchChar(char c)
{
    struct oneValue *result;

    result = oneChar();
    if (result == NIL) {
        return NIL;
    }
    if (result->charValue != c) {
        return NIL;
    }

    return result;
}

// returns the SAME value, as int values are immutable
struct oneValue *oneMatchInt(int i)
{
    struct oneValue *result;

    result = oneInt();
    if (result == NIL) {
        return NIL;
    }
    if (result->intValue != i) {
        return NIL;
    }

    return result;
}

// returns a NEW value, containing the SAME char values, as
// char values are immutable but list/string values are mutable
struct oneValue *oneMatchString(char *s)
{
    struct oneValue *result;
    int i;

    result = oneNewList();

    for (i = 0; s[i] != '\0'; i++) {
        if (oneCurrentNode == NIL) {
            return NIL;
        }
        if (oneCurrentNode->value == NIL) {
            return NIL;
        }
        if (oneCurrentNode->value->tag != TAG_CHAR) {
            return NIL;
        }
        if (oneCurrentNode->value->charValue != s[i]) {
            return NIL;
        }

        oneAppend(result, oneCurrentNode->value);
        oneCurrentNode = oneCurrentNode->next;
    }
    return result;
}

// TODO add greater flexibility by having oneToken call
// a oneSpaces routine that the user must implement

struct oneValue *oneToken(char *s)
{
    while (oneMatchString(" ") != NIL) {
    }

    return oneMatchString(s);
}

struct oneValue *oneChar(void)
{
    return oneThing(TAG_CHAR);
}

struct oneValue *oneInt(void)
{
    return oneThing(TAG_INT);
}

// returns one of tag

struct oneValue *oneThing(enum oneTag tag)
{
    struct oneValue *result;

    if (oneCurrentNode == NIL) {
        return NIL;
    }
    if (oneCurrentNode->value == NIL) {
        return NIL;
    }
    if (oneCurrentNode->value->tag != tag) {
        return NIL;
    }

    result = oneCurrentNode->value;
    oneCurrentNode = oneCurrentNode->next;
    return result;
}

struct oneValue *oneToInt(struct oneValue *s)
{
    struct oneListNode *node;
    char c;
    int result;

    if (s == NIL) {
        return NIL;
    }
    if (s->tag != TAG_LIST) {
        return NIL;
    }

    result = 0;

    for (node = s->listValueFirst; node != NIL; node = node->next) {
        if (node->value == NIL) {
            return NIL;
        }
        if (node->value->tag != TAG_CHAR) {
            return NIL;
        }
        c = node->value->charValue;
        if (c < '0' || c > '9') {
            return NIL;
        }
        result = result*10 + (c - '0');
    }

    return oneNewInt(result);
}

// oneIf fails if x is zero, otherwise returns x

struct oneValue *oneIf(struct oneValue *x)
{
    if (x == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT) {
        return NIL;
    }
    if (x->intValue == 0) {
        return NIL;
    } else {
        return x;
    }
}

struct oneValue *oneNeg(struct oneValue *x)
{
    if (x == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(-(x->intValue));
}

struct oneValue *oneMul(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue * y->intValue);
}

struct oneValue *oneDiv(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue / y->intValue);
}

struct oneValue *oneMod(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue % y->intValue);
}

struct oneValue *oneAdd(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue + y->intValue);
}

struct oneValue *oneSub(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue - y->intValue);
}

struct oneValue *oneConcat(struct oneValue *x, struct oneValue *y)
{
    return NIL;
}

struct oneValue *oneEq(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue == y->intValue);
}

struct oneValue *oneNe(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue != y->intValue);
}

struct oneValue *oneLt(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue < y->intValue);
}

struct oneValue *oneGt(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue > y->intValue);
}

struct oneValue *oneLe(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue <= y->intValue);
}

struct oneValue *oneGe(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue >= y->intValue);
}

struct oneValue *oneAnd(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue & y->intValue);
}

struct oneValue *oneOr(struct oneValue *x, struct oneValue *y)
{
    if (x == NIL || y == NIL) {
        return NIL;
    }
    if (x->tag != TAG_INT || y->tag != TAG_INT) {
        return NIL;
    }
    return oneNewInt(x->intValue | y->intValue);
}

// stuff to support calculator example

struct oneValue *oneComp(void);
struct oneValue *oneListExpr(void);

int main(int argc, char **argv)
{
    struct oneValue *string;
    struct oneValue *tree;
    int c;

    string = oneNewList();

    while ((c = getchar()) != '\n') {
        oneAppend(string, oneNewChar(c));
    }

    // set stdin input as OneTongue input
    oneInput = string;
    oneCurrentNode = oneInput->listValueFirst;

    tree = oneComp();

    onePrint(tree);
    printf("\n\n");

    // set resulting tree as OneTongue input
    // this is sort of like the difference between matchAll and match
    oneInput = oneNewList();
    oneAppend(oneInput, tree);
    oneCurrentNode = oneInput->listValueFirst;

    onePrint(oneListExpr());
    printf("\n");
}
