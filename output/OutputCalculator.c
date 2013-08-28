#include "../support.h"
#include <stdlib.h>

struct oneValue *oneDigit(void);
struct oneValue *oneNumber(void);
struct oneValue *oneRelOp(void);
struct oneValue *oneAddOp(void);
struct oneValue *oneMulOp(void);
struct oneValue *oneComp(void);
struct oneValue *oneExpr(void);
struct oneValue *oneTerm(void);
struct oneValue *oneFactor(void);
struct oneValue *oneListExpr(void);
struct oneValue *oneDigit(void)
{
struct oneListNode *vn0;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
vRes = oneMatchChar('0');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('1');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('2');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('3');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('4');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('5');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('6');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('7');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('8');
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
vRes = oneMatchChar('9');
} while (0);
return vRes;
}

struct oneValue *oneNumber(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *cs;
struct oneValue *vRes;
do {
vRes = oneNewList();
do {
v0 = oneMatchString(" ");
if (v0 == NIL) { break; }
oneAppend(vRes, v0);
} while (1);
if (vRes == NIL) { break; }
v1 = oneDigit();
if (v1 == NIL) {
cs = NIL;
} else {
cs = oneNewList();
oneAppend(cs, v1);
do {
v1 = oneDigit();
if (v1 == NIL) { break; }
oneAppend(cs, v1);
} while (1);
}
vRes = cs;
if (vRes == NIL) { break; }
v3 = cs;
vRes = oneToInt(v3);
} while (0);
return vRes;
}

struct oneValue *oneRelOp(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneValue *v6;
struct oneValue *v7;
struct oneValue *v8;
struct oneValue *v9;
struct oneValue *v10;
struct oneValue *v11;
struct oneListNode *vn0;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
do {
vRes = oneToken("==");
if (vRes == NIL) { break; }
v0 = oneNewList();
v1 = oneNewChar('e');
oneAppend(v0, v1);
v1 = oneNewChar('q');
oneAppend(v0, v1);
vRes = v0;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken("<>");
if (vRes == NIL) { break; }
v2 = oneNewList();
v3 = oneNewChar('n');
oneAppend(v2, v3);
v3 = oneNewChar('e');
oneAppend(v2, v3);
vRes = v2;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken("<=");
if (vRes == NIL) { break; }
v4 = oneNewList();
v5 = oneNewChar('l');
oneAppend(v4, v5);
v5 = oneNewChar('e');
oneAppend(v4, v5);
vRes = v4;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken(">=");
if (vRes == NIL) { break; }
v6 = oneNewList();
v7 = oneNewChar('g');
oneAppend(v6, v7);
v7 = oneNewChar('e');
oneAppend(v6, v7);
vRes = v6;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken("<");
if (vRes == NIL) { break; }
v8 = oneNewList();
v9 = oneNewChar('l');
oneAppend(v8, v9);
v9 = oneNewChar('t');
oneAppend(v8, v9);
vRes = v8;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken(">");
if (vRes == NIL) { break; }
v10 = oneNewList();
v11 = oneNewChar('g');
oneAppend(v10, v11);
v11 = oneNewChar('t');
oneAppend(v10, v11);
vRes = v10;
} while (0);
} while (0);
return vRes;
}

struct oneValue *oneAddOp(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneListNode *vn0;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
do {
vRes = oneToken("+");
if (vRes == NIL) { break; }
v0 = oneNewList();
v1 = oneNewChar('a');
oneAppend(v0, v1);
v1 = oneNewChar('d');
oneAppend(v0, v1);
v1 = oneNewChar('d');
oneAppend(v0, v1);
vRes = v0;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken("-");
if (vRes == NIL) { break; }
v2 = oneNewList();
v3 = oneNewChar('s');
oneAppend(v2, v3);
v3 = oneNewChar('u');
oneAppend(v2, v3);
v3 = oneNewChar('b');
oneAppend(v2, v3);
vRes = v2;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken("or");
if (vRes == NIL) { break; }
v4 = oneNewList();
v5 = oneNewChar('o');
oneAppend(v4, v5);
v5 = oneNewChar('r');
oneAppend(v4, v5);
vRes = v4;
} while (0);
} while (0);
return vRes;
}

