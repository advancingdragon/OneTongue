#include "../support.c"

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
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneValue *v6;
struct oneValue *x;
struct oneValue *vRes;
do {
x = oneChar();
vRes = x;
if (vRes == NIL) { break; }
v2 = x;
v3 = oneNewChar('0');
v1 = oneGe(v2, v3);
v5 = x;
v6 = oneNewChar('9');
v4 = oneLe(v5, v6);
vRes = oneAnd(v1, v4);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
}

struct oneValue *oneNumber(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *cs;
struct oneValue *vRes;
do {
v0 = oneDigit();
if (v0 == NIL) {
cs = NIL;
} else {
cs = oneNewList();
oneAppend(cs, v0);
do {
v0 = oneDigit();
if (v0 == NIL) { break; }
oneAppend(cs, v0);
} while (0);
}
vRes = cs;
if (vRes == NIL) { break; }
v2 = cs;
vRes = oneToInt(v2);
} while (0);
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
struct oneListNode *vn0;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
do {
v0 = oneNewList();
v1 = oneNewChar('=');
oneAppend(v0, v1);
v1 = oneNewChar('=');
oneAppend(v0, v1);
vRes = oneToken(v0);
if (vRes == NIL) { break; }
vRes = oneNewList();
v3 = oneNewChar('e');
oneAppend(vRes, v3);
v3 = oneNewChar('q');
oneAppend(vRes, v3);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v4 = oneNewList();
v5 = oneNewChar('<');
oneAppend(v4, v5);
v5 = oneNewChar('>');
oneAppend(v4, v5);
vRes = oneToken(v4);
if (vRes == NIL) { break; }
vRes = oneNewList();
v7 = oneNewChar('n');
oneAppend(vRes, v7);
v7 = oneNewChar('e');
oneAppend(vRes, v7);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v8 = oneNewList();
v9 = oneNewChar('<');
oneAppend(v8, v9);
v9 = oneNewChar('=');
oneAppend(v8, v9);
vRes = oneToken(v8);
if (vRes == NIL) { break; }
vRes = oneNewList();
v11 = oneNewChar('l');
oneAppend(vRes, v11);
v11 = oneNewChar('e');
oneAppend(vRes, v11);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v12 = oneNewList();
v13 = oneNewChar('>');
oneAppend(v12, v13);
v13 = oneNewChar('=');
oneAppend(v12, v13);
vRes = oneToken(v12);
if (vRes == NIL) { break; }
vRes = oneNewList();
v15 = oneNewChar('g');
oneAppend(vRes, v15);
v15 = oneNewChar('e');
oneAppend(vRes, v15);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v16 = oneNewList();
v17 = oneNewChar('<');
oneAppend(v16, v17);
vRes = oneToken(v16);
if (vRes == NIL) { break; }
vRes = oneNewList();
v19 = oneNewChar('l');
oneAppend(vRes, v19);
v19 = oneNewChar('t');
oneAppend(vRes, v19);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v20 = oneNewList();
v21 = oneNewChar('>');
oneAppend(v20, v21);
vRes = oneToken(v20);
if (vRes == NIL) { break; }
vRes = oneNewList();
v23 = oneNewChar('g');
oneAppend(vRes, v23);
v23 = oneNewChar('t');
oneAppend(vRes, v23);
} while (0);
} while (0);
}

struct oneValue *oneAddOp(void)
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
v0 = oneNewList();
v1 = oneNewChar('+');
oneAppend(v0, v1);
vRes = oneToken(v0);
if (vRes == NIL) { break; }
vRes = oneNewList();
v3 = oneNewChar('a');
oneAppend(vRes, v3);
v3 = oneNewChar('d');
oneAppend(vRes, v3);
v3 = oneNewChar('d');
oneAppend(vRes, v3);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v4 = oneNewList();
v5 = oneNewChar('-');
oneAppend(v4, v5);
vRes = oneToken(v4);
if (vRes == NIL) { break; }
vRes = oneNewList();
v7 = oneNewChar('s');
oneAppend(vRes, v7);
v7 = oneNewChar('u');
oneAppend(vRes, v7);
v7 = oneNewChar('b');
oneAppend(vRes, v7);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v8 = oneNewList();
v9 = oneNewChar('o');
oneAppend(v8, v9);
v9 = oneNewChar('r');
oneAppend(v8, v9);
vRes = oneToken(v8);
if (vRes == NIL) { break; }
vRes = oneNewList();
v11 = oneNewChar('o');
oneAppend(vRes, v11);
v11 = oneNewChar('r');
oneAppend(vRes, v11);
} while (0);
} while (0);
}

