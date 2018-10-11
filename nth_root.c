#include<stdio.h>

double power(double x,int n)
{
	int i; double f=1;
	for(i=1;i<=n;i++)
		f*=x;
	return f;
}


int main()
{
	double x,a,b,c,t,s=1,i=0,prc=0;
	int n,choice,iter=200,count=0;
	printf("\n..Find N'th root of a given number(X)..\nEnter the number('x') and value of 'n'=[\n");
	scanf("%lf%d",&x,&n);
	printf("\nPlease specify MAXIMUM NO. OF ITERATION   OR   PRECISION,\n '0' for iteration limit   or   '1' for exactness\nEnter=[");
	scanf("%d",&choice);
	if(choice){
		printf("\nCorrect upto ( 2/3/4/disable ) decimal places, Choice=[");
		scanf("%d",&choice);
		prc=(choice==2)?0.009999999:((choice==3)?0.000999999:(choice==4)?0.000099999:0);
	}
	else{
		printf("\nMaximum number of iteration=[");
		scanf("%d",&iter);
	}
	printf("Do you want to see the iterations? Enter '1' for YES or '0' for NO =[");
	scanf("%d",&choice);
	if((n%2==0 && x<0) || n<0){
		printf("\nvalues are abnormal !\n");
		goto stop;
	}
	//************************initialize a and b****************//
		t=(x<0)?-1:1;
		s=t*x;
		while(power(i,n)<=s)
			i+=0.2;
		//printf("\ni=%lf\n",i);
		a=(t==1)?(i-0.2):(-1)*i;
		b=(t==1)?i:(-1)*(i-0.2);
		printf("\nHere is the initial values X(-ve)=%lf and X(+ve)=%lf\n\n",a,b);
	
	//*******************************Process for new x***********************//
	while(s!=0 && count<=iter && t*(b-a)>prc){
		t=power(a,n);
		c=a-(((b-a)*(t-x))/((power(b,n)-x)-(t-x)));	//.....regula-falsi
		//c=(a+b)/2;	//.................................bisection
		s=power(c,n)-x;
		if(choice)
			printf("\nX(-ve)=%lf   X(+ve)=%lf   New X=%lf  f(X)=%lf\n",a,b,c,s);
		if(s<0)
			a=c;
		else if(s>0)
			b=c;
		count++;
	}
	//********************************end of process*******************************//
	printf("\nThe %dth root of %lf is =[%lf or %d (rounded approx.) \n",n,x,c,choice=c);
	stop:
	return 0;
}