struct oneValue *oneMulOp(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneListNode *vn0;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
do {
vRes = oneToken("*");
if (vRes == NIL) { break; }
v0 = oneNewList();
v1 = oneNewChar('m');
oneAppend(v0, v1);
v1 = oneNewChar('u');
oneAppend(v0, v1);
v1 = oneNewChar('l');
oneAppend(v0, v1);
vRes = v0;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken("/");
if (vRes == NIL) { break; }
v2 = oneNewList();
v3 = oneNewChar('d');
oneAppend(v2, v3);
v3 = oneNewChar('i');
oneAppend(v2, v3);
v3 = oneNewChar('v');
oneAppend(v2, v3);
vRes = v2;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken("and");
if (vRes == NIL) { break; }
v4 = oneNewList();
v5 = oneNewChar('a');
oneAppend(v4, v5);
v5 = oneNewChar('n');
oneAppend(v4, v5);
v5 = oneNewChar('d');
oneAppend(v4, v5);
vRes = v4;
} while (0);
} while (0);
return vRes;
}

struct oneValue *oneComp(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneValue *x;
struct oneValue *op;
struct oneValue *y;
struct oneValue *vRes;
do {
x = oneExpr();
vRes = x;
if (vRes == NIL) { break; }
vRes = oneNewList();
do {
do {
op = oneRelOp();
v1 = op;
if (v1 == NIL) { break; }
y = oneExpr();
v1 = y;
if (v1 == NIL) { break; }
v4 = oneNewList();
v5 = op;
oneAppend(v4, v5);
v5 = x;
oneAppend(v4, v5);
v5 = y;
oneAppend(v4, v5);
x = v4;
v1 = x;
} while (0);
if (v1 == NIL) { break; }
oneAppend(vRes, v1);
} while (1);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
return vRes;
}

struct oneValue *oneExpr(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneValue *v6;
struct oneValue *v7;
struct oneValue *v8;
struct oneValue *v9;
struct oneValue *v10;
struct oneValue *v11;
struct oneValue *v12;
struct oneValue *v13;
struct oneValue *v14;
struct oneValue *v15;
struct oneListNode *vn0;
struct oneValue *x;
struct oneValue *op;
struct oneValue *y;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
do {
vRes = oneToken("-");
if (vRes == NIL) { break; }
x = oneTerm();
vRes = x;
if (vRes == NIL) { break; }
v1 = oneNewList();
v3 = oneNewList();
v4 = oneNewChar('n');
oneAppend(v3, v4);
v4 = oneNewChar('e');
oneAppend(v3, v4);
v4 = oneNewChar('g');
oneAppend(v3, v4);
v2 = v3;
oneAppend(v1, v2);
v2 = x;
oneAppend(v1, v2);
x = v1;
vRes = x;
if (vRes == NIL) { break; }
vRes = oneNewList();
do {
do {
op = oneAddOp();
v5 = op;
if (v5 == NIL) { break; }
y = oneTerm();
v5 = y;
if (v5 == NIL) { break; }
v8 = oneNewList();
v9 = op;
oneAppend(v8, v9);
v9 = x;
oneAppend(v8, v9);
v9 = y;
oneAppend(v8, v9);
x = v8;
v5 = x;
} while (0);
if (v5 == NIL) { break; }
oneAppend(vRes, v5);
} while (1);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
x = oneTerm();
vRes = x;
if (vRes == NIL) { break; }
vRes = oneNewList();
do {
do {
op = oneAddOp();
v11 = op;
if (v11 == NIL) { break; }
y = oneTerm();
v11 = y;
if (v11 == NIL) { break; }
v14 = oneNewList();
v15 = op;
oneAppend(v14, v15);
v15 = x;
oneAppend(v14, v15);
v15 = y;
oneAppend(v14, v15);
x = v14;
v11 = x;
} while (0);
if (v11 == NIL) { break; }
oneAppend(vRes, v11);
} while (1);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
} while (0);
return vRes;
}

struct oneValue *oneTerm(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneValue *x;
struct oneValue *op;
struct oneValue *y;
struct oneValue *vRes;
do {
x = oneFactor();
vRes = x;
if (vRes == NIL) { break; }
vRes = oneNewList();
do {
do {
op = oneMulOp();
v1 = op;
if (v1 == NIL) { break; }
y = oneFactor();
v1 = y;
if (v1 == NIL) { break; }
v4 = oneNewList();
v5 = op;
oneAppend(v4, v5);
v5 = x;
oneAppend(v4, v5);
v5 = y;
oneAppend(v4, v5);
x = v4;
v1 = x;
} while (0);
if (v1 == NIL) { break; }
oneAppend(vRes, v1);
} while (1);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
return vRes;
}

struct oneValue *oneFactor(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneListNode *vn0;
struct oneValue *x;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
vRes = oneNumber();
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
vRes = oneToken("(");
if (vRes == NIL) { break; }
x = oneComp();
vRes = x;
if (vRes == NIL) { break; }
vRes = oneToken(")");
if (vRes == NIL) { break; }
vRes = x;
} while (0);
} while (0);
return vRes;
}

