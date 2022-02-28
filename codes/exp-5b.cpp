#include<iostream>
#include<unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout<<"usage: "<<argv[0]<<" <src-file> <dest-file>"<<endl;
		exit(0);
	}
	if (link(argv[1], argv[2]) == -1) {
		perror("link");
		return -1;
	}
	return 0; 
}


