////////////////////////////////////////////////////////////
//Program 1 
//
//Author: vpvdev.
//Refer README for Question. 
////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int main()
{
	std::string s_ip;
	int i_run, j_run,i_cursor,i_strlen = 0;
	char temp,c_midval = 0;
	std::map<char,int> m_store;
	std::map<char,int>::iterator it;
	
	std::cout << "enter the string:";
	getline(std::cin, s_ip);
	
	/*sorting in alaphabetical order*/
	for(i_run = 0; s_ip[i_run] != '\0'; i_run++)
	{
		for(j_run = i_run + 1; s_ip[j_run] != '\0'; j_run++)
		{
			if(s_ip[i_run] > s_ip[j_run])
			{
				temp = s_ip[i_run];
				s_ip[i_run] = s_ip[j_run];
				s_ip[j_run] = temp;
			}
		}
	}
	
	/*storing with frequency of occurence*/	
	j_run = 1;
	for(i_run = 0; s_ip[i_run] != '\0'; i_run++)
	{
		i_strlen++;
		if( s_ip[i_run] == s_ip[i_run+1] )
		{
			j_run++;
			continue;
		}
		else
		{
			m_store[s_ip[i_run]] = j_run;
			j_run = 1;
		}
	}
	
	/*is palindrome possible or not*/
	it = m_store.begin();
	i_run = 0;
	while(it != m_store.end())
	{	
		if(it->second %2)
		{
			i_run++;
			c_midval = it->first;			
		}
		it++;			
	}	
	if(i_run > 1)
	{
		cout << "palindrom is not possible!!! Good Bye!!!"<<i_run<<endl;
		return 0;
	}
		
	/*creating the lexographically first palindrome*/
	i_cursor = 0;
	for (it = m_store.begin(); it != m_store.end(); it++)
	{
		i_run = it->second;
		temp  = it->first;
		for(j_run = 0; j_run < i_run/2; j_run++)
		{
			s_ip[i_cursor] = temp;
			s_ip[i_strlen - i_cursor - 1] = temp;
			i_cursor += 1;
		}
	}	
	if(c_midval)
		s_ip[i_cursor] = c_midval; 
		
	std::cout << "Palindrome output for the given string(lexographically):"<<s_ip << std::endl;
	return 0;
	
}