struct oneValue *oneMulOp(void)
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
v0 = oneNewList();
v1 = oneNewChar('*');
oneAppend(v0, v1);
vRes = oneToken(v0);
if (vRes == NIL) { break; }
vRes = oneNewList();
v3 = oneNewChar('m');
oneAppend(vRes, v3);
v3 = oneNewChar('u');
oneAppend(vRes, v3);
v3 = oneNewChar('l');
oneAppend(vRes, v3);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v4 = oneNewList();
v5 = oneNewChar('/');
oneAppend(v4, v5);
vRes = oneToken(v4);
if (vRes == NIL) { break; }
vRes = oneNewList();
v7 = oneNewChar('d');
oneAppend(vRes, v7);
v7 = oneNewChar('i');
oneAppend(vRes, v7);
v7 = oneNewChar('v');
oneAppend(vRes, v7);
} while (0);
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v8 = oneNewList();
v9 = oneNewChar('a');
oneAppend(v8, v9);
v9 = oneNewChar('n');
oneAppend(v8, v9);
v9 = oneNewChar('d');
oneAppend(v8, v9);
vRes = oneToken(v8);
if (vRes == NIL) { break; }
vRes = oneNewList();
v11 = oneNewChar('a');
oneAppend(vRes, v11);
v11 = oneNewChar('n');
oneAppend(vRes, v11);
v11 = oneNewChar('d');
oneAppend(vRes, v11);
} while (0);
} while (0);
}

struct oneValue *oneComp(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
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
x = oneNewList();
v4 = op;
oneAppend(x, v4);
v4 = x;
oneAppend(x, v4);
v4 = y;
oneAppend(x, v4);
v1 = x;
} while (0);
if (v1 == NIL) { break; }
oneAppend(vRes, v1);
} while (0);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
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
struct oneListNode *vn0;
struct oneValue *x;
struct oneValue *op;
struct oneValue *y;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
do {
v0 = oneNewList();
v1 = oneNewChar('-');
oneAppend(v0, v1);
vRes = oneToken(v0);
if (vRes == NIL) { break; }
x = oneTerm();
vRes = x;
if (vRes == NIL) { break; }
x = oneNewList();
v4 = oneNewList();
v5 = oneNewChar('n');
oneAppend(v4, v5);
v5 = oneNewChar('e');
oneAppend(v4, v5);
v5 = oneNewChar('g');
oneAppend(v4, v5);
oneAppend(x, v4);
v4 = x;
oneAppend(x, v4);
vRes = x;
if (vRes == NIL) { break; }
vRes = oneNewList();
do {
do {
op = oneAddOp();
v6 = op;
if (v6 == NIL) { break; }
y = oneTerm();
v6 = y;
if (v6 == NIL) { break; }
x = oneNewList();
v9 = op;
oneAppend(x, v9);
v9 = x;
oneAppend(x, v9);
v9 = y;
oneAppend(x, v9);
v6 = x;
} while (0);
if (v6 == NIL) { break; }
oneAppend(vRes, v6);
} while (0);
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
x = oneNewList();
v14 = op;
oneAppend(x, v14);
v14 = x;
oneAppend(x, v14);
v14 = y;
oneAppend(x, v14);
v11 = x;
} while (0);
if (v11 == NIL) { break; }
oneAppend(vRes, v11);
} while (0);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
} while (0);
}

struct oneValue *oneTerm(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
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
x = oneNewList();
v4 = op;
oneAppend(x, v4);
v4 = x;
oneAppend(x, v4);
v4 = y;
oneAppend(x, v4);
v1 = x;
} while (0);
if (v1 == NIL) { break; }
oneAppend(vRes, v1);
} while (0);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
}

struct oneValue *oneFactor(void)
{
struct oneValue *v0;
struct oneValue *v1;
struct oneValue *v2;
struct oneValue *v3;
struct oneValue *v4;
struct oneValue *v5;
struct oneValue *v6;
struct oneValue *v7;
struct oneListNode *vn0;
struct oneValue *x;
struct oneValue *vRes;
vn0 = oneCurrentNode;
do {
vRes = oneNumber();
if (vRes != NIL) { break; }
oneCurrentNode = vn0;
do {
v1 = oneNewList();
v2 = oneNewChar('(');
oneAppend(v1, v2);
vRes = oneToken(v1);
if (vRes == NIL) { break; }
x = oneComp();
vRes = x;
if (vRes == NIL) { break; }
v5 = oneNewList();
v6 = oneNewChar(')');
oneAppend(v5, v6);
vRes = oneToken(v5);
if (vRes == NIL) { break; }
vRes = x;
} while (0);
} while (0);
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
vRes = oneNumber();
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
oneCurrentNode = vn2;
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
x = oneListExpr();
vRes = x;
} while (0);
oneInput = v1;
oneCurrentNode = vn1;
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
oneCurrentNode = vn4;
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
oneCurrentNode = vn3;
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
oneCurrentNode = vn6;
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
oneCurrentNode = vn5;
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
oneCurrentNode = vn8;
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
oneCurrentNode = vn7;
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
oneCurrentNode = vn10;
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
oneCurrentNode = vn9;
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
oneCurrentNode = vn12;
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
oneCurrentNode = vn11;
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
oneCurrentNode = vn14;
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
oneCurrentNode = vn13;
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
oneCurrentNode = vn16;
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
oneCurrentNode = vn15;
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
oneCurrentNode = vn18;
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
oneCurrentNode = vn17;
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
oneCurrentNode = vn20;
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
oneCurrentNode = vn19;
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
oneCurrentNode = vn22;
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
oneCurrentNode = vn21;
} else {
vRes = NIL;
}
if (vRes == NIL) { break; }
v64 = x;
v65 = y;
vRes = oneGt(v64, v65);
} while (0);
} while (0);
}

