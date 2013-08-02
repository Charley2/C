#include "StdAfx.h"
#include "verylong.h"

string operator+(const string sum1, const string sum2) {
	verylong TEMP;
	int i=0, carry=0, max=0, dif;
	string result, temp;
	bool flag=false;
	TEMP.input(sum1, sum2);
	result.clear();
	char sym;
	if (TEMP.count2>TEMP.count1) {
		result=TEMP.number1;
		TEMP.number1.clear();
		TEMP.number1=TEMP.number2;
		TEMP.number2.clear();
		TEMP.number2=result;
		result.clear();
		dif=TEMP.count1;
		TEMP.count1=TEMP.count2;
		TEMP.count2=dif;
		dif=0;
		flag=true;
	}
	if (TEMP.count2==TEMP.count1) {
		for (i=TEMP.count1-1; i>=0; i--) {
			if (int(TEMP.number1[i])<int(TEMP.number2[i])) {
				string temp;
				temp=TEMP.number2;
				TEMP.number2.clear();
				TEMP.number2=TEMP.number1;
				TEMP.number1.clear();
				TEMP.number1=temp;
				temp.clear();
				i=-1;
				flag=true;
			}
		}
	}

//если оба положительные
if ((TEMP.minus1==false && TEMP.minus2==false) || (TEMP.minus1==true && TEMP.minus2==true)) {
	if (TEMP.count1>TEMP.count2 || TEMP.count1==TEMP.count2) {
	   dif=TEMP.count1-TEMP.count2;
	   max=TEMP.count2;
	}
	for (i=0; i<max; i++) {
	result+=char(((int(TEMP.number1[i])-48)+((int(TEMP.number2[i])-48)+carry))%TEMP.base)+48;
	if (((int(TEMP.number1[i])-48)+(int(TEMP.number2[i]-48))+carry)>TEMP.base-1) {
	carry=1;
	} else
		carry=0;
	}
	if (TEMP.count1 != TEMP.count2) {
	for (i=max; i<TEMP.count1; i++) {
	   if (TEMP.count1>TEMP.count2) {
		   result+=char((int(TEMP.number1[i])-48+carry)%TEMP.base)+48;
		   if ((int(TEMP.number1[i])-48+carry)>TEMP.base-1) {
		   carry=1;
		   } else
			   carry=0;
	   }
	}
	}
	if (carry==1) {
		result+=char(carry)+48;
	}
	carry=result.size();
	for (i=0; i<carry/2; i++) {
		sym=result[i];
		result[i]=result[(carry-1)-i];
		result[(carry-1)-i]=sym;
	}
}
if (TEMP.minus1==false && TEMP.minus2==false) {
   if (result.size()==0) {
	  result+="0";
   }
   return result;
}
//если minus1=true и minus2=true
if (TEMP.minus1==true && TEMP.minus2==true) {
	temp=result;
	result.clear();
	result+="-";
	result+=temp;
	if (result.size()==0) {
	  result+="0";
   }
   return result;
}

temp.clear();
if (TEMP.minus1==false && TEMP.minus2==true) {
//если number1>=number2
   if (!flag) {
   TEMP.minus1=false;
   TEMP.minus2=false;
   TEMP.number1=TEMP.reverse(TEMP.number1);
   TEMP.number2=TEMP.reverse(TEMP.number2);
   result=TEMP.number1-TEMP.number2;
   if (result.size()==0) {
	  result+="0";
   }
   return result;
   } else {
	 //иначе
	result.clear();
	TEMP.minus1=false;
	TEMP.minus2=false;
	TEMP.number1=TEMP.reverse(TEMP.number1);
	TEMP.number2=TEMP.reverse(TEMP.number2);
	temp=TEMP.number1-TEMP.number2;
	result+="-";
	result+=temp;
	if (result.size()==0) {
	  result+="0";
   }
   return result;
   }
}

if (TEMP.minus1==true && TEMP.minus2==false) {
//если number1>=number2
   if (!flag) {
   result.clear();
   TEMP.minus1=false;
   TEMP.minus2=false;
   TEMP.number1=TEMP.reverse(TEMP.number1);
   TEMP.number2=TEMP.reverse(TEMP.number2);
   temp=TEMP.number1-TEMP.number2;
   if (temp[0]=='0' && temp.size()==1) { //если 0
	   return temp;
   }
   result+="-";
   result+=temp;
   i=0, carry=0, max=0;
   flag=false;
   if (result.size()==0) {
	  result+="0";
   }
   return result;
   } else {
   //иначе
	 TEMP.minus1=false;
	 TEMP.minus2=false;
	 TEMP.number1=TEMP.reverse(TEMP.number1);
	 TEMP.number2=TEMP.reverse(TEMP.number2);
	 result=TEMP.number1-TEMP.number2;
	 i=0, carry=0, max=0;
		 flag=false;
		 if (result.size()==0) {
		 result+="0";
		 }
	 return result;
	 }
}
}


