// these two lines are required by every file that uses OMeta
fs = require('fs');
eval(fs.readFileSync(__dirname + "/OMetaLoader.js", 'utf8'));

util = require('util');

loadOMeta("OneTongue.txt");
loadOMeta("OneTranslator.txt");

var source = fs.readFileSync(__dirname + "/tests/Calculator.txt", 'utf8')
var tree = OneTongue.matchAll(source, "program");
var code = OneTranslator.match(tree, "program");

// console.log(util.inspect(tree, { depth: null }));
// console.log();
console.log(code);
