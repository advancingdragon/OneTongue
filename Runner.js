// these two lines are required by every file that uses OMeta
fs = require('fs');
eval(fs.readFileSync(__dirname + "/OMetaLoader.js", 'utf8'));

loadOMeta("OneTongue.txt");
loadOMeta("OneTranslator.txt");

var tree = OneTongue.matchAll("foo | bar baz \"quux\" 'wang' {dongs 3 4}", "expr");
var code = OneTranslator.match(tree, "doIt");

console.log(JSON.stringify(tree));
console.log();
console.log(code);
