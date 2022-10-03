#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// Function prototypes
void readPunchLine(ifstream&);
void readJoke(ifstream&);

int main()
{
	// Declare file streams
	ifstream jokeFile;
	ifstream punchLineFile;

	// Open the joke and punchline files
	jokeFile.open("joke.txt");
	punchLineFile.open("punchline.txt");

	// If there is an error opening the files break out of the application with a message
	if (jokeFile.fail() || punchLineFile.fail()) {
		cout << "There was an error opening the file." << endl;
		return 1;
	}

	// Execute functions to read lines
	readJoke(jokeFile);
	readPunchLine(punchLineFile);

	// Close the files when finished
	jokeFile.close();
	punchLineFile.close();
	
	return 0;
}

void readJoke(ifstream& jokeFile) {
	string joke;

	// Read each line and
	while (!jokeFile.eof()) {
		getline(jokeFile, joke);
		// Print the joke value
		cout << joke << endl;
	}
}

void readPunchLine(ifstream& punchLineFile) {
	string punchLine = "";
	char ch;

	// Initialize int i to track moving backwards from end
	int i = -1;

	// Get byte position for the last letter and store in i
	punchLineFile.seekg(i, ios::end);

	// Set character at last byte position to the ch variable
	ch = punchLineFile.get();

	// Loop backwards from the last character until the first \n character is found
	while (ch != '\n') {
		// Add character first or string will be backwards
		punchLine = ch + punchLine;
		punchLineFile.seekg(--i, ios::end);
		ch = punchLineFile.get();
	}

	// Print the punch line string
	cout << punchLine << endl;
}