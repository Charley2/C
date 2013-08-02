#include "StdAfx.h"
#include "verylong.h"
#include <ios>

string operator/ (const string num1, const string num2) {
verylong TEMP;
TEMP.input(num1, num2);
string del, rem, chas, result, temp;
int i=0, j, carry, rhand, lhand, divisor, tmp, zero=0, deg=0, deg_rem=0, deg_chas=0, offset=TEMP.count1-1;
bool metka=false, flag, exit=false, acess=true;
if (TEMP.number2[0] == '0' && TEMP.count2 ==1) {
   string error="Nicht! Nicht! Nicht! Division under zero!";
   return error;
}
if (TEMP.count2>=TEMP.count1) {
if (TEMP.count1==TEMP.count2) {
   for (i=TEMP.count2-1; i>=0; i--) {
	   if (int(TEMP.number2[i])!=int(TEMP.number1[i])) {
	   if (int(TEMP.number2[i])>int(TEMP.number1[i])) {
		  result="0";
		  temp=TEMP.number1;
		  for (i=0; i<TEMP.count1/2; i++) {
			  tmp=temp[i]-48;
			  temp[i]=temp[(TEMP.count1-1)-i];
			  temp[(TEMP.count1-1)-i]=tmp+48;
		  }
		  i=-1;
		  acess=false;
	   } else {
			if (int(TEMP.number2[i])<int(TEMP.number1[i])) {
			i=-1;
			}
	   }
	   }
   }
} else {
  result="0";
  temp=TEMP.number1;
  for (i=0; i<TEMP.count1/2; i++) {
	  tmp=temp[i]-48;
	  temp[i]=temp[(TEMP.count1-1)-i];
	  temp[(TEMP.count1-1)-i]=tmp+48;
  }
  i=-10;
  acess=false;
  }
}
if (acess) {
for (i=TEMP.count1-TEMP.count2; i<TEMP.count1; i++) {
	del+=TEMP.number1[i];
	deg++;
}
for (i=TEMP.count2-1; i>=0; i--) {
	if (int(TEMP.number2[i]) != int(del[i])) {
		if (int(TEMP.number2[i])>int(del[i])) {
		deg=0;
		del.clear();
		for (i=(TEMP.count1-TEMP.count2)-1; i<TEMP.count1; i++) {
		  del+=TEMP.number1[i];
		  deg++;
		}
		i=-1;
		}	else { 
			if (int(TEMP.number2[i])<int(del[i])) {
				i=-1;
			}
		}
	}
}
carry=0;
while(!exit) {
metka=false, flag=false;
lhand=0, rhand=TEMP.base;
while (!metka) {
metka=true;
carry=0;
if (!flag) {
divisor=(rhand-lhand)/2;  //если меньше
}
if (flag) {
divisor=(rhand-lhand)/2+lhand; //если больше
}
for (i=0; i<TEMP.count2; i++) {
	tmp=int(TEMP.number2[i])-48;
	tmp*=divisor;
	tmp+=carry;
	carry=tmp/TEMP.base;
	if (tmp>TEMP.base-1) {
	tmp=tmp-(tmp/TEMP.base)*TEMP.base;
	}
	chas+=char(tmp)+48;
	deg_chas++;
}

if (carry>0) {
   deg_chas++;
   chas+=char(carry)+48;
}
if (deg_chas > deg) {
   //divisor должен быть меньше
   metka=false;
   flag=false;
}
if (metka) {
   if (deg_chas == deg) {
   for (i=deg_chas-1; i>=0; i-- ) {
	  if (int(chas[i])-48!=int(del[i])-48) {	
		if (int(chas[i])-48>int(del[i])-48) {
		//divisor должен быть меньше
		metka=false;
		flag=false;
		i=-1;
		} else {
			if (int(chas[i])-48<int(del[i])-48) {
			i=-1;
			}
	    }
	  }
   }
   }
}
   carry=0;
   if (metka) {
	  for (i=0; i<deg_chas; i++) {
		  if (int(del[i])-48-carry < int(chas[i])-48) {
			 rem+=char(10+int(del[i])-48-carry-(int(chas[i])-48))+48;
			 deg_rem++;
			 carry=1;
		  }
		  if (int(del[i])-48-carry >= int(chas[i])-48) {
			 rem+=char((10+int(del[i])-48-carry-(int(chas[i])-48))%10)+48;
			 deg_rem++;
			 carry=0;
		  }
	 }
   if (deg_rem==deg && carry==1) {
	  metka=false;
	  flag=false;
   }
   }
   if (metka) {
	  for (i=deg_chas; i<deg; i++) {
		  if (int(del[i])-48-carry < carry) {
			 if (i!=deg-1 &&  int(del[i])-48-carry!=0) {
			 rem+=char(10+int(del[i])-48-carry)+48;
			 deg_rem++;
			 carry=1;
			 }
		  }  else {
			 rem+=char((TEMP.base+int(del[i])-48-carry)%TEMP.base)+48;
			 deg_rem++;
			 carry=0;
			 }
	  }
	  if (deg_rem==deg && carry==1) {
		 //divisor  должен быть меньше
		 metka=false;
		 flag=false;
	  }
   }
   if (deg_rem > 0) {
   if (rem[deg_rem-1] == '0' && metka==true) {     //обрезание остатка
	 for (i=deg_rem-1; i>=0; i--) {
		  if (rem[i] == '0') {
		  deg_rem--;
		  }  else {
			 i=-1;
			 }
	 }
   }
   }
   if (metka==true && deg_rem>TEMP.count2) {
   //divisor должен быть больше
   metka=false;
   flag=true;
   }
   if (metka == true && deg_rem == TEMP.count2) {
		  for (i=TEMP.count2-1; i>=0; i--) {
			 if (metka && int(TEMP.number2[i]) != int(rem[i])) {
			  if (int(TEMP.number2[i]) < int(rem[i])) {
				//divisor должен быть больше
				metka=false;
				flag=true;
				i=-1;
			  } else {
					if (int(TEMP.number2[i]) > int(rem[i])) {
						i=-1;
					}
				}
			 } else {
				if (metka && int(TEMP.number2[i]) == int(rem[i])) {
					if (i==0) {
					metka=false;
					flag=true;
					i=-1;
					}
				}
			 }
		  }
   }
 if (!metka) {
	  if (flag==true) {
	  lhand=divisor;
	  }
	  if (flag==false) {
	  rhand=divisor;
	  }
   }
 if (!metka) {
 deg_chas=0, deg_rem=0;
 chas.clear();
 rem.clear();
 }
}

if (zero > 0) {
	zero--;
}
//if (offset+(deg-deg_chas)+(deg_chas-deg_rem)!=TEMP.count1-1) {
	for (i=0; i<zero; i++) {
	result+="0";
	}
	zero=0;
//}
result+=char(divisor)+48;
/*if (offset+(deg-deg_chas)+(deg_chas-deg_rem)==TEMP.count1-1) {
	for (i=0; i<zero; i++) {
	result+="0";
	}
	zero=0;
} */

j=offset-(deg-1);
offset-=((deg-deg_chas)+(deg_chas-deg_rem));   //начальное положение остатка отно-но number1
if (rem[0] == '0' && deg_rem==0) {    //когда остаток нулевой
	   offset++;
	   	while (j-1>=0 && TEMP.number1[j-1]=='0') { 
		j--;
		offset=j;
		result+="0";
		}
	   if (j-TEMP.count2>=0) {
		   deg_rem=1;   
	   }
}
if ((j-(TEMP.count2-deg_rem)>=0 && deg_rem<TEMP.count2) || (i=j-1>=0 && deg_rem==TEMP.count2))  {
   if (deg_rem==1 && rem[0]=='0') {  //когда остаток нулевой
	   deg_rem=0;
   }
 /*  if (deg_rem==TEMP.count2) {
	  for(i=j-(TEMP.count2-deg_rem)-1; i<j; i++) {
	  temp+=TEMP.number1[i];
	  }
   } */
 if (deg_rem<TEMP.count2) {
//	  if (deg_rem!=0 && rem[0]!='0') {
/*		 for(i=j-(TEMP.count2-deg_rem); i<j-1; i++) {
		 zero++;
		 }*/
//	  }
/*	  if (deg_rem==0 && rem[0]=='0') {			  
		  for(i=j-TEMP.count2; i<j; i++) {
			  result+="0";
		 }
	  }*/ 
			for(i=j-(TEMP.count2-deg_rem); i<j; i++) { 
				temp+=TEMP.number1[i];
				zero++;
			}
	  }
   for (i=0; i<deg_rem; i++) {
	  temp+=rem[i];
   }
if (temp.size() == TEMP.count2) 
{
		if (rem[0] == '0' && deg_rem == 0) {
			//j--;
			offset--;
		}
	for (i=TEMP.count2-1; i>=0; i--) {
		if (int(TEMP.number2[i])-48 < int(temp[i])-48) { //если temp > number2
			i=-10;
			rem.clear();
			del.clear();
			del=temp;
			deg=temp.size();
			temp.clear();
			chas.clear();
			deg_chas=0;
			deg_rem=0;
		} else {
			if (int(TEMP.number2[i])-48 > int(temp[i])-48) { //если temp < number2
				if (j-(TEMP.count2-deg_rem)-1>=0) {
					deg=0;
					temp.clear();
					for (i=(j-(TEMP.count2-deg_rem))-1; i<j; i++) {
						temp+=TEMP.number1[i];
					}
					for (i=0; i<deg_rem; i++) {
						temp+=rem[i];
					}
					i=-10;
					zero++;
					rem.clear();
					del.clear();
					del=temp;
					deg=temp.size();
					temp.clear();
					chas.clear();
					deg_chas=0;
					deg_rem=0;
				} else {
					if (zero>0) {
						for (i=0; i<zero; i++) {
							result+="0";
						}
					}
					i=-10;
					j=j-(TEMP.count2-deg_rem)-1;
					zero=0;
					rem=temp;
					deg_rem=temp.size();
					exit=true;
				}
			}
		}
	}
		if (i==-1) { //если temp == number2
			rem.clear();
			del.clear();
			del=temp;
			deg=temp.size();
			temp.clear();
			chas.clear();
			deg_chas=0;
			deg_rem=0;
		}
}
} else  {
	for (i=0; i < j; i++) {
		result+="0";
	}
  zero=0;
  exit=true;
  }
} //while(!exit)

temp.clear();  //для остатка
if (deg_rem==0 && rem[0]=='0') 
{
	deg_rem=1;
}
if(rem[0]=='0' && deg_rem==1) //нулевой остаток в конце алгоритма
{   
	if (j==0) {
	   for (i=deg_rem-1; i>=0; i--) {
		temp+=rem[i];
		}
	}
}
if (deg_rem>1)  
{
	for (i=deg_rem-1; i>=0; i--) {
		temp+=rem[i];
	}
} else {
	if (rem[0]!='0') {
	   for (i=deg_rem-1; i>=0; i--) {
	   temp+=rem[i];
	   }
	}
  }
for (i=j-1; i>=0; i--) {
temp+=TEMP.number1[i];
}
}
/*cout << "Remainder:   " << temp << endl; */
if ((TEMP.minus1==true && TEMP.minus2==false) || (TEMP.minus1==false && TEMP.minus2==true)) {
   temp=result;
   result.clear();
   result+="-";
   result+=temp;
}
return result;
}

/*
string verylong::transform_bin_in_dec(string bin) {
string dec="0", pow;
double size=bin.size(), i;
char *temp = new char[size];
for (i=size-1; i>=0; i--) {
	if (bin[i]=='1') {
		dec=dec+power_over("2",(size-1)-i);
	}
}
return dec;
}*/