struct oneValue *oneListExpr(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneValue *v6;
struct oneValue *v7;
struct oneValue *v8;
struct oneValue *v9;
struct oneValue *v10;
struct oneValue *v11;
struct oneValue *v12;
struct oneValue *v13;
struct oneValue *v14;
struct oneValue *v15;
struct oneValue *v16;
struct oneValue *v17;
struct oneValue *v18;
struct oneValue *v19;
struct oneValue *v20;
struct oneValue *v21;
struct oneValue *v22;
struct oneValue *v23;
struct oneValue *v24;
struct oneValue *v25;
struct oneValue *v26;
struct oneValue *v27;
struct oneValue *v28;
struct oneValue *v29;
struct oneValue *v30;
struct oneValue *v31;
struct oneValue *v32;
struct oneValue *v33;
struct oneValue *v34;
struct oneValue *v35;
struct oneValue *v36;
struct oneValue *v37;
struct oneValue *v38;
struct oneValue *v39;
struct oneValue *v40;
struct oneValue *v41;
struct oneValue *v42;
struct oneValue *v43;
struct oneValue *v44;
struct oneValue *v45;
struct oneValue *v46;
struct oneValue *v47;
struct oneValue *v48;
struct oneValue *v49;
struct oneValue *v50;
struct oneValue *v51;
struct oneValue *v52;
struct oneValue *v53;
struct oneValue *v54;
struct oneValue *v55;
struct oneValue *v56;
struct oneValue *v57;
struct oneValue *v58;
struct oneValue *v59;
struct oneValue *v60;
struct oneValue *v61;
struct oneValue *v62;
struct oneValue *v63;
struct oneValue *v64;
struct oneValue *v65;
struct oneListNode *vn0;
struct oneListNode *vn1;
struct oneListNode *vn2;
struct oneListNode *vn3;
struct oneListNode *vn4;
struct oneListNode *vn5;
struct oneListNode *vn6;
struct oneListNode *vn7;
struct oneListNode *vn8;
struct oneListNode *vn9;
struct oneListNode *vn10;
struct oneListNode *vn11;
struct oneListNode *vn12;
struct oneListNode *vn13;
struct oneListNode *vn14;
struct oneListNode *vn15;
struct oneListNode *vn16;
struct oneListNode *vn17;
struct oneListNode *vn18;
struct oneListNode *vn19;
struct oneListNode *vn20;
struct oneListNode *vn21;
struct oneListNode *vn22;
struct oneValue *x;
struct oneValue *y;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
vRes = oneInt();
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v1 = oneInput;
vn1 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v2 = oneInput;
vn2 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("neg");
oneInput = v2;
if (vRes == NIL) {
oneCurrentNode = vn2;
} else {
oneCurrentNode = vn2->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
} while (0);
oneInput = v1;
if (vRes == NIL) {
oneCurrentNode = vn1;
} else {
oneCurrentNode = vn1->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v4 = x;
vRes = oneNeg(v4);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v6 = oneInput;
vn3 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v7 = oneInput;
vn4 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("mul");
oneInput = v7;
if (vRes == NIL) {
oneCurrentNode = vn4;
} else {
oneCurrentNode = vn4->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v6;
if (vRes == NIL) {
oneCurrentNode = vn3;
} else {
oneCurrentNode = vn3->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v10 = x;
v11 = y;
vRes = oneMul(v10, v11);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v12 = oneInput;
vn5 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v13 = oneInput;
vn6 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("div");
oneInput = v13;
if (vRes == NIL) {
oneCurrentNode = vn6;
} else {
oneCurrentNode = vn6->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v12;
if (vRes == NIL) {
oneCurrentNode = vn5;
} else {
oneCurrentNode = vn5->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v16 = x;
v17 = y;
vRes = oneDiv(v16, v17);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v18 = oneInput;
vn7 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v19 = oneInput;
vn8 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("add");
oneInput = v19;
if (vRes == NIL) {
oneCurrentNode = vn8;
} else {
oneCurrentNode = vn8->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v18;
if (vRes == NIL) {
oneCurrentNode = vn7;
} else {
oneCurrentNode = vn7->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v22 = x;
v23 = y;
vRes = oneAdd(v22, v23);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v24 = oneInput;
vn9 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v25 = oneInput;
vn10 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("sub");
oneInput = v25;
if (vRes == NIL) {
oneCurrentNode = vn10;
} else {
oneCurrentNode = vn10->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v24;
if (vRes == NIL) {
oneCurrentNode = vn9;
} else {
oneCurrentNode = vn9->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v28 = x;
v29 = y;
vRes = oneSub(v28, v29);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v30 = oneInput;
vn11 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v31 = oneInput;
vn12 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("eq");
oneInput = v31;
if (vRes == NIL) {
oneCurrentNode = vn12;
} else {
oneCurrentNode = vn12->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v30;
if (vRes == NIL) {
oneCurrentNode = vn11;
} else {
oneCurrentNode = vn11->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v34 = x;
v35 = y;
vRes = oneEq(v34, v35);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v36 = oneInput;
vn13 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v37 = oneInput;
vn14 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("ne");
oneInput = v37;
if (vRes == NIL) {
oneCurrentNode = vn14;
} else {
oneCurrentNode = vn14->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v36;
if (vRes == NIL) {
oneCurrentNode = vn13;
} else {
oneCurrentNode = vn13->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v40 = x;
v41 = y;
vRes = oneNe(v40, v41);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v42 = oneInput;
vn15 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v43 = oneInput;
vn16 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("le");
oneInput = v43;
if (vRes == NIL) {
oneCurrentNode = vn16;
} else {
oneCurrentNode = vn16->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v42;
if (vRes == NIL) {
oneCurrentNode = vn15;
} else {
oneCurrentNode = vn15->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v46 = x;
v47 = y;
vRes = oneLe(v46, v47);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v48 = oneInput;
vn17 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v49 = oneInput;
vn18 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("ge");
oneInput = v49;
if (vRes == NIL) {
oneCurrentNode = vn18;
} else {
oneCurrentNode = vn18->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v48;
if (vRes == NIL) {
oneCurrentNode = vn17;
} else {
oneCurrentNode = vn17->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v52 = x;
v53 = y;
vRes = oneGe(v52, v53);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v54 = oneInput;
vn19 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v55 = oneInput;
vn20 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("lt");
oneInput = v55;
if (vRes == NIL) {
oneCurrentNode = vn20;
} else {
oneCurrentNode = vn20->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v54;
if (vRes == NIL) {
oneCurrentNode = vn19;
} else {
oneCurrentNode = vn19->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v58 = x;
v59 = y;
vRes = oneLt(v58, v59);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v60 = oneInput;
vn21 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
do {
if (oneCurrentNode->value->tag == TAG_LIST) {
v61 = oneInput;
vn22 = oneCurrentNode;
oneInput = oneCurrentNode->value;
oneCurrentNode = oneInput->listValueFirst;
vRes = oneMatchString("gt");
oneInput = v61;
if (vRes == NIL) {
oneCurrentNode = vn22;
} else {
oneCurrentNode = vn22->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
if (vRes == NIL) { break; }
y = oneListExpr();
vRes = y;
} while (0);
oneInput = v60;
if (vRes == NIL) {
oneCurrentNode = vn21;
} else {
oneCurrentNode = vn21->next;
}
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v64 = x;
v65 = y;
vRes = oneGt(v64, v65);
} while (0);
} while (0);
return vRes;
}

