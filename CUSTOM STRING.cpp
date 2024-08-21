#include<iostream>
#include<cstring>
using namespace std;

//string class
class STRING
{
	char *p;
	public:
	STRING()
	{
		p=0;
	}
	STRING(const char *s)
	{
		p=new char[strlen(s)+1];
		strcpy(p,s);
	}
/*	STRING(STRING &t)
	{
		p=new char[strlen(t.p)+1];
		strcpy(p,t.p);
	}*/
	void getdata()
	{
		cout<<p<<endl;
	}

	void setdata()
	{
		cin>>p;
	}

//overloading operators
STRING operator+(STRING );
char& operator[](int);
STRING& operator=(STRING t);
friend ostream& operator<<(ostream& ,STRING );
friend istream& operator>>(istream& ,STRING );
int operator<(STRING);
int operator>(STRING);
int operator==(STRING);
int operator<=(STRING);
int operator>=(STRING);
int operator!=(STRING);

//friend functions
friend STRING & my_strcpy(STRING &,STRING &);
friend STRING & my_strncpy(STRING &,STRING &,int );
friend int my_strcmp(STRING &,STRING &);
friend int my_strncmp(STRING &,STRING &,int );
friend int my_strlen(STRING &);
friend STRING& my_strcat(STRING &,STRING &);
friend STRING& my_strncat(STRING &,STRING &,int );
friend STRING& my_strrev(STRING &);
friend char *my_strchr(STRING &,char );
friend char *my_strrchr(STRING &,char );
friend char *my_strstr(STRING &,char *);
friend STRING& my_strupr(STRING &);
friend STRING& my_strlwr(STRING &);
friend char *my_strswap(STRING &);
 
};	//string class ends here

char *my_strswap(STRING &t)
{
	char *p=t.p;
	while(*p)
	{
		if(*p>='a'&&*p<='z')
			*p=*p-32;
		else if(*p>='A'&& *p<='Z')
			*p=*p+32;
		p++;
	}
	return t.p;
}

STRING& my_strlwr(STRING &t)
{
	char *p=t.p;
	while(*p)
	{
		if(*p>='A'&&*p<='Z')
			*p=*p+32;
		p++;
	}
	return t;
}

STRING& my_strupr(STRING &t)
{
	char *p=t.p;
	while(*p)
	{
		if(*p>='a'&&*p<='z')
			*p=*p-32;
		p++;
	}
	return t;
}

char *my_strstr(STRING &t,char* s)
{
	return strstr(t.p,s);
}

char*  my_strchr(STRING &t,char ch)
{
	return strchr(t.p,ch);
}

char* my_strrchr(STRING &t,char ch)
{
	return strrchr(t.p,ch);
}

STRING& my_strrev(STRING & t)
{
	char *p=t.p;
	char *q=p;
	char temp;
	while(*q)
		q++;
	q--;
	while(p<q)
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
	}
	return t;
}

STRING& my_strncat(STRING &t1,STRING &t2,int n)
{
	strcat(t1.p," ");
	strncat(t1.p,t2.p,n);
	return t1;
}

STRING& my_strcat(STRING &t1,STRING &t2)
{
	strcat(t1.p," ");
	strcat(t1.p,t2.p);
	return t1;
}


int my_strlen(STRING &t)
{
	return strlen(t.p);
}

int my_strncmp(STRING &t1,STRING &t2,int n)
{
	return strncmp(t1.p,t2.p,n);
}

int my_strcmp(STRING &t1,STRING &t2)
{
	return strcmp(t1.p,t2.p);
}

STRING& my_strcpy(STRING &t1,STRING &t2)
{
	strcpy(t1.p,t2.p);
	return t1;
}

STRING& my_strncpy(STRING &t1,STRING &t2,int n)
{
	//strncpy(t1.p,t2.p,n);
	char *d=t1.p;
	char *s=t2.p;
	int temp=n;
	while(temp)
	{
	*d=*s;
	d++;
	s++;
	temp--;
	}
	*d='\0';
	return t1;
}

int STRING::operator>=(STRING t)
{
	return strcmp(p,t.p);
}

int STRING::operator<=(STRING t)
{
	return strcmp(p,t.p);
}

int STRING::operator!=(STRING t)
{
	return strcmp(p,t.p);
}

int STRING::operator==(STRING t)
{
	return strcmp(p,t.p);
}

int STRING::operator<(STRING t)
{
	return strcmp(p,t.p);
}

int STRING::operator>(STRING t)
{
	return strcmp(p,t.p);
}

ostream& operator<<(ostream& out,STRING t)
{
	out<<t.p;
	return out;
}

istream& operator>>(istream& in,STRING t)
{
	in>>t.p;
	return in;
}

STRING& STRING::operator=(STRING t)
{
	p=t.p;
	return *this;
}

