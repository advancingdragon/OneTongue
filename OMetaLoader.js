// this is the TinLizzie version of unescape, which
// is incompatible with the standard unescape

var unescape = function(s) {
    if (s.charAt(0) === "\\") {
        switch (s.charAt(1)) {
        case '"':
            return '"';
        case "'":
            return "'";
        case "\\":
            return "\\";
        case "b":
            return "\b";
        case "f":
            return "\f";
        case "n":
            return "\n";
        case "r":
            return "\r";
        case "t":
            return "\t";
        case "v":
            return "\v";
        case "x":
            return String.fromCharCode(parseInt(s.substring(2, 4), 16));
        case "u":
            return String.fromCharCode(parseInt(s.substring(2, 4), 16));
        default:
            return s.charAt(1);
        }
    } else {
        return s;
    }
};

// fs is already loaded by anyone importing OMetaLoader.js

// var fs = require('fs');

var load = function(file) {
    eval(fs.readFileSync(__dirname + "/ometa/" + file, 'utf8'));
};

load("lib.js");
load("ometa-base.js");
load("parser.js");
load("bs-js-compiler.js");
load("bs-ometa-compiler.js");
load("bs-ometa-optimizer.js");
load("bs-ometa-js-compiler.js");

var translateCode = function(s) {
    var translationError = function(m, i) {
        console.log("Translation error - please tell Alex about this!");
        throw fail;
    };
    var tree = BSOMetaJSParser.matchAll(s, "topLevel", undefined,
    function(m, i) {
        throw objectThatDelegatesTo(fail, {errorPos: i});
    });
    return BSOMetaJSTranslator.match(tree, "trans", undefined, translationError);
};

var ometa = function(s) {
    return eval(translateCode(s));
};

var loadOMeta = function(s) {
    return eval(translateCode(fs.readFileSync(__dirname + "/" + s, 'utf8')));
};
