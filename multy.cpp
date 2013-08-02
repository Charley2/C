
string operator* (const string num1, const string num2) {
	verylong TEMP;
	string res, sum="0", result;
	int i, j=0, tmp, carry=0, max=0, dif, deg1, deg2;
	char sym;
	TEMP.input(num1, num2);
	if ((TEMP.number1[0]=='0' && TEMP.count1==1) || (TEMP.number2[0]=='0' && TEMP.count2==1)) {
		TEMP.minus1=false;
		TEMP.minus2=false;
		sum="0";
		return sum;
	}
	for (j=0; j<TEMP.count1; j++) {
	res.clear();
	result.clear();
		for (i=0; i<TEMP.count2; i++) {
			tmp=int(TEMP.number2[i]-48);
			tmp*=(int(TEMP.number1[j]-48));
			tmp+=carry;
			carry=tmp/10;
		if (tmp>9) {
		tmp=tmp-(tmp/10)*10;
		}
		res+=char(tmp)+48;
		}
   if (carry>0) {
   res+=char(carry)+48;
   }
   carry=0;
   result=res;
   res.clear();
   for (i=0; i<j; i++) {
   res+='0';
   }
   for (i=0; i<result.size(); i++) {
	   res+=result[i];
   }
   result.clear();
   //cout << "sum:  " << sum << "res:  " << res << endl;
   deg1=sum.size(), deg2=res.size();
	if (deg2>deg1) {  //number1 - sum   number2 - res
		result=sum;
		sum.clear();
		sum=res;
		res.clear();
		res=result;
		result.clear();
		dif=deg1;
		deg1=deg2;
		deg2=dif;
		dif=0;
	}
	if (deg2==deg1) {
		for (i=deg1-1; i>=0; i--) {
			if (int(sum[i])<int(res[i])) {
				string temp;
				temp=res;
				res.clear();
				res=sum;
				sum.clear();
				sum=temp;
				temp.clear();
				i=-1;
			}
		}
	}
	if (deg1>deg2 || deg1==deg2) {
	   dif=deg1-deg2;
	   max=deg2;
	}
	for (i=0; i<max; i++) {
	result+=char(((int(sum[i])-48)+((int(res[i])-48)+carry))%TEMP.base)+48;
	if (((int(sum[i])-48)+(int(res[i]-48))+carry)>TEMP.base-1) {
	carry=1;
	} else
		carry=0;
	}
	if (deg1 != deg2) {
	for (i=max; i<deg1; i++) {
	   if (deg1>deg2) {
		   result+=char((int(sum[i])-48+carry)%TEMP.base)+48;
		   if ((int(sum[i])-48+carry)>TEMP.base-1) {
		   carry=1;
		   } else
			   carry=0;
	   }
	}
	}
	if (carry==1) {
		result+=char(carry)+48;
	}
   sum.clear();
   sum=result;
   max=0, dif=0, carry=0;
   }
   max=sum.size();
   for (i=0; i<max/2; i++) {
	   sym=sum[i];
	   sum[i]=sum[(max-1)-i];
	   sum[(max-1)-i]=sym;

   }
   if ((TEMP.minus1==true && TEMP.minus2==false) || (TEMP.minus1==false && TEMP.minus2==true)) {
   res.clear();
   res=sum;
   sum.clear();
   sum+='-';
   sum+=res;
   res.clear();
   }
return sum;
}

string verylong::power_over(string p, double n) {
	string res = "1";
	double i;
/*	ostringstream oss; //�������������� �� double � string
	oss << n;
	power=oss.str();*/
	for (i=0; i < n; i++) 
		res = res*p;
	return res;
}