STRING STRING::operator+(STRING x)
{
	STRING t;
	t.p=new char[strlen(p)+strlen(x.p)+1];
	strcpy(t.p,p);
	strcat(t.p," ");
	strcat(t.p,x.p);

	return t;
}

char& STRING::operator[](int i)
{
	return p[i];
}



int main()
{
STRING s1("Hello"),s2("Manju"),s3,s4(s2);

cout<<"copy constructor(usign deep copy)"<<endl;
cout<<s4<<endl;
cout<<"-------------------"<<endl;

cout<<"s1: "<<s1<<endl;
cout<<"s2: "<<s2<<endl;
s3=s1+s2;
cout<<"+ operator overloaded"<<endl;
cout<<"s3=s1+s2"<<endl;
s3.getdata();
cout<<"-------------------"<<endl;

cout<<"= operator overloaded"<<endl;
cout<<"s4=s3"<<endl;
s4=s3;
s4.getdata();
cout<<"-------------------"<<endl;

cout<<"[] operator overloaded"<<endl;
for(int i=0;s3[i];i++)
{
cout<<s3[i]<<" ";
}
cout<<endl;
cout<<"-------------------"<<endl;

cout<<">> operator overloaded"<<endl;
cout<<"enter two string s1 and s2"<<endl;
cin>>s1;
cin>>s2;
cout<<"-------------------"<<endl;

cout<<"<< operator overloaded"<<endl;
cout<<s1<<"\n"<<s2<<endl;
cout<<"-------------------"<<endl;



////friend function////
cout<<"friend functions"<<endl;

cout<<"-------------------\n"<<endl;
cout<<"strcpy()"<<endl;
cout<<"enter two strings"<<endl;
cin>>s1>>s2;
my_strcpy(s1,s2);
cout<<"string copied successfully"<<endl;
cout<<s1<<endl;

cout<<"-------------------\n"<<endl;

cout<<"strncpy()"<<endl;
cout<<"enter two strings"<<endl;
cin>>s1>>s2;
cout<<"Enter the N value"<<endl;
int n;
cin>>n;
my_strncpy(s1,s2,n);
cout<<"string copied successfully"<<endl;
cout<<s1<<endl;
cout<<"-------------------\n"<<endl;

cout<<"strcmp()"<<endl;
cout<<"enter two strings"<<endl;
cin>>s1>>s2;
int i=my_strcmp(s1,s2);
if(i){
cout<<"not equal"<<endl;
}
else 
cout<<"equal"<<endl;
cout<<"-------------------\n"<<endl;

cout<<"strncmp()"<<endl;
cout<<"enter two strings"<<endl;
cin>>s1>>s2;
cout<<"Enter N value"<<endl;
cin>>n;
i=my_strncmp(s1,s2,n);
if(i){
cout<<"not equal"<<endl;
}
else 
cout<<"equal"<<endl;
cout<<"-------------------\n"<<endl;

cout<<"strcat()"<<endl;
cout<<"enter two strings"<<endl;
cin>>s1>>s2;
cout<<my_strcat(s1,s2);
cout<<"-------------------\n"<<endl;

cout<<"strncat()"<<endl;
cout<<"enter two strings"<<endl;
cin>>s1>>s2;
cout<<"Enter N value"<<endl;
cin>>n;
cout<<my_strncat(s1,s2,n);
cout<<"-------------------\n"<<endl;

cout<<"strrev()"<<endl;
cout<<"enter one string"<<endl;
cin>>s1;
cout<<my_strrev(s1);
cout<<"-------------------\n"<<endl;

cout<<"strchr()"<<endl;
cout<<"enter one string"<<endl;
cin>>s1;
char ch;
cout<<"Enter the character"<<endl;
cin>>ch;
cout<<my_strchr(s1,ch)<<endl;
cout<<"-------------------\n"<<endl;

cout<<"strrchr()"<<endl;
cout<<my_strrchr(s1,ch)<<endl;
cout<<"-------------------\n"<<endl;

cout<<"strstr()"<<endl;
cout<<"enter MAIN string and SUB string"<<endl;
char s[10];
cin>>s1>>s;
cout<<my_strstr(s1,s)<<endl;
cout<<"-------------------\n"<<endl;

cout<<"strupr()"<<endl;
cout<<"enter one string"<<endl;
cin>>s1;
cout<<my_strupr(s1)<<endl;
cout<<"-------------------\n"<<endl;

cout<<"strlwr()"<<endl;
cout<<"enter one string"<<endl;
cin>>s1;
cout<<my_strlwr(s1)<<endl;
cout<<"-------------------\n"<<endl;

cout<<"strswap()"<<endl;
cout<<"enter one string"<<endl;
cin>>s1;
cout<<my_strswap(s1)<<endl;
cout<<"-------------------\n"<<endl;
}
