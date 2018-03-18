#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

//int ofs = 260; // first save
int ofs = 0xd5e; // second save
int main(int argc, char *argv[])
{
	if(argc!=3) {
		cout << "Usage: "<<argv[0]<<" width height\n";
		return 0;
	}
	int x=strtol(argv[1],0,10), y=strtol(argv[2],0,10);
	string filename=string(getenv("HOME")) +"/.config/runesoft/robinhood/Profiles";

	if(FILE* f = fopen(filename.c_str(), "r+b")) {
		//read file
		float rf[2];
		fseek(f, ofs, SEEK_SET);
		fread(&rf, 4, 2, f);
		printf("%d, Resolution was %dx%d\n",ofs,int(rf[0]),int(rf[1]));

		//write file
		float wf[2]={float(x),float(y)};
		fseek(f, ofs, SEEK_SET);
		fwrite(&wf, 4, 2, f);
		fclose(f);
		printf("Resolution set to %dx%d\n",x,y);
	} else {
		cout << "File "+filename+" not found. Make sure you have a savefile in ~/.config/runesoft/robinhood/Profiles\n";
	}
}
