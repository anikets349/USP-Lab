#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<unistd.h>
#include<limits.h>
#include<iostream>
using namespace std;

int main(void) {
	cout<<"1. Compile time limits"<<endl;
	cout<<"2. Runtime limits"<<endl;
	cout<<"Enter your choice : ";
	int choice;
	cin>>choice;
	
	switch(choice) {
		case 1 : 
			#ifdef _POSIX_CLK_TCK
				cout<<"Number of clock ticks per second is : "<<_POSIX_CLK_TCK<<endl;
			#else
				cout<<"_POSIX_CLK_TCK not defined"<<endl;
			#endif
			
			#ifdef _POSIX_CHILD_MAX
				cout<<"Number of child processes opened by a process at any time : "<<_POSIX_CHILD_MAX<<endl;
			#else
				cout<<"_POSIX_CHILD_MAX not defined"<<endl;
			#endif
			
			#ifdef _POSIX_PATH_MAX
				cout<<"Maximum no. of characters in the pathname of a file is : "<<_POSIX_PATH_MAX<<endl;
			#else
				cout<<"_POSIX_PATH_MAX not defined"<<endl;
			#endif
			
			#ifdef _POSIX_NAME_MAX
				cout<<"Maximum no. of characters in the filename is : "<<_POSIX_NAME_MAX<<endl;
			#else
				cout<<"_POSIX_NAME_MAX not defined"<<endl;
			#endif
			
			#ifdef _POSIX_OPEN_MAX
				cout<<"Maximum no. of files opened by a process is : "<<_POSIX_OPEN_MAX<<endl;
			#else
				cout<<"_POSIX_OPEN_MAX not defined"<<endl;
			#endif
			
			break;
			
		case 2 :
			int res;
			if ((res = (sysconf(_SC_CLK_TCK))) == -1) 
				perror("sysconf");
			else
				cout<<"No. of clock ticks at runtime : "<<res<<endl;
				
			if ((res = (sysconf(_SC_CHILD_MAX))) == -1) 
				perror("sysconf");
			else
				cout<<"Number of child processes opened by a process at any time : "<<res<<endl;
				
			if ((res = (pathconf("/",_PC_PATH_MAX))) == -1) 
				perror("pathconf");
			else
				cout<<"Maximum no. of characters in the pathname of a file is : "<<res<<endl;
				
			if ((res = (fpathconf(0,_PC_NAME_MAX))) == -1) 
				perror("fpathconf");
			else
				cout<<"Maximum no. of characters in the filename is : "<<res<<endl;
				
			if ((res = (sysconf(_SC_OPEN_MAX))) == -1) 
				perror("sysconf");
			else
				cout<<"Maximum no. of files opened by a process is : "<<res<<endl;
				
			break;
			
		default:
			cout<<"No matching choice found"<<endl;	
	}
	return 0;
}
