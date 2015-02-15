/**
 * Params
 */

var params = {
	stackSize: 100
};

/**
 * Program
 */

var getTypes = getTypesFn();
var getOps   = getOpsFn();

var i;

for (i = 0; i < params.stackSize; i++) {
  var type = getTypes()[Math.round((Math.random() * 100) % (getTypes().length - 1))];
  var val = Math.random() * type.max + type.min;
  if (type.round) { val = Math.floor(val); }
  else {
	  if (String(val).indexOf('.') == -1) {
		  val = val + '.0';
	  }
  }
  console.log('push ' + type.name + '(' + val + ')');
}

console.log('');

for (i = 0; i < params.stackSize - 1; i++) {
	console.log(getOps()[Math.round(Math.random() * 100) % (getOps().length - 1)].name);
}

console.log('dump');
console.log('exit');

/**
 * Functions
 */

function getTypesFn () {
	var types = [
		{
			name  : "int8",
			max   : 127,
			min   : -128,
			round : true
		},
		{
			name  : "int16",
			max   : 32767,
			min   : -32768,
			round : true
		},
		{
			name  : "int32",
			max   : 2147483647,
			min   : -2147483648,
			round : true
		},
		{
			name : "float",
			max  : 3400000000000000,
			min  : 0.0000034
		},
		{
			name : "double",
			max  : 3400000000000000,
			min  : 0.0000034
		}
	];
	return function () {
		return types;
	};
}

function getOpsFn () {
	var ops = [
		{
			name : "pop"
		},
		{
			name : "mul"
		},
		{
			name : "div"
		},
		{
			name : "add"
		},
		{
			name : "sub"
		}
	];
	return function () {
		return ops;
	};
}
