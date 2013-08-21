#include "support.h"
#include <stdlib.h>
#include <stdio.h>

struct oneValue *oneInput;
struct oneListNode *oneCurrentNode;
int oneCurrentStringPos; // used for string optimization

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

    if (oneCurrentNode->value == NIL) {
        return NIL;
    }
    if (oneCurrentNode->value->tag != TAG_CHAR) {
        return NIL;
    }
    if (oneCurrentNode->value->charValue != c) {
        return NIL;
    }

    result = oneCurrentNode->value;
    oneCurrentNode = oneCurrentNode->next;
    return result;
}

// returns the SAME value, as int values are immutable
struct oneValue *oneMatchInt(int i)
{
    struct oneValue *result;

    if (oneCurrentNode->value == NIL) {
        return NIL;
    }
    if (oneCurrentNode->value->tag != TAG_INT) {
        return NIL;
    }
    if (oneCurrentNode->value->intValue != i) {
        return NIL;
    }

    result = oneCurrentNode->value;
    oneCurrentNode = oneCurrentNode->next;
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

void oneEnterList(void)
{
    // TODO
}

void oneLeaveList(void)
{
    // TODO
}

int main(int argc, char **argv)
{
    // just a bunch of test cases

    struct oneValue *testChar;
    struct oneValue *testChar2;
    struct oneValue *testInt;
    struct oneValue *testList;
    struct oneValue *testList2;

    testChar = oneNewChar('w');
    onePrint(testChar);
    printf("\n");

    testChar2 = oneNewChar('*');
    onePrint(testChar2);
    printf("\n");

    testInt = oneNewInt(42);
    onePrint(testInt);
    printf("\n");

    testList = oneNewList();
    oneAppend(testList, testChar);
    oneAppend(testList, testInt);
    oneAppend(testList, testChar);
    onePrint(testList);
    printf("\n");

    testList2 = oneNewList();
    oneAppend(testList2, testInt);
    oneAppend(testList2, testList);
    oneAppend(testList2, testChar2);
    oneAppend(testList2, testChar);
    onePrint(testList2);
    printf("\n");
    return 0;
}
