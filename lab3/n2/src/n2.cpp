#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	srand(time(NULL));
	 ofstream textFile("INPUT.txt");

	 for(int i=0; i<2; i++)
	 {
		 for (int i=0; i <5; i++)
			 textFile << rand() %9 << ' ';
		 textFile << endl;
	 }
	 textFile.close();

	 ofstream text("OUTPUT.txt");

	 int n;

	 vector<double> vec;

	 double average =0;

	 ifstream file("INPUT.txt");

	 while (file >> n)
		 vec.push_back(n);

	average = accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
	text << average;

	 file.close();

	 text.close();
	return 0;
}
