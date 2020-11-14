int main(void){
	func1(1,2,3);

	func2((1,2), 3);

	if (a){
		statement1 = 1;
	}else {
		statement2 = 2;
	}

	if (a){
		statement1 = 1;
	}

	if (a); else {
		statement2 = 2;
	}

	if (a);else;

	while(a){
		statement2 = 2;
	}

	while(a);

	while(a){

	}

	while(a){
		statement1 = 1;
		statement2 = 2;
		statement3 = 3;
	}
	{;}

	{statement1 = 1;}

	{statement1 = 1; statement2 = 2;}

	return 0;
	return ;
}	