// these two lines are required by every file that uses OMeta
fs = require('fs');
eval(fs.readFileSync(__dirname + "/OMetaLoader.js", 'utf8'));

loadOMeta("OneTongue.txt");
loadOMeta("OneTranslator.txt");

var source = fs.readFileSync(__dirname + "/tests/Calculator.txt", 'utf8')
var tree = OneTongue.matchAll(source, "program");
// var code = OneTranslator.match(tree, "doIt");

console.log(tree);
console.log();
console.log(JSON.stringify(tree));
// console.log();
// console.log(code);
