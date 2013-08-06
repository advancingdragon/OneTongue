fs = require('fs');

load = function(file) {
    eval(fs.readFileSync(__dirname + "/ometa/" + file, 'utf8'));
};

load("lib.js");
load("ometa-base.js");
load("parser.js");
load("bs-js-compiler.js");
load("bs-ometa-compiler.js");
load("bs-ometa-optimizer.js");
load("bs-ometa-js-compiler.js");

translateCode = function(s) {
    var translationError = function(m, i) {
        console.log("Translation error - please tell Alex about this!");
        throw fail;
    },
    tree = BSOMetaJSParser.matchAll(s, "topLevel", undefined,
    function(m, i) {
        throw objectThatDelegatesTo(fail, {errorPos: i});
    });
    return BSOMetaJSTranslator.match(tree, "trans", undefined, translationError);
};

ometa = function(s) {
    return eval(translateCode(s));
};

loadOMeta = function(s) {
    return eval(translateCode(fs.readFileSync(__dirname + "/" + s, 'utf8')));
};

loadOMeta("OneTongue.txt");
loadOMeta("OneTranslator.txt");

var tree = OneTongue.matchAll("foo | bar baz {dongs 3 4}", "expr");
var code = OneTranslator.match(tree, "doIt");

console.log(JSON.stringify(tree));

console.log();

// strange, does not support newlines
code = code.split("\\n");
for (var i = 0; i < code.length; i++) {
    console.log(code[i]);
}