string operator-(const string num1, const string num2) {
verylong TEMP;
string result, temp;
int i, carry=0, diff=0, min, tmp;
char sym;
bool flag=false;
TEMP.input(num1, num2);

if (TEMP.count2>TEMP.count1) {
		result=TEMP.number1;
		TEMP.number1.clear();
		TEMP.number1=TEMP.number2;
		TEMP.number2.clear();
		TEMP.number2=result;
		result.clear();
		diff=TEMP.count1;
		TEMP.count1=TEMP.count2;
		TEMP.count2=diff;
		diff=0;
		flag=true;
}
   if (TEMP.count1==TEMP.count2) {
   for (i=TEMP.count2-1; i>=0; i--) {
	   if (int(TEMP.number2[i])>int(TEMP.number1[i])) {
	   result=TEMP.number1;
	   TEMP.number1.clear();
	   TEMP.number1=TEMP.number2;
	   TEMP.number2.clear();
	   TEMP.number2=result;
	   result.clear();
	   diff=TEMP.count1;
	   TEMP.count1=TEMP.count2;
	   TEMP.count2=diff;
	   diff=0;
	   i=-1;
	   flag=true;
	   } else {
			if (int(TEMP.number2[i])<int(TEMP.number1[i])) {
			i=-1;
			}
	   }
   }
}
if ((TEMP.minus1==false && TEMP.minus2==false)) {
min=TEMP.count2;
if (TEMP.count1>TEMP.count2) {
	diff=TEMP.count1-TEMP.count2;
}
for (i=0; i<min; i++) {
	if (int(TEMP.number1[i])-48-carry < int(TEMP.number2[i])-48) {
	   result+=char(TEMP.base+int(TEMP.number1[i])-carry-48-(int(TEMP.number2[i])-48))+48;
	   carry=1;
	}
	if (int(TEMP.number1[i])-48-carry >= int(TEMP.number2[i])-48) {
	   result+=char((TEMP.base+(int(TEMP.number1[i])-48-carry)-(int(TEMP.number2[i])-48))%10)+48;
	   carry=0;
	}
}
for (i=min; i<TEMP.count1; i++) {
	if (int(TEMP.number1[i])-48 < carry) {
		result+=char(TEMP.base+int(TEMP.number1[i])-48-carry)+48;
		carry=1;
	}  else {
	   result+=char((TEMP.base+int(TEMP.number1[i])-48-carry)%10)+48;
	   carry=0;
	}
}
tmp=result.size();
diff=tmp-1;
for (i=tmp-1; i>=0; i--) {
	if (result[i]=='0') {
	diff--;
	} else
	i=-1;
}

temp.clear();
for (i=diff; i>=0; i--) {
	temp+=result[i];
}
result.clear();
if (flag) {
   result+="-";
   result+=temp;
   return result;
} else {
	if (temp.size()==0) {
	  temp+="0";
	}
return temp;
}
}
if (TEMP.minus1==true && TEMP.minus2==true) {
   TEMP.minus1=false;
   TEMP.minus2=false;
   if (!flag) {
   temp=TEMP.number1-TEMP.number2;
   result+="-";
   result+=temp;
   return result;
   } else {
   result=TEMP.number1-TEMP.number2;
   if (result.size()==0) {
	  result+="0";
   }
   return result;
   }
}
if (TEMP.minus1==false && TEMP.minus2==true) {
   TEMP.minus2=false;
   TEMP.number1=TEMP.reverse(TEMP.number1);
   TEMP.number2=TEMP.reverse(TEMP.number2);
   result=TEMP.number1+TEMP.number2;
   return result;
}
if (TEMP.minus1==true && TEMP.minus2==false) {
   TEMP.minus1=false;
   TEMP.number1=TEMP.reverse(TEMP.number1);
   TEMP.number2=TEMP.reverse(TEMP.number2);
   temp=TEMP.number1+TEMP.number2;
   result="-";
   result+=temp;
   return result;
}
}
