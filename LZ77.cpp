//It is recommended to read ReadME.md file before running the algorithm.

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int window_size,sb_size,lab_size;

struct values
{
	int v1,v2;
};

values is_available(char sb[],char lab[])	//checks sb and internal lab repetition
{
	int i=0,j=0,count=0,prev_length=0;
	values v;
	v.v1=0;
	v.v2=0;
	while(i<sb_size) 
	{
		/* checking in sb if lab characters are present. if all match then go upto
		   lab_size not ahead otherwise it will cause std:out_of_range */
		while((lab[j]==sb[i])&&(count<lab_size))
		{
			j++;
			i++;
			count++;
		} 
		char tempa[count]; //Storing matched array to check repeated counts in LAB 
		int p=0;
		while(p<count)
		{
			tempa[p]=sb[i-(count-p)];	//tempa= temp aRRAY
			p++;
		}
		p=0;
		int temp_count=count;
		while(lab[j]==tempa[p])	//checking internal repetition of lab
		{
			j++;
			p++;
			if(p==temp_count)
			{
				p=0;
			}
			count++;
		}
		if(count>=prev_length && count!=0)
		{
			prev_length=count;
			v.v1=(sb_size)-(i-temp_count);
			v.v2=count;
		}
		
		i++;	//Check string for further match ahead if any 
		count=0;
		j=0;
	}
	return v;
}

char* sliding_window(string s,char window[])
{
	int i;
	for(i=0;i<s.length();i++)
	{
		window[i]=s.at(i);
	}
	return window;
}
int main()
{
	int i,j;
	vector<int>pos;
	vector<int>len;
	vector<char>ch;
	cout<<"\n Enter window size and sb size:";
	cin>>window_size>>sb_size;
	lab_size=window_size-sb_size;
	string s1;
	cout<<"\n Enter the string : ";
	cin>>s1;
	cout<<"\n string s1:"<<s1;
	cout<<"\n length of s1:"<<s1.length();
	char sb[sb_size];
	char lab[lab_size];
		
	// Initializing the Look ahead buffer.
	for(i=0;i<lab_size;i++)
	{
		lab[i]=s1.at(i);
	}
	for(i=0;i<sb_size;i++)
	{
		sb[i]='\0';
	}
	// Taking in character by character and putting it into sb 
	i=0;
	int p,k;
	cout<<"\n\n";
	while(i<s1.length())
	{
		values v=is_available(sb,lab);	//checking match
		//cout<<"\n pos:"<<v.v1<<"\t length:"<<v.v2<<"\t i:"<<i;
		cout<<"\n < "<<v.v1<<" , "<<v.v2<<" , c("<<s1.at(i+v.v2)<<" ) >";
		pos.push_back(v.v1);
		len.push_back(v.v2);
		ch.push_back(s1.at(i+v.v2));
		for(j=0;j<=v.v2;j++)
		{	
			for(k=1;k<sb_size;k++)
			{
				sb[k-1]=sb[k];	
			}
			sb[k-1]=s1.at(i+j);
		}
		string sub=s1.substr(i+(v.v2)+1,lab_size);
		char *ptr=sliding_window(sub,lab);	
		for(j=0;j<lab_size;j++)	//updating lab
		{
			ptr[j]=lab[j]; 
		}	
		i+=v.v2+1;
	}	
	i=0;
	string decoding_str;
	while(i<s1.length())
	{
		for(j=0;j<pos.size();j++)
		{
			if(pos.at(j)>=len.at(j))	//if there is no internal repetition of lab
			{
				decoding_str+=decoding_str.substr(decoding_str.length()-pos.at(j),len.at(j));	
				decoding_str+=ch.at(j);	//add the c() character
			}
			else	//if there is internal repetition of lab
			{
				char temp_array[pos.at(j)];
				int p,m=1;
				for(p=0;p<pos.at(j);p++)
				{
					temp_array[p]=decoding_str.at(decoding_str.length()-pos.at(j)+p);
				}
				p=0;
				int temp_count=len.at(j);
				while(m<=temp_count)
				{
					decoding_str+=temp_array[p];
					p++;
					m++;
					p=p%pos.at(j);	//if there is repetition more times
				}
				decoding_str+=ch.at(j);	//add c() character
			}
			i+=len.at(j)+1;
		}	
	}	
	
	cout<<"\n\n decoding str:"<<decoding_str;
	cout<<"\n\n length of decoding_str:"<<decoding_str.length();
	return 0;	
	}
