var number = 0;

permutation= function(str,prefix) {
	if(str.length==0){
		console.log(number, prefix);
		number += 1;
		return;
	}
	var rem;
	var i;
	for(i=0;i<str.length;i++){
		var rem = str.substring(0,i)+str.substring(i+1);
		permutation(rem,prefix+str[i], number);
	}
 }

 permutation("012","");
 
