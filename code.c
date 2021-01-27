#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isal(char a)
{
	if(a>='A' && a<='Z')
		return 1;
	if(a>='a' && a<= 'z')
		return 1;
	if(a=='0')
		return 1;
	else
		return 0;
}

char * decode(char *ptr)
{
	/*
	aPp1e5
	Pa1p5e
	Pa*1p*5e
	51Pa*0p*0e
	*/
	int n=strlen(ptr),i=0,j=0;
	char arr[100],num[100];

	
//	printf("arr=%s\nnum=%s\n",arr,num);
	
	while(*ptr)
	{	
		if(*ptr=='\n')
		arr[i++]=0;
		else if(*ptr=='*')
			ptr++;
		else if(*ptr>='1' && *ptr<='9')
			num[j++]=*ptr++;
		else if(isal(*ptr) && isal(*(ptr+1)) )
		{
			arr[i++]=*(ptr+1);
			arr[i++]=*ptr++;
			ptr++;
		}
		else
		arr[i++]=*ptr++;
	}

	num[j]=0;
	//ptr=arr;
	for(i=1,j=0;i>=0;i--)
	{
	///	printf("%c",arr[i]);
		if(ptr[i]=='0')
			ptr[i]=num[j++];
	}

	printf("arr=%s\nnum=%s\n",arr,num);

	//ptr=arr;
	
return ptr;
}

char * getstring()
{	
	//puts("in getstring");
	char *ptr=NULL,c;
	int i=0;
	do
	{	//puts("in do while loop");
		ptr=realloc(ptr,1+i);
		scanf("%c",&c);
		ptr[i++]=c;
	//	printf("%d %d",i,ptr[i-1]);
	}while(ptr[i-1]!='\n');
	
	ptr[i]=0;
return ptr;
}

int main()
{
	char *code=getstring();
	code=decode(code);
	puts("in main");
	printf("%s\n",code);
	return 0;
}
